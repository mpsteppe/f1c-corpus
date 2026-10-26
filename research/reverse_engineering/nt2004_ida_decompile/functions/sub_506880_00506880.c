int __thiscall sub_506880(
        _DWORD *this,
        int a2,
        char *a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        int a9,
        int a10)
{
  double v10; // st7
  double v11; // st6
  int v12; // edi
  float v14; // [esp+10h] [ebp+Ch]

  v10 = (double)dword_6152E8;
  v11 = (double)dword_6152EC;
  v12 = (__int64)(a4 * v10 + 0.5);
  v14 = v11;
  return sub_506750(
           this,
           a2,
           a3,
           v12,
           (__int64)(v11 * a5 + 0.5),
           (__int64)(a6 + 0.5),
           (__int64)(v10 * a7 + 0.5),
           (__int64)(v14 * a8 + 0.5),
           a9,
           a10);
}
