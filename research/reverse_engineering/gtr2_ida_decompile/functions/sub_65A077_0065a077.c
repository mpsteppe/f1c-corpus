int __thiscall sub_65A077(_DWORD *this, unsigned int *a2, _DWORD *a3)
{
  unsigned int *i; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax

  for ( i = (unsigned int *)this[154]; i[27]; i = (unsigned int *)i[27] )
    ;
  if ( a2 )
    *a2 = *i;
  if ( a3 )
  {
    v4 = i[1];
    v5 = *i;
    if ( v4 < v5 )
      *a3 = 0;
    else
      *a3 = v4 - v5;
  }
  return 0;
}
