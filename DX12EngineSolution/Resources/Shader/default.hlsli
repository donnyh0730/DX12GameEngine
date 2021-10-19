

struct VS_IN
{
    float3 pos : POSITION;//엘레엔트 디스크립션에서 넣어준 형식을 적용.
    float4 color : COLOR;
};

struct VS_OUT
{
    float4 pos : SV_Position;//이값은 포지션 용도로 사용할 것이다.
    float4 color : COLOR;//이값은 컬러값 용도로 사용할 것이다.
};

VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT)0;

    output.pos = float4(input.pos, 1.f);
    output.color = input.color;

    return output;
}

//픽셀쉐이더코드가 되는 부분, 아무것도 안하고 그냥 받은 정점 컬러값을 그대로 내보낸다.
float4 PS_Main(VS_OUT input) : SV_Target                                     
{
    return input.color;
}