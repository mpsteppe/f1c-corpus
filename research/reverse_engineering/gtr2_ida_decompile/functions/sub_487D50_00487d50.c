DWORD __stdcall sub_487D50()
{
  HINSTANCE v0; // edi
  HWND DesktopWindow; // eax
  HWND DialogParamA; // eax
  HINSTANCE v3; // ebx
  HWND v4; // eax
  HWND v5; // eax
  HINSTANCE v6; // ebx
  HWND v7; // eax
  HWND v8; // eax
  HINSTANCE v9; // ebx
  HWND v10; // eax
  HWND v11; // eax
  HINSTANCE v12; // ebx
  HWND v13; // eax
  DWORD v14; // eax
  _DWORD *v15; // eax
  int i; // eax
  DWORD v17; // eax
  _DWORD *v18; // eax
  struct tagMSG Msg; // [esp+0h] [ebp-1Ch] BYREF

  v0 = dword_B6F1AC;
  DesktopWindow = GetDesktopWindow();
  DialogParamA = CreateDialogParamA(v0, (LPCSTR)0x6C, DesktopWindow, (DLGPROC)&dword_4877A8[2], 0);
  v3 = dword_B6F1AC;
  dword_B6CE6C = DialogParamA;
  v4 = GetDesktopWindow();
  v5 = CreateDialogParamA(v3, (LPCSTR)0x66, v4, sub_484DD0, 0);
  v6 = dword_B6F1AC;
  hDlg = v5;
  v7 = GetDesktopWindow();
  v8 = CreateDialogParamA(v6, (LPCSTR)0x67, v7, (DLGPROC)sub_4851B0, 0);
  v9 = dword_B6F1AC;
  hWnd = v8;
  v10 = GetDesktopWindow();
  v11 = CreateDialogParamA(v9, (LPCSTR)0x68, v10, (DLGPROC)sub_485F30, 0);
  v12 = dword_B6F1AC;
  dword_B6CE78 = v11;
  v13 = GetDesktopWindow();
  dword_B6CE68 = CreateDialogParamA(v12, (LPCSTR)0x6A, v13, sub_47F820, 0);
  if ( hMutex && ((v14 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v14 == 128) )
    v15 = &unk_759EA8;
  else
    v15 = 0;
  *v15 = 1;
  if ( hMutex )
    ReleaseMutex(hMutex);
  for ( i = GetMessageA(&Msg, 0, 0, 0); i; i = GetMessageA(&Msg, 0, 0, 0) )
  {
    if ( i == -1 )
      break;
    if ( !IsDialogMessageA(hDlg, &Msg)
      && !IsDialogMessageA(hWnd, &Msg)
      && !IsDialogMessageA(dword_B6CE78, &Msg)
      && !IsDialogMessageA(dword_B6CE68, &Msg) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
  }
  ShowWindow(hDlg, 0);
  ShowWindow(hWnd, 0);
  ShowWindow(dword_B6CE78, 0);
  ShowWindow(dword_B6CE68, 0);
  DestroyWindow(hDlg);
  DestroyWindow(hWnd);
  DestroyWindow(dword_B6CE78);
  DestroyWindow(dword_B6CE68);
  if ( hMutex && ((v17 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v17 == 128) )
    v18 = &unk_759EA8;
  else
    v18 = 0;
  *v18 = 4;
  if ( hMutex )
    ReleaseMutex(hMutex);
  return 0;
}
