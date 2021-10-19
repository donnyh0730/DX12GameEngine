#pragma once

// [계약서 / 결재]

// CPU [        ]    GPU [        ]
// 한국 [        ]   베트남 [       ]
//이 시그니처 라는 객체또한 DX가 어떤식으로 동작할 것이냐에 대한 정보를 담고있다.
//D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
//즉, 인풋어셈블러 와 인풋레이아웃 방식을 허용한다 정도로 이해하면될것이다. 
class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	ComPtr<ID3D12RootSignature>	_signature;
};

