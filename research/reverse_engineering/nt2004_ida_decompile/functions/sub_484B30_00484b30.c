_DWORD *__thiscall sub_484B30(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // edx
  int v4; // ecx
  bool v5; // cc
  const char *v6; // eax
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
    switch ( *(_DWORD *)this[210] )
    {
      case 0:
        v4 = dword_76AD58;
        dword_76AD4C = 0;
        if ( dword_76AD54 <= 0 )
        {
          v5 = dword_76AD58 < 0;
          goto LABEL_22;
        }
        dword_76AD4C = dword_76AD54;
        break;
      case 1:
        v4 = dword_76AD58;
        dword_76AD4C = 1;
        if ( dword_76AD54 <= 1 )
        {
          v5 = dword_76AD58 < 1;
          goto LABEL_22;
        }
        dword_76AD4C = dword_76AD54;
        break;
      case 2:
        v4 = dword_76AD58;
        dword_76AD4C = 2;
        if ( dword_76AD54 <= 2 )
        {
          v5 = dword_76AD58 < 2;
          goto LABEL_22;
        }
        dword_76AD4C = dword_76AD54;
        break;
      case 3:
        v4 = dword_76AD58;
        dword_76AD4C = 3;
        if ( dword_76AD54 <= 3 )
        {
          v5 = dword_76AD58 < 3;
          goto LABEL_22;
        }
        dword_76AD4C = dword_76AD54;
        break;
      case 4:
        v4 = dword_76AD58;
        dword_76AD4C = 4;
        if ( dword_76AD54 <= 4 )
        {
          v5 = dword_76AD58 < 4;
LABEL_22:
          if ( v5 )
            dword_76AD4C = v4;
        }
        else
        {
          dword_76AD4C = dword_76AD54;
        }
        break;
      default:
        break;
    }
    v6 = (const char *)sub_49D690(*(_DWORD *)this[210]);
    strncpy(Destination, v6, 0x3Fu);
    Destination[63] = 0;
    return (_DWORD *)sub_4A1AC0(Destination);
  }
  return result;
}
