float *__thiscall sub_576B50(float *this, float *a2, float *a3, float *a4, float *a5, float *a6)
{
  float *v7; // esi
  int v8; // ecx
  _BYTE *v9; // ebx
  float *v10; // edx
  double v11; // st7
  int v12; // ecx
  double v13; // st7
  double v14; // st6
  double v15; // st5
  float *result; // eax
  double v17; // st7
  float v18; // [esp+Ch] [ebp-3Ch] BYREF
  float v19; // [esp+10h] [ebp-38h]
  float v20; // [esp+14h] [ebp-34h]
  float v21; // [esp+18h] [ebp-30h] BYREF
  float v22; // [esp+1Ch] [ebp-2Ch]
  float v23; // [esp+20h] [ebp-28h]
  float v24; // [esp+24h] [ebp-24h]
  float v25; // [esp+28h] [ebp-20h]
  float v26; // [esp+2Ch] [ebp-1Ch]
  float v27; // [esp+30h] [ebp-18h]
  float v28; // [esp+34h] [ebp-14h]
  float v29; // [esp+38h] [ebp-10h]
  float v30; // [esp+3Ch] [ebp-Ch] BYREF
  float v31; // [esp+40h] [ebp-8h]
  float v32; // [esp+44h] [ebp-4h]

  v7 = this + 3984;
  sub_4F09D0(this + 3984, this + 3993, a2, &v30);
  v18 = v7[6] * a3[2] + v7[3] * a3[1] + *a3 * *v7;
  v19 = v7[7] * a3[2] + v7[4] * a3[1] + v7[1] * *a3;
  v20 = v7[8] * a3[2] + v7[5] * a3[1] + v7[2] * *a3;
  sub_573AD0(this, &v30, &v21);
  v8 = 0;
  v9 = this + 804;
  v10 = this + 4042;
  while ( 1 )
  {
    v27 = v30 - *(v10 - 2);
    v24 = v27;
    v28 = v31 - *(v10 - 1);
    v25 = v28;
    v29 = v32 - *v10;
    v11 = v10[31];
    v26 = v29;
    if ( v11 * v11 > v27 * v27 + v28 * v28 + v29 * v29 )
    {
      if ( *v9 )
        break;
    }
    ++v8;
    v10 += 63;
    v9 += 296;
    if ( v8 >= 4 )
      goto LABEL_7;
  }
  v12 = 63 * v8;
  v13 = -(v26 * this[v12 + 4049]);
  v14 = v25 * this[v12 + 4049];
  v15 = v20 * v14 + v19 * v13 + v18 * 0.0;
  v27 = v18 * v15;
  v24 = v27;
  v28 = v19 * v15;
  v25 = v28;
  v29 = v20 * v15;
  v26 = v29;
  v27 = -v27;
  v28 = v13 - v28;
  v21 = v21 + v27;
  v22 = v22 + v28;
  v23 = v23 + v14 - v29;
LABEL_7:
  *a4 = v23 * v20 + v22 * v19 + v21 * v18;
  *a5 = sub_573320(this, &v30, &v18);
  result = a6;
  if ( a6 )
  {
    v17 = *a4;
    v30 = v18 * v17;
    v27 = v30;
    v31 = v19 * v17;
    v28 = v31;
    v32 = v20 * v17;
    v29 = v32;
    v30 = v21 - v30;
    v21 = v30;
    v31 = v22 - v31;
    v22 = v31;
    v32 = v23 - v32;
    v23 = v32;
    *a6 = v32 * v7[2] + v31 * v7[1] + v30 * *v7;
    a6[1] = v23 * v7[5] + v22 * v7[4] + v21 * v7[3];
    a6[2] = v23 * v7[8] + v22 * v7[7] + v21 * v7[6];
  }
  return result;
}
