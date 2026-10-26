char *__thiscall sub_65DC2C(_DWORD *this, char *a2, _DWORD *a3)
{
  char *i; // edi
  int v7; // [esp+Ch] [ebp-4h]
  int v8; // [esp+18h] [ebp+8h]

  v7 = 0;
  v8 = 0;
  for ( i = a2; (unsigned int)i < this[1]; ++i )
  {
    if ( v8 || sub_635155(*i) != 117 )
    {
      if ( v7 || sub_635155(*i) != 108 )
        break;
      v7 = 1;
    }
    else
    {
      v8 = 1;
    }
  }
  if ( a3 )
  {
    if ( v8 )
    {
      *a3 = 4;
    }
    else if ( v7 )
    {
      *a3 = 3;
    }
  }
  return (char *)(i - a2);
}
