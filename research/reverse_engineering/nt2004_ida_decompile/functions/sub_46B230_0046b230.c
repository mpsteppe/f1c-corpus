BOOL __thiscall sub_46B230(_DWORD *this)
{
  HWND DlgItem; // eax

  this[105] = 2;
  DlgItem = GetDlgItem(hDlg, 1185);
  return EnableWindow(DlgItem, 0);
}
