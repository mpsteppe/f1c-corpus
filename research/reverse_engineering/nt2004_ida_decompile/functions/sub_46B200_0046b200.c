BOOL __thiscall sub_46B200(_DWORD *this)
{
  HWND DlgItem; // eax

  this[105] = 3;
  DlgItem = GetDlgItem(hDlg, 1005);
  return EnableWindow(DlgItem, 0);
}
