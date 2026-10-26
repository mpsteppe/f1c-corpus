int __thiscall sub_50B1D0(_DWORD *this, int a2)
{
  int *v3; // edi

  v3 = &this[76 * a2];
  sub_50AF50(this, v3 + 85);
  sub_50C860(a2, 0.0);
  v3 += 102;
  sub_50AF50(this, v3);
  if ( *v3 )
    sub_59ECC0(0, 0, 0, 0);
  return sub_50B4E0(this[717], 1);
}
