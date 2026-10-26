double __thiscall sub_4EFBD0(float *this, int a2)
{
  float *v3; // esi
  float *v4; // edx
  float *v5; // ebx
  float *v6; // ebp
  double v7; // st7
  double v8; // st6
  float *v9; // eax
  float *v10; // eax
  float v11; // ecx
  float v12; // edx
  double v13; // st7
  double v14; // st7
  float *v15; // eax
  float v16; // ecx
  float v17; // edx
  float v18; // eax
  float *v19; // eax
  float v20; // ecx
  float v21; // edx
  double v22; // st7
  double v23; // st7
  float v25; // [esp+4h] [ebp-40h]
  float v26; // [esp+4h] [ebp-40h]
  float v27; // [esp+8h] [ebp-3Ch] BYREF
  float v28; // [esp+Ch] [ebp-38h]
  float v29; // [esp+10h] [ebp-34h]
  float v30; // [esp+14h] [ebp-30h] BYREF
  float v31; // [esp+18h] [ebp-2Ch]
  float v32; // [esp+1Ch] [ebp-28h]
  float v33; // [esp+20h] [ebp-24h] BYREF
  float v34; // [esp+24h] [ebp-20h]
  float v35; // [esp+28h] [ebp-1Ch]
  float v36; // [esp+2Ch] [ebp-18h] BYREF
  float v37; // [esp+30h] [ebp-14h]
  float v38; // [esp+34h] [ebp-10h]
  float v39[3]; // [esp+38h] [ebp-Ch] BYREF
  float v40; // [esp+48h] [ebp+4h]

  v30 = *(float *)(a2 + 36);
  v31 = *(float *)(a2 + 40);
  v32 = *(float *)(a2 + 44);
  v3 = this + 3372;
  v4 = &this[3 * *(_DWORD *)(a2 + 20) + 3758];
  v5 = this + 3381;
  v6 = this + 3393;
  v25 = *(float *)(a2 + 56) * v32 + *(float *)(a2 + 52) * v31 + *(float *)(a2 + 48) * v30;
  v7 = this[3374] * v4[2] + this[3373] * v4[1] + this[3372] * *v4;
  v8 = this[3377] * v4[2] + this[3376] * v4[1] + this[3375] * *v4;
  v35 = this[3380] * v4[2] + this[3379] * v4[1] + this[3378] * *v4;
  v33 = v7 + this[3381];
  v34 = v8 + this[3382];
  v35 = v35 + this[3383];
  v9 = sub_4ED750(this + 3393, v4, &v27);
  v36 = *v9;
  v37 = v9[1];
  v38 = v9[2];
  v10 = sub_4ED710(this + 3390, &v36, v39);
  v11 = *v10;
  v12 = v10[1];
  v29 = v10[2];
  v13 = v29 * v3[2];
  v28 = v12;
  v27 = v11;
  v14 = (v29 * v3[8] + v12 * v3[7] + v11 * v3[6]) * v32
      + (v29 * v3[5] + v12 * v3[4] + v11 * v3[3]) * v31
      + (v13 + v12 * v3[1] + v11 * *v3) * v30;
  if ( v14 == 0.0 )
    v40 = 0.0;
  else
    v40 = (v35 * v32 + v34 * v31 + v33 * v30 - v25) / v14;
  sub_4EF680(this, (int)&v33);
  v36 = v35 * v3[2] + v34 * v3[1] + v33 * *v3;
  v37 = v35 * v3[5] + v34 * v3[4] + v33 * v3[3];
  v38 = v35 * v3[8] + v34 * v3[7] + v33 * v3[6];
  sub_4EC020(&v36, v5);
  v15 = sub_4ED750(v6, &v33, v39);
  v16 = *v15;
  v17 = v15[1];
  v18 = v15[2];
  v33 = v16;
  v34 = v17;
  v35 = v18;
  v19 = sub_4ED710(this + 3390, &v33, v39);
  v20 = v19[1];
  v27 = *v19;
  v21 = v19[2];
  v28 = v20;
  v29 = v21;
  sub_4ED7B0(v3, &v27, v39);
  v26 = sub_4EFEE0(&v36, &v30) - v25;
  v22 = sub_4EFEE0(v39, &v30);
  if ( v22 == 0.0 )
    v23 = 0.0;
  else
    v23 = v26 / v22;
  if ( v40 > v23 )
    v23 = v40;
  if ( v23 < 0.0 )
    return this[3371];
  if ( v23 <= 0.025 )
    return this[3371] - v23;
  return this[3371] - 0.025;
}
