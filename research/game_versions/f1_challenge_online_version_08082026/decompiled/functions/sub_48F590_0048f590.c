int __thiscall sub_48F590(_DWORD *this)
{
  int v1; // edx
  _DWORD *v2; // eax

  v1 = this[93];
  if ( v1 < 0 || v1 >= this[63] )
    return 0;
  v2 = (_DWORD *)this[60];
  if ( v1 > 0 )
  {
    while ( v2 )
    {
      v2 = (_DWORD *)v2[1];
      if ( --v1 <= 0 )
        goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  if ( !v2 )
    return 0;
  return *v2;
}
