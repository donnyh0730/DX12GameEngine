

struct VS_IN
{
    float3 pos : POSITION;//������Ʈ ��ũ���ǿ��� �־��� ������ ����.
    float4 color : COLOR;
};

struct VS_OUT
{
    float4 pos : SV_Position;//�̰��� ������ �뵵�� ����� ���̴�.
    float4 color : COLOR;//�̰��� �÷��� �뵵�� ����� ���̴�.
};

VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT)0;

    output.pos = float4(input.pos, 1.f);
    output.color = input.color;

    return output;
}

//�ȼ����̴��ڵ尡 �Ǵ� �κ�, �ƹ��͵� ���ϰ� �׳� ���� ���� �÷����� �״�� ��������.
float4 PS_Main(VS_OUT input) : SV_Target                                     
{
    return input.color;
}