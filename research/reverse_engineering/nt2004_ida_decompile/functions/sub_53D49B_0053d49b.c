int __stdcall sub_53D49B(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _BYTE v6[84]; // [esp+4h] [ebp-54h] BYREF

  sub_53DD41(v6);
  v3 = 0;
  v4 = sub_53F81B(a1, a2, a3, 0);
  if ( v4 < 0 )
    v3 = v4;
  sub_53DD5A(v6);
  return v3;
}
