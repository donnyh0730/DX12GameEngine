#include "pch.h"
#include "Mesh.h"
#include "Engine.h"

void Mesh::Init(vector<Vertex>& vec)
{
	_vertexCount = static_cast<uint32>(vec.size());
	uint32 bufferSize = _vertexCount * sizeof(Vertex);

	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	DEVICE->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_vertexBuffer));

	// Copy the triangle data to the vertex buffer.
	void* vertexDataBuffer = nullptr;//CPU�޸��� ���ؽ� �����Ͱ���.
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_vertexBuffer->Map(0, &readRange, &vertexDataBuffer);//CPU�޸� ������ GPU�޸𸮿����� ������.
	::memcpy(vertexDataBuffer, &vec[0], bufferSize);//���ø޸𸮿��ִ� ���ؽ����۸� CPU�޸𸮿� �����ص�.
	//�̷��� �ڿ������� GPU�޸𸮷� ���ؽ����۰� �����.
	_vertexBuffer->Unmap(0, nullptr);//���� �Ϸ�Ǿ����Ƿ� ������ ����

	// Initialize the vertex buffer view.
	_vertexBufferView.BufferLocation = _vertexBuffer->GetGPUVirtualAddress();
	_vertexBufferView.StrideInBytes = sizeof(Vertex); // ���� 1�� ũ��
	_vertexBufferView.SizeInBytes = bufferSize; // ������ ũ��	
}

void Mesh::Render()
{
	CMD_LIST->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);//���ؽ��� �ﰢ�� �������� Ÿ������ ����.
	CMD_LIST->IASetVertexBuffers(0, 1, &_vertexBufferView); // Slot: (0~15)
	
	GEngine->GetCB()->PushData(0, &_transform, sizeof(_transform));
	GEngine->GetCB()->PushData(1, &_transform, sizeof(_transform));

	CMD_LIST->DrawInstanced(_vertexCount, 1, 0, 0);
}