#ifndef _ANIMATION_FX_
#define _ANIMATION_FX_

#include "params.fx"
#include "utils.fx"
#include "math.fx"

struct AnimFrameParams
{
    float4 scale;
    float4 rotation;
    float4 translation;
};

StructuredBuffer<AnimFrameParams>   g_bone_frame : register(t8);//ToRoot매트릭스
StructuredBuffer<matrix>            g_offset : register(t9);//Offset매트릭스
RWStructuredBuffer<matrix>          g_final : register(u0);

// ComputeAnimation
// g_int_0 : BoneCount
// g_int_1 : CurrentFrame
// g_int_2 : NextFrame
// g_float_0 : Ratio
[numthreads(256, 1, 1)]
void CS_Main(int3 threadIdx : SV_DispatchThreadID)
{
    if (g_int_0 <= threadIdx.x)
        return;

    int boneCount = g_int_0;
    int currentFrame = g_int_1;
    int nextFrame = g_int_2;
    float ratio = g_float_0;

    uint idx = (boneCount * currentFrame) + threadIdx.x;
    uint nextIdx = (boneCount * nextFrame) + threadIdx.x;

    float4 quaternionZero = float4(0.f, 0.f, 0.f, 1.f);

    //lerp와 QuaternionSlerp는 interpolation을 수행하는 함수인데, 지금 이렇게 하는 이유는
    //데이터상의 현재 키프레임과 다음 키프레임간에 아주 짧은 순간에도
    //real타임에서는 렌더링이되어야 하기때문에, 그부분을 보간해서 채워주고 있는 것이다.

    float4 scale = lerp(g_bone_frame[idx].scale, g_bone_frame[nextIdx].scale, ratio);
    float4 rotation = QuaternionSlerp(g_bone_frame[idx].rotation, g_bone_frame[nextIdx].rotation, ratio);
    float4 translation = lerp(g_bone_frame[idx].translation, g_bone_frame[nextIdx].translation, ratio);

    matrix matBone = MatrixAffineTransformation(scale, quaternionZero, rotation, translation);
    //matBone은 ToRoot변환과 같다. 즉 월드를 기준으로 SRT를 적용하는 것이기 때문에,
    g_final[threadIdx.x] = mul(g_offset[threadIdx.x], matBone);//== OffsetMatrix * ToRootMatrix
}

#endif