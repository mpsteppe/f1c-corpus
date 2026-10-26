int __cdecl _cftoe(double *a1, int a2, int a3, int a4)
{
  double v6; // [esp+0h] [ebp-3Ch]
  char Destination[24]; // [esp+14h] [ebp-28h] BYREF
  int v8[4]; // [esp+2Ch] [ebp-10h] BYREF

  v6 = *a1;
  _fltout2(SLOBYTE(v6), SHIDWORD(v6), (int)v8, Destination);
  _fptostr((void *)((v8[0] == 45) + a2 + (a3 > 0)), a3 + 1, (int)v8);
  _cftoe2(a2, a3, a4, v8, 0);
  return a2;
}
