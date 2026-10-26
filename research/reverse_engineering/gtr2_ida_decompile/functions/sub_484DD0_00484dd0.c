INT_PTR __stdcall sub_484DD0(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  char *v4; // eax
  LRESULT v6; // eax
  WPARAM v7; // esi
  HWND v8; // eax
  char *v9; // edi
  const CHAR *v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND DlgItem; // eax
  unsigned int v15; // kr00_4
  __int32 v16; // edi
  void (__stdcall *v17)(HWND, CHAR *, int); // edi
  WPARAM v18; // [esp+0h] [ebp-73Ch] BYREF
  LPARAM v19; // [esp+4h] [ebp-738h]
  void *Block; // [esp+14h] [ebp-728h]
  int v21; // [esp+1Ch] [ebp-720h] BYREF
  CHAR String[256]; // [esp+20h] [ebp-71Ch] BYREF
  _BYTE v23[527]; // [esp+120h] [ebp-61Ch] BYREF
  char v24; // [esp+32Fh] [ebp-40Dh] BYREF
  LPARAM lParam[256]; // [esp+330h] [ebp-40Ch] BYREF
  int v26; // [esp+738h] [ebp-4h]

  switch ( a2 )
  {
    case 2u:
LABEL_15:
      sub_484D30();
      return 0;
    case 0x110u:
      GetWindowTextA(hDlg, String, 255);
      strcpy(String, sub_41D840(&byte_91CC38, String));
      SetWindowTextA(hDlg, String);
      v19 = 0;
      v18 = (WPARAM)GetWindowTextA;
      v15 = __readeflags();
      v16 = dword_16C6F04 + 1420286465;
      __writeeflags(v15);
      v17 = (void (__stdcall *)(HWND, CHAR *, int))_InterlockedExchange((volatile __int32 *)&v18, v16);
      EnumChildWindows(hDlg, (WNDENUMPROC)v18, v19);
      v17(hDlg, byte_B6CD60, 255);
      SendDlgItemMessageA(hDlg, 1024, 0xC5u, 0x50u, 0);
      SendMessageA(hDlg, 0x401u, 0x3EFu, 0);
      v19 = 0;
      v18 = 2048;
      DlgItem = GetDlgItem(hDlg, 1034);
      SendMessageA(DlgItem, 0x194u, v18, v19);
      return 0;
    case 0x111u:
      if ( (unsigned __int16)a3 > 0x3EFu )
      {
        switch ( (unsigned __int16)a3 )
        {
          case 0x400u:
            if ( HIWORD(a3) == 768 )
            {
              v19 = SendDlgItemMessageA(hDlg, 1024, 0xC1u, 0, 0) > 0;
              v13 = GetDlgItem(hDlg, 1007);
              EnableWindow(v13, v19);
            }
            break;
          case 0x40Bu:
            v19 = 5;
            sub_484CD0();
            sub_47F650();
            break;
          case 0x4A1u:
            sub_484CD0();
            sub_481CB0(2);
            break;
        }
      }
      else if ( (unsigned __int16)a3 == 1007 )
      {
        if ( SendDlgItemMessageA(hDlg, 1024, 0xC1u, 0, 0) > 0 )
        {
          LOWORD(lParam[0]) = 1023;
          *((_BYTE *)lParam + SendDlgItemMessageA(hDlg, 1024, 0xC4u, 0, (LPARAM)lParam) + 1) = 0;
          v9 = &v24;
          while ( *++v9 )
            ;
          *(_WORD *)v9 = 32;
          sub_47F730();
          sub_615860(lParam);
          sub_47F760();
          SendDlgItemMessageA(hDlg, 1024, 0xCu, 0, (LPARAM)WindowName);
          sub_40D650();
          v26 = 1;
          sub_615A50("> ");
          sub_615A50(lParam);
          v11 = (const CHAR *)Block;
          if ( !Block )
            v11 = WindowName;
          sub_47F220((LPARAM)v11);
          v12 = GetDlgItem(hDlg, 1007);
          EnableWindow(v12, 0);
          if ( Block )
            j_j__free(Block);
        }
      }
      else if ( (unsigned __int16)a3 > 0x3EDu )
      {
        if ( (unsigned __int16)a3 == 1006 )
        {
          v6 = SendDlgItemMessageA(hDlg, 1033, 0x188u, 0, 0);
          v7 = v6;
          if ( v6 != -1 )
          {
            SendDlgItemMessageA(hDlg, 1033, 0x199u, v6, 0);
            SendDlgItemMessageA(hDlg, 1033, 0x182u, v7, 0);
            sub_4744D0(v23);
            v18 = (WPARAM)&v21;
            v26 = 0;
            if ( (unsigned __int8)sub_47A1A0() )
            {
              sub_474860(&dword_B6CBA8, v21, 0);
              v8 = GetDlgItem(hDlg, 1006);
              EnableWindow(v8, 0);
            }
            v26 = -1;
            nullsub_7(v23);
          }
        }
      }
      else
      {
        if ( (unsigned __int16)a3 == 1005 )
        {
          sub_484CD0();
          sub_481CB0(1);
          return 0;
        }
        if ( (_WORD)a3 && (unsigned __int16)a3 <= 2u )
        {
          if ( byte_B6CEA0 && byte_B6CBC3 )
          {
            v4 = (char *)dword_759EC0;
            if ( !dword_759EC0 )
              v4 = (char *)WindowName;
            CINet::LeaveRoom((CINet *)dword_B6CBB0, v4);
            CINet::Logout((CINet *)dword_B6CBB0);
          }
          goto LABEL_15;
        }
      }
      break;
  }
  return 0;
}
