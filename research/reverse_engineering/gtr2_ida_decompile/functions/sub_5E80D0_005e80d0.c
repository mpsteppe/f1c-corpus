int __thiscall sub_5E80D0(_DWORD *this, int a2)
{
  int v2; // edx

  v2 = this[65];
  if ( v2 && a2 <= this[64] )
    return v2 + 484 * a2;
  else
    return 0;
}
