int __thiscall sub_5A7DD0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax

  if ( this[1296] )
  {
    if ( a2[7] )
      sub_5BE8AE();
    v2 = a2[9];
    a2[7] = 0;
    a2[11] = 0;
    if ( v2 )
      sub_5BE8AE();
    a2[9] = 0;
    a2[12] = 0;
    return 0;
  }
  else
  {
    sub_5A7FD0(a2[7]);
    if ( a2[7] )
      sub_5BE8AE();
    sub_5A8170(a2[9]);
    if ( a2[9] )
      sub_5BE8AE();
    return 0;
  }
}
