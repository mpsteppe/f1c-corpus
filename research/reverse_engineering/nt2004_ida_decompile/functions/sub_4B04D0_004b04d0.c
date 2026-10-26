char __thiscall sub_4B04D0(int *this, _DWORD *a2, _DWORD *a3)
{
  int v3; // ecx
  double v4; // st7
  int v6; // [esp+0h] [ebp-1Ch] BYREF
  float v7; // [esp+4h] [ebp-18h]
  float v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h] BYREF
  int v10; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h] BYREF

  v3 = *this;
  if ( !v3 )
    return 0;
  v7 = 800.0 / (double)dword_6152E8;
  v8 = 600.0 / (double)dword_6152EC;
  sub_5A17A0(v3, 0, (int)&v10, (int)&v11, (int)&v12, (int)&v6, (int)&v6, (int)&v9);
  v4 = *(float *)&v11 * v8;
  *a2 = (__int64)(*(float *)&v10 * v7 + 0.5);
  *a3 = (__int64)(v4 + 0.5);
  return 1;
}
