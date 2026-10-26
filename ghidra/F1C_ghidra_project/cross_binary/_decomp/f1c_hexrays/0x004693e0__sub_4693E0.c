// f1c  0x004693e0  size=204
char *__thiscall sub_4693E0(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  const char **v5; // eax
  const char *v6; // esi
  unsigned int v7; // edx
  _BYTE *v8; // eax
  char *result; // eax

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
  v8 = (_BYTE *)(strlen((const char *)(this + 836)) + this + 836);
  if ( (unsigned int)v8 > this + 836 )
  {
    while ( *v8 != 46 )
    {
      if ( (unsigned int)--v8 <= v7 )
        goto LABEL_15;
    }
    *v8 = 0;
  }
LABEL_15:
  result = (char *)(strlen((const char *)(this + 836)) + this + 836);
  if ( (unsigned int)result > v7 )
  {
    while ( *result != 92 )
    {
      if ( (unsigned int)--result <= v7 )
        return result;
    }
    ++result;
  }
  return result;
}
