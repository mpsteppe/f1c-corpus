int __stdcall sub_64479A(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _BYTE v6[84]; // [esp+4h] [ebp-54h] BYREF

  sub_6464A7(v6);
  v3 = 0;
  v4 = sub_64A450(a1, a2, a3, 0);
  if ( v4 < 0 )
    v3 = v4;
  sub_6464C0(v6);
  return v3;
}
