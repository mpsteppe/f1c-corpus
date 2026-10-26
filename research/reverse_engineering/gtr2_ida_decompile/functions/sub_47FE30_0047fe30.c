BOOL sub_47FE30()
{
  HWND DlgItem; // eax
  BOOL v1; // edi
  HWND v2; // eax
  HWND v3; // eax
  CHAR String[32]; // [esp+Ch] [ebp-20h] BYREF

  SendDlgItemMessageA(hWnd, 1200, 0x406u, 1u, (unsigned __int16)dword_B6CEA8 | 0x27100000);
  SendDlgItemMessageA(hWnd, 1200, 0x405u, 1u, lParam);
  String[0] = 0;
  sprintf(String, "%d kbits/s", lParam);
  DlgItem = GetDlgItem(hWnd, 1043);
  SetWindowTextA(DlgItem, String);
  v1 = *(_DWORD *)dword_B6CE7C == 5;
  v2 = GetDlgItem(hWnd, 1200);
  EnableWindow(v2, v1);
  v3 = GetDlgItem(hWnd, 1043);
  return EnableWindow(v3, v1);
}
