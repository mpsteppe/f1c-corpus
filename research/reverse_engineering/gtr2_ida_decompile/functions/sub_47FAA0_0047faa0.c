void __thiscall sub_47FAA0(_DWORD *this, char a2)
{
  HWND DlgItem; // eax
  HWND v4; // eax
  HWND v5; // eax
  HWND v6; // eax
  HWND v7; // eax
  int v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  BOOL v19; // [esp-10h] [ebp-14h]
  BOOL v20; // [esp-10h] [ebp-14h]
  BOOL v21; // [esp-10h] [ebp-14h]
  BOOL v22; // [esp-10h] [ebp-14h]
  char *v23; // [esp-10h] [ebp-14h]

  if ( a2 || sub_617F80(this + 240) >= 0.1 )
  {
    sub_617E70(this + 240);
    if ( IsWindowVisible(hDlg) )
    {
      v19 = SendDlgItemMessageA(hDlg, 1033, 0x188u, 0, 0) != -1;
      DlgItem = GetDlgItem(hDlg, 1006);
      EnableWindow(DlgItem, v19);
    }
    if ( IsWindowVisible(hWnd) )
    {
      if ( SendDlgItemMessageA(hWnd, 1003, 0x190u, 0, 0) == 1 )
      {
        v4 = GetDlgItem(hWnd, 1004);
        EnableWindow(v4, 1);
        v20 = 1;
      }
      else
      {
        v6 = GetDlgItem(hWnd, 1004);
        EnableWindow(v6, 0);
        v20 = 0;
      }
      v5 = GetDlgItem(hWnd, 1005);
      EnableWindow(v5, v20);
      v21 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0) > 0;
      v7 = GetDlgItem(hWnd, 1032);
      EnableWindow(v7, v21);
    }
    v8 = this[217];
    if ( v8 )
    {
      if ( v8 == 5 )
      {
        if ( IsWindowVisible(hDlg) )
        {
          v22 = dword_757C10 > 0;
          v13 = GetDlgItem(hDlg, 1005);
          EnableWindow(v13, v22);
          v14 = GetDlgItem(hDlg, 1185);
          EnableWindow(v14, 1);
          v15 = GetDlgItem(hDlg, 1035);
          EnableWindow(v15, 1);
          if ( *(_DWORD *)dword_B640C8 == 6 )
            v23 = sub_41D840(&byte_91CC38, "Restart Race");
          else
            v23 = sub_41D840(&byte_91CC38, "Next Session");
          v16 = GetDlgItem(hDlg, 1005);
          SetWindowTextA(v16, v23);
        }
        else if ( !IsWindowVisible(hWnd) && IsWindowVisible(dword_B6CE78) )
        {
          v17 = GetDlgItem(hDlg, 1185);
          EnableWindow(v17, 1);
          v18 = GetDlgItem(dword_B6CE78, 1034);
          EnableWindow(v18, 1);
        }
      }
      else
      {
        v9 = GetDlgItem(hDlg, 1005);
        EnableWindow(v9, 0);
        v10 = GetDlgItem(hDlg, 1185);
        EnableWindow(v10, 0);
        v11 = GetDlgItem(hDlg, 1035);
        EnableWindow(v11, 0);
        v12 = GetDlgItem(dword_B6CE78, 1034);
        EnableWindow(v12, 0);
      }
    }
  }
}
