int __stdcall sub_5006D5(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _BYTE v6[84]; // [esp+4h] [ebp-54h] BYREF

  F_7FieldInitializer(v6);
  v3 = 0;
  v4 = DirectXSurfaceFormatNegotiation(a1, a2, a3, 0);
  if ( v4 < 0 )
    v3 = v4;
  ArithmeticComparison_0f55(v6);
  return v3;
}

