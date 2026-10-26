int __thiscall sub_601880(_DWORD *this, int a2)
{
  int v2; // edx
  _DWORD *v3; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[2347] )
    return 0;
  v3 = (_DWORD *)this[2344];
  if ( a2 > 0 )
  {
    while ( v3 )
    {
      v3 = (_DWORD *)v3[1];
      if ( --v2 <= 0 )
        goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  if ( !v3 )
    return 0;
  return *v3;
}
