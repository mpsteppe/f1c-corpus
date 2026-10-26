char __thiscall sub_523AE0(_BYTE *this)
{
  char *v1; // eax
  char *v2; // edi
  char *v4; // edx
  char *v5; // edi
  char v8; // [esp-1h] [ebp-51h] BYREF
  char v9[77]; // [esp+0h] [ebp-50h] BYREF
  __int16 v10; // [esp+4Dh] [ebp-3h]
  char v11; // [esp+4Fh] [ebp-1h]

  LOBYTE(v1) = this[4];
  if ( !(_BYTE)v1 && *(_DWORD *)this == 1 )
  {
    LOBYTE(v1) = sub_4735A0();
    if ( !(_BYTE)v1 )
    {
      memset(v9, 0, sizeof(v9));
      v10 = 0;
      v11 = 0;
      strcpy(v9, sub_41D840(&byte_91CC38, "Replay Activation"));
      v2 = &v8;
      while ( *++v2 )
        ;
      *(_WORD *)v2 = 32;
      v1 = sub_463820(&dword_B74AA0);
      if ( v1 )
      {
        v4 = sub_41D840(&byte_91CC38, v1);
        v1 = (char *)(strlen(v4) + 1);
        v5 = &v8;
        while ( *++v5 )
          ;
        qmemcpy(v5, v4, (unsigned int)v1);
      }
    }
  }
  return (char)v1;
}
