#pragma once

// [유니티짱]과 같이 정점으로 이루어진 물체
class Mesh
{
public:
	void Init(vector<Vertex>& vec);
	void Render();

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {};
	//view란 보는법 즉, 버텍스 버퍼를 보는법을 기술해놓은 구조체이다. 정점하나의 사이즈, 전체버퍼크기를 넣어서 GPU에게 버텍스 버퍼란 이런것이다. 라고 기술 하는 것이다.
	uint32 _vertexCount = 0;
};

