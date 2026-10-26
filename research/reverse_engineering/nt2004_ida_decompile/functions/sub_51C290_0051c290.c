double __thiscall sub_51C290(float *this, int a2)
{
  float *v3; // esi
  float *v4; // edx
  float *v5; // ebx
  float *v6; // ebp
  double v7; // st7
  double v8; // st6
  float *v9; // eax
  float *v10; // eax
  double v11; // st7
  double v12; // st6
  double v13; // st7
  float *v14; // eax
  float v15; // ecx
  float v16; // edx
  float v17; // eax
  float *v18; // eax
  float v19; // ecx
  float v20; // edx
  float v21; // eax
  double v22; // st7
  double v23; // st7
  float v25; // [esp+4h] [ebp-4Ch]
  float v26; // [esp+4h] [ebp-4Ch]
  float v27; // [esp+8h] [ebp-48h] BYREF
  float v28; // [esp+Ch] [ebp-44h]
  float v29; // [esp+10h] [ebp-40h]
  float v30; // [esp+14h] [ebp-3Ch] BYREF
  float v31; // [esp+18h] [ebp-38h]
  float v32; // [esp+1Ch] [ebp-34h]
  float v33; // [esp+20h] [ebp-30h] BYREF
  float v34; // [esp+24h] [ebp-2Ch]
  float v35; // [esp+28h] [ebp-28h]
  float v36; // [esp+2Ch] [ebp-24h] BYREF
  float v37; // [esp+30h] [ebp-20h]
  float v38; // [esp+34h] [ebp-1Ch]
  float v39; // [esp+38h] [ebp-18h] BYREF
  float v40; // [esp+3Ch] [ebp-14h]
  float v41; // [esp+40h] [ebp-10h]
  float v42[3]; // [esp+44h] [ebp-Ch] BYREF
  float v43; // [esp+54h] [ebp+4h]

  v27 = *(float *)(a2 + 36);
  v28 = *(float *)(a2 + 40);
  v29 = *(float *)(a2 + 44);
  v3 = this + 4371;
  v4 = &this[3 * *(_DWORD *)(a2 + 20) + 4757];
  v5 = this + 4380;
  v6 = this + 4392;
  v25 = *(float *)(a2 + 56) * v29 + *(float *)(a2 + 52) * v28 + *(float *)(a2 + 48) * v27;
  v7 = this[4373] * v4[2] + this[4372] * v4[1] + this[4371] * *v4;
  v8 = this[4376] * v4[2] + this[4375] * v4[1] + this[4374] * *v4;
  v35 = this[4379] * v4[2] + this[4378] * v4[1] + this[4377] * *v4;
  v33 = v7 + this[4380];
  v34 = v8 + this[4381];
  v35 = v35 + this[4382];
  v9 = sub_51B790(this + 4392, v4, v42);
  v39 = *v9;
  v40 = v9[1];
  v41 = v9[2];
  v10 = sub_4F5370(this + 4389, &v39, v42);
  v30 = *v10;
  v31 = v10[1];
  v11 = v31 * v3[1];
  v32 = v10[2];
  v12 = v32 * v3[2];
  v38 = v32;
  v36 = v30;
  v37 = v31;
  v13 = (v30 * v3[6] + v31 * v3[7] + v32 * v3[8]) * v29
      + (v30 * v3[3] + v31 * v3[4] + v32 * v3[5]) * v28
      + (v11 + v12 + v30 * *v3) * v27;
  if ( v13 == 0.0 )
    v43 = 0.0;
  else
    v43 = (v35 * v29 + v34 * v28 + v33 * v27 - v25) / v13;
  sub_51BCE0(this, (int)&v30);
  v39 = v32 * v3[2] + v31 * v3[1] + v30 * *v3;
  v40 = v32 * v3[5] + v31 * v3[4] + v30 * v3[3];
  v41 = v32 * v3[8] + v31 * v3[7] + v30 * v3[6];
  sub_518460(&v39, v5);
  v14 = sub_51B790(v6, &v30, v42);
  v15 = *v14;
  v16 = v14[1];
  v17 = v14[2];
  v33 = v15;
  v34 = v16;
  v35 = v17;
  v18 = sub_4F5370(this + 4389, &v33, v42);
  v19 = *v18;
  v20 = v18[1];
  v21 = v18[2];
  v37 = v20;
  v38 = v21;
  v36 = v19;
  sub_51C5D0(&v36, &v30);
  v26 = sub_51C5B0(&v39, &v27) - v25;
  v22 = sub_51C5B0(&v30, &v27);
  if ( v22 == 0.0 )
    v23 = 0.0;
  else
    v23 = v26 / v22;
  if ( v43 > v23 )
    v23 = v43;
  if ( v23 < 0.0 )
    return this[4370];
  if ( v23 <= 0.025 )
    return this[4370] - v23;
  return this[4370] - 0.025;
}
