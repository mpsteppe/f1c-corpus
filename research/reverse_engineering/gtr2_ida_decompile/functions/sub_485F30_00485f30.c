INT_PTR __stdcall sub_485F30(HWND hWnd, UINT a2, WPARAM a3, HWND a4)
{
  unsigned int v4; // kr00_4
  INT_PTR result; // eax
  LRESULT v6; // esi
  HWND v7; // eax
  HWND DlgItem; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  int v12; // eax
  char v13; // cl
  int v14; // eax
  char v15; // cl
  int v16; // eax
  char v17; // cl
  int v18; // eax
  char v19; // cl
  _DWORD *v20; // eax
  HWND v21; // eax
  LRESULT v22; // eax
  int v23; // esi
  LRESULT v24; // eax
  LRESULT v25; // eax
  LRESULT v26; // eax
  LRESULT v27; // eax
  LRESULT v28; // eax
  LRESULT v29; // eax
  LRESULT v30; // eax
  LRESULT v31; // eax
  LRESULT v32; // eax
  LRESULT v33; // eax
  LRESULT v34; // eax
  LRESULT v35; // eax
  LRESULT v36; // eax
  float v37; // [esp+10h] [ebp-514h] BYREF
  int v38; // [esp+14h] [ebp-510h]
  CHAR v39[12]; // [esp+18h] [ebp-50Ch] BYREF
  char lParam[256]; // [esp+24h] [ebp-500h] BYREF
  CHAR String[256]; // [esp+124h] [ebp-400h] BYREF
  _BYTE v42[256]; // [esp+224h] [ebp-300h] BYREF
  _BYTE v43[256]; // [esp+324h] [ebp-200h] BYREF
  char Buffer[256]; // [esp+424h] [ebp-100h] BYREF

  if ( a2 <= 0x110 )
  {
    switch ( a2 )
    {
      case 0x110u:
        GetWindowTextA(hWnd, String, 255);
        sub_41D840(&byte_91CC38, String);
        return off_16C926C(hWnd, 272, a3, a4);
      case 2u:
        sub_484D30();
        return 0;
      case 0x10u:
        PostQuitMessage(0);
        return 1;
    }
    return 0;
  }
  if ( a2 == 273 )
  {
    switch ( (__int16)a3 )
    {
      case 1004:
        if ( *(int *)dword_759E74 >= 23 )
          return 0;
        sprintf(v39, "%02d:00", ++*(_DWORD *)dword_759E74);
        DlgItem = GetDlgItem(hWnd, 1054);
        SetWindowTextA(DlgItem, v39);
        return 0;
      case 1006:
        v24 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v24 == 1 )
        {
          byte_759E64 = 1;
          return 0;
        }
        if ( v24 )
          return 0;
        result = 0;
        byte_759E64 = 0;
        return result;
      case 1007:
        v25 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v25 == 1 )
        {
          byte_759E65 = 1;
          return 0;
        }
        if ( v25 )
          return 0;
        result = 0;
        byte_759E65 = 0;
        return result;
      case 1008:
        v26 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v26 == 1 )
        {
          byte_759E66 = 1;
          return 0;
        }
        if ( v26 )
          return 0;
        result = 0;
        byte_759E66 = 0;
        return result;
      case 1009:
        v27 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v27 == 1 )
        {
          byte_759E67 = 1;
          return 0;
        }
        if ( v27 )
          return 0;
        result = 0;
        byte_759E67 = 0;
        return result;
      case 1010:
        v28 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v28 == 1 )
        {
          byte_759E68 = 1;
          return 0;
        }
        if ( v28 )
          return 0;
        result = 0;
        byte_759E68 = 0;
        return result;
      case 1011:
        v29 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v29 == 1 )
        {
          byte_B6CE94 = 1;
          return 0;
        }
        if ( v29 )
          return 0;
        result = 0;
        byte_B6CE94 = 0;
        return result;
      case 1012:
        v31 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v31 == 1 )
        {
          byte_759E69 = 1;
          return 0;
        }
        if ( v31 )
          return 0;
        result = 0;
        byte_759E69 = 0;
        return result;
      case 1013:
        v32 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v32 == 1 )
        {
          byte_759E6A = 1;
          return 0;
        }
        if ( v32 )
          return 0;
        result = 0;
        byte_759E6A = 0;
        return result;
      case 1014:
        v33 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v33 == 1 )
        {
          byte_759E6B = 1;
          return 0;
        }
        if ( v33 )
          return 0;
        result = 0;
        byte_759E6B = 0;
        return result;
      case 1017:
        v34 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v34 == 1 )
        {
          byte_B6CE95 = 1;
          return 0;
        }
        if ( v34 )
          return 0;
        result = 0;
        byte_B6CE95 = 0;
        return result;
      case 1018:
        v35 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v35 == 1 )
        {
          byte_B6CE96 = 1;
          return 0;
        }
        if ( v35 )
          return 0;
        result = 0;
        byte_B6CE96 = 0;
        return result;
      case 1019:
        v36 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v36 == 1 )
        {
          byte_759E6D = 1;
          return 0;
        }
        if ( v36 )
          return 0;
        result = 0;
        byte_759E6D = 0;
        return result;
      case 1024:
        if ( HIWORD(a3) == 512 )
        {
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)v43);
          sub_615860(v43);
        }
        else if ( HIWORD(a3) == 768 && SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xBAu, 0, 0) > 1 )
        {
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          v12 = 0;
          if ( lParam[0] != 13 )
          {
            do
              v13 = lParam[++v12];
            while ( v13 != 13 );
          }
          lParam[v12] = 0;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xCu, 0, (LPARAM)WindowName);
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xCu, 0, (LPARAM)lParam);
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xB1u, 0, -1);
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xB6u, strlen(lParam), -1);
          v14 = 0;
          do
          {
            v15 = lParam[v14];
            v43[v14++] = v15;
          }
          while ( v15 );
          return 0;
        }
        return 0;
      case 1025:
        if ( HIWORD(a3) == 512 )
        {
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)v42);
          sub_615860(v42);
        }
        else if ( HIWORD(a3) == 768 && SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xBAu, 0, 0) > 1 )
        {
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          v16 = 0;
          if ( lParam[0] != 13 )
          {
            do
              v17 = lParam[++v16];
            while ( v17 != 13 );
          }
          lParam[v16] = 0;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xCu, 0, (LPARAM)WindowName);
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xCu, 0, (LPARAM)lParam);
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xB1u, 0, -1);
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xB6u, strlen(lParam), -1);
          v18 = 0;
          do
          {
            v19 = lParam[v18];
            v42[v18++] = v19;
          }
          while ( v19 );
          return 0;
        }
        return 0;
      case 1028:
        if ( HIWORD(a3) != 1 )
          return 0;
        wParam = SendDlgItemMessageA(hWnd, 1028, 0x147u, 0, 0);
        return 0;
      case 1029:
        if ( HIWORD(a3) != 1 )
          return 0;
        dword_759E58 = SendDlgItemMessageA(hWnd, 1029, 0x147u, 0, 0);
        return 0;
      case 1030:
        if ( HIWORD(a3) != 1 )
          return 0;
        *(_DWORD *)dword_759E5C = SendDlgItemMessageA(hWnd, 1030, 0x147u, 0, 0);
        return 0;
      case 1031:
        if ( HIWORD(a3) != 1 )
          return 0;
        *(_DWORD *)dword_759E60 = SendDlgItemMessageA(hWnd, 1031, 0x147u, 0, 0);
        return 0;
      case 1032:
        if ( HIWORD(a3) != 1 )
          return 0;
        v22 = SendDlgItemMessageA(hWnd, 1032, 0x147u, 0, 0);
        v38 = v22;
        v37 = 0.0;
        if ( v22 )
        {
          if ( v22 == 11 )
          {
            v23 = 0;
          }
          else
          {
            v23 = 2;
            v37 = (double)v38 * 0.1;
          }
        }
        else
        {
          v23 = 1;
        }
        sub_409B80(flt_B70844, &v37);
        v4 = __readeflags();
        *(float *)(*(_DWORD *)sub_1007D10 ^ dword_16C6CD8) = v37;
        __writeeflags(v4);
        result = 0;
        *(_DWORD *)dword_B6CE8C = v23;
        return result;
      case 1033:
        dword_B6CE84 = SendDlgItemMessageA(hWnd, 1033, 0x147u, 0, 0);
        sub_50F030(&byte_B6F530, dword_B6CE84);
        ((void (*)(void))loc_47F360)();
        *(_DWORD *)dword_B6CE88 = dword_B6CE84;
        return 0;
      case 1034:
        sub_484CD0();
        if ( hHandle )
          WaitForSingleObject(hHandle, dword_B6CECC);
        v20 = operator new(4u);
        *v20 = 4;
        sub_5FDFB0(v20, 1);
        v21 = GetDlgItem(dword_B6CE78, 1034);
        EnableWindow(v21, 0);
        if ( hHandle )
          ReleaseMutex(hHandle);
        goto LABEL_46;
      case 1035:
LABEL_46:
        sub_484CD0();
        sub_47F650();
        return 0;
      case 1056:
        if ( *(int *)dword_759E74 <= 0 )
          return 0;
        sprintf(v39, "%02d:00", --*(_DWORD *)dword_759E74);
        v9 = GetDlgItem(hWnd, 1054);
        SetWindowTextA(v9, v39);
        return 0;
      case 1062:
        v11 = GetDlgItem(hWnd, 1206);
        EnableWindow(v11, 0);
        *(_DWORD *)dword_759E94 = 0;
        return 0;
      case 1063:
        *(_DWORD *)dword_759E94 = 1;
        v10 = GetDlgItem(hWnd, 1206);
        EnableWindow(v10, 1);
        return 0;
      case 1206:
        *(_DWORD *)dword_759E98 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0) != 0;
        return 0;
      case 1207:
        v30 = SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xF0u, 0, 0);
        if ( v30 == 1 )
        {
          byte_759E9C = 1;
          return 0;
        }
        if ( v30 )
          return 0;
        result = 0;
        byte_759E9C = 0;
        return result;
      default:
        return 0;
    }
  }
  if ( a2 != 276 || (unsigned __int16)a3 > 7u )
    return 0;
  if ( GetDlgCtrlID(a4) == 1199 )
  {
    v6 = SendDlgItemMessageA(hWnd, 1199, 0x400u, 0, 0);
    sprintf(Buffer, "%d%%", v6);
    v7 = GetDlgItem(hWnd, 1038);
    SetWindowTextA(v7, Buffer);
    *(_DWORD *)dword_759E70 = v6;
  }
  return 1;
}
