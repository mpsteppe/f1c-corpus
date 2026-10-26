int __thiscall sub_4AA390(int this, int a2, const char *a3)
{
  int v3; // ebp
  int v5; // ecx
  __int16 v6; // bp
  const char *v8; // [esp-10h] [ebp-12Ch]
  _DWORD v9[4]; // [esp+Ch] [ebp-110h]
  CHAR Text[253]; // [esp+1Ch] [ebp-100h] BYREF
  __int16 v11; // [esp+119h] [ebp-3h]
  char v12; // [esp+11Bh] [ebp-1h]

  v3 = a2;
  if ( a2 > 1 )
  {
    Text[0] = byte_629120;
    memset(&Text[1], 0, 0xFCu);
    v5 = *(_DWORD *)(this + 468);
    v11 = 0;
    v9[0] = aUndefinedError;
    v9[1] = aWarning;
    v9[2] = aError;
    v9[3] = aCriticalError;
    v8 = (const char *)v9[a2];
    v12 = 0;
    sprintf(Text, "OSC %s on line %d : ", v8, v5);
    if ( a3 )
    {
      v6 = *(_WORD *)word_5FD024;
      *(_WORD *)&Text[strlen(Text)] = *(_WORD *)word_5FD024;
      strcat(Text, a3);
      *(_WORD *)&Text[strlen(Text)] = v6;
      v3 = a2;
      *(_WORD *)&Text[strlen(Text)] = *(_WORD *)asc_5FB9D8;
    }
    if ( *(_DWORD *)(this + 56) )
      goto LABEL_8;
    if ( (unsigned __int8)sub_57A110((char *)(this + 340), 0, 1, 1) )
      sub_57A5B0(0);
    if ( *(_DWORD *)(this + 56) )
LABEL_8:
      sub_57A400(this + 56, aS_5, (char)Text);
    if ( v3 == 3 || v3 == 2 )
    {
      if ( !*(_DWORD *)(this + 492) )
      {
        MessageBoxA(0, Text, Caption, 0);
        exit(1);
      }
      sub_4AE6B0(Text);
    }
  }
  return 0;
}
