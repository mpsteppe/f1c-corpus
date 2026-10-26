BOOL sub_46B970()
{
  HWND DlgItem; // eax
  BOOL v1; // edi
  HWND v2; // eax
  HWND v3; // eax
  CHAR String[32]; // [esp+Ch] [ebp-20h] BYREF

  SendDlgItemMessageA(hWnd, 1200, 0x406u, 1u, (unsigned __int16)dword_764ECC | 0x27100000);
  SendDlgItemMessageA(hWnd, 1200, 0x405u, 1u, dword_764ED8);
  String[0] = 0;
  sprintf(String, "%d kbits/s", dword_764ED8);
  DlgItem = GetDlgItem(hWnd, 1043);
  SetWindowTextA(DlgItem, String);
  v1 = dword_7652C4 == 5;
  v2 = GetDlgItem(hWnd, 1200);
  EnableWindow(v2, v1);
  v3 = GetDlgItem(hWnd, 1043);
  return EnableWindow(v3, v1);
}
