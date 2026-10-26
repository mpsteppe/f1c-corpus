int __thiscall sub_4A04E0(_DWORD **this)
{
  int v2; // edx
  int result; // eax
  char v4[8]; // [esp+24h] [ebp-210h] BYREF
  unsigned int v6; // [esp+30h] [ebp-204h] BYREF
  char v7[252]; // [esp+34h] [ebp-200h] BYREF
  __int16 v8; // [esp+130h] [ebp-104h]
  char v9; // [esp+132h] [ebp-102h]

  v2 = sub_4CE1B0(this);
  result = 0;
  if ( v2 >= 0 )
  {
    memset(v7, 0, sizeof(v7));
    v8 = 0;
    v9 = 0;
    strcpy(v7, (const char *)sub_4CE2D0(v2));
    v6 = strlen(v7);
    if ( v6 )
      v7[strlen(v7) - 1] = 0;
    if ( strlen(CINet::GetChatRoomPassword((CINet *)dword_B6CBB0, v7)) )
    {
      sub_4CD6D0("ONLINE CLIENT CHAT PASSWORD ENTRY");
      return 0;
    }
    else if ( CINet::JoinChatRoom((CINet *)dword_B6CBB0, (char *)&v6) )
    {
      return 0;
    }
    else
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090) )
        sub_4D0AC0(37);
      CINet::GetDriverList((CINet *)dword_B6CBB0);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090) )
        sub_4D0AC0(34);
      CINet::GetChatRoomMessage((CINet *)dword_B6CBB0, v4);
      CINet::GetPendingChat((CINet *)dword_B6CBB0);
      (*(void (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 26);
      sub_41D840(&byte_91CC38, "CHATBOX - ");
      return off_16C9590();
    }
  }
  return result;
}
