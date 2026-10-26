int __thiscall sub_54A630(int this)
{
  double v2; // st7
  int result; // eax
  int v4; // ebx
  int v5; // ecx
  float *v6; // esi
  double v7; // st7
  long double v8; // st7
  double v9; // st6
  double v10; // st6
  float v11; // edx
  int v12; // ecx
  float *v13; // ebp
  int i; // ebx
  float v15; // ecx
  int v16; // edx
  double v18; // st7
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c3
  double v21; // st7
  int *v22; // eax
  int v23; // ecx
  float v24; // edx
  int v25; // eax
  int v26; // edx
  float v27; // eax
  float v28; // [esp+0h] [ebp-B4h]
  float v29; // [esp+8h] [ebp-ACh]
  float v30; // [esp+1Ch] [ebp-98h]
  int v31; // [esp+20h] [ebp-94h] BYREF
  float v32; // [esp+24h] [ebp-90h]
  float v33; // [esp+28h] [ebp-8Ch]
  float v34; // [esp+2Ch] [ebp-88h]
  float v35; // [esp+30h] [ebp-84h]
  int v36; // [esp+34h] [ebp-80h] BYREF
  float v37; // [esp+38h] [ebp-7Ch]
  int v38; // [esp+3Ch] [ebp-78h]
  float v39; // [esp+40h] [ebp-74h]
  float v40; // [esp+44h] [ebp-70h]
  float v41; // [esp+48h] [ebp-6Ch]
  int v42; // [esp+4Ch] [ebp-68h] BYREF
  int v43; // [esp+50h] [ebp-64h]
  int v44; // [esp+54h] [ebp-60h]
  float v45; // [esp+58h] [ebp-5Ch]
  float v46; // [esp+5Ch] [ebp-58h]
  float v47; // [esp+60h] [ebp-54h]
  float v48; // [esp+64h] [ebp-50h]
  float v49; // [esp+68h] [ebp-4Ch]
  float v50; // [esp+6Ch] [ebp-48h]
  float v51; // [esp+70h] [ebp-44h]
  float v52; // [esp+74h] [ebp-40h]
  float v53; // [esp+78h] [ebp-3Ch]
  float v54; // [esp+7Ch] [ebp-38h]
  float v55; // [esp+80h] [ebp-34h]
  float v56; // [esp+84h] [ebp-30h]
  float v57; // [esp+88h] [ebp-2Ch]
  float v58; // [esp+8Ch] [ebp-28h]
  int v59[2]; // [esp+90h] [ebp-24h] BYREF
  float v60; // [esp+98h] [ebp-1Ch]
  float v61; // [esp+9Ch] [ebp-18h]
  float v62; // [esp+A0h] [ebp-14h]
  float v63; // [esp+A4h] [ebp-10h]
  int v64[2]; // [esp+A8h] [ebp-Ch] BYREF
  float v65; // [esp+B0h] [ebp-4h]

  if ( dword_BE1204 == 2 )
    v2 = sub_5210A0(&dword_BE120C);
  else
    v2 = dbl_FB1D18;
  result = *(_DWORD *)(this + 108);
  v4 = 0;
  v34 = v2;
  v38 = 0;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(this + 112);
      v6 = *(float **)(v5 + 4 * v4);
      if ( v34 > (double)v6[3] || v34 < (double)v6[2] )
      {
        v26 = *(_DWORD *)(this + 108) - 1;
        *(_DWORD *)(this + 108) = v26;
        *(_DWORD *)(v5 + 4 * *((_DWORD *)v6 + 1)) = *(_DWORD *)(v5 + 4 * v26);
        *(float *)(*(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *((_DWORD *)v6 + 1)) + 4) = v6[1];
        v27 = *v6;
        v6[1] = NAN;
        sub_5FCB20(LODWORD(v27));
        --v4;
        goto LABEL_33;
      }
      v7 = v34 - v6[2];
      v30 = v7;
      v61 = v7 * v6[14];
      v50 = v61;
      v62 = v30 * v6[15];
      v51 = v62;
      v63 = v30 * v6[16];
      v52 = v63;
      *(float *)&v44 = v61 + v6[11];
      v31 = v44;
      v45 = v62 + v6[12];
      v32 = v45;
      v46 = v63 + v6[13];
      v33 = v46;
      v8 = pow(v30 * *(float *)(this + 72), *(float *)(this + 76));
      v9 = v6[26];
      v56 = v9 * *(float *)(this + 36);
      v47 = v56;
      v57 = v9 * *(float *)(this + 40);
      v48 = v57;
      v58 = v9 * *(float *)(this + 44);
      v49 = v58;
      v53 = v56 + *(float *)(this + 24);
      v39 = v53;
      v54 = v57 + *(float *)(this + 28);
      v40 = v54;
      v10 = v58 + *(float *)(this + 32);
      v35 = *(float *)(this + 12);
      v55 = v10;
      v41 = v55;
      v11 = *(float *)(this + 16);
      v40 = v54 * v8;
      v41 = v55 * v8;
      v37 = *(float *)(this + 20);
      v35 = v53 * v8 + v35;
      *(float *)&v36 = v40 + v11;
      v37 = v41 + v37;
      v32 = *(float *)&v36 * 0.5 + v45;
      if ( dword_B71464 == 1 )
      {
        v22 = (int *)(*(&dword_91E088 + dword_91E078) + 5732);
        v23 = *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 5736);
        v64[0] = *v22;
        v24 = *((float *)v22 + 2);
        v64[1] = v23;
        v65 = v24;
        if ( fabs(*(float *)v64 - *(float *)&v31) < flt_903998 && fabs(v65 - v33) < flt_903998 )
          sub_548520((float *)&v31, (float *)&v36, v6 + 21, (float *)v64, COERCE_FLOAT(1));
      }
      else if ( dword_B71464 > 1 && dword_B71464 <= 3 )
      {
        if ( dword_91E07C )
          v12 = *((_DWORD *)dword_91E07C + 5617);
        else
          v12 = 104;
        v43 = 104;
        if ( (dword_B71464 & 1) == 0 )
          v43 = v12;
        v28 = v33 + *(float *)&v31;
        v13 = sub_5432C0(&flt_BE23D8, v28, flt_90399C, &v42);
        for ( i = 0; i < v42; ++i )
        {
          v15 = v13[i];
          v59[0] = *(_DWORD *)(LODWORD(v15) + 5716);
          v16 = *(_DWORD *)(LODWORD(v15) + 5720);
          v60 = *(float *)(LODWORD(v15) + 5724);
          v59[1] = v16;
          if ( fabs(*(float *)v59 - *(float *)&v31) < flt_903998
            && fabs(v60 - v33) < flt_903998
            && v43 != *(_DWORD *)(LODWORD(v15) + 4) )
          {
            sub_548520((float *)&v31, (float *)&v36, v6 + 21, (float *)v59, 0.0);
          }
        }
        v4 = v38;
      }
      sub_5FCCB0(*(_DWORD *)v6, v31, LODWORD(v32), LODWORD(v33));
      sub_5FCD10(*(_DWORD *)v6, LODWORD(v35), v36, LODWORD(v37));
      v18 = v30;
      if ( !(v19 | v20) )
        break;
      if ( v18 <= v6[5] )
      {
        v21 = v30 * v6[8];
        goto LABEL_30;
      }
      v25 = sub_4015C0(v6[10]);
LABEL_31:
      sub_5FC760(*(_DWORD *)v6, &byte_FFFFFF[0x1000000 * v25]);
LABEL_33:
      result = *(_DWORD *)(this + 108);
      v38 = ++v4;
      if ( v4 >= result )
        return result;
    }
    v21 = 1.0 - (v18 - v6[6]) * v6[9];
LABEL_30:
    v29 = v21 * v6[10];
    v25 = sub_4015C0(v29);
    goto LABEL_31;
  }
  return result;
}
