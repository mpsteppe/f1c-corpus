char __thiscall sub_4B0560(int *this, _DWORD *a2, _DWORD *a3)
{
  int v4; // ecx
  double v5; // st7
  int v7; // [esp+4h] [ebp-28h] BYREF
  int v8; // [esp+8h] [ebp-24h] BYREF
  float v9; // [esp+Ch] [ebp-20h]
  float v10; // [esp+10h] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-18h] BYREF
  int v12; // [esp+18h] [ebp-14h] BYREF
  int v13; // [esp+1Ch] [ebp-10h] BYREF
  int v14; // [esp+20h] [ebp-Ch] BYREF
  int v15; // [esp+24h] [ebp-8h] BYREF
  int v16; // [esp+28h] [ebp-4h] BYREF

  v4 = *this;
  if ( !v4 )
    return 0;
  v9 = 800.0 / (double)dword_6152E8;
  v10 = 600.0 / (double)dword_6152EC;
  sub_5A17A0(v4, 0, (int)&v14, (int)&v15, (int)&v16, (int)&v7, (int)&v7, (int)&v8);
  sub_5A17A0(*this, 2, (int)&v11, (int)&v12, (int)&v13, (int)&v7, (int)&v7, (int)&v8);
  v5 = *(float *)&v12 - *(float *)&v15;
  *a2 = (__int64)((*(float *)&v11 - *(float *)&v14) * v9 + 0.5);
  *a3 = (__int64)(v5 * v10 + 0.5);
  return 1;
}
