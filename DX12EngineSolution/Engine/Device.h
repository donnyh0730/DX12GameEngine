#pragma once


// �η� �繫��
class Device
{
public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }

private:
	// COM(Component Object Model)
	// - DX�� ���α׷��� ��� �������� ���� ȣȯ���� �����ϰ� �ϴ� ���
	// ��, GPU�� ��Ȱ�ϰ� ����ϰԲ� ���ִ� �߰� ��ü�� ������Ʈ��� �θ��µ� �װͿ� ���� ������.
	// - COM ��ü(COM �������̽�)�� ���. ���λ����� �츮���� ������
	// - ComPtr ������ ����Ʈ ������ ->����� ���� delete�� �ؾ �������. ���۷���ī��Ʈ �ǰ�����.
	ComPtr<ID3D12Debug>			_debugController;
	ComPtr<IDXGIFactory>		_dxgi; // ȭ�� ���� ��ɵ�
	ComPtr<ID3D12Device>		_device; // ���� ��ü ����
};

