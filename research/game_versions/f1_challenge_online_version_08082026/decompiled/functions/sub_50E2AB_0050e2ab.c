int __stdcall sub_50E2AB(int a1, int a2, int a3, int a4, int a5, float a6)
{
  float v7; // [esp+0h] [ebp-24h]
  int v8[4]; // [esp+4h] [ebp-20h] BYREF
  int v9[4]; // [esp+14h] [ebp-10h] BYREF

  sub_50E198((int)v8, a2, a5, a6);
  sub_50E198((int)v9, a3, a4, a6);
  v7 = (1.0 - a6) * a6 + (1.0 - a6) * a6;
  sub_50E198(a1, (int)v8, (int)v9, v7);
  return a1;
}
