int __thiscall sub_548800(int this)
{
  double v2; // st7
  int result; // eax
  int v4; // ebp
  int v5; // ecx
  float *v6; // esi
  int v7; // ebx
  double v8; // st7
  double v9; // st7
  int i; // ebp
  float v11; // ecx
  int v12; // edx
  double v14; // st7
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c3
  double v17; // st7
  int *v18; // ebx
  int v19; // eax
  float v20; // ecx
  int v21; // eax
  int v22; // edx
  float v23; // eax
  float v24; // [esp+0h] [ebp-A8h]
  float v25; // [esp+8h] [ebp-A0h]
  float v26; // [esp+1Ch] [ebp-8Ch]
  float v27; // [esp+20h] [ebp-88h]
  int v28; // [esp+24h] [ebp-84h] BYREF
  float v29; // [esp+28h] [ebp-80h]
  float v30; // [esp+2Ch] [ebp-7Ch]
  int v31; // [esp+30h] [ebp-78h]
  int v32; // [esp+34h] [ebp-74h] BYREF
  float v33; // [esp+38h] [ebp-70h]
  int v34; // [esp+3Ch] [ebp-6Ch] BYREF
  float v35; // [esp+40h] [ebp-68h]
  float v36; // [esp+44h] [ebp-64h]
  float v37; // [esp+48h] [ebp-60h]
  float v38; // [esp+4Ch] [ebp-5Ch]
  float v39; // [esp+50h] [ebp-58h]
  float v40; // [esp+54h] [ebp-54h]
  float v41; // [esp+58h] [ebp-50h]
  float v42; // [esp+5Ch] [ebp-4Ch]
  float v43; // [esp+60h] [ebp-48h]
  float v44; // [esp+64h] [ebp-44h]
  float v45; // [esp+68h] [ebp-40h]
  float v46; // [esp+6Ch] [ebp-3Ch]
  float v47; // [esp+70h] [ebp-38h]
  float v48; // [esp+74h] [ebp-34h]
  int v49; // [esp+78h] [ebp-30h]
  float v50; // [esp+7Ch] [ebp-2Ch]
  float *v51; // [esp+80h] [ebp-28h]
  int v52[2]; // [esp+84h] [ebp-24h] BYREF
  float v53; // [esp+8Ch] [ebp-1Ch]
  int v54; // [esp+90h] [ebp-18h]
  float v55; // [esp+94h] [ebp-14h]
  float v56; // [esp+98h] [ebp-10h]
  int v57[2]; // [esp+9Ch] [ebp-Ch] BYREF
  float v58; // [esp+A4h] [ebp-4h]

  if ( dword_BE1204 == 2 )
    v2 = sub_5210A0(&dword_BE120C);
  else
    v2 = dbl_FB1D18;
  result = *(_DWORD *)(this + 108);
  v4 = 0;
  v27 = v2;
  v31 = 0;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(this + 112);
      v6 = *(float **)(v5 + 4 * v4);
      if ( v27 > (double)v6[3] || v27 < (double)v6[2] )
      {
        v22 = *(_DWORD *)(this + 108) - 1;
        *(_DWORD *)(this + 108) = v22;
        *(_DWORD *)(v5 + 4 * *((_DWORD *)v6 + 1)) = *(_DWORD *)(v5 + 4 * v22);
        *(float *)(*(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *((_DWORD *)v6 + 1)) + 4) = v6[1];
        v23 = *v6;
        v6[1] = NAN;
        sub_5FCB20(LODWORD(v23));
        --v4;
        goto LABEL_27;
      }
      v7 = *((_DWORD *)v6 + 17);
      v8 = v27 - v6[2];
      v26 = v8;
      v36 = v8 * v6[14];
      v45 = v36;
      v37 = v26 * v6[15];
      v46 = v37;
      v38 = v26 * v6[16];
      v47 = v38;
      *(float *)&v54 = v36 + v6[11];
      v28 = v54;
      v55 = v37 + v6[12];
      v29 = v55;
      v56 = v38 + v6[13];
      v30 = v56;
      v9 = v26 * v6[26];
      v39 = v9 * *(float *)(this + 24);
      v42 = v39;
      v40 = v9 * *(float *)(this + 28);
      v43 = v40;
      v41 = v9 * *(float *)(this + 32);
      v44 = v41;
      v48 = v39 + *(float *)(this + 12);
      v33 = v48;
      *(float *)&v49 = v40 + *(float *)(this + 16);
      v34 = v49;
      v50 = v41 + *(float *)(this + 20);
      v35 = v50;
      if ( v7 >= 0 )
      {
        if ( byte_B71428 )
        {
          v24 = v30 + *(float *)&v28;
          v51 = sub_5432C0(&flt_BE23D8, v24, flt_90399C, &v32);
          for ( i = 0; i < v32; ++i )
          {
            v11 = v51[i];
            v52[0] = *(_DWORD *)(LODWORD(v11) + 5716);
            v12 = *(_DWORD *)(LODWORD(v11) + 5720);
            v53 = *(float *)(LODWORD(v11) + 5724);
            v52[1] = v12;
            if ( fabs(*(float *)v52 - *(float *)&v28) < flt_903998
              && fabs(v53 - v30) < flt_903998
              && v7 != *(_DWORD *)(LODWORD(v11) + 4) )
            {
              sub_548520((float *)&v28, (float *)&v34, v6 + 21, (float *)v52, 0.0);
            }
          }
          v4 = v31;
        }
        else
        {
          v18 = (int *)((char *)&unk_921B04 + 22616 * v7);
          v19 = v18[1];
          v20 = *((float *)v18 + 2);
          v57[0] = *v18;
          v57[1] = v19;
          v58 = v20;
          if ( fabs(*(float *)v57 - *(float *)&v28) < flt_903998 && fabs(v58 - v30) < flt_903998 )
            sub_548520((float *)&v28, (float *)&v34, v6 + 21, (float *)v57, 0.0);
        }
      }
      sub_5FCCB0(*(_DWORD *)v6, v28, LODWORD(v29), LODWORD(v30));
      sub_5FCD10(*(_DWORD *)v6, LODWORD(v33), v34, LODWORD(v35));
      v14 = v26;
      if ( !(v15 | v16) )
        break;
      if ( v14 <= v6[5] )
      {
        v17 = v26 * v6[8];
        goto LABEL_24;
      }
      v21 = sub_4015C0(v6[10]);
LABEL_25:
      sub_5FC760(*(_DWORD *)v6, &off_16C9A78[0x1000000 * v21]);
LABEL_27:
      result = *(_DWORD *)(this + 108);
      v31 = ++v4;
      if ( v4 >= result )
        return result;
    }
    v17 = 1.0 - (v14 - v6[6]) * v6[9];
LABEL_24:
    v25 = v17 * v6[10];
    v21 = sub_4015C0(v25);
    goto LABEL_25;
  }
  return result;
}
