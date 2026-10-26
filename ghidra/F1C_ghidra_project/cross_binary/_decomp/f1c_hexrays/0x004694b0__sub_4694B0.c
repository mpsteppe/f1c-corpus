// f1c  0x004694b0  size=152
char *__thiscall sub_4694B0(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  const char **v5; // eax
  const char *v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // kr04_4
  _BYTE *v9; // eax
  bool v10; // cf

  v3 = a2;
  if ( a2 < 0 || a2 >= *(_DWORD *)(this + 1104) )
    return byte_5EA438;
  v4 = *(_DWORD *)(this + 1092);
  if ( a2 > 0 )
  {
    while ( v4 )
    {
      v4 = *(_DWORD *)(v4 + 4);
      if ( --v3 <= 0 )
        goto LABEL_6;
    }
    return byte_5EA438;
  }
LABEL_6:
  if ( !v4 )
    return byte_5EA438;
  v5 = *(const char ***)v4;
  if ( !v5 )
    return byte_5EA438;
  v6 = *v5;
  if ( !*v5 )
    v6 = byte_5EA438;
  v7 = this + 836;
  strcpy((char *)(this + 836), v6);
  v8 = strlen((const char *)(this + 836)) + 1;
  if ( (int)(v8 - 1) > 0 )
  {
    v9 = (_BYTE *)(v8 - 1 + this + 836);
    if ( (unsigned int)v9 >= v7 )
    {
      do
      {
        if ( *v9 == 92 )
          break;
        v10 = (unsigned int)v9 < v7;
        *v9 = 0;
        if ( (unsigned int)v9 > v7 )
          v10 = (unsigned int)--v9 < v7;
      }
      while ( !v10 );
    }
  }
  return (char *)(this + 836);
}
