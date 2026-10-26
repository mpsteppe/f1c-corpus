int __thiscall sub_464740(void *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( sub_56A630(*(_DWORD *)(*(_DWORD *)this + 6708)) )
    return 0;
  v2 = sub_56A2C0(a2);
  if ( !v2 )
    return 0;
  v3 = v2 - 2;
  if ( !v3 )
    return 1;
  v4 = v3 - 1;
  if ( !v4 )
    return 2;
  if ( v4 == 2 )
    return 4;
  return 3;
}
