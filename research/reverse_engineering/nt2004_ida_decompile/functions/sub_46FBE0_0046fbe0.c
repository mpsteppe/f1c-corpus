_DWORD *__thiscall sub_46FBE0(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  int i; // edi
  int v7; // eax
  const char *v8; // eax
  char Destination[64]; // [esp+4h] [ebp-40h] BYREF

  result = (_DWORD *)this[210];
  if ( result )
  {
    v3 = this[211];
    if ( *result <= v3 )
    {
      if ( *result < this[212] )
        *result = v3;
    }
    else
    {
      *result = this[212];
    }
    v4 = this[212];
    v5 = this[211];
    for ( i = 0; v4 <= v5; ++i )
    {
      if ( *(_DWORD *)this[210] <= v4 )
        break;
      v4 += this[213];
    }
    v7 = sub_4AF0A0(this) - 1;
    if ( v7 < 0 )
      v7 = 0;
    if ( i >= 0 )
    {
      if ( i > v7 )
        i = v7;
    }
    else
    {
      i = 0;
    }
    v8 = (const char *)sub_49D690(i);
    strncpy(Destination, v8, 0x3Fu);
    Destination[63] = 0;
    return (_DWORD *)sub_4A1AC0(Destination);
  }
  return result;
}
