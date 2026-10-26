double __thiscall sub_577800(float *this, int a2)
{
  double v2; // st7
  float v3; // edx
  double v4; // st6
  double v5; // st5
  int v7; // eax
  float *v8; // ebx
  float *v9; // ebp
  float *v10; // esi
  double v11; // st7
  float v12; // edx
  double v13; // st7
  double v14; // st6
  double v15; // st7
  double v16; // st7
  float v18; // [esp+10h] [ebp-34h]
  float v19; // [esp+14h] [ebp-30h] BYREF
  float v20; // [esp+18h] [ebp-2Ch]
  float v21; // [esp+1Ch] [ebp-28h]
  float v22; // [esp+20h] [ebp-24h]
  float v23; // [esp+24h] [ebp-20h]
  float v24; // [esp+28h] [ebp-1Ch]
  float v25; // [esp+2Ch] [ebp-18h] BYREF
  float v26; // [esp+30h] [ebp-14h]
  float v27; // [esp+34h] [ebp-10h]
  float v28[3]; // [esp+38h] [ebp-Ch] BYREF
  float v29; // [esp+48h] [ebp+4h]

  v2 = *(float *)(a2 + 48);
  v3 = *(float *)(a2 + 40);
  v4 = *(float *)(a2 + 52);
  v5 = *(float *)(a2 + 56);
  v22 = *(float *)(a2 + 36);
  v7 = *(_DWORD *)(a2 + 20);
  v24 = *(float *)(a2 + 44);
  v23 = v3;
  v8 = &this[3 * v7 + 4376];
  v9 = this + 3993;
  v10 = this + 3984;
  v18 = v5 * v24 + v4 * v3 + v2 * v22;
  sub_416420(this + 3984, this + 3993, v8, &v25);
  sub_573AD0(this, v8, &v19);
  v11 = (v21 * v10[8] + v20 * v10[7] + v19 * v10[6]) * v24
      + (v21 * v10[5] + v20 * v10[4] + v19 * v10[3]) * v23
      + (v21 * v10[2] + v20 * v10[1] + v19 * *v10) * v22;
  if ( v11 == 0.0 )
    v29 = 0.0;
  else
    v29 = (v27 * v24 + v26 * v23 + v25 * v22 - v18) / v11;
  v12 = this[699];
  v13 = this[4104] - this[4136];
  v14 = this[4041] - this[4073];
  v25 = 0.0;
  v27 = v12;
  v26 = (v13 + v14) * 0.5;
  sub_416420(v10, v9, &v25, v28);
  sub_573AD0(this, &v25, &v19);
  v15 = (v21 * v10[8] + v20 * v10[7] + v19 * v10[6]) * v24
      + (v21 * v10[5] + v20 * v10[4] + v19 * v10[3]) * v23
      + (v21 * v10[2] + v20 * v10[1] + v19 * *v10) * v22;
  if ( v15 == 0.0 )
    v16 = 0.0;
  else
    v16 = (v28[2] * v24 + v28[1] * v23 + v28[0] * v22 - v18) / v15;
  if ( v29 > v16 )
    v16 = v29;
  if ( v16 < 0.0 )
    return this[3983];
  if ( v16 <= 0.025 )
    return this[3983] - v16;
  return this[3983] - 0.025;
}
