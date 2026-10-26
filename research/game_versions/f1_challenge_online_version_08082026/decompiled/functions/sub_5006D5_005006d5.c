int __stdcall sub_5006D5(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _BYTE v6[84]; // [esp+4h] [ebp-54h] BYREF

  sub_500F3C(v6);
  v3 = 0;
  v4 = sub_502A15(a1, a2, a3, 0);
  if ( v4 < 0 )
    v3 = v4;
  sub_500F55(v6);
  return v3;
}
