int __thiscall sub_548F30(int this)
{
  int result; // eax
  float *v3; // eax
  float v4; // ecx
  float v5; // edx
  double v6; // st7
  double v7; // st7
  int v8; // edi
  int v9; // ecx
  int v10; // esi
  float *v11; // edi
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v18; // st7
  char v19; // c0
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int v23; // ecx
  float v24; // edx
  long double v25; // st7
  float *v26; // eax
  int v27; // ebx
  float v28; // ecx
  long double v29; // st7
  float v30; // edx
  double v31; // st7
  double v32; // st7
  int v33; // edi
  int v34; // edx
  int v35; // eax
  float v36; // [esp+0h] [ebp-FCh]
  int v37; // [esp+18h] [ebp-E4h]
  float v38; // [esp+1Ch] [ebp-E0h]
  float v39; // [esp+20h] [ebp-DCh]
  int v40; // [esp+24h] [ebp-D8h] BYREF
  int i; // [esp+28h] [ebp-D4h]
  float v42; // [esp+2Ch] [ebp-D0h] BYREF
  float v43; // [esp+30h] [ebp-CCh]
  float v44; // [esp+34h] [ebp-C8h]
  float v45; // [esp+38h] [ebp-C4h]
  float v46; // [esp+3Ch] [ebp-C0h]
  float v47; // [esp+40h] [ebp-BCh]
  float v48; // [esp+44h] [ebp-B8h]
  float v49; // [esp+48h] [ebp-B4h]
  float v50; // [esp+4Ch] [ebp-B0h]
  float v51; // [esp+50h] [ebp-ACh]
  float v52; // [esp+54h] [ebp-A8h]
  float v53; // [esp+58h] [ebp-A4h]
  float v54; // [esp+5Ch] [ebp-A0h]
  float v55; // [esp+60h] [ebp-9Ch]
  float v56; // [esp+64h] [ebp-98h]
  float v57; // [esp+68h] [ebp-94h]
  float v58; // [esp+6Ch] [ebp-90h]
  float v59; // [esp+70h] [ebp-8Ch]
  float v60; // [esp+74h] [ebp-88h]
  float v61; // [esp+78h] [ebp-84h]
  float v62; // [esp+7Ch] [ebp-80h]
  float v63; // [esp+80h] [ebp-7Ch]
  float v64; // [esp+84h] [ebp-78h]
  float v65; // [esp+88h] [ebp-74h]
  float v66; // [esp+8Ch] [ebp-70h]
  float v67; // [esp+90h] [ebp-6Ch]
  float v68; // [esp+94h] [ebp-68h]
  float v69; // [esp+98h] [ebp-64h]
  float v70; // [esp+9Ch] [ebp-60h]
  float v71; // [esp+A0h] [ebp-5Ch]
  float v72; // [esp+A4h] [ebp-58h]
  float v73; // [esp+A8h] [ebp-54h]
  float v74; // [esp+ACh] [ebp-50h]
  float *v75; // [esp+B0h] [ebp-4Ch]
  float v76; // [esp+B4h] [ebp-48h]
  int v77; // [esp+B8h] [ebp-44h]
  float v78; // [esp+BCh] [ebp-40h]
  float v79; // [esp+C0h] [ebp-3Ch]
  int v80; // [esp+C4h] [ebp-38h]
  float v81; // [esp+C8h] [ebp-34h]
  float v82; // [esp+CCh] [ebp-30h]
  float v83; // [esp+D0h] [ebp-2Ch]
  float v84; // [esp+D4h] [ebp-28h]
  float v85[6]; // [esp+D8h] [ebp-24h] BYREF
  float v86; // [esp+F0h] [ebp-Ch] BYREF

  result = sub_40DCE0(&dword_91BF20);
  if ( !result )
    return result;
  v3 = (float *)(result + 36);
  v4 = *v3;
  v5 = v3[1];
  v74 = v3[2];
  v72 = v4;
  v73 = v5;
  if ( dword_BE1204 == 2 )
  {
    if ( sub_5210D0(&dword_BE120C) == 5 )
    {
      v38 = 0.0;
      goto LABEL_8;
    }
    v6 = sub_5210C0(&dword_BE120C);
  }
  else
  {
    v6 = dbl_FB1D10;
  }
  v38 = v6;
LABEL_8:
  if ( dword_BE1204 == 2 )
    v7 = sub_5210A0(&dword_BE120C);
  else
    v7 = dbl_FB1D18;
  result = *(_DWORD *)(this + 108);
  v8 = 0;
  v39 = v7;
  for ( i = 0; v8 < result; i = v8 )
  {
    v9 = *(_DWORD *)(this + 112);
    v10 = *(_DWORD *)(v9 + 4 * v8);
    if ( v39 > (double)*(float *)(v10 + 12) || v39 < (double)*(float *)(v10 + 8) )
    {
      v34 = *(_DWORD *)(this + 108) - 1;
      *(_DWORD *)(this + 108) = v34;
      *(_DWORD *)(v9 + 4 * *(_DWORD *)(v10 + 4)) = *(_DWORD *)(v9 + 4 * v34);
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *(_DWORD *)(v10 + 4)) + 4) = *(_DWORD *)(v10 + 4);
      v35 = *(_DWORD *)v10;
      *(_DWORD *)(v10 + 4) = -1;
      sub_5FCB20(v35);
      v33 = v8 - 1;
    }
    else
    {
      v11 = (float *)(v10 + 44);
      *(float *)(v10 + 44) = v38 * *(float *)(v10 + 56) + *(float *)(v10 + 44);
      *(float *)(v10 + 48) = v38 * *(float *)(v10 + 60) + *(float *)(v10 + 48);
      *(float *)(v10 + 52) = v38 * *(float *)(v10 + 64) + *(float *)(v10 + 52);
      *(float *)(v10 + 60) = *(float *)(v10 + 60) - fabs(v38) * 9.8100004;
      v12 = *(float *)(v10 + 52) * *(float *)(v10 + 92)
          + *(float *)(v10 + 48) * *(float *)(v10 + 88)
          + *(float *)(v10 + 44) * *(float *)(v10 + 84);
      if ( v12 < *(float *)(v10 + 100) )
      {
        v13 = *(float *)(v10 + 100) - v12;
        v63 = v13 * *(float *)(v10 + 84);
        v54 = v63;
        v64 = v13 * *(float *)(v10 + 88);
        v55 = v64;
        v65 = v13 * *(float *)(v10 + 92);
        v56 = v65;
        *v11 = v63 + *v11;
        *(float *)(v10 + 48) = v55 + *(float *)(v10 + 48);
        *(float *)(v10 + 52) = v56 + *(float *)(v10 + 52);
        v14 = *(float *)(v10 + 64) * *(float *)(v10 + 92)
            + *(float *)(v10 + 60) * *(float *)(v10 + 88)
            + *(float *)(v10 + 56) * *(float *)(v10 + 84);
        v15 = v14 + v14;
        v69 = v15 * *(float *)(v10 + 84);
        v60 = v69;
        v70 = v15 * *(float *)(v10 + 88);
        v61 = v70;
        v71 = v15 * *(float *)(v10 + 92);
        v16 = *(float *)(v10 + 56);
        v62 = v71;
        *(float *)(v10 + 56) = v16 - v69;
        *(float *)(v10 + 60) = *(float *)(v10 + 60) - v61;
        *(float *)(v10 + 64) = *(float *)(v10 + 64) - v62;
        v18 = *(float *)(v10 + 56);
        if ( v19 )
        {
          *(float *)(v10 + 56) = v18 + v18;
          *(float *)(v10 + 60) = *(float *)(v10 + 60) + *(float *)(v10 + 60);
          v20 = *(float *)(v10 + 64) + *(float *)(v10 + 64);
        }
        else
        {
          *(float *)(v10 + 56) = v18 * 0.5;
          *(float *)(v10 + 60) = *(float *)(v10 + 60) * 0.5;
          v20 = *(float *)(v10 + 64) * 0.5;
        }
        *(float *)(v10 + 64) = v20;
      }
      if ( (dword_B71488 & 3) != 0 )
      {
        v45 = *(float *)(v10 + 56) * 0.03125;
        v21 = *(float *)(v10 + 60);
        v42 = v45;
        v46 = v21 * 0.03125;
        v22 = *(float *)(v10 + 64);
        v43 = v46;
        v47 = v22 * 0.03125;
        v44 = v47;
        if ( dword_B71488 == 1 )
        {
          if ( dword_91E07C )
          {
            v23 = *((_DWORD *)dword_91E07C + 699);
            v24 = *((float *)dword_91E07C + 700);
            v76 = *((float *)dword_91E07C + 698);
            v25 = v76 - *v11;
            v77 = v23;
            v78 = v24;
            if ( fabs(v25) < 4.0 && fabs(v78 - *(float *)(v10 + 52)) < 4.0 )
            {
              v26 = sub_401250((float *)(v10 + 44), &v42, &v86);
              return off_16C9244(*(_DWORD *)v26, *((_DWORD *)v26 + 1));
            }
          }
        }
        else
        {
          v36 = *(float *)(v10 + 52) + *v11;
          v75 = sub_5432C0(&flt_BE23D8, v36, 5.6568542, &v40);
          v27 = 0;
          if ( v40 > 0 )
          {
            do
            {
              v28 = v75[v27];
              v79 = *(float *)(LODWORD(v28) + 2776);
              v29 = v79 - *v11;
              v30 = *(float *)(LODWORD(v28) + 2784);
              v80 = *(_DWORD *)(LODWORD(v28) + 2780);
              v81 = v30;
              if ( fabs(v29) < 4.0
                && fabs(v81 - *(float *)(v10 + 52)) < 4.0
                && ((dword_B71488 & 1) != 0 || *(_DWORD *)(LODWORD(v28) + 4) != dword_91E078) )
              {
                v66 = v42 + *v11;
                v82 = v66;
                v67 = v43 + *(float *)(v10 + 48);
                v83 = v67;
                v68 = v44 + *(float *)(v10 + 52);
                v84 = v68;
                sub_544170();
              }
              ++v27;
            }
            while ( v27 < v37 );
          }
        }
      }
      v48 = *(float *)(v10 + 56) - v72;
      v31 = *(float *)(v10 + 60);
      v51 = v48;
      v49 = v31 - v73;
      v32 = *(float *)(v10 + 64);
      v52 = v49;
      v50 = v32 - v74;
      v53 = v50;
      v57 = v48 * 0.03125;
      v85[0] = v57;
      v58 = v49 * 0.03125;
      v85[1] = v58;
      v59 = v50 * 0.03125;
      v85[2] = v59;
      sub_542590((float *)this, v10, v85);
      v33 = i;
    }
    result = *(_DWORD *)(this + 108);
    v8 = v33 + 1;
  }
  return result;
}
