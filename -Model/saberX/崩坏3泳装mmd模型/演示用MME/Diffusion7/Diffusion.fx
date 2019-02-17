////////////////////////////////////////////////////////////////////////////////////////////////
// ���[�U�[�p�����[�^

// �ڂ����͈�(�傫����������ƎȂ��o�܂�)
float Extent
<
   string UIName = "Extent";
   string UIWidget = "Slider";
   bool UIVisible =  true;
   float UIMin = 0.00;
   float UIMax = 0.01;
> = float( 0.002 );

// �t�B���^���x
float Strength
<
   string UIName = "Strength";
   string UIWidget = "Slider";
   bool UIVisible =  true;
   float UIMin = 0.0;
   float UIMax = 1.0;
> = float( 0.7 );


//�w�i�F
float4 ClearColor
<
   string UIName = "ClearColor";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4(0,0,0,0);


//�������@�̑I��
// 0: �I���W�i���摜�ƍ���
// 1: ���ȏ�Z�摜�ƍ���
#define MIX_TYPE  1


//���x��r�@�̑I��
// 0: �t�H�g�V���b�v����
// 1: �x�N�g������r
// 2: �e�F���Z��r
// 3: �e�F�ʔ�r
#define BCOMP_TYPE  0


//�ڂ����̃T���v�����O��
#define SAMP_NUM  7


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//����ȍ~�̓G�t�F�N�g�̒m���̂���l�ȊO�͐G��Ȃ�����


float Script : STANDARDSGLOBAL <
    string ScriptOutput = "color";
    string ScriptClass = "scene";
    string ScriptOrder = "postprocess";
> = 0.8;


// �}�e���A���F
float4 MaterialDiffuse : DIFFUSE  < string Object = "Geometry"; >;
static float alpha1 = MaterialDiffuse.a;

float scaling0 : CONTROLOBJECT < string name = "(self)"; >;
static float scaling = scaling0 * 0.1;

float3 objpos : CONTROLOBJECT < string name = "(self)"; >;

// �X�N���[���T�C�Y
float2 ViewportSize : VIEWPORTPIXELSIZE;

static const float2 ViewportOffset = (float2(0.5,0.5)/ViewportSize);

static const float2 SampStep = (float2(Extent,Extent)/ViewportSize*ViewportSize.y) * scaling;

// �����_�����O�^�[�Q�b�g�̃N���A�l
float ClearDepth  = 1.0;

// �[�x�o�b�t�@
texture2D DepthBuffer : RENDERDEPTHSTENCILTARGET <
    float2 ViewPortRatio = {1.0,1.0};
    string Format = "D24S8";
>;

// �I���W�i���̕`�挋�ʂ��L�^���邽�߂̃����_�[�^�[�Q�b�g
texture2D ScnMap : RENDERCOLORTARGET <
    float2 ViewPortRatio = {1.0,1.0};
    int MipLevels = 1;
    string Format = "A8R8G8B8" ;
>;
sampler2D ScnSamp = sampler_state {
    texture = <ScnMap>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
    MipFilter = NONE;
    AddressU  = CLAMP;
    AddressV = CLAMP;
};

// X�����̂ڂ������ʂ��L�^���邽�߂̃����_�[�^�[�Q�b�g
texture2D ScnMap2 : RENDERCOLORTARGET <
    float2 ViewPortRatio = {1.0,1.0};
    int MipLevels = 1;
    string Format = "A8R8G8B8" ;
>;
sampler2D ScnSamp2 = sampler_state {
    texture = <ScnMap2>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
    MipFilter = NONE;
    AddressU  = CLAMP;
    AddressV = CLAMP;
};


////////////////////////////////////////////////////////////////////////////////////////////////
// ���ʒ��_�V�F�[�_
struct VS_OUTPUT {
    float4 Pos            : POSITION;
    float2 Tex            : TEXCOORD0;
};

VS_OUTPUT VS_passDraw( float4 Pos : POSITION, float4 Tex : TEXCOORD0 ) {
    VS_OUTPUT Out = (VS_OUTPUT)0; 
    
    Out.Pos = Pos;
    Out.Tex = Tex + ViewportOffset;
    
    return Out;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// ���x��r

float4 BrightnessCompare(float4 color1, float4 color2){
    
    color1.a = color2.a > color1.a ? color2.a : color1.a;
    
    #if BCOMP_TYPE==0
        float brightness1 = (color1.r * 0.29 + color1.g * 0.59 + color1.b * 0.12);
        float brightness2 = (color2.r * 0.29 + color2.g * 0.59 + color2.b * 0.12 );
        
        if(brightness2 > brightness1) color1 = color2;
        
    #elif BCOMP_TYPE==1
        float brightness1 = length(color1.rgb);
        float brightness2 = length(color2.rgb);
        
        if(brightness2 > brightness1) color1 = color2;
        
    #elif BCOMP_TYPE==2
        float brightness1 = (color1.r + color1.g + color1.b );
        float brightness2 = (color2.r + color2.g + color2.b );
        
        if(brightness2 > brightness1) color1 = color2;
        
    #elif BCOMP_TYPE==3
        color1.r = color2.r > color1.r ? color2.r : color1.r;
        color1.g = color2.g > color1.g ? color2.g : color1.g;
        color1.b = color2.b > color1.b ? color2.b : color1.b;
        
    #endif
    
    return color1;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// X�����ڂ���

float4 PS_passX( float2 Tex: TEXCOORD0 ) : COLOR {   
    float4 Color, sum = 0;
    float e, n = 0;
    
    [unroll] //���[�v�W�J
    for(int i = -SAMP_NUM; i <= SAMP_NUM; i++){
        float2 stex = Tex + float2(SampStep.x * (float)i, 0);
        e = exp(-pow((float)i / (SAMP_NUM / 2.0), 2) / 2); //���K���z
        
        float4 org_color = tex2D( ScnSamp, stex );
        org_color.rgb = pow(org_color.rgb, 2); //RGB��2��
        sum += org_color * e;
        n += e;
    }
    
    Color = sum / n;
    return Color;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Y�����ڂ��� + ����

float4 PS_passY(float2 Tex: TEXCOORD0) : COLOR
{   
    float4 Color, sum = 0;
    float4 ColorSrc, ColorOrg;
    
    float e, n = 0;
    
    [unroll] //���[�v�W�J
    for(int i = -SAMP_NUM; i <= SAMP_NUM; i++){
        float2 stex = Tex + float2(0, SampStep.y * (float)i);
        e = exp(-pow((float)i / (SAMP_NUM / 2.0), 2) / 2); //���K���z
        sum += tex2D( ScnSamp2, stex ) * e;
        n += e;
    }
    
    Color = sum / n;
    ColorOrg = tex2D( ScnSamp, Tex );
    ColorSrc = float4(pow(ColorOrg.rgb, 2), ColorOrg.a);
    
    //�X�N���[������
    Color.rgb = Color.rgb + ColorSrc.rgb - Color.rgb * ColorSrc.rgb;
    
    //��r(��)
    #if MIX_TYPE==0
        Color = BrightnessCompare(Color, ColorOrg);
    #else
        Color = BrightnessCompare(Color, ColorSrc);
    #endif
    
    //�ȈՐF���␳
    Color.rgb *= (objpos + 1);
    
    //�t�B���^���x�����ɃI���W�i���ƍ���
    Color = lerp(ColorOrg, Color, Strength * alpha1);
    
    return Color;
}

////////////////////////////////////////////////////////////////////////////////////////////////

technique Diffusion <
    string Script = 
        
        "RenderColorTarget0=ScnMap;"
        "RenderDepthStencilTarget=DepthBuffer;"
        "ClearSetColor=ClearColor;"
        "ClearSetDepth=ClearDepth;"
        "Clear=Color;"
        "Clear=Depth;"
        "ScriptExternal=Color;"
        
        "RenderColorTarget0=ScnMap2;"
        "RenderDepthStencilTarget=DepthBuffer;"
        "ClearSetColor=ClearColor;"
        "ClearSetDepth=ClearDepth;"
        "Clear=Color;"
        "Clear=Depth;"
        "Pass=Gaussian_X;"
        
        "RenderColorTarget0=;"
        "RenderDepthStencilTarget=;"
        "ClearSetColor=ClearColor;"
        "ClearSetDepth=ClearDepth;"
        "Clear=Color;"
        "Clear=Depth;"
        "Pass=Gaussian_Y;"
    ;
    
> {
    
    pass Gaussian_X < string Script= "Draw=Buffer;"; > {
        AlphaBlendEnable = FALSE;
        VertexShader = compile vs_3_0 VS_passDraw();
        PixelShader  = compile ps_3_0 PS_passX();
    }
    pass Gaussian_Y < string Script= "Draw=Buffer;"; > {
        AlphaBlendEnable = FALSE;
        VertexShader = compile vs_3_0 VS_passDraw();
        PixelShader  = compile ps_3_0 PS_passY();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
