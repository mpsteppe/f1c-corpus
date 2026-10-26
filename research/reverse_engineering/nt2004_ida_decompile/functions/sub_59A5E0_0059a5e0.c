int __thiscall sub_59A5E0(_DWORD *this)
{
  int v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  v2 = this[9];
  *this = 0;
  for ( this[1] = 0; v2; v2 = v3[42] )
  {
    sub_598630(v2);
    *v4 += v3[37];
    v4[1] += v3[38];
  }
  return 0;
}
