int __thiscall sub_5ADDC0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // eax

  v2 = a2[11];
  if ( v2 )
    *(_DWORD *)(v2 + 48) = a2[12];
  v3 = a2[12];
  if ( v3 )
    *(_DWORD *)(v3 + 44) = a2[11];
  if ( a2 == (_DWORD *)this[71] )
    this[71] = a2[12];
  sub_5ACEA0();
  j_nullsub_6(a2);
  sub_5BE8AE();
  return 0;
}
