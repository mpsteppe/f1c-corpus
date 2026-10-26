int __thiscall sub_427140(_DWORD *this)
{
  int v2; // ebp
  int v3; // ebx
  int i; // esi
  char *v5; // eax

  if ( flt_7DAB04 >= 0.25 )
    v2 = 5;
  else
    v2 = this[6125];
  v3 = 0;
  for ( i = 0; i < *(_DWORD *)(this[4695] + 16); ++i )
  {
    v5 = *(char **)sub_5009C0(i);
    if ( !v5 )
      v5 = &byte_629120;
    if ( v2 == sub_4BFFC0(v5) )
      v3 = i;
  }
  return v3;
}
