int __cdecl sub_58BEF0(double *a1, int a2, int a3)
{
  double v4; // [esp+0h] [ebp-3Ch]
  _BYTE v5[24]; // [esp+14h] [ebp-28h] BYREF
  _DWORD v6[4]; // [esp+2Ch] [ebp-10h] BYREF

  v4 = *a1;
  LocaleAwareStringFormat(SLOBYTE(v4), HIDWORD(v4), v6, v5);
  sub_5955AA(a2 + (v6[0] == 45), a3 + v6[1], v6);
  UtilityFunction_bf45(a2, a3, v6, 0);
  return a2;
}
