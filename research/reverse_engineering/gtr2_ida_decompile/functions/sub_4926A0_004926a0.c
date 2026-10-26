int __thiscall sub_4926A0(_DWORD *this)
{
  unsigned int v2; // eax
  char *v3; // edi
  int v6; // [esp+14h] [ebp-104h] BYREF
  char v7[256]; // [esp+18h] [ebp-100h] BYREF

  sub_4DF020(this[12]);
  if ( !CINet::CreateChatRoom((CINet *)dword_B6CBB0, byte_B6DF30, byte_B6DF40, byte_B6DF50)
    && !CINet::JoinChatRoom((CINet *)dword_B6CBB0, byte_B6DF30) )
  {
    if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 34) )
      sub_4D0AC0(v6);
    (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)this[12] + 28))(this[12], 26);
    strcpy(v7, sub_41D840(&byte_91CC38, "CHATBOX - "));
    v2 = strlen(byte_B6DF30) + 1;
    v3 = (char *)&v6 + 3;
    while ( *++v3 )
      ;
    qmemcpy(v3, byte_B6DF30, v2);
    sub_615860(v7);
  }
  return 0;
}
