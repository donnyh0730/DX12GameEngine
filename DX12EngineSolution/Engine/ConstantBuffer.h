#pragma once

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	void Init(uint32 size, uint32 count);

	void Clear();

	D3D12_CPU_DESCRIPTOR_HANDLE PushData(int32 rootParamIndex, void* buffer, uint32 size);

	D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);
	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle(uint32 index);

private:
	void CreateBuffer();
	void CreateView();
private:
	ComPtr<ID3D12Resource>	_cbvBuffer; //GRAM��
	BYTE* _mappedBuffer = nullptr; //RAM�� 
	//constan buffer ��, ������۴� ��ĺ�ȯ���̹Ƿ� ��� ������Ʈ�� ����� ������ �� 
	//����ְԵȴ�. ���޽��� �ش��ϴ� ��� Ʈ���� �� ������ �迭�̴�.
	//��ü�ϳ��� �ܽ�źƮ�����ϳ��� ����ִ°� �ƴ϶� �̷��� �ϳ��� ��ü�� ���δ� ��� �ִ´�... 
	uint32					_elementSize = 0;
	uint32					_elementCount = 0;

	ComPtr<ID3D12DescriptorHeap>		_cbvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE			_cpuHandleBegin = {};
	uint32								_handleIncrementSize = 0;

	uint32					_currentIndex = 0;
};

