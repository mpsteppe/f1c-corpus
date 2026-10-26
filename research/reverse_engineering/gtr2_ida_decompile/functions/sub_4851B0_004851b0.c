INT_PTR __stdcall sub_4851B0(HWND hWnd, UINT a2, WPARAM a3, HWND a4)
{
  INT_PTR result; // eax
  int v5; // eax
  LRESULT v6; // esi
  HWND v7; // eax
  LRESULT v8; // esi
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
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND DlgItem; // eax
  HWND v33; // eax
  HWND v34; // eax
  char v35; // dl
  LPARAM *v36; // edi
  DWORD v37; // kr04_4
  const BYTE *v38; // ecx
  HWND v39; // esi
  void (__stdcall *v40)(HWND, int, UINT, WPARAM, LPARAM); // edi
  LRESULT v41; // eax
  LRESULT v42; // eax
  int v43; // ecx
  int v44; // [esp-10h] [ebp-930h]
  DWORD cbData; // [esp+10h] [ebp-910h] BYREF
  INT_PTR v46; // [esp+14h] [ebp-90Ch]
  HKEY phkResult; // [esp+18h] [ebp-908h] BYREF
  DWORD Type; // [esp+1Ch] [ebp-904h] BYREF
  char lParam[252]; // [esp+20h] [ebp-900h] BYREF
  __int16 v50; // [esp+11Ch] [ebp-804h]
  char v51; // [esp+11Eh] [ebp-802h]
  char Buffer[253]; // [esp+120h] [ebp-800h] BYREF
  __int16 v53; // [esp+21Dh] [ebp-703h]
  char v54; // [esp+21Fh] [ebp-701h]
  char v55[252]; // [esp+220h] [ebp-700h] BYREF
  __int16 v56; // [esp+31Ch] [ebp-604h]
  char v57; // [esp+31Eh] [ebp-602h]
  BYTE Data[252]; // [esp+320h] [ebp-600h] BYREF
  __int16 v59; // [esp+41Ch] [ebp-504h]
  char v60; // [esp+41Eh] [ebp-502h]
  CHAR String[256]; // [esp+420h] [ebp-500h] BYREF
  LPARAM v62[256]; // [esp+520h] [ebp-400h] BYREF

  memset(Buffer, 0, sizeof(Buffer));
  v53 = 0;
  v54 = 0;
  v46 = 0;
  if ( a2 > 0x110 )
  {
    if ( a2 == 273 )
    {
      switch ( (__int16)a3 )
      {
        case 1000:
          switch ( HIWORD(a3) )
          {
            case 1u:
              goto LABEL_90;
            case 2u:
LABEL_91:
              sub_484380();
              return v46;
            case 3u:
LABEL_90:
              sub_4800B0(1, 0);
              return v46;
            default:
              return v46;
          }
        case 1001:
          goto LABEL_91;
        case 1002:
          goto LABEL_96;
        case 1003:
          switch ( HIWORD(a3) )
          {
            case 1u:
              goto LABEL_95;
            case 2u:
LABEL_96:
              sub_4846C0();
              result = v46;
              break;
            case 3u:
LABEL_95:
              sub_4800B0(0, 0);
              result = v46;
              break;
            default:
              return v46;
          }
          break;
        case 1004:
          v39 = hWnd;
          v40 = (void (__stdcall *)(HWND, int, UINT, WPARAM, LPARAM))SendDlgItemMessageA;
          if ( SendDlgItemMessageA(hWnd, 1003, 0x191u, 0x100u, (LPARAM)v62) != 1 )
            return v46;
          SendDlgItemMessageA(hWnd, 1003, 0x189u, v62[0], (LPARAM)Buffer);
          SendDlgItemMessageA(hWnd, 1003, 0x182u, v62[0], 0);
          v41 = SendDlgItemMessageA(hWnd, 1003, 0x181u, v62[0] - 1 < 0 ? 0 : v62[0] - 1, (LPARAM)Buffer);
          goto LABEL_103;
        case 1005:
          v39 = hWnd;
          v40 = (void (__stdcall *)(HWND, int, UINT, WPARAM, LPARAM))SendDlgItemMessageA;
          if ( SendDlgItemMessageA(hWnd, 1003, 0x191u, 0x100u, (LPARAM)v62) != 1 )
            return v46;
          SendDlgItemMessageA(hWnd, 1003, 0x189u, v62[0], (LPARAM)Buffer);
          SendDlgItemMessageA(hWnd, 1003, 0x182u, v62[0], 0);
          v42 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0);
          if ( v42 >= v62[0] + 1 )
            v42 = v62[0] + 1;
          v41 = SendDlgItemMessageA(hWnd, 1003, 0x181u, v42, (LPARAM)Buffer);
LABEL_103:
          v40(v39, 1003, 0x185u, 1u, v41);
          return v46;
        case 1006:
          DlgItem = GetDlgItem(hWnd, 1006);
          if ( SendMessageA(DlgItem, 0xF0u, 0, 0) )
          {
            byte_B6CEA0 = 1;
            SendDlgItemMessageA(hWnd, 1026, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CEA0 = 0;
            SendDlgItemMessageA(hWnd, 1026, 0xAu, 0, 0);
          }
          return v46;
        case 1007:
          v33 = GetDlgItem(hWnd, 1007);
          if ( SendMessageA(v33, 0xF0u, 0, 0) )
          {
            byte_B6CEA1 = 1;
            SendDlgItemMessageA(hWnd, 1053, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CEA1 = 0;
            SendDlgItemMessageA(hWnd, 1053, 0xAu, 0, 0);
          }
          return v46;
        case 1008:
          v34 = GetDlgItem(hWnd, 1008);
          if ( SendMessageA(v34, 0xF0u, 0, 0) )
          {
            byte_B6CEA2 = 1;
            SendDlgItemMessageA(hWnd, 1054, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CEA2 = 0;
            SendDlgItemMessageA(hWnd, 1054, 0xAu, 0, 0);
          }
          return v46;
        case 1009:
          v10 = GetDlgItem(hWnd, 1009);
          if ( SendMessageA(v10, 0xF0u, 0, 0) )
          {
            byte_759E78 = 1;
            v11 = GetDlgItem(hWnd, 1055);
            SendMessageA(v11, 0xAu, 1u, 0);
          }
          else
          {
            byte_759E78 = 0;
            v12 = GetDlgItem(hWnd, 1055);
            SendMessageA(v12, 0xAu, 0, 0);
          }
          return v46;
        case 1010:
          v13 = GetDlgItem(hWnd, 1010);
          if ( SendMessageA(v13, 0xF0u, 0, 0) )
          {
            byte_B6CE97 = 1;
            v14 = GetDlgItem(hWnd, 1056);
            SendMessageA(v14, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CE97 = 0;
            v15 = GetDlgItem(hWnd, 1056);
            SendMessageA(v15, 0xAu, 0, 0);
          }
          return v46;
        case 1011:
          v16 = GetDlgItem(hWnd, 1011);
          if ( SendMessageA(v16, 0xF0u, 0, 0) )
          {
            byte_B6CE98 = 1;
            v17 = GetDlgItem(hWnd, 1057);
            SendMessageA(v17, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CE98 = 0;
            v18 = GetDlgItem(hWnd, 1057);
            SendMessageA(v18, 0xAu, 0, 0);
          }
          return v46;
        case 1012:
          v19 = GetDlgItem(hWnd, 1012);
          if ( SendMessageA(v19, 0xF0u, 0, 0) )
          {
            byte_B6CE99 = 1;
            v20 = GetDlgItem(hWnd, 1058);
            SendMessageA(v20, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CE99 = 0;
            v21 = GetDlgItem(hWnd, 1058);
            SendMessageA(v21, 0xAu, 0, 0);
          }
          return v46;
        case 1013:
          v22 = GetDlgItem(hWnd, 1013);
          if ( SendMessageA(v22, 0xF0u, 0, 0) )
          {
            byte_B6CE9A = 1;
            v23 = GetDlgItem(hWnd, 1059);
            SendMessageA(v23, 0xAu, 1u, 0);
          }
          else
          {
            byte_B6CE9A = 0;
            v24 = GetDlgItem(hWnd, 1059);
            SendMessageA(v24, 0xAu, 0, 0);
          }
          return v46;
        case 1014:
          v25 = GetDlgItem(hWnd, 1014);
          if ( SendMessageA(v25, 0xF0u, 0, 0) )
          {
            byte_B6CE9B = 1;
            v26 = GetDlgItem(hWnd, 1060);
            SendMessageA(v26, 0xAu, 1u, 0);
            v27 = GetDlgItem(hWnd, 1065);
            EnableWindow(v27, 1);
            v28 = GetDlgItem(hWnd, 1063);
            EnableWindow(v28, 1);
          }
          else
          {
            byte_B6CE9B = 0;
            v29 = GetDlgItem(hWnd, 1060);
            SendMessageA(v29, 0xAu, 0, 0);
            v30 = GetDlgItem(hWnd, 1065);
            EnableWindow(v30, 0);
            v31 = GetDlgItem(hWnd, 1063);
            EnableWindow(v31, 0);
          }
          return v46;
        case 1026:
          if ( HIWORD(a3) != 512 )
            return v46;
          memset(lParam, 0, sizeof(lParam));
          v50 = 0;
          v51 = 0;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          v35 = lParam[0];
          memset(v55, 0, sizeof(v55));
          v56 = 0;
          v57 = 0;
          if ( lParam[0] )
          {
            v36 = (LPARAM *)lParam;
            do
            {
              if ( v35 != 45 )
                v55[strlen(v55)] = v35;
              v35 = *((_BYTE *)v36 + 1);
              v36 = (LPARAM *)((char *)v36 + 1);
            }
            while ( v35 );
          }
          sub_615860(v55);
          if ( RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", (PHKEY)&cbData) )
            return v46;
          v37 = strlen(v55);
          v38 = lpData;
          if ( !lpData )
            v38 = (const BYTE *)WindowName;
          RegSetValueExA((HKEY)cbData, "SerialNumber", 0, 1u, v38, v37);
          RegCloseKey((HKEY)cbData);
          return v46;
        case 1032:
        case 1070:
          goto LABEL_86;
        case 1034:
          if ( !*(_DWORD *)(sub_484CD0() + 868) )
            goto LABEL_85;
LABEL_86:
          sub_484CD0();
          sub_47F650();
          return v46;
        case 1042:
          if ( HIWORD(a3) == 1 )
          {
            *(_DWORD *)dword_B6CE7C = SendDlgItemMessageA(hWnd, 1042, 0x147u, 0, 0);
            switch ( *(_DWORD *)dword_B6CE7C )
            {
              case 0:
                ::lParam = dword_B6CEA8;
                break;
              case 1:
                v43 = dword_B6CEAC;
                goto LABEL_112;
              case 2:
                ::lParam = dword_B6CEB0;
                break;
              case 3:
                ::lParam = dword_B6CEB4;
                break;
              case 4:
                ::lParam = 10000;
                break;
              case 5:
                v43 = dword_B6CEB0;
LABEL_112:
                ::lParam = v43;
                break;
              default:
                break;
            }
            sub_47FE30();
            sub_47FF00();
          }
          return v46;
        case 1053:
          if ( HIWORD(a3) != 512 )
            return v46;
          goto LABEL_55;
        case 1054:
          if ( HIWORD(a3) != 512 )
            return v46;
LABEL_55:
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          sub_615860(lParam);
          return v46;
        case 1055:
          if ( HIWORD(a3) != 512 )
            return v46;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          *(_DWORD *)dword_759E7C = j__atol(lParam);
          return v46;
        case 1056:
          if ( HIWORD(a3) != 512 )
            return v46;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          *(_DWORD *)dword_759E80 = j__atol(lParam);
          return v46;
        case 1057:
          if ( HIWORD(a3) != 512 )
            return v46;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          *(_DWORD *)dword_759E84 = j__atol(lParam);
          return v46;
        case 1058:
          if ( HIWORD(a3) != 512 )
            return v46;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          *(_DWORD *)dword_759E88 = j__atol(lParam);
          return v46;
        case 1059:
          if ( HIWORD(a3) != 512 )
            return v46;
          SendDlgItemMessageA(hWnd, (unsigned __int16)a3, 0xDu, 0x100u, (LPARAM)lParam);
          *(_DWORD *)dword_759E8C = j__atol(lParam);
          return v46;
        case 1060:
          if ( HIWORD(a3) != 512 )
            return v46;
          v44 = (unsigned __int16)a3;
          goto LABEL_71;
        case 1063:
        case 1065:
          v44 = 1060;
LABEL_71:
          SendDlgItemMessageA(hWnd, v44, 0xDu, 0x100u, (LPARAM)lParam);
          if ( SendDlgItemMessageA(hWnd, 1063, 0xF0u, 0, 0) )
          {
            *(_DWORD *)dword_759E90 = 0;
            *(_DWORD *)dword_B6CE9C = j__atol(lParam);
            return v46;
          }
          else
          {
            *(_DWORD *)dword_759E90 = j__atol(lParam);
            result = v46;
            *(_DWORD *)dword_B6CE9C = 0;
          }
          return result;
        default:
          return v46;
      }
    }
    else
    {
      if ( a2 != 276 || (unsigned __int16)a3 > 7u )
        return v46;
      v5 = GetDlgCtrlID(a4) - 1200;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v6 = SendDlgItemMessageA(hWnd, 1201, 0x400u, 0, 0);
          sprintf(Buffer, "%d", v6);
          v7 = GetDlgItem(hWnd, 1036);
          SetWindowTextA(v7, Buffer);
          v46 = 1;
          result = 1;
          *(_DWORD *)dword_759E4C = v6;
          return result;
        }
      }
      else
      {
        v8 = SendDlgItemMessageA(hWnd, 1200, 0x400u, 0, 0);
        sprintf(Buffer, "%d kbits/s", v8);
        v9 = GetDlgItem(hWnd, 1043);
        SetWindowTextA(v9, Buffer);
        ::lParam = v8;
        sub_47FF00();
      }
      v46 = 1;
      return 1;
    }
  }
  else
  {
    if ( a2 != 272 )
    {
      if ( a2 == 2 )
      {
LABEL_85:
        sub_484D30();
        return v46;
      }
      if ( a2 == 16 )
      {
        PostQuitMessage(0);
        v46 = 1;
        return 1;
      }
      return v46;
    }
    GetWindowTextA(hWnd, String, 255);
    strcpy(String, sub_41D840(&byte_91CC38, String));
    SetWindowTextA(hWnd, String);
    EnumChildWindows(hWnd, EnumFunc, 0);
    memset(Data, 0, sizeof(Data));
    v59 = 0;
    v60 = 0;
    if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &phkResult) )
    {
      cbData = 255;
      Type = RegQueryValueExA(phkResult, "SerialNumber", 0, &Type, Data, &cbData);
      RegCloseKey(phkResult);
      SendDlgItemMessageA(hWnd, 1026, 0xCu, 0, (LPARAM)Data);
    }
    sub_615860(Data);
    return v46;
  }
  return result;
}
