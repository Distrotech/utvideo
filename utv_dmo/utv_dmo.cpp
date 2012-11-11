/* �����R�[�h�͂r�i�h�r ���s�R�[�h�͂b�q�k�e */
/* $Id: utv_dmo.cpp 515 2010-05-06 10:11:26Z umezawa $ */

// utv_dmo.cpp : DLL �G�N�X�|�[�g�̎����ł��B


#include "stdafx.h"
#include "resource.h"
#include "utv_dmo.h"


class CUtVideoDMOModule : public CAtlDllModuleT<CUtVideoDMOModule>
{
public :
	DECLARE_LIBID(LIBID_UtVideoDMO)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_UTVIDEODMO, "{E625D10C-D936-4469-9A2D-93F921C29DF9}")
};

CUtVideoDMOModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL �G���g�� �|�C���g
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// DLL �� OLE �ɂ���ăA�����[�h�ł���悤�ɂ��邩�ǂ������w�肵�܂��B
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// �v�����ꂽ�^�̃I�u�W�F�N�g���쐬����N���X �t�@�N�g����Ԃ��܂��B
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - �G���g�����V�X�e�� ���W�X�g���ɒǉ����܂��B
STDAPI DllRegisterServer(void)
{
    // �I�u�W�F�N�g�A�^�C�v ���C�u��������у^�C�v ���C�u�������̂��ׂẴC���^�[�t�F�C�X��o�^���܂�
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - �G���g�������W�X�g������폜���܂��B
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
