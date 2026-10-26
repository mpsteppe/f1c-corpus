int __thiscall sub_50B170(_DWORD *this, int a2)
{
  _DWORD *v3; // edi

  v3 = &this[76 * a2];
  sub_50AEE0(this, (int)(v3 + 85));
  v3 += 102;
  sub_50AEE0(this, (int)v3);
  if ( *v3 )
    sub_59ECC0(1, 1, 0, 0);
  return sub_50B4E0(this[717], 1);
}
