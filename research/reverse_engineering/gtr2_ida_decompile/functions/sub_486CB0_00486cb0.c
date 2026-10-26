DWORD __stdcall sub_486CB0(LPVOID lpThreadParameter)
{
  char v1; // bl
  const CHAR *v2; // ecx
  const CHAR *v3; // eax
  char *v4; // eax
  const CHAR *v5; // ecx
  const CHAR *v6; // eax
  char *v7; // eax
  const CHAR *v8; // ecx
  const CHAR *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  _DWORD *v15; // eax
  int v16; // eax
  _DWORD *v17; // ecx
  bool v18; // zf
  const char *v19; // ecx
  const char *v20; // eax
  const char *v21; // eax
  HWND DlgItem; // eax
  char *v24; // [esp+12h] [ebp-23Ch]
  const char *v25; // [esp+12h] [ebp-23Ch]
  char *v26; // [esp+12h] [ebp-23Ch]
  char *v27; // [esp+12h] [ebp-23Ch]
  char *v28; // [esp+16h] [ebp-238h]
  char *v29; // [esp+16h] [ebp-238h]
  char *v30; // [esp+16h] [ebp-238h]
  char v31; // [esp+34h] [ebp-21Ah]
  char v32; // [esp+35h] [ebp-219h]
  bool IsSubscriptionServer; // [esp+36h] [ebp-218h]
  char v34[61]; // [esp+3Eh] [ebp-210h] BYREF
  __int16 v35; // [esp+7Bh] [ebp-1D3h]
  char v36; // [esp+7Dh] [ebp-1D1h]
  _BYTE v37[64]; // [esp+7Eh] [ebp-1D0h] BYREF
  char v38[128]; // [esp+BEh] [ebp-190h] BYREF
  char v39[252]; // [esp+13Eh] [ebp-110h] BYREF
  __int16 v40; // [esp+23Ah] [ebp-14h]
  char v41; // [esp+23Ch] [ebp-12h]
  int v42; // [esp+24Ah] [ebp-4h]

  CINet::SetConnectionClosedCallback((CINet *)dword_B6CBB0, 0);
  v1 = 0;
  v31 = 0;
  v32 = 0;
  do
  {
    while ( 1 )
    {
      v2 = (const CHAR *)lpData;
      if ( !lpData )
        v2 = WindowName;
      v3 = *(const CHAR **)dword_759EE0;
      if ( !*(_DWORD *)dword_759EE0 )
        v3 = WindowName;
      v28 = (char *)v2;
      v24 = (char *)v3;
      v4 = (char *)sub_486C40();
      switch ( CINet::ReLogin((CINet *)dword_B6CBB0, v4, v24, v28, 1) )
      {
        case 0:
          v1 = 1;
          v31 = 1;
          goto LABEL_32;
        case 2:
          v1 = 1;
          v25 = "An update to GTR2 is required. Cannot Broadcast to Lobby.";
          goto LABEL_60;
        case 5:
          v1 = 1;
LABEL_12:
          v25 = "Login Failed: Invalid CD-Key. Cannot Broadcast to Lobby.";
          goto LABEL_60;
        case 7:
          v1 = 1;
          v25 = "Login Failed: General Error!  Cannot Broadcast to Lobby.";
          goto LABEL_60;
        case 8:
          v5 = (const CHAR *)lpData;
          if ( !lpData )
            v5 = WindowName;
          v6 = *(const CHAR **)dword_759EE0;
          if ( !*(_DWORD *)dword_759EE0 )
            v6 = WindowName;
          v29 = (char *)v5;
          v26 = (char *)v6;
          v7 = (char *)sub_486C40();
          switch ( CINet::Register((CINet *)dword_B6CBB0, v7, v26, v29, (char *)WindowName) )
          {
            case 0:
              v8 = (const CHAR *)lpData;
              if ( !lpData )
                v8 = WindowName;
              v9 = *(const CHAR **)dword_759EE0;
              if ( !*(_DWORD *)dword_759EE0 )
                v9 = WindowName;
              v30 = (char *)v8;
              v27 = (char *)v9;
              v10 = (char *)sub_486C40();
              if ( CINet::ReLogin((CINet *)dword_B6CBB0, v10, v27, v30, 1) )
                goto LABEL_31;
              v1 = 1;
              v31 = 1;
              goto LABEL_32;
            case 1:
              v11 = sub_41D840(
                      &byte_91CC38,
                      "Registration Failed: Could not connect to the server ! Cannot Broadcast to Lobby");
              goto LABEL_28;
            case 2:
              v11 = sub_41D840(&byte_91CC38, "An update to GTR2 is required. Cannot Broadcast to Lobby.");
              goto LABEL_28;
            case 3:
              v11 = sub_41D840(&byte_91CC38, "Login Failed. Incorrect Password ! Cannot Broadcast to Lobby");
              goto LABEL_28;
            case 5:
              goto LABEL_12;
            case 6:
              v25 = "Registration Failed ! Cannot Broadcast to Lobby";
              goto LABEL_60;
            case 0xA:
              v11 = sub_41D840(&byte_91CC38, "Could not find server !  Cannot Broadcast to Lobby.");
LABEL_28:
              MessageBoxA(0, v11, byte_B6CD60, 0);
              v1 = 1;
              break;
            default:
              goto LABEL_31;
          }
          break;
        case 9:
          v1 = 1;
          v25 = "Login Failed: CD-Key already online. Cannot Broadcast to Lobby.";
LABEL_60:
          v12 = sub_41D840(off_16C9A08[0], v25);
          MessageBoxA(0, v12, byte_B6CD60, 0);
          break;
        default:
          break;
      }
LABEL_31:
      if ( v31 != 1 )
        break;
LABEL_32:
      while ( CINet::PopulatingRooms((CINet *)dword_B6CBB0) )
        ;
      v13 = (char *)dword_759EC0;
      if ( !dword_759EC0 )
        v13 = (char *)WindowName;
      if ( !CINet::RoomExists((CINet *)dword_B6CBB0, v13) )
      {
        v31 = 1;
        break;
      }
      if ( v32 )
      {
        v14 = sub_41D840(
                &byte_91CC38,
                "A room with the same name already exists in the lobby. Cannot Broadcast to Lobby.");
        MessageBoxA(0, v14, byte_B6CD60, 0);
        CINet::Logout((CINet *)dword_B6CBB0);
        v31 = 0;
        break;
      }
      v32 = 1;
      v1 = 0;
      CINet::Logout((CINet *)dword_B6CBB0);
      Sleep(0x7530u);
    }
  }
  while ( !v1 );
  if ( v31 )
    CINet::SetConnectionClosedCallback((CINet *)dword_B6CBB0, sub_487190);
  else
    byte_B6CBC3 = 0;
  sub_4744E0(v37);
  v42 = 0;
  sub_4747D0(&dword_B6CBA8, (int)v37, 0);
  v15 = *(_DWORD **)(sub_484CD0() + 8);
  if ( v15 && *v15
    || (v16 = sub_484CD0(), v17 = *(_DWORD **)v16,
                            v18 = *(_DWORD *)v16 == 0,
                            *(_DWORD *)(v16 + 8) = *(_DWORD *)v16,
                            !v18)
    && *v17 )
  {
    memset(v39, 0, sizeof(v39));
    v19 = (const char *)dword_759EC0;
    v40 = 0;
    v41 = 0;
    v20 = (const char *)dword_759EC0;
    if ( !dword_759EC0 )
      v20 = WindowName;
    if ( strlen(v20) )
    {
      if ( !dword_759EC0 )
        v19 = WindowName;
    }
    else
    {
      v19 = *(const char **)dword_759ED8;
      if ( !*(_DWORD *)dword_759ED8 )
        v19 = WindowName;
    }
    strcpy(v39, v19);
    IsSubscriptionServer = CINet::IsSubscriptionServer((CINet *)dword_B6CBB0);
    memset(v34, 0, sizeof(v34));
    v35 = 0;
    v36 = 0;
    sub_53A410(&unk_BE1CFD, v34, 63);
    v21 = (const char *)dword_759EC8;
    if ( !dword_759EC8 )
      v21 = WindowName;
    CINet::CreateRoom(
      (CINet *)dword_B6CBB0,
      IsSubscriptionServer,
      v39,
      v34,
      *(_DWORD *)dword_759E90,
      *(_DWORD *)dword_B6CE9C,
      byte_759E9C,
      v38,
      *(_DWORD *)dword_759E4C + 1,
      &v21[strlen(v21) + 1] != v21 + 1,
      dword_B6CE60,
      dword_B73294,
      dword_B706CC,
      dword_B73000,
      dword_B72EBC,
      dword_B70588,
      dword_B6FE20,
      dword_B73348,
      1,
      0,
      0);
    *(_DWORD *)(sub_484CD0() + 868) = 3;
    DlgItem = GetDlgItem(hDlg, 1185);
    EnableWindow(DlgItem, 0);
  }
  v42 = -1;
  nullsub_7(v37);
  return 0;
}
