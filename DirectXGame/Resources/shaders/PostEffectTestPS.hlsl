#include "PostEffectTest.hlsli"

Texture2D<float4> tex : register(t0);  // 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0);      // 0番スロットに設定されたサンプラー

float4 main(VSOutput input) : SV_TARGET
{
	//テクスチャのサイズを指定
    int uWidth = 512;  // テクスチャの幅
    int vHeight = 512; // テクスチャの高さ

    // サンプリング範囲の設定
    float2 texelSize = float2(1.0 / uWidth, 1.0 / vHeight);

    // カーネルサイズ
    int kernelSize = 3;

    // ピクセルの初期値を設定
    float3 color = float3(0, 0, 0);

    // サンプリング範囲内のピクセルを合計
    for (int x = -kernelSize; x <= kernelSize; x++)
    {
        for (int y = -kernelSize; y <= kernelSize; y++)
        {
            float2 offset = float2(x, y) * texelSize;
            color += tex.Sample(smp, input.uv + offset).rgb;
        }
    }

    // ピクセル数で割って平均化
    color /= (kernelSize * 2 + 1) * (kernelSize * 2 + 1);

    return float4(color, 1);
}

//明度を変更(明度を2倍)
//return float4(texcolor.rgb * 2.0f, 1);

//色反転
//return float4(1.0f - texcolor.rgb, 1);

//UVずらし(0.0f～1.0fの間)
//float4 texcolor = tex.Sample(smp, input.uv + float2(0.2f,0.0f));

//平均ぼかし
//テクスチャのサイズを指定
//int uWidth = 512;  // テクスチャの幅
//int vHeight = 512; // テクスチャの高さ
//
//// サンプリング範囲の設定
//float2 texelSize = float2(1.0 / uWidth, 1.0 / vHeight);
//
//// カーネルサイズ
//int kernelSize = 3;
//
//// ピクセルの初期値を設定
//float3 color = float3(0, 0, 0);
//
//// サンプリング範囲内のピクセルを合計
//for (int x = -kernelSize; x <= kernelSize; x++)
//{
//    for (int y = -kernelSize; y <= kernelSize; y++)
//    {
//        float2 offset = float2(x, y) * texelSize;
//        color += tex.Sample(smp, input.uv + offset).rgb;
//    }
//}
//
//// ピクセル数で割って平均化
//color /= (kernelSize * 2 + 1) * (kernelSize * 2 + 1);
//
//return float4(color, 1);