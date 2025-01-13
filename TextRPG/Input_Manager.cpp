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

    // DirectInput 초기화
    if (FAILED(DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pDirectInput, nullptr))) {
        delete pInstance;
        return nullptr;
    }

    // 키보드 장치 생성
    if (FAILED(g_pDirectInput->CreateDevice(GUID_SysKeyboard, &g_pKeyboard, nullptr))) {
        g_pDirectInput->Release();
        delete pInstance;
        return nullptr;
    }

    // 키보드 장치 데이터 형식 설정
    if (FAILED(g_pKeyboard->SetDataFormat(&c_dfDIKeyboard))) {
        g_pKeyboard->Release();
        g_pDirectInput->Release();
        delete pInstance;
        return nullptr;
    }

    // 협조 수준 설정
    if (FAILED(g_pKeyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))) {
        g_pKeyboard->Release();
        g_pDirectInput->Release();
        delete pInstance;
        return nullptr;
    }

    // 키보드 장치 활성화
    g_pKeyboard->Acquire();

    return pInstance;
}

void Input_Manager::Update() {
    // 이전 키 상태를 저장
    memcpy(m_byPrevKeyState, m_byKeyState, sizeof(m_byKeyState));

    // 현재 키 상태를 얻음
    HRESULT hr = g_pKeyboard->GetDeviceState(sizeof(m_byKeyState), (LPVOID)m_byKeyState);
    if (FAILED(hr)) {
        // 장치가 포커스를 잃었으면 다시 획득
        if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) {
            g_pKeyboard->Acquire();
        }
    }

    // Key 상태 업데이트
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
