LRESULT __thiscall sub_47F220(LPARAM lParam)
{
  LRESULT result; // eax
  LRESULT v2; // edi
  HWND DlgItem; // eax
  int v4; // edi
  tagSCROLLINFO v5; // [esp+8h] [ebp-1Ch] BYREF

  SendDlgItemMessageA(hDlg, 1034, 0x180u, 0, lParam);
  result = SendDlgItemMessageA(hDlg, 1034, 0x18Bu, 0, 0);
  v2 = result;
  if ( result != -1 )
  {
    DlgItem = GetDlgItem(hDlg, 1034);
    v5.cbSize = 28;
    v5.fMask = 7;
    result = GetScrollInfo(DlgItem, 1, &v5);
    if ( result )
    {
      result = v5.nPos + v5.nPage;
      if ( v5.nPos + v5.nPage == v5.nMax )
        result = SendDlgItemMessageA(hDlg, 1034, 0x186u, v2 - 1, 0);
    }
  }
  v4 = v2 - 128;
  if ( v4 > 0 )
  {
    do
    {
      result = SendDlgItemMessageA(hDlg, 1034, 0x182u, 0, 0);
      --v4;
    }
    while ( v4 );
  }
  return result;
}
