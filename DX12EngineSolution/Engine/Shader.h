#pragma once

// [일감 기술서] 외주 인력들이 뭘 해야할지 기술
class Shader
{
public:
	void Init(const wstring& path);
	void Update();

private:
	void CreateShader(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob, D3D12_SHADER_BYTECODE& shaderByteCode);
	void CreateVertexShader(const wstring& path, const string& name, const string& version);
	void CreatePixelShader(const wstring& path, const string& name, const string& version);

private:
	ComPtr<ID3DBlob>					_vsBlob;
	ComPtr<ID3DBlob>					_psBlob;
	ComPtr<ID3DBlob>					_errBlob;

	ComPtr<ID3D12PipelineState>			_pipelineState;
	//메쉬를 렌더링 하기위해 들고있는 버텍스쉐이더나 픽셀쉐이더 정보
	D3D12_GRAPHICS_PIPELINE_STATE_DESC  _pipelineDesc = {};
};

