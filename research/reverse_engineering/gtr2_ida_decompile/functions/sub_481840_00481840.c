BOOL sub_481840()
{
  HWND DlgItem; // eax
  HWND v1; // eax
  CHAR String[72]; // [esp+10h] [ebp-A0h] BYREF
  _BYTE v4[8]; // [esp+58h] [ebp-58h] BYREF
  CHAR v5[80]; // [esp+60h] [ebp-50h] BYREF

  String[0] = 0;
  v5[0] = 0;
  sub_53A390(&unk_BE1CFD);
  ((void (__thiscall *)(void *, _BYTE *, int, CHAR *, int))dword_53A310)(&unk_BE1CFD, v4, 79, String, 79);
  DlgItem = GetDlgItem(hDlg, 1186);
  SetWindowTextA(DlgItem, String);
  v1 = GetDlgItem(hDlg, 1187);
  return SetWindowTextA(v1, v5);
}
