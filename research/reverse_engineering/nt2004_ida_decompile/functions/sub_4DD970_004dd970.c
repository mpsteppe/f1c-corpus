char __thiscall sub_4DD970(float **this, float a2)
{
  float *v2; // ecx
  float *v3; // esi
  char v4; // bl
  double v6; // st7
  double v7; // st6
  double v8; // st5
  float v9; // [esp+8h] [ebp-68h]
  float v10; // [esp+Ch] [ebp-64h]
  float v11; // [esp+10h] [ebp-60h] BYREF
  float v12; // [esp+14h] [ebp-5Ch]
  float v13; // [esp+18h] [ebp-58h]
  float v14; // [esp+1Ch] [ebp-54h]
  float v15; // [esp+20h] [ebp-50h]
  float v16; // [esp+24h] [ebp-4Ch]
  float v17[3]; // [esp+28h] [ebp-48h] BYREF
  float v18[3]; // [esp+34h] [ebp-3Ch] BYREF
  _BYTE v19[12]; // [esp+40h] [ebp-30h] BYREF
  _BYTE v20[8]; // [esp+4Ch] [ebp-24h] BYREF
  float v21; // [esp+54h] [ebp-1Ch]
  float v22; // [esp+60h] [ebp-10h]
  float v23; // [esp+6Ch] [ebp-4h]
  float v24; // [esp+74h] [ebp+4h]

  v2 = *this;
  v3 = v2 + 21;
  v4 = LOBYTE(a2);
  v9 = v2[4407] * v2[4407] + v2[4408] * v2[4408] + v2[4409] * v2[4409];
  if ( !LOBYTE(a2) && v9 > 1.0 )
    return 0;
  sub_4F8EF0(v2, v18, &v11);
  sub_579100(&v11, v20);
  v14 = -v21;
  v15 = -v22;
  v16 = -v23;
  sub_51C1E0(v17, v19);
  v6 = -v3[4373];
  v7 = -v3[4376];
  v8 = -v3[4379];
  v11 = v17[0] - v18[0];
  v12 = v17[1] - v18[1];
  v13 = v17[2] - v18[2];
  v24 = v16 * v13 + v15 * v12 + v11 * v14;
  v10 = v8 * v16 + v7 * v15 + v6 * v14;
  if ( v4 )
  {
    if ( v9 > 1.0 || v13 * v13 + v12 * v12 + v11 * v11 > 5.0625 || v24 > 1.5 || v10 < 0.75 )
      return 0;
  }
  else
  {
    if ( v13 * v13 + v12 * v12 + v11 * v11 > 3.0625 )
      return 0;
    if ( v24 > 1.25 )
      return 0;
    if ( v10 < 0.85000002 )
      return 0;
  }
  return 1;
}
