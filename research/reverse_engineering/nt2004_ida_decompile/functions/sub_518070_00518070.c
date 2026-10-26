char __thiscall sub_518070(float *this, int a2, char a3)
{
  float *v5; // ebp
  float *v6; // eax
  float v7; // ecx
  float v8; // edx
  double v9; // st7
  float *v10; // edi
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v17; // st7
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int *v21; // ebp
  int v22; // eax
  int v23; // ecx
  double v25; // [esp+8h] [ebp-74h]
  double v26; // [esp+10h] [ebp-6Ch]
  float v27; // [esp+14h] [ebp-68h]
  float v28; // [esp+28h] [ebp-54h] BYREF
  float v29; // [esp+2Ch] [ebp-50h]
  float v30; // [esp+30h] [ebp-4Ch]
  float v31; // [esp+34h] [ebp-48h] BYREF
  float v32; // [esp+38h] [ebp-44h]
  float v33; // [esp+3Ch] [ebp-40h]
  double v34; // [esp+40h] [ebp-3Ch] BYREF
  float v35; // [esp+48h] [ebp-34h]
  float v36[2]; // [esp+58h] [ebp-24h] BYREF
  float v37; // [esp+60h] [ebp-1Ch]
  int v38[2]; // [esp+64h] [ebp-18h] BYREF
  double v39; // [esp+6Ch] [ebp-10h]
  double v40; // [esp+74h] [ebp-8h]
  float v41; // [esp+80h] [ebp+4h]

  v5 = (float *)(a2 + 36);
  v6 = sub_516530((float *)(a2 + 36), this + 4380, v36);
  v7 = *v6;
  v8 = v6[1];
  v30 = v6[2];
  v9 = v30 * this[4377];
  v29 = v8;
  v28 = v7;
  v10 = (float *)(a2 + 48);
  v31 = v9 + v8 * this[4374] + v7 * this[4371];
  v32 = v30 * this[4378] + v8 * this[4375] + v7 * this[4372];
  v33 = v30 * this[4379] + v8 * this[4376] + v7 * this[4373];
  v11 = this[4377] * *(float *)(a2 + 56) + this[4374] * *(float *)(a2 + 52) + *(float *)(a2 + 48) * this[4371];
  v12 = this[4372] * *(float *)(a2 + 48) + this[4378] * *(float *)(a2 + 56) + this[4375] * *(float *)(a2 + 52);
  v41 = *(float *)(a2 + 4);
  v37 = this[4373] * *(float *)(a2 + 48) + this[4379] * *(float *)(a2 + 56) + this[4376] * *(float *)(a2 + 52);
  v28 = v41 * v11;
  v36[0] = v28;
  v29 = v12 * v41;
  v36[1] = v29;
  v30 = v37 * v41;
  v13 = this[4397];
  v37 = v30;
  *((float *)&v34 + 1) = v29 * v13;
  v35 = v30 * v13;
  this[4389] = v28 * v13 + this[4389];
  this[4390] = *((float *)&v34 + 1) + this[4390];
  this[4391] = v35 + this[4391];
  this[4386] = this[4373] * this[4391] + this[4372] * this[4390] + this[4371] * this[4389];
  this[4387] = this[4374] * this[4389] + this[4376] * this[4391] + this[4375] * this[4390];
  this[4388] = this[4377] * this[4389] + this[4379] * this[4391] + this[4378] * this[4390];
  v35 = v29 * v31 - v32 * v28;
  v14 = v33 * v28 - v30 * v31;
  v28 = (v32 * v30 - v33 * v29) * this[4401];
  v15 = v14 * this[4402];
  v16 = v35 * this[4403];
  this[4392] = v28 + this[4392];
  this[4393] = v15 + this[4393];
  this[4394] = v16 + this[4394];
  if ( !*((_DWORD *)this + 4125) )
  {
    *(double *)v38 = *v5;
    v39 = *(float *)(a2 + 40);
    v40 = *(float *)(a2 + 44);
    v17 = *(float *)(a2 + 4) * 40.0;
    v26 = v17 * *(float *)(a2 + 56);
    v25 = v17 * *(float *)(a2 + 52);
    sub_5184E0(
      COERCE_UNSIGNED_INT64(v17 * *v10),
      HIDWORD(COERCE_UNSIGNED_INT64(v17 * *v10)),
      LODWORD(v25),
      HIDWORD(v25),
      LODWORD(v26),
      HIDWORD(v26));
    sub_4418F0((int)&dbl_75E930, (double *)v38, &v34);
  }
  v18 = *((_DWORD *)this + 4125);
  if ( v18 )
  {
    v19 = v18 - 1;
    if ( v19 )
    {
      v20 = v19 - 1;
      if ( !v20 )
      {
        v20 = sub_465CC0(dword_764D70, *(_DWORD *)(*(_DWORD *)this + 25248));
        if ( v20 )
        {
          v21 = (int *)(v20 + 24);
          sub_4CFBA0((_DWORD *)(v20 + 24), &v28);
          v27 = *(float *)(a2 + 4) * this[4397];
          v22 = sub_518490((int)v38, v27);
          v34 = *(double *)v22;
          v35 = *(float *)(v22 + 8);
          sub_518460(&v34);
          LOBYTE(v20) = sub_4CFA90(v21, &v28);
        }
      }
      return v20;
    }
    if ( *(_DWORD *)(a2 + 12) == 6 )
    {
      v28 = v31;
      v29 = v32;
      v23 = *(_DWORD *)this;
      v30 = v33;
      sub_42D5C0(v23, (int)&v28);
    }
  }
  LOBYTE(v20) = a3;
  if ( a3 )
    LOBYTE(v20) = sub_518630(&v31, v36, a2);
  return v20;
}
