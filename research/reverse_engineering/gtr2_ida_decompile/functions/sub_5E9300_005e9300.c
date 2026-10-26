int __thiscall sub_5E9300(_DWORD *this, unsigned __int16 a2)
{
  int v2; // eax
  _DWORD *v3; // ecx

  v2 = a2;
  if ( a2 >= (int)this[12] )
    return 0;
  v3 = (_DWORD *)this[9];
  if ( a2 )
  {
    while ( v3 )
    {
      v3 = (_DWORD *)v3[1];
      if ( --v2 <= 0 )
        goto LABEL_5;
    }
    return 0;
  }
LABEL_5:
  if ( !v3 )
    return 0;
  return *v3;
}
