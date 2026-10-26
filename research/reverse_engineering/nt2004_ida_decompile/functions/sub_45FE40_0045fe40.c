int __fastcall sub_45FE40(int a1, int a2, _DWORD *a3)
{
  unsigned int v4; // ebp
  float *v5; // edi
  float *v6; // ebx
  float v7; // eax
  float v8; // ecx
  float *v9; // esi
  float *v10; // eax
  float v11; // ecx
  float v12; // edx
  float v13; // eax
  double v14; // st7
  long double v15; // st5
  long double v16; // st7
  float *v17; // edx
  double v18; // st7
  float *v19; // ecx
  double v20; // st6
  double v21; // st5
  double v22; // st7
  double v23; // st6
  double v24; // st5
  double v25; // st4
  double v26; // st3
  long double v27; // st5
  long double v28; // st5
  double v29; // st7
  double v30; // st6
  double v31; // st5
  double v32; // st7
  double v33; // st7
  double v34; // st6
  double v35; // st5
  double v36; // st7
  double v37; // st6
  float v38; // edx
  float v39; // eax
  float v40; // ecx
  float v41; // edx
  int result; // eax
  float v43; // ecx
  float v44; // eax
  float v45; // ecx
  float v46; // edx
  float *v47; // ebp
  float v48; // ebx
  float *v49; // edi
  float v50; // ecx
  float v51; // ebx
  float v52; // [esp+0h] [ebp-74h]
  float v53; // [esp+14h] [ebp-60h]
  float v54; // [esp+14h] [ebp-60h]
  float v55; // [esp+18h] [ebp-5Ch] BYREF
  float v56; // [esp+1Ch] [ebp-58h]
  float v57; // [esp+20h] [ebp-54h]
  float v58; // [esp+24h] [ebp-50h]
  float v59; // [esp+28h] [ebp-4Ch]
  float v60; // [esp+2Ch] [ebp-48h]
  float v61; // [esp+30h] [ebp-44h]
  float v62; // [esp+34h] [ebp-40h]
  float v63; // [esp+38h] [ebp-3Ch]
  float v64; // [esp+3Ch] [ebp-38h]
  float v65; // [esp+40h] [ebp-34h]
  float v66; // [esp+44h] [ebp-30h]
  float v67; // [esp+48h] [ebp-2Ch]
  float v68; // [esp+4Ch] [ebp-28h]
  float v69; // [esp+50h] [ebp-24h]
  float v70; // [esp+54h] [ebp-20h]
  float v71; // [esp+58h] [ebp-1Ch]
  float v72; // [esp+5Ch] [ebp-18h]
  float v73; // [esp+60h] [ebp-14h]
  float v74; // [esp+64h] [ebp-10h]
  int v75; // [esp+68h] [ebp-Ch] BYREF
  float v76; // [esp+6Ch] [ebp-8h]
  float v77; // [esp+70h] [ebp-4h]
  float v78; // [esp+78h] [ebp+4h]
  float v79; // [esp+78h] [ebp+4h]

  v78 = dbl_7DA9C8;
  v4 = *a3 & 0x3F;
  v55 = *(float *)&a1;
  if ( dbl_7DA9C8 >= 0.0 )
  {
    if ( v78 > 0.033333335 )
      v78 = 0.033333335;
  }
  else
  {
    v78 = 0.0;
  }
  v5 = (float *)(56 * v4 + a1 + 30152);
  v6 = (float *)(a3 + 9);
  v7 = v6[1];
  v8 = v6[2];
  v60 = *v6;
  v9 = v5 + 2;
  v61 = v7;
  v62 = v8;
  v69 = v60 - v5[2];
  v72 = v69;
  v70 = v7 - v5[3];
  v73 = v70;
  v71 = v8 - v5[4];
  v74 = v71;
  v52 = 1.0 / v78;
  v10 = (float *)sub_518490((int)&v75, v52);
  v11 = *v10;
  v12 = v10[1];
  v13 = v10[2];
  v57 = v11;
  v53 = *(float *)&dword_769B5C;
  v58 = v12;
  v59 = v13;
  v56 = flt_769A90 - *(float *)&dword_769B5C;
  if ( sub_45DFA0((unsigned __int8 *)(LODWORD(v55) + 27716), v4, &v55, COERCE_FLOAT(1))
    && v55 > (double)v53
    && v56 > 0.0 )
  {
    v14 = (v55 - v53) / v56;
    if ( v14 >= 1.0 )
      v14 = 1.0;
    v15 = (flt_769BA4 - flt_769B80) * (1.0 - v14) + flt_769B80;
    if ( fabs(v15 - *v5) > 5.0 )
    {
      *v5 = v15;
      v16 = sqrt(v15);
      v5[1] = v16 * flt_769BC8 + v16 * flt_769BC8;
    }
    v17 = v5 + 11;
    v18 = v78 * v5[11];
    v19 = v5 + 8;
    v20 = v78 * v5[12];
    v69 = v5[11];
    v21 = v78 * v5[13];
    v70 = v5[12];
    v77 = v21;
    v71 = v5[13];
    v72 = v18 + v5[8];
    v22 = v20 + v5[9];
    v23 = v77 + v5[10];
    v24 = v57 - v5[5];
    v25 = v58 - v5[6];
    v77 = v59 - v5[7];
    v26 = 1.0 / v78;
    v54 = v26;
    v63 = v26 * v24;
    v66 = v63;
    v64 = v54 * v25;
    v67 = v64;
    v65 = v54 * v77;
    v68 = v65;
    v27 = v65 * v65 + v64 * v64 + v63 * v63;
    if ( v27 > 2500.0 )
    {
      v28 = 50.0 / sqrt(v27);
      v66 = v63 * v28;
      v67 = v67 * v28;
      v68 = v68 * v28;
    }
    v63 = v60 - v72;
    v64 = v61 - v22;
    v65 = v62 - v23;
    v72 = v57 - v69;
    v73 = v58 - v70;
    v74 = v59 - v71;
    if ( v65 * v65 + v64 * v64 + v63 * v63 <= 256.0 )
    {
      v29 = v5[1];
      v30 = v72 * v29;
      v76 = v73 * v29;
      v77 = v74 * v29;
      v31 = *v5;
      v72 = v63 * v31;
      v73 = v64 * v31;
      v74 = v31 * v65;
      v77 = v74 + v77;
      v72 = v72 + v30 + v66;
      *(float *)&v75 = v72 * v78;
      v76 = (v73 + v76 + v67) * v78;
      v32 = (v68 + v77) * v78;
      *v17 = *(float *)&v75 + *v17;
      v5[12] = v76 + v5[12];
      v5[13] = v32 + v5[13];
      v33 = v69 + *v17;
      v34 = v70 + v5[12];
      v77 = v71 + v5[13];
      v35 = v78 * 0.5;
      v79 = v35;
      v72 = v35 * v33;
      v36 = v79 * v34;
      v37 = v79 * v77;
      *v19 = v72 + *v19;
      v5[9] = v36 + v5[9];
      v5[10] = v37 + v5[10];
    }
    else
    {
      *v19 = v60;
      v5[9] = v61;
      v5[10] = v62;
      *v17 = v57;
      v5[12] = v58;
      v5[13] = v59;
    }
    *v6 = *v19;
    v38 = v60;
    v6[1] = v5[9];
    v39 = v61;
    v6[2] = v5[10];
    v40 = v62;
    *v9 = v38;
    v41 = v57;
    v5[3] = v39;
    result = LODWORD(v58);
    v5[4] = v40;
    v43 = v59;
    v5[5] = v41;
    *((_DWORD *)v5 + 6) = result;
    v5[7] = v43;
  }
  else
  {
    v44 = v60;
    v45 = v61;
    v46 = v62;
    v5[8] = v60;
    v5[9] = v45;
    v5[10] = v46;
    v47 = v5 + 11;
    v5[11] = v57;
    v48 = v58;
    *v9 = v44;
    result = LODWORD(v57);
    v49 = v5 + 5;
    v9[1] = v45;
    v50 = v58;
    v47[1] = v48;
    v51 = v59;
    *(_DWORD *)v49 = result;
    v49[1] = v50;
    v49[2] = v51;
    v9[2] = v46;
    v47[2] = v51;
  }
  return result;
}
