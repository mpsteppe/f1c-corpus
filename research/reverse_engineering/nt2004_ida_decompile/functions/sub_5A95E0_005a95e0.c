int __thiscall sub_5A95E0(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  _DWORD *v6; // eax
  int i; // edx

  if ( a2 >= this[71] )
    return -1;
  v6 = (_DWORD *)this[72];
  for ( i = 0; i < a2; v6 = (_DWORD *)v6[8] )
  {
    if ( !v6[8] )
      break;
    ++i;
  }
  if ( a3 )
    *a3 = v6[2];
  if ( a4 )
    *a4 = v6[3];
  if ( a5 )
    *a5 = v6[5];
  if ( a6 )
    *a6 = *v6;
  return 0;
}
