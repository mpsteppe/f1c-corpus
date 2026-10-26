int sub_480E60()
{
  const CHAR *v0; // eax
  const CHAR *v1; // eax
  HWND DlgItem; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  BOOL v15; // [esp+8h] [ebp-4h]

  v0 = (const CHAR *)dword_759EC0;
  if ( !dword_759EC0 )
    v0 = WindowName;
  SendDlgItemMessageA(dword_B6CE78, 1024, 0xCu, 0, (LPARAM)v0);
  v1 = (const CHAR *)dword_759EC8;
  if ( !dword_759EC8 )
    v1 = WindowName;
  SendDlgItemMessageA(dword_B6CE78, 1025, 0xCu, 0, (LPARAM)v1);
  if ( *(_DWORD *)dword_759E94 )
  {
    SendDlgItemMessageA(dword_B6CE78, 1063, 0xF1u, 1u, 0);
    SendDlgItemMessageA(dword_B6CE78, 1062, 0xF1u, 0, 0);
    v15 = 1;
  }
  else
  {
    SendDlgItemMessageA(dword_B6CE78, 1063, 0xF1u, 0, 0);
    SendDlgItemMessageA(dword_B6CE78, 1062, 0xF1u, 1u, 0);
    v15 = 0;
  }
  DlgItem = GetDlgItem(dword_B6CE78, 1206);
  EnableWindow(DlgItem, v15);
  if ( *(_DWORD *)dword_759E98 )
    SendDlgItemMessageA(dword_B6CE78, 1206, 0xF1u, 1u, 0);
  else
    SendDlgItemMessageA(dword_B6CE78, 1206, 0xF1u, 0, 0);
  SendDlgItemMessageA(dword_B6CE78, 1024, 0xC5u, 0x18u, 0);
  SendDlgItemMessageA(dword_B6CE78, 1025, 0xC5u, 0xFu, 0);
  SendDlgItemMessageA(dword_B6CE78, 1028, 0x14Bu, 0, 0);
  v3 = sub_41D840(&byte_91CC38, "None");
  SendDlgItemMessageA(dword_B6CE78, 1028, 0x143u, 0, (LPARAM)v3);
  v4 = sub_41D840(&byte_91CC38, "Black Only");
  SendDlgItemMessageA(dword_B6CE78, 1028, 0x143u, 0, (LPARAM)v4);
  v5 = sub_41D840(&byte_91CC38, "Full");
  SendDlgItemMessageA(dword_B6CE78, 1028, 0x143u, 0, (LPARAM)v5);
  SendDlgItemMessageA(dword_B6CE78, 1028, 0x14Eu, wParam, 0);
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x14Bu, 0, 0);
  v6 = sub_41D840(&byte_91CC38, off_6F1D6C);
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v6);
  v7 = sub_41D840(&byte_91CC38, "Normal");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v7);
  v8 = sub_41D840(&byte_91CC38, "2x");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v8);
  v9 = sub_41D840(&byte_91CC38, "3x");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v9);
  v10 = sub_41D840(&byte_91CC38, "4x");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v10);
  v11 = sub_41D840(&byte_91CC38, "5x");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v11);
  v12 = sub_41D840(&byte_91CC38, "6x");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v12);
  v13 = sub_41D840(&byte_91CC38, "7x");
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x143u, 0, (LPARAM)v13);
  SendDlgItemMessageA(dword_B6CE78, 1029, 0x14Eu, dword_759E58, 0);
  SendDlgItemMessageA(dword_B6CE78, 1030, 0x14Bu, 0, 0);
  sub_41D840(&byte_91CC38, off_6F1D6C);
  return off_16C9670();
}
