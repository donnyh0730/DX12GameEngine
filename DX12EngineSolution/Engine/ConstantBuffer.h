#pragma once

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	void Init(uint32 size, uint32 count);

	void Clear();
	void PushData(int32 rootParamIndex, void* buffer, uint32 size);

	D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);

private:
	void CreateBuffer();

private:
	ComPtr<ID3D12Resource>	_cbvBuffer; //GRAM용
	BYTE* _mappedBuffer = nullptr; //RAM용 
	//constan buffer 즉, 상수버퍼는 행렬변환용이므로 모든 오브젝트에 적용될 값들이 다 
	//들어있게된다. 각메쉬에 해당하는 모든 트랜스 폼 값들의 배열이다.
	//물체하나당 콘스탄트버퍼하나를 들고있는게 아니라 이렇게 하나의 객체가 전부다 들고 있는다... 
	uint32					_elementSize = 0;
	uint32					_elementCount = 0;

	uint32					_currentIndex = 0;
};

