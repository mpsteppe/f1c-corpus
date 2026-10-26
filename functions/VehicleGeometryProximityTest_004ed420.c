int __thiscall sub_4ED420(float *this, float *a2, float *a3, float *a4, float *a5, int a6)
{
  float *v7; // eax
  float v8; // ecx
  float v9; // edx
  double v10; // st7
  float *v11; // eax
  float *v12; // eax
  float v13; // ecx
  float v14; // edx
  float v15; // eax
  int v16; // ecx
  float *v17; // edx
  float *v18; // ebx
  double v19; // st7
  int v20; // ecx
  double v21; // st7
  double v22; // st6
  double v23; // st5
  int result; // eax
  double v25; // st7
  float v26; // [esp+Ch] [ebp-48h] BYREF
  float v27; // [esp+10h] [ebp-44h]
  float v28; // [esp+14h] [ebp-40h]
  float v29; // [esp+18h] [ebp-3Ch]
  float v30; // [esp+1Ch] [ebp-38h]
  float v31; // [esp+20h] [ebp-34h]
  float v32; // [esp+24h] [ebp-30h]
  float v33; // [esp+28h] [ebp-2Ch]
  float v34; // [esp+2Ch] [ebp-28h]
  float v35; // [esp+30h] [ebp-24h] BYREF
  float v36; // [esp+34h] [ebp-20h]
  float v37; // [esp+38h] [ebp-1Ch]
  float v38; // [esp+3Ch] [ebp-18h] BYREF
  float v39; // [esp+40h] [ebp-14h]
  float v40; // [esp+44h] [ebp-10h]
  _BYTE v41[12]; // [esp+48h] [ebp-Ch] BYREF

  v7 = sub_4EA930(a2, this + 3381, &v38);
  v8 = *v7;
  v9 = v7[1];
  v31 = v7[2];
  v10 = v31 * this[3378];
  v30 = v9;
  v29 = v8;
  v35 = v10 + v9 * this[3375] + v8 * this[3372];
  v36 = v31 * this[3379] + v9 * this[3376] + v8 * this[3373];
  v37 = v31 * this[3380] + v9 * this[3377] + v8 * this[3374];
  v26 = this[3378] * a3[2] + this[3375] * a3[1] + *a3 * this[3372];
  v27 = this[3379] * a3[2] + this[3376] * a3[1] + this[3373] * *a3;
  v28 = this[3380] * a3[2] + this[3377] * a3[1] + this[3374] * *a3;
  v11 = (float *)F_3DCrossProduct(&v38);
  v32 = *v11;
  v33 = v11[1];
  v34 = v11[2];
  v12 = (float *)Vec3Add(v41);
  v13 = *v12;
  v14 = v12[1];
  v15 = v12[2];
  v29 = v13;
  v30 = v14;
  v31 = v15;
  v16 = 0;
  v17 = this + 522;
  v18 = this + 3429;
  while ( 1 )
  {
    v19 = v35 - *(v18 - 2);
    v33 = v36 - *(v18 - 1);
    v34 = v37 - *v18;
    if ( v18[31] * v18[31] > v34 * v34 + v33 * v33 + v19 * v19 && *(_DWORD *)v17 && *((_BYTE *)v17 + 64) )
      break;
    ++v16;
    v18 += 62;
    v17 += 74;
    if ( v16 >= 4 )
      goto LABEL_8;
  }
  v20 = 62 * v16;
  v21 = -(v34 * this[v20 + 3436]);
  v22 = v33 * this[v20 + 3436];
  v23 = v28 * v22 + v27 * v21 + v26 * 0.0;
  v33 = v27 * v23;
  v34 = v28 * v23;
  v38 = -(v26 * v23);
  v39 = v21 - v33;
  v29 = v29 + v38;
  v30 = v30 + v39;
  v31 = v31 + v22 - v34;
LABEL_8:
  *a4 = v31 * v28 + v30 * v27 + v29 * v26;
  *a5 = AnisoVectorTripleProduct(this, &v35, &v26);
  result = a6;
  if ( a6 )
  {
    v25 = *a4;
    v39 = v27 * v25;
    v40 = v28 * v25;
    v32 = v29 - v26 * v25;
    v38 = v32;
    v33 = v30 - v39;
    v39 = v33;
    v34 = v31 - v40;
    v40 = v34;
    return F_33MatrixVectorMultiply(&v38, a6);
  }
  return result;
}
