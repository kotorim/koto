////////////////////////////////////////////////////////////////////////////////////////////////
//
//  dGreenerShader ver.2013.04.16 (�h�D�h�D)
//
//  �x�[�X�FGreenerShader ver1.12 for ExcellentShadow (������P)
//  �x�[�X�̃x�[�X�F  full.fx ver2.0                  (���͉��P)
//                    �ȈՃ\�t�g�V���h�E�G�t�F�N�g    (�r�[���}��P)
//  �h�D�h�D�����ł̒ǉ��@�\�̈��p���F
//                    �ٕ����t�B���^�����O            (Furia��)
//                    ���ʔ���,Full���[�h             (�r�[���}��P)
//                    �����Օ��}�b�s���O              (DirectX�T���v��)
//
////////////////////////////////////////////////////////////////////////////////////////////////
// �p�����[�^�錾

/////////////////////////////
//�ǉ��p�����[�^/////////////
/////////////////////////////
//���C�����C�g�p�����[�^�[
float3 TColorM = {1.00,0.20,0.20};//�g�b�v���C�g�̐F�B//���ׂ�1�Ŕ��B���ׂ�0�ō��B
float3 MColorM = {0.50,0.10,0.10};//�~�h�����C�g�̐F�B//�F�̖��邳�������ɉe������̂Œ��ӁB
float3 UColorM = {0.50,0.10,0.10};//�{�g�����C�g�̐F�B

float LightIntensityM = 1.00;//���C�����C�g�̑S�̂̋����B1�Ō��������B
float TIntensityM = 1.2;//�g�b�v���C�g�̋����B1.0�ŋ����̕ω��Ȃ��B
float MIntensityM = 0.1;//�~�h�����C�g�̋����B1.0�ŋ����̕ω��Ȃ��B
float UIntensityM = 0.0;//�{�g�����C�g�̋����B1.0�ŋ����̕ω��Ȃ��B

/////////////////////////////
//�Ƃ�Ԃ������p�����[�^�[
float3 TColorA = {0.8,0.8,0.8};//�g�b�v���C�g�̐F�B//���ׂ�1�Ŕ��B���ׂ�0�ō��B
float3 MColorA = {0.5,0.5,0.5};//�~�h�����C�g�̐F�B//�F�̖��邳�������ɉe������̂Œ��ӁB
float3 UColorA = {0.4,0.4,0.4};//�{�g�����C�g�̐F�B

float LightIntensityA = 0.1;//�Ƃ�Ԃ������̑S�̂̋����B1�Ō��������B
float TIntensityA = 1.0;//�g�b�v���C�g�̋����B1.0�ŋ����̕ω��Ȃ��B
float MIntensityA = 1.0;//�~�h�����C�g�̋����B1.0�ŋ����̕ω��Ȃ��B
float UIntensityA = 2.0;//�{�g�����C�g�̋����B1.0�ŋ����̕ω��Ȃ��B
float AmbientBalance = 0.3;//���������Z����Z���B�P�ŉ��Z�B�O�ŏ�Z

/////////////////////////////
//�n�C���C�g�p�����[�^�[
int SpecularON = 0;//1�Ō��̃X�y�L�����[���g�p�B0�ŕʌv�Z�̃n�C���C�g���g�p�B
float HilightPower = 0.50;//�n�C���C�g�̋����B
float3 HiColor = {1.0,1.0,1.0};//�n�C���C�g�̐F�B���ׂ�1�Ŕ��B
float HilightGlow = 2;//�n�C���C�g�̍L����B���l���グ��΁A�n�C���C�g�������Ȃ�B��{2�`3���炢�B

/////////////////////////////
//�G�b�W���C�g�p�����[�^�[(�[���o�b�N���C�g)
float3 EColor = {1.0,0.5,0.5};
float LightIntensityE = 0.8;//�G�b�W���C�g�������̂̋���
float AttenuationC = 0.4;//���邢���̃G�b�W���C�g�����B�O�Ō��������B
float AttenuationD = 0.9;//���C�g�̌����ɂ��G�b�W���C�g�̋����B�O�Ō������֌W�Ȃ������ő�

/////////////////////////////
//�e�F�p�����[�^�[
float SColorBlend = 0.5;//�e�F�̃u�����h�䗦�B�ő�P�B0�Ńf�t�H���g�J���[

/////////////////////////////
//�e�p�����[�^�[(�Z���t�V���h�E����)
float ShadowIntensityC = 0.2;//�e�̋����B������ƈÂ��Ȃ�B�Ƃ�Ԃ��������Ȃ��ꍇ�A�O�Ő^���ÁB
float ShadowIntensityE = 0.8;//�e�����̃G�b�W���C�g�����B�f�t�H�P�B������Ǝキ�Ȃ�B

/////////////////////////////
//SSAO�p�����[�^�[
float SSAOPower = 0.8;

/////////////////////////////
//���܂�M��Ȃ����Ă����p�����[�^�[
float SphereMapIn = 1;
float EdgeGlow = 2.5;
/////////////////////////////
//�\�t�g�V���h�E�p�ڂ�����
float SoftShadowParam = 3;
//�V���h�E�}�b�v�T�C�Y
//�ʏ�F1024 CTRL+G�ŉ𑜓x���グ���ꍇ 4096
#define SHADOWMAP_SIZE 4096

// DarkShader�R���̃p�����[�^ ----------------------------------------------------------------------
#define EDGE_ENABLED // �G�b�W��`�悵�Ȃ� (�`�悷��ꍇ�A����//���O��)
#define SHADOW_ENABLED // �e�i��Z���t�V���h�E�j��`�悵�Ȃ� (�`�悷��ꍇ�A����//���O��)
#define CULLING_ENABLED // �������ŃZ���t�V���h�E���ςȎ��ɁA����//��t���ċ����I�ɗ��ʕ`��(�d��)
//#define USE_HDR // �I�[�g���~�i�X�ɔ���������(�����Ȃ��ꍇ�A����//)
//#define USE_DARK // �F�̈��^���Â���o�͂ł���悤�Ɋg�� (���Ȃ��ꍇ�A����//)

// �}�b�s���O�g�p�ݒ� ------------------------------------------------------------------------------

// ����2�e�N�X�`��(�e�N�X�`���̐F��ς���A�y��)
//#define USE_TEX_BLEND // �g��? (�g��Ȃ��ꍇ�A����//)
    #define TEX_BLEND_PATH "TexBlend.png"
    float TexBlendRatio = 1.0; // �F�u�����h�䗦(0:���摜100% �` 1:�u���摜100%)
    float TexBlendRepeat = 1.0; // �u�����h�e�N�X�`���̌J��Ԃ��� ���폜�s��

// ����2�X�t�B�A(���͂̌��̗l�q��ς��ĉA�e�t���A�y��)
//#define IGNORE_SPHERE_1ST // �����̃X�t�B�A�𖳎�����? (���p����ꍇ�A����//)

//#define USE_SPHERE_2ND // �g��? (�g��Ȃ��ꍇ�A����//)
    #define SPHERE_2ND_PATH "_�ʂ邷�ӂ���(�݂݂�����).png"
    #define SPHERE_ADD // �g�p����X�t�B�A�͉��Z�^�C�v? (��Z�^�C�v�̏ꍇ�A����//)    
    float3 AmbientBoost = float3(1.0,1.0,1.0) * 0.9; // �X�t�B�A�ȊO�̖��邳�Ɋ|����{��
    float3 SphereBoost  = float3(1.0,1.0,1.0) * 1.0; // �X�t�B�A�̖��邳�Ɋ|����{��

#define NormalMapRepeat 30.0 // (�@���E�����E�X�y�L����)�}�b�v�̌J��Ԃ��� ���폜�s��

// ���X�y�L�����}�b�v(���˗���ς��ĉA�e�t���A�y��)
//#define USE_SPECULAR_MAP // �g��? (�g��Ȃ��ꍇ�A����//)
    #define SPECULAR_MAP_PATH "SpecularMap.png"

// ���@���}�b�v(�@���̕�����ς��ĉ��ʊ��A�d��)
//#define USE_NORMAL_MAP // �g��? (�g��Ȃ��ꍇ�A����//)
    #define NORMAL_MAP_PATH "_NM_Skin(pmot��).png"
  //#define INVERSE_X // �@���}�b�v�� X�v�f�̕������t�]
  //#define INVERSE_Y // �@���}�b�v�� Y�v�f�̕������t�]
    #define NormalMapSize float2(256, 256) // �m�[�}���}�b�v�̃T�C�Y(�����Օ��}�b�v���g���ꍇ�A�v�w��)
    
// �������}�b�v(�ʒu�����炵�ĉ��ʊ��A�d�� ���@���}�b�v��L���ɂ���K�v����)
//#define USE_HEIGHT_MAP // �g��? (�g��Ȃ��ꍇ�A����//)
    #define HEIGHT_MAP_PATH "HeightMap.png"
  //#define INVERSE_HIGHT // �����}�b�v�̍������t�] (�ʏ�:0��`1��, �t�]:1��`0��)
    #define HEIGHT_MAP_METHOD 2 // 1:�����}�b�v(���d), 2:�����Օ��}�b�v(���d, ���̊���)
    // �����}�b�s���O(PM)�g�p���̐ݒ�
    static float HeightScalePM = 0.03 * sqrt(NormalMapRepeat); // �[��(�����₵������Ɣj�]���܂�)
    // �����Օ��}�b�s���O(POM)�g�p���̐ݒ�
    float       HeightScalePOM = 0.1; // �[��
    #define  POM_SMOOTHING_MIN   10   // ���炩�ɂ��邽�߂̃T���v�����F�ŏ��l(�����₷�ƒ��d���Ȃ�܂�)
    #define  POM_SMOOTHING_MAX   20   //             �V              �F�ő�l(          �V          )
    #define  DISPLAY_SHADOWS          // �\�t�g�V���h�E���g����
    float    SoftShadow        = 0.5; // �\�t�g�V���h�E�̂ڂ�����
    #define  USE_POM_LOD              // LOD(�߂���POM�ŏڍׂɁA�����͖@���}�b�v�őe���`��)���g����
    int      MipLevelSikiiLOD  = 4;   // LOD臒l(MIP���x�������̒l�ȏ�Ȃ�A�ʏ�̖@���}�b�v�ŕ\��)

// �����ʔ���
//#define USE_MIRROR // �g��?
    float MirrorParam = 0.5; // ���˗�(0�`1)
    float ReflectSpecularSikii = 0.1; // �ގ��̃X�y�L�����F���X�y�L�����}�b�v�̐ԗv�f�����̒l�ȏ�Ȃ�
                                      // ���ʔ��˂�����(0.0�`1.0) ��ɔ��˂���������� 0 ���w��

// ���t�����[�h
//#define USE_FULLMODE // �g��? �t�����[�h�̏ڍׂ͐�������
    #define DefSubset "8-13,15-19" // �t�����[�h�̑ΏۂɁu���Ȃ��v�T�u�Z�b�g
                                   // �@���E�����E�X�y�L�����}�b�v�𖳎����܂��B

// �ٕ����t�B���^�����O�^�~�b�v�}�b�v�ݒ� ----------------------------------------------------------

// ���ٕ����t�B���^�����O���g�p���邩
//  0 : �g�p���Ȃ� (��i��, �y��, MMD7.39.�ȑO����)
//  1 : �Ǝ��Ƀ~�b�v�}�b�v���쐬���Ďg�p���� (���`���i��, �d��(�璷�ȏ������K�v), MMD7.39.�ȑO����)
//  2 : MMD�{�̂̃~�b�v�}�b�v�𗘗p���Ďg�p���� (���i��, ����, MMD64bit�Ł^32bit�}���`�R�A�Ō���)
#define ANISOTROPY_TYPE 2

// �ٕ����t�B���^�����O�̃T���v�����O��(1�`16��I���\�A�����قǏd�������i��)
#define MAX_ANISOTROPY 16

// �Ǝ��Ƀ~�b�v�}�b�v���쐬����ꍇ( ANISOTROPY_TYPE 1 )�́A�o�b�t�@�T�C�Y
//  �E���f���ɐ��l�ȏ�̍��𑜓x�ȃe�N�X�`�����g�p����Ă���ꍇ�A���₵�Ă��������B���d���Ȃ�܂�
//  �E�}���`�R�A�łɃo�[�W�����A�b�v�� ANISOTROPY_TYPE 2 ���g���������y���Ȃ�܂��B
#define TEXBUFFWIDTH  512
#define TEXBUFFHEIGHT 512
#define TEXBUFFSIZE { TEXBUFFWIDTH, TEXBUFFHEIGHT }

#include "_dGSCommon.fxsub"
