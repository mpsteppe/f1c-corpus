int __thiscall sub_4F2E10(int this)
{
  double v2; // st7
  int result; // eax
  int v4; // ebx
  float *v5; // esi
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st7
  long double v10; // st7
  double v11; // st6
  double v12; // st5
  float v13; // ecx
  int v14; // ecx
  float *v15; // ebp
  int j; // ebx
  float v17; // ecx
  double v19; // st7
  unsigned __int8 v20; // c0
  unsigned __int8 v21; // c3
  int v22; // eax
  float *v23; // eax
  float v24; // [esp+0h] [ebp-ACh]
  float v25; // [esp+1Ch] [ebp-90h]
  float v26; // [esp+20h] [ebp-8Ch]
  float v27; // [esp+20h] [ebp-8Ch]
  float v28; // [esp+24h] [ebp-88h] BYREF
  float v29; // [esp+28h] [ebp-84h]
  int v30; // [esp+2Ch] [ebp-80h]
  float v31; // [esp+30h] [ebp-7Ch] BYREF
  float v32; // [esp+34h] [ebp-78h]
  float v33; // [esp+38h] [ebp-74h]
  float v34; // [esp+3Ch] [ebp-70h]
  int i; // [esp+40h] [ebp-6Ch]
  int v36[2]; // [esp+44h] [ebp-68h] BYREF
  float v37; // [esp+4Ch] [ebp-60h]
  float v38; // [esp+50h] [ebp-5Ch]
  float v39; // [esp+54h] [ebp-58h]
  float v40; // [esp+58h] [ebp-54h]
  float v41; // [esp+5Ch] [ebp-50h]
  int v42; // [esp+60h] [ebp-4Ch]
  float v43; // [esp+64h] [ebp-48h]
  float v44; // [esp+68h] [ebp-44h]
  int v45; // [esp+6Ch] [ebp-40h]
  float v46[2]; // [esp+70h] [ebp-3Ch] BYREF
  float v47; // [esp+78h] [ebp-34h]
  int v48; // [esp+7Ch] [ebp-30h]
  float v49[2]; // [esp+80h] [ebp-2Ch] BYREF
  float v50; // [esp+88h] [ebp-24h]
  int v51; // [esp+8Ch] [ebp-20h]
  float v52; // [esp+90h] [ebp-1Ch]
  float v53; // [esp+98h] [ebp-14h]
  float v54; // [esp+9Ch] [ebp-10h]
  float v55; // [esp+A8h] [ebp-4h]

  if ( dword_7D5DA4 == 2 )
    v2 = sub_4D9E20(&dword_7D5DAC);
  else
    v2 = dbl_7DA9D0;
  result = *(_DWORD *)(this + 108);
  v4 = 0;
  v34 = v2;
  for ( i = 0; v4 < result; i = v4 )
  {
    v5 = *(float **)(*(_DWORD *)(this + 112) + 4 * v4);
    if ( v34 > (double)v5[3] || v34 < (double)v5[2] )
    {
      sub_4F2B40((_DWORD *)this, v5);
      --v4;
    }
    else
    {
      v6 = v34 - v5[2];
      v25 = v6;
      v7 = v6 * v5[14];
      v8 = v25 * v5[15];
      v55 = v25 * v5[16];
      v39 = v7 + v5[11];
      v40 = v8 + v5[12];
      v9 = v55 + v5[13];
      v31 = v39;
      v32 = v40;
      v41 = v9;
      v33 = v41;
      v10 = pow(v25 * *(float *)(this + 72), *(float *)(this + 76));
      v11 = v5[26];
      v12 = v11 * *(float *)(this + 36);
      v53 = v11 * *(float *)(this + 40);
      v54 = v11 * *(float *)(this + 44);
      *(float *)&v42 = v12 + *(float *)(this + 24);
      v36[1] = v42;
      v43 = v53 + *(float *)(this + 28);
      v37 = v43;
      v26 = *(float *)(this + 12);
      v44 = v54 + *(float *)(this + 32);
      v38 = v44;
      v13 = *(float *)(this + 20);
      v28 = *(float *)(this + 16);
      v37 = v43 * v10;
      v38 = v44 * v10;
      v27 = *(float *)&v42 * v10 + v26;
      v28 = v37 + v28;
      v29 = v38 + v13;
      v32 = v28 * 0.5 + v40;
      if ( dword_767E20 == 1 )
      {
        v23 = (float *)(dword_75AAD0[dword_75AAC0] + 4748);
        v49[0] = *v23;
        v49[1] = v23[1];
        v50 = v23[2];
        if ( fabs(v49[0] - v31) < flt_611398 && fabs(v50 - v33) < flt_611398 )
          sub_4F3390(&v31, &v28, v5 + 21, v49);
      }
      else if ( dword_767E20 > 1 && dword_767E20 <= 3 )
      {
        if ( dword_75AAC4 )
          v14 = *(int *)(dword_75AAC4 + 25248);
        else
          v14 = 48;
        v30 = 48;
        if ( (dword_767E20 & 1) == 0 )
          v30 = v14;
        v24 = v33 + v31;
        v15 = sub_4F1080(flt_7D6BD0, v24, flt_61139C, v36);
        for ( j = 0; j < v36[0]; ++j )
        {
          v17 = v15[j];
          v46[0] = *(float *)(LODWORD(v17) + 4664);
          v46[1] = *(float *)(LODWORD(v17) + 4668);
          v47 = *(float *)(LODWORD(v17) + 4672);
          if ( fabs(v46[0] - v31) < flt_611398 && fabs(v47 - v33) < flt_611398 && v30 != *(_DWORD *)(LODWORD(v17) + 4) )
            sub_4F3390(&v31, &v28, v5 + 21, v46);
        }
        v4 = i;
      }
      sub_5B0B40(*(_DWORD *)v5, LODWORD(v31), LODWORD(v32), LODWORD(v33));
      sub_5B0B90(*(_DWORD *)v5, LODWORD(v27), LODWORD(v28), LODWORD(v29));
      v19 = v25;
      if ( v20 | v21 )
      {
        if ( v19 <= v5[5] )
        {
          *(float *)&v30 = v25 * v5[8] * v5[10];
          v45 = (int)*(float *)&v30;
          v22 = v45;
        }
        else
        {
          v52 = v5[10];
          v51 = (int)v52;
          v22 = v51;
        }
      }
      else
      {
        *(float *)&v30 = (1.0 - (v19 - v5[6]) * v5[9]) * v5[10];
        v48 = (int)*(float *)&v30;
        v22 = v48;
      }
      sub_5B0C30(*(_DWORD *)v5, *((_DWORD *)v5 + 24) + (v22 << 24));
    }
    result = *(_DWORD *)(this + 108);
    ++v4;
  }
  return result;
}
