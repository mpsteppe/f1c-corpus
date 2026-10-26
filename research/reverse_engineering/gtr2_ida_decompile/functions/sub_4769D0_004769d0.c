char __thiscall sub_4769D0(int this)
{
  int v2; // ebp
  char v3; // al
  char v4; // dl
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  char v8; // cl
  int v9; // eax
  char *v10; // eax
  char result; // al
  char *v12; // edi
  const char *v13; // eax
  unsigned int v14; // kr00_4
  unsigned int v15; // ebx
  float v16; // [esp+0h] [ebp-98h] BYREF
  char v17[136]; // [esp+10h] [ebp-88h] BYREF

  if ( *(_BYTE *)(this + 2153) )
  {
    v2 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v2 >= ((dword_B698E8 & 4) != 0 ? dword_B6A2F4 : 0) )
        {
          if ( !*(_BYTE *)(this + 2153) )
          {
            v10 = sub_41D840(&byte_91CC38, "Chat:");
            sub_472920((const char **)&dword_B6CB98, v10, 1);
          }
          goto LABEL_24;
        }
        if ( word_B6A2F8[v2] != 1 )
          break;
        sub_45EAE0(1);
        if ( *(_BYTE *)(this + 2153) )
        {
          v9 = *(_DWORD *)(this + 2224);
          *(_BYTE *)(this + 2153) = 0;
          dword_B698E8 = v9;
          sub_461600((char *)&dword_B69668);
        }
LABEL_18:
        ++v2;
      }
      if ( word_B6A2F8[v2] == 14 )
      {
        v7 = strlen((const char *)(this + 2154));
        if ( v7 <= 0 )
          goto LABEL_18;
        *(_BYTE *)(this + v7 + 2153) = v8;
        ++v2;
      }
      else if ( word_B6A2F8[v2] == 28 )
      {
        if ( *(_BYTE *)(this + 2154) )
          sub_476670();
        if ( !*(_BYTE *)(this + 2153) )
          goto LABEL_18;
        v6 = *(_DWORD *)(this + 2224);
        *(_BYTE *)(this + 2153) = 0;
        dword_B698E8 = v6;
        sub_461600((char *)&dword_B69668);
        ++v2;
      }
      else
      {
        v3 = sub_45E670();
        if ( v3 < 32 )
          goto LABEL_18;
        v5 = strlen((const char *)(this + 2154));
        if ( v5 >= 69 )
          goto LABEL_18;
        *(_BYTE *)(this + 2154 + v5) = v3;
        *(_BYTE *)(v5 + this + 2155) = v4;
        ++v2;
      }
    }
  }
  if ( dword_B6BFE4 && !byte_B6F118 )
    sub_474060();
LABEL_24:
  result = *(_BYTE *)(this + 2153);
  if ( result )
  {
    v16 = dbl_FB1D20 + dbl_FB1D20;
    v16 = COERCE_FLOAT(sub_4015C0(v16));
    v14 = __readeflags();
    v15 = ~dword_16C6E38 ^ 0xA75425FF;
    __writeeflags(v14);
    LOBYTE(v15) = _InterlockedExchange((volatile __int32 *)&v16, v15) & 1;
    v12 = sub_41D840(&byte_91CC38, (const char *)LODWORD(v16));
    v13 = (const char *)&word_6F66E4;
    if ( !(_BYTE)v15 )
      v13 = CommandLine;
    sub_632041(v17, 133, "%s %s%s", v12, (const char *)(this + 2154), v13);
    v17[133] = 0;
    sub_472920((const char **)&dword_B6CB98, v12, 1);
    return sub_4730C0((int **)&dword_B6CB98, v17, 0, (int)&unk_F0F0F0, 1084227584);
  }
  return result;
}
