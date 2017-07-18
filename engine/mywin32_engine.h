#pragma once

namespace mywin32_engine {

	namespace util 
	{
		// , 로 구분된 문자열을 실수형 배열을 만든다. 반환값은 생성된 실수의 갯수
		int Buffer2DoubleArray(TCHAR *szBuf, double *pResult) 
		{
			int nCount = 0;

			TCHAR *pwc;
			pwc = wcstok(szBuf, L", #");
			pResult[nCount++] += _wtof(pwc);

			while (pwc != NULL) {
				pwc = wcstok(NULL, L", #");
				if (pwc != NULL) {
					//nSum += _wtoi(pwc);
					pResult[nCount++] = _wtof(pwc);
				}
			}

			return nCount;
		}
		void OutputDebugformat(TCHAR *fmt, ...) {
			TCHAR szBuf[256];
			va_list ap;
			va_start(ap, fmt);
			vswprintf_s(szBuf, 256, fmt, ap);
			//g_nMsgLogTailIndex++;
			//OutputDebug(szBuf);
			OutputDebugString(szBuf);

			va_end(ap);
		}

	}

	HWND makeTextBox(HWND hWnd, int nPosX, int nPosY, int nWidth, int nHeight, int nHandle)
	{

		return CreateWindow(L"static", L"", WS_CHILD | WS_VISIBLE | WS_BORDER,
			nPosX, nPosY, nWidth, nHeight,
			hWnd,
			(HMENU)nHandle, hInst, NULL);
	}


	void makeMiniEdit(HWND hWnd, int nPosX, int nPosY,  int nHandle)
	{
		CreateWindow(L"edit", NULL, 
			WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL,
			nPosX, nPosY, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}

	void makeEditBox(HWND hWnd, int nPosX, int nPosY, int nWidth, int nHandle)
	{
		CreateWindow(L"edit", NULL,
			WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL,
			nPosX, nPosY, nWidth, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}


	void makeMiniButton(HWND hWnd, TCHAR *pszText, int nPosX, int nPosY, int nHandle)
	{
		CreateWindow(L"button", pszText, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			nPosX, nPosY, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}

	double GetControlValueDouble(HWND hWnd, int nId)
	{
		TCHAR szBuf[256];
		GetWindowText(GetDlgItem(hWnd, nId), szBuf, 256);
		return _wtof(szBuf);
	}

	int GetControlValueInt(HWND hWnd, int nid) {
		TCHAR szBuf[256];
		GetWindowText(GetDlgItem(hWnd, nid), szBuf, 256);
		return _wtoi(szBuf);
	}
	void SetControlValueInt(HWND hWnd, int nid, int nValue) {
		TCHAR szBuf[256];
		swprintf_s(szBuf, 256, L"%d", nValue);
		SetWindowText(GetDlgItem(hWnd, nid), szBuf);
	}
}