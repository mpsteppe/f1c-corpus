INT_PTR __stdcall DialogFunc(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  LRESULT v5; // eax
  WPARAM v6; // esi
  LRESULT v7; // ebp
  HWND v8; // eax
  CHAR *v9; // eax
  HWND v10; // eax
  HWND DlgItem; // eax
  BOOL v12; // [esp-4h] [ebp-98h]
  LPARAM v13[2]; // [esp+Ch] [ebp-88h] BYREF
  LPARAM lParam[32]; // [esp+14h] [ebp-80h] BYREF

  switch ( a2 )
  {
    case 2u:
LABEL_10:
      sub_466AB0();
      return 0;
    case 0x110u:
      SendDlgItemMessageA(hDlg, 1024, 0xC5u, 0x50u, 0);
      SendMessageA(hDlg, 0x401u, 0x3EFu, 0);
      return 0;
    case 0x111u:
      if ( (unsigned __int16)a3 > 0x3EFu )
      {
        switch ( (unsigned __int16)a3 )
        {
          case 0x400u:
            if ( HIWORD(a3) != 768 )
              return 0;
            v12 = SendDlgItemMessageA(hDlg, 1024, 0xC1u, 0, 0) > 0;
            DlgItem = GetDlgItem(hDlg, 1007);
            EnableWindow(DlgItem, v12);
            return 0;
          case 0x40Bu:
            sub_466A60();
            sub_46C1D0(4);
            return 0;
          case 0x4A1u:
            sub_466A60();
            sub_468880(2);
            return 0;
          default:
            return 0;
        }
      }
      else if ( (unsigned __int16)a3 == 1007 )
      {
        if ( SendDlgItemMessageA(hDlg, 1024, 0xC1u, 0, 0) <= 0 )
          return 0;
        LOWORD(lParam[0]) = 127;
        *((_BYTE *)lParam + SendDlgItemMessageA(hDlg, 1024, 0xC4u, 0, (LPARAM)lParam)) = 0;
        if ( hHandle )
          WaitForSingleObject(hHandle, dword_764EFC);
        sub_578600(lParam);
        if ( hHandle )
          ReleaseMutex(hHandle);
        SendDlgItemMessageA(hDlg, 1024, 0xCu, 0, (LPARAM)&byte_629120);
        v13[0] = (LPARAM)operator new(0x80u);
        *(_BYTE *)v13[0] = 0;
        v13[1] = 128;
        sub_578560(asc_60079C);
        sub_578560(lParam);
        v9 = (CHAR *)v13[0];
        if ( !v13[0] )
          v9 = &byte_629120;
        sub_46B130((LPARAM)v9);
        v10 = GetDlgItem(hDlg, 1007);
        EnableWindow(v10, 0);
        if ( !v13[0] )
          return 0;
        sub_5BE8AE((LPVOID)v13[0]);
        return 0;
      }
      else if ( (unsigned __int16)a3 > 0x3EDu )
      {
        if ( (unsigned __int16)a3 != 1006 )
          return 0;
        v5 = SendDlgItemMessageA(hDlg, 1033, 0x188u, 0, 0);
        v6 = v5;
        if ( v5 == -1 )
          return 0;
        v7 = SendDlgItemMessageA(hDlg, 1033, 0x199u, v5, 0);
        SendDlgItemMessageA(hDlg, 1033, 0x182u, v6, 0);
        sub_462BC0(lParam);
        if ( sub_463D40(dword_764D70, v7, lParam, v13) )
        {
          sub_464350(dword_764D70, v13[0]);
          v8 = GetDlgItem(hDlg, 1006);
          EnableWindow(v8, 0);
        }
        nullsub_6(lParam);
        return 0;
      }
      else
      {
        if ( (unsigned __int16)a3 != 1005 )
        {
          if ( !(_WORD)a3 || (unsigned __int16)a3 > 2u )
            return 0;
          goto LABEL_10;
        }
        sub_466A60();
        sub_468880(1);
        return 0;
      }
    default:
      return 0;
  }
}
