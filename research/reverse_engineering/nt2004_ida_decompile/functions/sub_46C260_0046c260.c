BOOL sub_46C260()
{
  HWND DlgItem; // eax
  HWND v1; // eax
  CHAR String[80]; // [esp+8h] [ebp-A0h] BYREF
  CHAR v4[80]; // [esp+58h] [ebp-50h] BYREF

  String[0] = 0;
  v4[0] = 0;
  sub_4E8F80(String, 79);
  sub_4E8F40(v4, 79);
  DlgItem = GetDlgItem(hDlg, 1186);
  SetWindowTextA(DlgItem, String);
  v1 = GetDlgItem(hDlg, 1187);
  return SetWindowTextA(v1, v4);
}
