int __thiscall sub_4D1A80(int *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  double v5; // st7
  int v6; // esi
  int v8; // [esp+4h] [ebp-Ch] BYREF
  float v9; // [esp+8h] [ebp-8h]
  _BYTE v10[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_5AE03B(v10, &v8);
  v2 = 219837 * (this[513] + 2);
  v3 = v2 + v8;
  this[513] = v2;
  v4 = *this;
  v8 = v3;
  v5 = *(float *)&this[(unsigned __int8)v4 + 1];
  *this = v4 + 1;
  v9 = v5;
  v6 = GetTickCount() - (__int64)(v9 * -3499.01);
  return (2 * rand() + 1) * v6 + v8;
}
