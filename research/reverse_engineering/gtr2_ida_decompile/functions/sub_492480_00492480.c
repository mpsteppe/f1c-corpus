int __thiscall sub_492480(_DWORD **this)
{
  int v2; // eax
  char *v3; // edx
  char v4; // cl
  bool v5; // zf
  char *v6; // eax
  unsigned int v7; // eax
  char *v8; // edi
  int v11; // [esp+0h] [ebp-218h]
  int v12; // [esp+10h] [ebp-208h] BYREF
  _BYTE v13[4]; // [esp+14h] [ebp-204h] BYREF
  char v14[252]; // [esp+18h] [ebp-200h] BYREF
  __int16 v15; // [esp+114h] [ebp-104h]
  char v16; // [esp+116h] [ebp-102h]
  char v17; // [esp+117h] [ebp-101h] BYREF
  char v18[256]; // [esp+118h] [ebp-100h] BYREF

  sub_4DE540(&v12, v13);
  v2 = ((int (__thiscall *)(_DWORD **))(*this)[1])(this);
  if ( v12 < v2 && sub_4CE1B0(this) >= 0 )
  {
    v3 = (char *)sub_4CE170(this);
    if ( v3 )
    {
      memset(v14, 0, sizeof(v14));
      v4 = *v3;
      v5 = *v3 == 9;
      v15 = 0;
      v16 = 0;
      if ( !v5 )
      {
        v6 = v3;
        do
        {
          v6[v14 - v3] = v4;
          v4 = *++v6;
        }
        while ( v4 != 9 );
      }
      if ( strcmp((const char *)(dword_B6CBB0 + 1080), v14) )
      {
        if ( CINet::CanChatTo((CINet *)dword_B6CBB0, v14) )
        {
          if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 26) )
          {
            strcpy(v18, sub_41D840(&byte_91CC38, "CHATBOX - Chatting to - "));
            v7 = strlen(v14) + 1;
            v8 = &v17;
            while ( *++v8 )
              ;
            qmemcpy(v8, v14, v7);
            sub_615860(v18);
            CINet::ChatTo((CINet *)dword_B6CBB0, v14);
            if ( CINet::NewDriverChat((CINet *)dword_B6CBB0, v14) )
            {
              if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 34) )
                sub_4D0AC0(v11);
            }
          }
        }
      }
    }
  }
  return 0;
}
