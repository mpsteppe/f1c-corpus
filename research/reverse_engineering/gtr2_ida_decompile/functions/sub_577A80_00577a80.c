bool __thiscall sub_577A80(float *this)
{
  float v3; // [esp+0h] [ebp-30h]
  float v4; // [esp+4h] [ebp-2Ch]
  float v5; // [esp+8h] [ebp-28h]
  float v6; // [esp+Ch] [ebp-24h] BYREF
  float v7; // [esp+10h] [ebp-20h]
  float v8; // [esp+14h] [ebp-1Ch]
  float v9[3]; // [esp+18h] [ebp-18h] BYREF
  _DWORD v10[3]; // [esp+24h] [ebp-Ch] BYREF

  sub_577780(this, &v6, v10);
  sub_54FDF0(off_16C9A84, *(_DWORD *)this, (int)v10, (int)v9);
  v6 = v3 - v9[0];
  v7 = v4 - v9[1];
  v8 = v5 - v9[2];
  return v8 * v8 + v7 * v7 + v6 * v6 < 4.0;
}
