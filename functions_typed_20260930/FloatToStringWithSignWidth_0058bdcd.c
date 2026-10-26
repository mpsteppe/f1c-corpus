int __cdecl sub_58BDCD(double *a1, int a2, int a3, int a4)
{
  double v5; // [esp+0h] [ebp-3Ch]
  _BYTE v6[24]; // [esp+14h] [ebp-28h] BYREF
  _DWORD v7[4]; // [esp+2Ch] [ebp-10h] BYREF

  v5 = *a1;
  LocaleAwareStringFormat(SLOBYTE(v5), HIDWORD(v5), v7, v6);
  sub_5955AA((v7[0] == 45) + a2 + (a3 > 0), a3 + 1, v7);
  sub_58BE2E(a2, a3, a4, v7, 0);
  return a2;
}

