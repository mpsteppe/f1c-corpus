INT_PTR __stdcall sub_466E60(HWND hDlg, UINT a2, WPARAM a3, HWND hWnd)
{
  int v4; // ebx
  INT_PTR result; // eax
  int v6; // ecx
  LRESULT v7; // eax
  LRESULT v8; // eax
  LRESULT v9; // eax
  int v10; // edx
  int v11; // eax
  LRESULT v12; // esi
  HWND DlgItem; // eax
  LRESULT v14; // esi
  HWND v15; // eax
  CHAR v16[256]; // [esp+Ch] [ebp-500h] BYREF
  LPARAM lParam[256]; // [esp+10Ch] [ebp-400h] BYREF

  v16[0] = byte_629120;
  memset(&v16[1], 0, 255);
  v4 = 0;
  if ( a2 > 0x111 )
  {
    if ( a2 == 276 && (unsigned __int16)a3 <= 7u )
    {
      v11 = GetDlgCtrlID(hWnd) - 1200;
      if ( v11 )
      {
        if ( v11 == 1 )
        {
          v12 = SendDlgItemMessageA(hDlg, 1201, 0x400u, 0, 0);
          sprintf(v16, "%d", v12);
          DlgItem = GetDlgItem(hDlg, 1036);
          SetWindowTextA(DlgItem, v16);
          *(_DWORD *)dword_600760 = v12;
          return 1;
        }
      }
      else
      {
        v14 = SendDlgItemMessageA(hDlg, 1200, 0x400u, 0, 0);
        sprintf(v16, "%d kbits/s", v14);
        v15 = GetDlgItem(hDlg, 1043);
        SetWindowTextA(v15, v16);
        dword_764ED8 = v14;
        sub_46BA40();
      }
      return 1;
    }
    return v4;
  }
  if ( a2 != 273 )
  {
    if ( a2 == 2 )
    {
LABEL_9:
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
  v6 = (unsigned __int16)a3 - 1000;
  switch ( (__int16)a3 )
  {
    case 1000:
      switch ( HIWORD(a3) )
      {
        case 1u:
          goto LABEL_14;
        case 2u:
LABEL_19:
          sub_46BB60(v6);
          return 0;
        case 3u:
LABEL_14:
          LOBYTE(v6) = 1;
          sub_46BEE0(v6, 0);
          return 0;
        default:
          return v4;
      }
    case 1001:
      goto LABEL_19;
    case 1002:
      goto LABEL_20;
    case 1003:
      switch ( HIWORD(a3) )
      {
        case 1u:
          goto LABEL_18;
        case 2u:
LABEL_20:
          sub_46BD20(v6);
          result = 0;
          break;
        case 3u:
LABEL_18:
          LOBYTE(v6) = 0;
          sub_46BEE0(v6, 0);
          result = 0;
          break;
        default:
          return v4;
      }
      break;
    case 1004:
      if ( SendDlgItemMessageA(hDlg, 1003, 0x191u, 0x100u, (LPARAM)lParam) != 1 )
        return v4;
      SendDlgItemMessageA(hDlg, 1003, 0x189u, lParam[0], (LPARAM)v16);
      SendDlgItemMessageA(hDlg, 1003, 0x182u, lParam[0], 0);
      v7 = SendDlgItemMessageA(hDlg, 1003, 0x181u, lParam[0] - 1 < 0 ? 0 : lParam[0] - 1, (LPARAM)v16);
      SendDlgItemMessageA(hDlg, 1003, 0x185u, 1u, v7);
      return 0;
    case 1005:
      if ( SendDlgItemMessageA(hDlg, 1003, 0x191u, 0x100u, (LPARAM)lParam) != 1 )
        return v4;
      SendDlgItemMessageA(hDlg, 1003, 0x189u, lParam[0], (LPARAM)v16);
      SendDlgItemMessageA(hDlg, 1003, 0x182u, lParam[0], 0);
      v8 = SendDlgItemMessageA(hDlg, 1003, 0x18Bu, 0, 0);
      if ( v8 >= lParam[0] + 1 )
        v8 = lParam[0] + 1;
      v9 = SendDlgItemMessageA(hDlg, 1003, 0x181u, v8, (LPARAM)v16);
      SendDlgItemMessageA(hDlg, 1003, 0x185u, 1u, v9);
      return 0;
    case 1032:
      sub_466A60();
      sub_46C1D0(5);
      return 0;
    case 1034:
      if ( !*((_DWORD *)sub_466A60() + 105) )
        goto LABEL_9;
      sub_466A60();
      sub_46C1D0(3);
      return 0;
    case 1042:
      if ( HIWORD(a3) != 1 )
        return v4;
      dword_7652C4 = SendDlgItemMessageA(hDlg, 1042, 0x147u, 0, 0);
      switch ( dword_7652C4 )
      {
        case 0u:
          dword_764ED8 = dword_764ECC;
          sub_46B970();
          sub_46BA40();
          return 0;
        case 1u:
          v10 = dword_764F14;
          goto LABEL_35;
        case 2u:
          dword_764ED8 = dword_764F0C;
          sub_46B970();
          sub_46BA40();
          return 0;
        case 3u:
          dword_764ED8 = dword_764F10;
          sub_46B970();
          sub_46BA40();
          return 0;
        case 4u:
          dword_764ED8 = 10000;
          sub_46B970();
          sub_46BA40();
          return 0;
        case 5u:
          v10 = dword_764F0C;
LABEL_35:
          dword_764ED8 = v10;
          goto LABEL_36;
        default:
LABEL_36:
          sub_46B970();
          sub_46BA40();
          result = 0;
          break;
      }
      return result;
    default:
      return v4;
  }
  return result;
}
