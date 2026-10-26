int __thiscall sub_5924D0(void *this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  int v4; // ebx
  char v6; // cl
  FILE *v7; // esi
  bool v8; // zf
  const char *v9; // edi
  void *v11; // eax
  _DWORD *v12; // esi
  int v13; // eax
  size_t v14; // ecx
  size_t i; // eax
  int v16; // [esp+10h] [ebp-214h]
  char v17[16]; // [esp+14h] [ebp-210h] BYREF
  char String[256]; // [esp+24h] [ebp-200h] BYREF
  char Buffer[256]; // [esp+124h] [ebp-100h] BYREF

  v3 = a3;
  v4 = 0;
  v16 = 0;
  if ( !a3 || !*a3 )
    return v16;
  do
  {
    v6 = *v3;
    v3[String - a3] = *v3;
    ++v3;
  }
  while ( v6 );
  _strupr(String);
  v7 = fopen(String, aRb);
  if ( !v7 )
  {
    v8 = dword_7E8D58 == 0;
    if ( dword_7E8D58 > 0 )
    {
      v9 = byte_7E4CCC;
      do
      {
        sprintf(Buffer, "%s\\%s", v9, String);
        v7 = fopen(Buffer, aRb);
        if ( v7 )
          break;
        ++v4;
        v9 += 132;
      }
      while ( v4 < dword_7E8D58 );
      v8 = v4 == dword_7E8D58;
    }
    if ( v8 )
    {
      sprintf(Buffer, "Error opening MAS file %s", String);
      sub_591C60((int)this, -2, Buffer);
      return -2;
    }
  }
  sub_5BED6F(v17, 1u, 0xCu, v7);
  fclose(v7);
  if ( !strcmp(v17, aCubemas410) )
  {
    v11 = operator new(0x134u);
    if ( v11 )
      v12 = (_DWORD *)sub_5AEAF0(v11);
    else
      v12 = 0;
    v13 = sub_5AEB50(v12, (int)String);
    switch ( v13 )
    {
      case -2:
        if ( v12 )
        {
          j_nullsub_6(v12);
          sub_5BE8AE();
        }
        v16 = -2;
        break;
      case -1:
        if ( v12 )
        {
          j_nullsub_6(v12);
          sub_5BE8AE();
        }
        v16 = -1;
        break;
      case 0:
        v14 = ElementCount;
        if ( ElementCount )
        {
          for ( i = *(_DWORD *)(ElementCount + 304); i; i = *(_DWORD *)(i + 304) )
            v14 = i;
          *(_DWORD *)(v14 + 304) = v12;
          v12[75] = v14;
        }
        else
        {
          ElementCount = (size_t)v12;
        }
        ++dword_7E5D54;
        v16 = 0;
        break;
    }
    if ( a2 )
      *a2 = v12;
    return v16;
  }
  if ( strcmp(v17, aCubemas400) && strcmp(v17, aCubemas401) )
    return v16;
  sub_591C60((int)this, -2, aIncorrectMasFi);
  return -1;
}
