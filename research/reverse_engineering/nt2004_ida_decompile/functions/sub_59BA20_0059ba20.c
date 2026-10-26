int __thiscall sub_59BA20(_DWORD *this, int a2)
{
  int result; // eax
  unsigned __int16 *v3; // ebp
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  double v8; // st7
  double v9; // st6
  double v10; // st5
  float *v11; // esi
  int v12; // ebp
  int v13; // esi
  int v14; // ebp
  double v15; // st7
  float *v16; // esi
  float *v17; // ebp
  float *v18; // edi
  double v19; // st4
  double v20; // st3
  long double v21; // st7
  double v22; // st6
  double v23; // st5
  double v24; // st4
  int v25; // ebx
  double v26; // st6
  double v27; // st5
  double v28; // st4
  float *v29; // edi
  double v30; // st7
  double v31; // st6
  float *v32; // edx
  int v33; // eax
  int v34; // edi
  int v35; // edx
  double v36; // st7
  float *v37; // edx
  double v38; // st7
  __int16 v39; // ax
  bool v40; // cc
  float v41; // [esp+0h] [ebp-1Ch]
  float v42; // [esp+4h] [ebp-18h]
  float v43; // [esp+4h] [ebp-18h]
  float v44; // [esp+4h] [ebp-18h]
  float v45; // [esp+8h] [ebp-14h]
  float v46; // [esp+Ch] [ebp-10h]
  float v47; // [esp+Ch] [ebp-10h]
  int v48; // [esp+10h] [ebp-Ch]
  float v49; // [esp+10h] [ebp-Ch]
  double v50; // [esp+10h] [ebp-Ch]
  int v51; // [esp+18h] [ebp-4h]

  result = 0;
  v51 = 0;
  if ( (int)this[72] > 0 )
  {
    v48 = 0;
    while ( 1 )
    {
      v3 = (unsigned __int16 *)(v48 + this[73]);
      v4 = *(_DWORD *)(*((_DWORD *)v3 + 2) + 12);
      v5 = *v3;
      v6 = v3[1];
      v7 = v3[2];
      if ( ((unsigned int)&unk_800000 & this[5]) != 0 )
      {
        v8 = *(float *)(v4 + (v5 << 6)) + *(float *)(v4 + (v6 << 6)) + *(float *)(v4 + (v7 << 6));
        v9 = *(float *)(v4 + (v5 << 6) + 4) + *(float *)(v4 + (v6 << 6) + 4) + *(float *)(v4 + (v7 << 6) + 4);
        v10 = *(float *)(v4 + (v5 << 6) + 8) + *(float *)(v4 + (v6 << 6) + 8) + *(float *)(v4 + (v7 << 6) + 8);
      }
      else
      {
        v11 = (float *)(v4 + 48 * v5);
        v8 = *v11 + *(float *)(v4 + 48 * v6) + *(float *)(v4 + 48 * v7);
        v12 = v4 + 48 * v7;
        v9 = v11[1] + *(float *)(v4 + 48 * v6 + 4) + *(float *)(v12 + 4);
        v10 = v11[2] + *(float *)(v4 + 48 * v6 + 8) + *(float *)(v12 + 8);
        v3 = (unsigned __int16 *)(v48 + this[73]);
      }
      v13 = v48;
      v46 = v10;
      *((float *)v3 + 4) = v8 * 0.33333334;
      *(float *)(v48 + this[73] + 20) = v9 * 0.33333334;
      *(float *)(v48 + this[73] + 24) = v46 * 0.33333334;
      if ( ((unsigned int)&unk_800000 & this[5]) != 0 )
      {
        v14 = this[73];
        v15 = *(float *)(v48 + v14 + 16);
        v16 = (float *)(v14 + v48);
        v17 = (float *)((v5 << 6) + v4);
        v18 = (float *)(v4 + (v6 << 6));
        v19 = v16[6] - v17[2];
        v20 = v16[5] - v17[1];
        v21 = v19 * v19 + v20 * v20 + (v15 - *v17) * (v15 - *v17);
        v22 = v16[4] - *v18;
        v23 = v16[5] - v18[1];
        v24 = v16[6] - v18[2];
        v42 = v24 * v24 + v23 * v23 + v22 * v22;
        if ( v21 <= v42 )
          v21 = v42;
        v25 = v7 << 6;
        v26 = v16[4] - *(float *)(v25 + v4);
        v27 = v16[5] - *(float *)(v25 + v4 + 4);
        v28 = v16[6] - *(float *)(v25 + v4 + 8);
        v43 = v28 * v28 + v27 * v27 + v26 * v26;
        if ( v21 <= v43 )
          v21 = v43;
        v13 = v48;
      }
      else
      {
        v17 = (float *)(48 * v5 + v4);
        v44 = *v17;
        v49 = v44;
        v29 = (float *)(48 * v6 + v4);
        v41 = v17[1];
        v47 = v41;
        v30 = v17[2];
        v45 = v17[2];
        if ( *v29 <= (double)v44 )
          v49 = *v29;
        v31 = *(float *)(v4 + 48 * v7);
        v32 = (float *)(48 * v7 + v4);
        if ( v31 <= v49 )
          v49 = *v32;
        if ( *v29 >= (double)v44 )
          v44 = *v29;
        if ( *v32 >= (double)v44 )
          v44 = *v32;
        if ( v29[1] <= (double)v41 )
          v47 = v29[1];
        if ( v32[1] <= (double)v47 )
          v47 = v32[1];
        if ( v29[1] >= (double)v41 )
          v41 = v29[1];
        if ( v32[1] >= (double)v41 )
          v41 = v32[1];
        if ( v30 >= v29[2] )
          v45 = v29[2];
        if ( v32[2] <= (double)v45 )
          v45 = v32[2];
        if ( v30 <= v29[2] )
          v30 = v29[2];
        if ( v30 <= v32[2] )
          v30 = v32[2];
        v21 = (v44 - v49) * (v44 - v49) + (v41 - v47) * (v41 - v47) + (v30 - v45) * (v30 - v45);
      }
      *(float *)(v13 + this[73] + 28) = sqrt(v21);
      v33 = this[73];
      v34 = this[75];
      v35 = 16 * *(_DWORD *)(v33 + v13 + 12);
      v36 = v17[2] * *(float *)(v35 + v34 + 8);
      v37 = (float *)(v34 + v35);
      *(float *)(v13 + v33 + 32) = v36 + v17[1] * v37[1] + *v17 * *v37;
      v38 = fabs(*v37);
      v50 = fabs(v37[1]);
      if ( v38 <= v50 )
        break;
      if ( v38 <= fabs(v37[2]) )
        goto LABEL_43;
      v39 = *v37 <= 0.0;
LABEL_45:
      *(_WORD *)(v13 + this[73] + 6) = v39;
      result = v51 + 1;
      v40 = ++v51 < this[72];
      v48 = v13 + 36;
      if ( !v40 )
        return result;
    }
    if ( fabs(v37[2]) < v50 )
    {
      v39 = 2;
      if ( v37[1] <= 0.0 )
        v39 = 3;
      goto LABEL_45;
    }
LABEL_43:
    v39 = 4;
    if ( v37[2] <= 0.0 )
      v39 = 5;
    goto LABEL_45;
  }
  return result;
}
