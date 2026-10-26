// f1c  0x004b3c60  size=124
DWORD __thiscall sub_4B3C60(int *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  double v5; // st7
  DWORD TickCount; // esi
  DWORD v7; // esi
  int v8; // ecx
  int v9; // eax
  int v11; // [esp+4h] [ebp-Ch] BYREF
  float v12; // [esp+8h] [ebp-8h]
  char v13[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_55687B(v13, &v11);
  v2 = 219837 * (this[513] + 2);
  v3 = v2 + v11;
  this[513] = v2;
  v4 = *this;
  v11 = v3;
  v5 = *(float *)&this[(unsigned __int8)v4 + 1];
  *this = v4 + 1;
  v12 = v5;
  TickCount = GetTickCount();
  v7 = TickCount - sub_587BDC(v12 * -3499.01);
  v9 = sub_5884ED(v8);
  return (2 * v9 + 1) * v7 + v11;
}
