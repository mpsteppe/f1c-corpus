INT_PTR __stdcall sub_467380(HWND hDlg, UINT a2, WPARAM nIDDlgItem, HWND hWnd)
{
  int v4; // edi
  INT_PTR result; // eax
  int v6; // eax
  char v7; // cl
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  int v12; // eax
  char v13; // cl
  LRESULT v14; // eax
  LRESULT v15; // eax
  LRESULT v16; // eax
  LRESULT v17; // eax
  LRESULT v18; // eax
  LRESULT v19; // eax
  LRESULT v20; // eax
  LRESULT v21; // eax
  LRESULT v22; // eax
  LRESULT v23; // eax
  LRESULT v24; // eax
  LRESULT v25; // eax
  int v26; // eax
  LRESULT v27; // esi
  HWND DlgItem; // eax
  HWND v29; // eax
  LRESULT v30; // [esp+10h] [ebp-404h]
  char lParam[256]; // [esp+14h] [ebp-400h] BYREF
  CHAR String[256]; // [esp+114h] [ebp-300h] BYREF
  _BYTE v33[256]; // [esp+214h] [ebp-200h] BYREF
  _BYTE v34[256]; // [esp+314h] [ebp-100h] BYREF

  v4 = 0;
  if ( a2 > 0x111 )
  {
    if ( a2 == 276 && (unsigned __int16)nIDDlgItem <= 7u )
    {
      v26 = GetDlgCtrlID(hWnd) - 1198;
      if ( v26 )
      {
        if ( v26 == 1 )
        {
          v27 = SendDlgItemMessageA(hDlg, 1199, 0x400u, 0, 0);
          sprintf(String, "%d%%", v27);
          DlgItem = GetDlgItem(hDlg, 1038);
          SetWindowTextA(DlgItem, String);
          result = 1;
          dword_600784 = v27;
          return result;
        }
      }
      else
      {
        v30 = SendDlgItemMessageA(hDlg, 1198, 0x400u, 0, 0);
        sprintf(String, "%d%%", v30);
        v29 = GetDlgItem(hDlg, 1037);
        SetWindowTextA(v29, String);
        flt_600780 = (double)v30 * 0.0099999998;
      }
      return 1;
    }
    return v4;
  }
  if ( a2 != 273 )
  {
    if ( a2 == 2 )
    {
      sub_466AB0();
      return 0;
    }
    if ( a2 == 16 )
    {
      PostQuitMessage(0);
      return 1;
    }
    return v4;
  }
  switch ( (__int16)nIDDlgItem )
  {
    case 1006:
      v14 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v14 == 1 )
      {
        byte_600774 = 1;
        return 0;
      }
      if ( v14 )
        return v4;
      byte_600774 = 0;
      return 0;
    case 1007:
      v15 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v15 == 1 )
      {
        byte_600775 = 1;
        return 0;
      }
      if ( v15 )
        return v4;
      byte_600775 = 0;
      return 0;
    case 1008:
      v16 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v16 == 1 )
      {
        byte_600776 = 1;
        return 0;
      }
      if ( v16 )
        return v4;
      byte_600776 = 0;
      return 0;
    case 1009:
      v17 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v17 == 1 )
      {
        byte_600777 = 1;
        return 0;
      }
      if ( v17 )
        return v4;
      byte_600777 = 0;
      return 0;
    case 1010:
      v18 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v18 == 1 )
      {
        byte_600778 = 1;
        return 0;
      }
      if ( v18 )
        return v4;
      byte_600778 = 0;
      return 0;
    case 1011:
      v19 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v19 == 1 )
      {
        byte_7652D0 = 1;
        return 0;
      }
      if ( v19 )
        return v4;
      byte_7652D0 = 0;
      return 0;
    case 1012:
      v20 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v20 == 1 )
      {
        byte_600779 = 1;
        return 0;
      }
      if ( v20 )
        return v4;
      byte_600779 = 0;
      return 0;
    case 1013:
      v21 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v21 == 1 )
      {
        byte_60077A = 1;
        return 0;
      }
      if ( v21 )
        return v4;
      byte_60077A = 0;
      return 0;
    case 1014:
      v22 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v22 == 1 )
      {
        byte_60077B = 1;
        return 0;
      }
      if ( v22 )
        return v4;
      byte_60077B = 0;
      return 0;
    case 1015:
      v23 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v23 == 1 )
      {
        byte_60077C = 1;
        return 0;
      }
      if ( v23 )
        return v4;
      byte_60077C = 0;
      return 0;
    case 1016:
      v24 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v24 == 1 )
      {
        byte_60077D = 1;
        return 0;
      }
      if ( v24 )
        return v4;
      byte_60077D = 0;
      return 0;
    case 1017:
      v25 = SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xF0u, 0, 0);
      if ( v25 == 1 )
      {
        byte_7652D1 = 1;
        return 0;
      }
      if ( v25 )
        return v4;
      byte_7652D1 = 0;
      return 0;
    case 1024:
      if ( HIWORD(nIDDlgItem) == 512 )
      {
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xDu, 0x100u, (LPARAM)v33);
        sub_578600(v33);
      }
      else if ( HIWORD(nIDDlgItem) == 768 && SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xBAu, 0, 0) > 1 )
      {
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xDu, 0x100u, (LPARAM)lParam);
        v6 = 0;
        if ( lParam[0] != 13 )
        {
          do
            v7 = lParam[++v6];
          while ( v7 != 13 );
        }
        lParam[v6] = 0;
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xCu, 0, (LPARAM)&byte_629120);
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xCu, 0, (LPARAM)lParam);
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xB1u, 0, -1);
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xB6u, strlen(lParam), -1);
        v8 = 0;
        do
        {
          v9 = lParam[v8];
          v33[v8++] = v9;
        }
        while ( v9 );
        return 0;
      }
      return 0;
    case 1025:
      if ( HIWORD(nIDDlgItem) == 512 )
      {
        SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xDu, 0x100u, (LPARAM)v34);
        sub_578600(v34);
        return 0;
      }
      if ( HIWORD(nIDDlgItem) != 768 || SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xBAu, 0, 0) <= 1 )
        return 0;
      SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xDu, 0x100u, (LPARAM)lParam);
      v10 = 0;
      if ( lParam[0] != 13 )
      {
        do
          v11 = lParam[++v10];
        while ( v11 != 13 );
      }
      lParam[v10] = 0;
      SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xCu, 0, (LPARAM)&byte_629120);
      SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xCu, 0, (LPARAM)lParam);
      SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xB1u, 0, -1);
      SendDlgItemMessageA(hDlg, (unsigned __int16)nIDDlgItem, 0xB6u, strlen(lParam), -1);
      v12 = 0;
      do
      {
        v13 = lParam[v12];
        v34[v12++] = v13;
      }
      while ( v13 );
      return 0;
    case 1028:
      if ( HIWORD(nIDDlgItem) != 1 )
        return v4;
      wParam = SendDlgItemMessageA(hDlg, 1028, 0x147u, 0, 0);
      return 0;
    case 1029:
      if ( HIWORD(nIDDlgItem) != 1 )
        return v4;
      dword_600764 = SendDlgItemMessageA(hDlg, 1029, 0x147u, 0, 0);
      return 0;
    case 1030:
      if ( HIWORD(nIDDlgItem) != 1 )
        return v4;
      dword_600768 = SendDlgItemMessageA(hDlg, 1030, 0x147u, 0, 0);
      return 0;
    case 1031:
      if ( HIWORD(nIDDlgItem) != 1 )
        return v4;
      dword_60076C = SendDlgItemMessageA(hDlg, 1031, 0x147u, 0, 0);
      return 0;
    case 1032:
      if ( HIWORD(nIDDlgItem) != 1 )
        return v4;
      dword_600770 = SendDlgItemMessageA(hDlg, 1032, 0x147u, 0, 0);
      return 0;
    case 1034:
      sub_466A60();
      sub_468880(3);
      sub_466A60();
      sub_46C1D0(3);
      return 0;
    case 1035:
      sub_466A60();
      sub_46C1D0(4);
      return 0;
    default:
      return v4;
  }
}
