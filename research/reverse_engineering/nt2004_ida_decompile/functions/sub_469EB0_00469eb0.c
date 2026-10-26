void __thiscall sub_469EB0(_DWORD *this, char a2)
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
  BOOL v17; // [esp-4h] [ebp-14h]
  BOOL v18; // [esp-4h] [ebp-14h]
  BOOL v19; // [esp-4h] [ebp-14h]
  BOOL v20; // [esp-4h] [ebp-14h]
  BOOL v21; // [esp-4h] [ebp-14h]

  if ( a2 || sub_57B7C0(this + 126) >= 0.1 )
  {
    sub_57B690(this + 126);
    if ( IsWindowVisible(hDlg) )
    {
      v17 = SendDlgItemMessageA(hDlg, 1033, 0x188u, 0, 0) != -1;
      DlgItem = GetDlgItem(hDlg, 1006);
      EnableWindow(DlgItem, v17);
    }
    if ( IsWindowVisible(hWnd) )
    {
      if ( SendDlgItemMessageA(hWnd, 1003, 0x190u, 0, 0) == 1 )
      {
        v4 = GetDlgItem(hWnd, 1004);
        EnableWindow(v4, 1);
        v18 = 1;
      }
      else
      {
        v6 = GetDlgItem(hWnd, 1004);
        EnableWindow(v6, 0);
        v18 = 0;
      }
      v5 = GetDlgItem(hWnd, 1005);
      EnableWindow(v5, v18);
      v19 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0) > 0;
      v7 = GetDlgItem(hWnd, 1032);
      EnableWindow(v7, v19);
    }
    v8 = this[105];
    if ( v8 )
    {
      if ( v8 != 4 )
      {
        v9 = GetDlgItem(hDlg, 1005);
        EnableWindow(v9, 0);
        v10 = GetDlgItem(hDlg, 1185);
        EnableWindow(v10, 0);
        v11 = GetDlgItem(hDlg, 1035);
        EnableWindow(v11, 0);
        v20 = 0;
LABEL_22:
        v16 = GetDlgItem(dword_7652C0, 1034);
        EnableWindow(v16, v20);
        return;
      }
      if ( IsWindowVisible(hDlg) )
      {
        if ( dword_75CBB0 == 7 || (int)NumOfElements <= 0 )
        {
          v21 = 0;
          v12 = GetDlgItem(hDlg, 1005);
        }
        else
        {
          v21 = 1;
          v12 = GetDlgItem(hDlg, 1005);
        }
        EnableWindow(v12, v21);
        v13 = GetDlgItem(hDlg, 1185);
        EnableWindow(v13, 1);
        v14 = GetDlgItem(hDlg, 1035);
        EnableWindow(v14, 1);
      }
      else if ( !IsWindowVisible(hWnd) && IsWindowVisible(dword_7652C0) )
      {
        v15 = GetDlgItem(hDlg, 1185);
        EnableWindow(v15, 1);
        v20 = 1;
        goto LABEL_22;
      }
    }
  }
}
