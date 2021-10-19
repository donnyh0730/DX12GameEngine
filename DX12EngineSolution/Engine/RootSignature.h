#pragma once

// [��༭ / ����]

// CPU [        ]    GPU [        ]
// �ѱ� [        ]   ��Ʈ�� [       ]
//�� �ñ״�ó ��� ��ü���� DX�� ������� ������ ���̳Ŀ� ���� ������ ����ִ�.
//D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
//��, ��ǲ����� �� ��ǲ���̾ƿ� ����� ����Ѵ� ������ �����ϸ�ɰ��̴�. 
class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	ComPtr<ID3D12RootSignature>	_signature;
};

