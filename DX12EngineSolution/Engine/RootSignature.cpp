#include "pch.h"
#include "RootSignature.h"

void RootSignature::Init(ComPtr<ID3D12Device> device)
{
	CD3DX12_ROOT_PARAMETER param[2];
	param[0].InitAsConstantBufferView(0); // 0번 -> b0 -> CBV b1번 레지스터를 에약 사용하겠다.
	param[1].InitAsConstantBufferView(1); // 1번 -> b1 -> CBV b0번 레지스터를 예약 사용하겠다.
	//앞으로 렌더링에 사용하게될 각종 버퍼들이나 쉐이더들은 위의 레지스터에 기록되고 사용되어질 것이다.
	//레지스터의 크기는 작기때문에 실제로 레지스터에 버퍼가들어가는 것이아니라 버퍼를 가리키는 포인터가 들어가게됨.
	D3D12_ROOT_SIGNATURE_DESC sigDesc = CD3DX12_ROOT_SIGNATURE_DESC(2, param);

	sigDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT; // 입력 조립기 단계

	ComPtr<ID3DBlob> blobSignature;
	ComPtr<ID3DBlob> blobError;
	::D3D12SerializeRootSignature(&sigDesc, D3D_ROOT_SIGNATURE_VERSION_1, &blobSignature, &blobError);
	device->CreateRootSignature(0, blobSignature->GetBufferPointer(), blobSignature->GetBufferSize(), IID_PPV_ARGS(&_signature));
}