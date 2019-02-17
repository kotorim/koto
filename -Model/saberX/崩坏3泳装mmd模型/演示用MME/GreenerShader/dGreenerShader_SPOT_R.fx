////////////////////////////////////////////////////////////////////////////////////////////////
//
//  dGreenerShader ver.2013.04.16 (ドゥドゥ)
//
//  ベース：GreenerShader ver1.12 for ExcellentShadow (下っ腹P)
//  ベースのベース：  full.fx ver2.0                  (舞力介入P)
//                    簡易ソフトシャドウエフェクト    (ビームマンP)
//  ドゥドゥ改造での追加機能の引用元：
//                    異方向フィルタリング            (Furia氏)
//                    鏡面反射,Fullモード             (ビームマンP)
//                    視差遮蔽マッピング              (DirectXサンプル)
//
////////////////////////////////////////////////////////////////////////////////////////////////
// パラメータ宣言

/////////////////////////////
//追加パラメータ/////////////
/////////////////////////////
//メインライトパラメーター
float3 TColorM = {1.00,0.20,0.20};//トップライトの色。//すべて1で白。すべて0で黒。
float3 MColorM = {0.50,0.10,0.10};//ミドルライトの色。//色の明るさが強さに影響するので注意。
float3 UColorM = {0.50,0.10,0.10};//ボトムライトの色。

float LightIntensityM = 1.00;//メインライトの全体の強さ。1で減少無し。
float TIntensityM = 1.2;//トップライトの強さ。1.0で強さの変化なし。
float MIntensityM = 0.1;//ミドルライトの強さ。1.0で強さの変化なし。
float UIntensityM = 0.0;//ボトムライトの強さ。1.0で強さの変化なし。

/////////////////////////////
//照り返し環境光パラメーター
float3 TColorA = {0.8,0.8,0.8};//トップライトの色。//すべて1で白。すべて0で黒。
float3 MColorA = {0.5,0.5,0.5};//ミドルライトの色。//色の明るさが強さに影響するので注意。
float3 UColorA = {0.4,0.4,0.4};//ボトムライトの色。

float LightIntensityA = 0.1;//照り返し環境光の全体の強さ。1で減少無し。
float TIntensityA = 1.0;//トップライトの強さ。1.0で強さの変化なし。
float MIntensityA = 1.0;//ミドルライトの強さ。1.0で強さの変化なし。
float UIntensityA = 2.0;//ボトムライトの強さ。1.0で強さの変化なし。
float AmbientBalance = 0.3;//環境光を加算か乗算か。１で加算。０で乗算

/////////////////////////////
//ハイライトパラメーター
int SpecularON = 0;//1で元のスペキュラーを使用。0で別計算のハイライトを使用。
float HilightPower = 0.50;//ハイライトの強さ。
float3 HiColor = {1.0,1.0,1.0};//ハイライトの色。すべて1で白。
float HilightGlow = 2;//ハイライトの広がり。数値を上げれば、ハイライトが狭くなる。基本2～3ぐらい。

/////////////////////////////
//エッジライトパラメーター(擬似バックライト)
float3 EColor = {1.0,0.5,0.5};
float LightIntensityE = 0.8;//エッジライト強さ自体の強さ
float AttenuationC = 0.4;//明るい所のエッジライト減少。０で減少無し。
float AttenuationD = 0.9;//ライトの向きによるエッジライトの強さ。０で向きを関係なく強さ最大

/////////////////////////////
//影色パラメーター
float SColorBlend = 0.5;//影色のブレンド比率。最大１。0でデフォルトカラー

/////////////////////////////
//影パラメーター(セルフシャドウ部分)
float ShadowIntensityC = 0.2;//影の強さ。下げると暗くなる。照り返し環境光がない場合、０で真っ暗。
float ShadowIntensityE = 0.8;//影部分のエッジライト強さ。デフォ１。下げると弱くなる。

/////////////////////////////
//SSAOパラメーター
float SSAOPower = 0.8;

/////////////////////////////
//あまり弄らないくていいパラメーター
float SphereMapIn = 1;
float EdgeGlow = 2.5;
/////////////////////////////
//ソフトシャドウ用ぼかし率
float SoftShadowParam = 3;
//シャドウマップサイズ
//通常：1024 CTRL+Gで解像度を上げた場合 4096
#define SHADOWMAP_SIZE 4096

// DarkShader由来のパラメータ ----------------------------------------------------------------------
#define EDGE_ENABLED // エッジを描画しない (描画する場合、左の//を外す)
#define SHADOW_ENABLED // 影（非セルフシャドウ）を描画しない (描画する場合、左の//を外す)
#define CULLING_ENABLED // 屋内等でセルフシャドウが変な時に、左に//を付けて強制的に両面描画(重い)
//#define USE_HDR // オートルミナスに反応させる(させない場合、左に//)
//#define USE_DARK // 色領域を真っ暗から出力できるように拡張 (しない場合、左に//)

// マッピング使用設定 ------------------------------------------------------------------------------

// ●第2テクスチャ(テクスチャの色を変える、軽い)
//#define USE_TEX_BLEND // 使う? (使わない場合、左に//)
    #define TEX_BLEND_PATH "TexBlend.png"
    float TexBlendRatio = 1.0; // 色ブレンド比率(0:元画像100% ～ 1:置換画像100%)
    float TexBlendRepeat = 1.0; // ブレンドテクスチャの繰り返し数 ※削除不可

// ●第2スフィア(周囲の光の様子を変えて陰影付け、軽い)
//#define IGNORE_SPHERE_1ST // 既存のスフィアを無視する? (併用する場合、左に//)

//#define USE_SPHERE_2ND // 使う? (使わない場合、左に//)
    #define SPHERE_2ND_PATH "_ぬるすふぃあ(みみずく氏).png"
    #define SPHERE_ADD // 使用するスフィアは加算タイプ? (乗算タイプの場合、左に//)    
    float3 AmbientBoost = float3(1.0,1.0,1.0) * 0.9; // スフィア以外の明るさに掛ける倍率
    float3 SphereBoost  = float3(1.0,1.0,1.0) * 1.0; // スフィアの明るさに掛ける倍率

#define NormalMapRepeat 30.0 // (法線・高さ・スペキュラ)マップの繰り返し数 ※削除不可

// ●スペキュラマップ(反射率を変えて陰影付け、軽い)
//#define USE_SPECULAR_MAP // 使う? (使わない場合、左に//)
    #define SPECULAR_MAP_PATH "SpecularMap.png"

// ●法線マップ(法線の方向を変えて凹凸感、重い)
//#define USE_NORMAL_MAP // 使う? (使わない場合、左に//)
    #define NORMAL_MAP_PATH "_NM_Skin(pmot氏).png"
  //#define INVERSE_X // 法線マップの X要素の方向を逆転
  //#define INVERSE_Y // 法線マップの Y要素の方向を逆転
    #define NormalMapSize float2(256, 256) // ノーマルマップのサイズ(視差遮蔽マップを使う場合、要指定)
    
// ●視差マップ(位置をずらして凹凸感、重い ※法線マップを有効にする必要あり)
//#define USE_HEIGHT_MAP // 使う? (使わない場合、左に//)
    #define HEIGHT_MAP_PATH "HeightMap.png"
  //#define INVERSE_HIGHT // 高さマップの高さを逆転 (通常:0低～1高, 逆転:1低～0高)
    #define HEIGHT_MAP_METHOD 2 // 1:視差マップ(少重), 2:視差遮蔽マップ(激重, 立体感高)
    // 視差マッピング(PM)使用時の設定
    static float HeightScalePM = 0.03 * sqrt(NormalMapRepeat); // 深さ(※増やしすぎると破綻します)
    // 視差遮蔽マッピング(POM)使用時の設定
    float       HeightScalePOM = 0.1; // 深さ
    #define  POM_SMOOTHING_MIN   10   // 滑らかにするためのサンプル数：最小値(※増やすと超重くなります)
    #define  POM_SMOOTHING_MAX   20   //             〃              ：最大値(          〃          )
    #define  DISPLAY_SHADOWS          // ソフトシャドウを使うか
    float    SoftShadow        = 0.5; // ソフトシャドウのぼかし率
    #define  USE_POM_LOD              // LOD(近くはPOMで詳細に、遠くは法線マップで粗く描画)を使うか
    int      MipLevelSikiiLOD  = 4;   // LOD閾値(MIPレベルがこの値以上なら、通常の法線マップで表示)

// ●鏡面反射
//#define USE_MIRROR // 使う?
    float MirrorParam = 0.5; // 反射率(0～1)
    float ReflectSpecularSikii = 0.1; // 材質のスペキュラ色かスペキュラマップの赤要素がこの値以上なら
                                      // 鏡面反射させる(0.0～1.0) 常に反射させたければ 0 を指定

// ●フルモード
//#define USE_FULLMODE // 使う? フルモードの詳細は説明書で
    #define DefSubset "8-13,15-19" // フルモードの対象に「しない」サブセット
                                   // 法線・視差・スペキュラマップを無視します。

// 異方向フィルタリング／ミップマップ設定 ----------------------------------------------------------

// ●異方向フィルタリングを使用するか
//  0 : 使用しない (低品質, 軽い, MMD7.39.以前向け)
//  1 : 独自にミップマップを作成して使用する (中～高品質, 重い(冗長な処理が必要), MMD7.39.以前向け)
//  2 : MMD本体のミップマップを利用して使用する (高品質, 普通, MMD64bit版／32bitマルチコア版向け)
#define ANISOTROPY_TYPE 2

// 異方向フィルタリングのサンプリング数(1～16を選択可能、多いほど重いが高品質)
#define MAX_ANISOTROPY 16

// 独自にミップマップを作成する場合( ANISOTROPY_TYPE 1 )の、バッファサイズ
//  ・モデルに数値以上の高解像度なテクスチャが使用されている場合、増やしてください。※重くなります
//  ・マルチコア版にバージョンアップし ANISOTROPY_TYPE 2 を使った方が軽くなります。
#define TEXBUFFWIDTH  512
#define TEXBUFFHEIGHT 512
#define TEXBUFFSIZE { TEXBUFFWIDTH, TEXBUFFHEIGHT }

#include "_dGSCommon.fxsub"
