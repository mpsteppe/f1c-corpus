int __thiscall sub_4A66B0(_DWORD *this)
{
  int *v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // edx
  char *v7; // eax
  int v8; // eax
  char *v9; // eax
  int result; // eax
  char *v11; // eax
  char *v12; // eax
  HKEY phkResult; // [esp+0h] [ebp-4Ch] BYREF
  HKEY hKey; // [esp+4h] [ebp-48h] BYREF
  int v15; // [esp+28h] [ebp-24h]
  int v16; // [esp+2Ch] [ebp-20h]
  int v17; // [esp+30h] [ebp-1Ch]
  int v18; // [esp+34h] [ebp-18h]
  char *v19; // [esp+38h] [ebp-14h]

  v19 = sub_41D840(&byte_91CC38, "Please wait...");
  sub_4EB900(off_16C9B58, v19);
  sub_615860(byte_B6DFF0);
  sub_615860(&byte_B6E010);
  v2 = (int *)this[12];
  v3 = *v2;
  v18 = 34;
  if ( (*(int (__thiscall **)(int *))(v3 + 28))(v2) )
    sub_4D0AC0(v18);
  v4 = *(_DWORD *)dword_B6E090;
  v17 = 25;
  if ( (*(int (__thiscall **)(int))(v4 + 28))(dword_B6E090) )
    sub_4D0AC0(v17);
  v5 = *(_DWORD *)dword_B6E090;
  v16 = 24;
  if ( (*(int (__thiscall **)(int))(v5 + 28))(dword_B6E090) )
    sub_4D0AC0(v16);
  v6 = *(_DWORD *)dword_B6E090;
  v15 = 35;
  if ( (*(int (__thiscall **)(int))(v6 + 28))(dword_B6E090) )
    sub_4D0AC0(v15);
  v7 = (char *)dword_B7384C;
  if ( !dword_B7384C )
    v7 = (char *)WindowName;
  CINet::SetServerName((CINet *)dword_B6CBB0, v7);
  CINet::SetDifficulty((CINet *)dword_B6CBB0, dword_B72338);
  CINet::SetLobbyTimeout((CINet *)dword_B6CBB0, (unsigned __int16)word_B733E4);
  if ( dword_B6CBBC || byte_B6CBC1 )
    v8 = CINet::SetupsLogin((CINet *)dword_B6CBB0, byte_B6DFF0, &byte_B6E010, byte_B6DFD0, 0);
  else
    v8 = CINet::Login((CINet *)dword_B6CBB0, byte_B6DFF0, &byte_B6E010, byte_B6DFD0, 0, 1, 1, 1, 1, (char *)WindowName);
  switch ( v8 )
  {
    case 0:
      if ( dword_B6CBBC )
      {
        byte_B6CBC0 = 1;
        v9 = sub_41D840(&byte_91CC38, "Please Wait...");
        sub_4EB900(&unk_B6F134, v9);
        sub_4DF020(this[12]);
        if ( dword_B6CBBC == 1 )
        {
          sub_4E1810("GARAGEONLINEPAGE", 0);
          return 0;
        }
        else
        {
          if ( dword_B6CBBC != 2 )
            goto LABEL_41;
          sub_4E1810("TIMETRIAL_ONLINE_PAGE", 0);
          return 0;
        }
      }
      else
      {
        if ( byte_B6CBC1 )
        {
          sub_4CD6D0("SUMMARY_MPLIST");
          byte_B6CBC2 = 1;
          sub_46AD90();
          sub_615860(byte_B6DC70);
        }
        else
        {
          byte_B6CBC3 = 1;
          sub_4CD6D0("LOGIN_SUCCESSFUL");
        }
        return 0;
      }
    case 1:
      v11 = sub_41D840(&byte_91CC38, "Could not connect to the server !");
      goto LABEL_31;
    case 2:
      sub_4CD6D0("LOBBY UPDATE PAGE");
      return 0;
    case 5:
      v12 = sub_41D840(&byte_91CC38, "Registration Failed: Invalid CD Key !");
      sub_615860(v12);
      if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB", &phkResult) )
        RegCloseKey(phkResult);
      if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2", &phkResult) )
        RegCloseKey(phkResult);
      if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &phkResult) )
        RegCloseKey(phkResult);
      if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\SBDT AB\\GTR2\\Keys", &hKey) )
      {
        RegDeleteValueA(hKey, "SerialNumber");
        RegCloseKey(hKey);
      }
      sub_4CD6D0("JOIN FAILURE PAGE");
      goto LABEL_41;
    case 7:
      v11 = sub_41D840(&byte_91CC38, "Login Failed: General Error!");
      goto LABEL_31;
    case 8:
      v11 = sub_41D840(&byte_91CC38, "Login Failed: Invalid Username/Password !");
      goto LABEL_31;
    case 9:
      v11 = sub_41D840(&byte_91CC38, "Login Failed: CD-Key already online.");
      goto LABEL_31;
    case 10:
      v11 = sub_41D840(&byte_91CC38, "Could not find server !");
LABEL_31:
      sub_615860(v11);
      sub_4CD6D0("JOIN FAILURE PAGE");
      result = 0;
      break;
    default:
LABEL_41:
      result = 0;
      break;
  }
  return result;
}
