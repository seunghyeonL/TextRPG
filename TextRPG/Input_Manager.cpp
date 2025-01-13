#include "Input_Manager.h"

LPDIRECTINPUT8 g_pDirectInput = nullptr;
LPDIRECTINPUTDEVICE8 g_pKeyboard = nullptr;

Input_Manager::Input_Manager() {
    memset(m_byKeyState, 0, sizeof(m_byKeyState));
    memset(m_byPrevKeyState, 0, sizeof(m_byPrevKeyState));
    memset(m_bKeyState, false, sizeof(m_bKeyState));
}

Input_Manager* Input_Manager::Create(HINSTANCE hInst, HWND hWnd) {
    auto* pInstance = new Input_Manager();

    // DirectInput �ʱ�ȭ
    if (FAILED(DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pDirectInput, nullptr))) {
        delete pInstance;
        return nullptr;
    }

    // Ű���� ��ġ ����
    if (FAILED(g_pDirectInput->CreateDevice(GUID_SysKeyboard, &g_pKeyboard, nullptr))) {
        g_pDirectInput->Release();
        delete pInstance;
        return nullptr;
    }

    // Ű���� ��ġ ������ ���� ����
    if (FAILED(g_pKeyboard->SetDataFormat(&c_dfDIKeyboard))) {
        g_pKeyboard->Release();
        g_pDirectInput->Release();
        delete pInstance;
        return nullptr;
    }

    // ���� ���� ����
    if (FAILED(g_pKeyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))) {
        g_pKeyboard->Release();
        g_pDirectInput->Release();
        delete pInstance;
        return nullptr;
    }

    // Ű���� ��ġ Ȱ��ȭ
    g_pKeyboard->Acquire();

    return pInstance;
}

void Input_Manager::Update() {
    // ���� Ű ���¸� ����
    memcpy(m_byPrevKeyState, m_byKeyState, sizeof(m_byKeyState));

    // ���� Ű ���¸� ����
    HRESULT hr = g_pKeyboard->GetDeviceState(sizeof(m_byKeyState), (LPVOID)m_byKeyState);
    if (FAILED(hr)) {
        // ��ġ�� ��Ŀ���� �Ҿ����� �ٽ� ȹ��
        if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) {
            g_pKeyboard->Acquire();
        }
    }

    // Key ���� ������Ʈ
    for (int i = 0; i < 256; ++i) {
        m_bKeyState[i] = (m_byKeyState[i] & 0x80) != 0;
    }
}

bool Input_Manager::Key_Pressing(unsigned int _iKey) {
    return (m_bKeyState[_iKey]);
}

bool Input_Manager::Key_Down(unsigned int _iKey) {
    return (m_bKeyState[_iKey] && !(m_byPrevKeyState[_iKey] & 0x80));
}

bool Input_Manager::Key_Up(unsigned int _iKey) {
    return (!m_bKeyState[_iKey] && (m_byPrevKeyState[_iKey] & 0x80));
}

void Input_Manager::Free() {
    if (g_pKeyboard) {
        g_pKeyboard->Unacquire();
        g_pKeyboard->Release();
        g_pKeyboard = nullptr;
    }

    if (g_pDirectInput) {
        g_pDirectInput->Release();
        g_pDirectInput = nullptr;
    }

    delete this;
}
