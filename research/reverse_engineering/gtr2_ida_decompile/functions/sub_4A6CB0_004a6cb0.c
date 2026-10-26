int __thiscall sub_4A6CB0(_DWORD **this)
{
  char *v2; // eax
  unsigned int v3; // eax
  char *v4; // edi
  char *v6; // edi
  char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char *v12; // ecx
  unsigned int v13; // eax
  char *v14; // esi
  char *v15; // edi
  int v18; // [esp+4h] [ebp-308h]
  char v19; // [esp+Bh] [ebp-301h] BYREF
  char v20[256]; // [esp+Ch] [ebp-300h] BYREF
  char Buffer[256]; // [esp+10Ch] [ebp-200h] BYREF
  char v22[256]; // [esp+20Ch] [ebp-100h] BYREF

  CINet::ChatTo((CINet *)dword_B6CBB0, (char *)WindowName);
  if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 26) )
  {
    if ( dword_B71F90 )
    {
      if ( dword_B71F90 == 1 )
      {
        sprintf(Buffer, "MAIN-SP");
      }
      else if ( dword_B71F90 == 2 )
      {
        sprintf(Buffer, "MAIN-SIM");
      }
    }
    else
    {
      sprintf(Buffer, "MAIN-NOV");
    }
    v2 = sub_41D840(&byte_91CC38, "NEWS_LANGUAGE");
    sprintf(v22, "%s (%s)", Buffer, v2);
    CINet::JoinChatRoom((CINet *)dword_B6CBB0, v22);
    strcpy(v20, sub_41D840(&byte_91CC38, "CHATBOX - "));
    v3 = strlen(Buffer) + 1;
    v4 = &v19;
    while ( *++v4 )
      ;
    qmemcpy(v4, Buffer, v3);
    v6 = &v19;
    while ( *++v6 )
      ;
    strcpy(v6, " (");
    v8 = sub_41D840(&byte_91CC38, "NEWS_LANGUAGE");
    v9 = strlen(v8) + 1;
    v10 = &v19;
    while ( *++v10 )
      ;
    qmemcpy(v10, v8, v9);
    v12 = sub_41D840(&byte_91CC38, (const char *)&word_6FBE80);
    v13 = strlen(v12) + 1;
    v14 = v12;
    v15 = &v19;
    while ( *++v15 )
      ;
    qmemcpy(v15, v14, v13);
    sub_615860(v20);
    if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 34) )
    {
      sub_4D0AC0(v18);
      CINet::GetChatRoomMessage((CINet *)dword_B6CBB0, v22);
      CINet::GetPendingChat((CINet *)dword_B6CBB0);
    }
  }
  return 0;
}
