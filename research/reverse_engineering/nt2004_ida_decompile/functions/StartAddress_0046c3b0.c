DWORD __stdcall StartAddress()
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
  DWORD v11; // eax
  _DWORD *v12; // eax
  int i; // eax
  DWORD v14; // eax
  _DWORD *v15; // eax
  tagMSG Msg; // [esp+0h] [ebp-1Ch] BYREF

  v0 = hinst;
  DesktopWindow = GetDesktopWindow();
  DialogParamA = CreateDialogParamA(v0, (LPCSTR)0x66, DesktopWindow, DialogFunc, 0);
  v3 = hinst;
  hDlg = DialogParamA;
  v4 = GetDesktopWindow();
  v5 = CreateDialogParamA(v3, (LPCSTR)0x67, v4, (DLGPROC)sub_466E60, 0);
  v6 = hinst;
  hWnd = v5;
  v7 = GetDesktopWindow();
  v8 = CreateDialogParamA(v6, (LPCSTR)0x68, v7, (DLGPROC)sub_467380, 0);
  v9 = hinst;
  dword_7652C0 = v8;
  v10 = GetDesktopWindow();
  dword_7652B4 = CreateDialogParamA(v9, (LPCSTR)0x6A, v10, sub_466B10, 0);
  if ( hMutex && ((v11 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v11 == 128) )
    v12 = &unk_764EDC;
  else
    v12 = 0;
  *v12 = 1;
  if ( hMutex )
    ReleaseMutex(hMutex);
  for ( i = GetMessageA(&Msg, 0, 0, 0); i; i = GetMessageA(&Msg, 0, 0, 0) )
  {
    if ( i == -1 )
      break;
    if ( !IsDialogMessageA(hDlg, &Msg)
      && !IsDialogMessageA(hWnd, &Msg)
      && !IsDialogMessageA(dword_7652C0, &Msg)
      && !IsDialogMessageA(dword_7652B4, &Msg) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
  }
  ShowWindow(hDlg, 0);
  ShowWindow(hWnd, 0);
  ShowWindow(dword_7652C0, 0);
  ShowWindow(dword_7652B4, 0);
  DestroyWindow(hDlg);
  DestroyWindow(hWnd);
  DestroyWindow(dword_7652C0);
  DestroyWindow(dword_7652B4);
  if ( hMutex && ((v14 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v14 == 128) )
    v15 = &unk_764EDC;
  else
    v15 = 0;
  *v15 = 4;
  if ( hMutex )
    ReleaseMutex(hMutex);
  return 0;
}
