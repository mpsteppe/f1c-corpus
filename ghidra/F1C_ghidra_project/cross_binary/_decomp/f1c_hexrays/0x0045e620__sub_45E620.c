// f1c  0x0045e620  size=1243
float *__fastcall sub_45E620(int a1, int a2, int a3)
{
  unsigned int v4; // edi
  float *v5; // ebp
  float v6; // eax
  float v7; // ecx
  int v8; // esi
  int v9; // eax
  float v10; // edx
  float v11; // ebx
  double v12; // st7
  long double v13; // st5
  long double v14; // st7
  float *v15; // edi
  double v16; // st7
  float *v17; // ebx
  double v18; // st6
  float v19; // ecx
  float v20; // edx
  double v21; // st5
  double v22; // rt0
  double v23; // st6
  float *v24; // eax
  float v25; // ecx
  float v26; // edx
  long double v27; // st7
  long double v28; // st7
  float v29; // ecx
  float v30; // edx
  float v31; // ebp
  double v32; // st7
  double v33; // st6
  double v34; // st5
  double v35; // st7
  double v36; // st7
  double v37; // st6
  double v38; // st5
  double v39; // st7
  double v40; // st6
  float *result; // eax
  float v42; // edx
  float v43; // ecx
  float v44; // edx
  float v45; // ecx
  float v46; // edi
  float v47; // eax
  float *v48; // edi
  float v49; // edx
  float v50; // edx
  float *v51; // ebp
  float v52; // ecx
  float v53; // [esp+4h] [ebp-68h]
  float v54; // [esp+8h] [ebp-64h]
  float v55; // [esp+8h] [ebp-64h]
  float v56; // [esp+Ch] [ebp-60h] BYREF
  float v57; // [esp+10h] [ebp-5Ch]
  float v58; // [esp+14h] [ebp-58h]
  float v59; // [esp+18h] [ebp-54h]
  float v60; // [esp+1Ch] [ebp-50h]
  float v61; // [esp+20h] [ebp-4Ch]
  float v62; // [esp+24h] [ebp-48h]
  float v63; // [esp+28h] [ebp-44h]
  float v64; // [esp+2Ch] [ebp-40h]
  float v65; // [esp+30h] [ebp-3Ch]
  float v66; // [esp+34h] [ebp-38h]
  float v67; // [esp+38h] [ebp-34h]
  int v68; // [esp+3Ch] [ebp-30h] BYREF
  float v69; // [esp+40h] [ebp-2Ch]
  float v70; // [esp+44h] [ebp-28h]
  float v71; // [esp+48h] [ebp-24h]
  float v72; // [esp+4Ch] [ebp-20h]
  float v73; // [esp+50h] [ebp-1Ch]
  float v74; // [esp+54h] [ebp-18h]
  float v75; // [esp+58h] [ebp-14h]
  float v76; // [esp+5Ch] [ebp-10h]
  int v77; // [esp+60h] [ebp-Ch] BYREF
  float v78; // [esp+64h] [ebp-8h]
  float v79; // [esp+68h] [ebp-4h]

  v53 = dbl_8AFE98;
  v4 = (unsigned __int8)*(_DWORD *)a3;
  v56 = *(float *)&a1;
  if ( dbl_8AFE98 >= 0.0 )
  {
    if ( v53 > 0.033333335 )
      v53 = 0.033333335;
  }
  else
  {
    v53 = 0.0;
  }
  v5 = (float *)(56 * v4 + a1 + 112544);
  v6 = *(float *)(a3 + 12);
  v7 = *(float *)(a3 + 16);
  v65 = *(float *)(a3 + 8);
  v8 = 56 * v4 + a1 + 112552;
  v66 = v6;
  v67 = v7;
  v71 = v65 - *(float *)v8;
  v74 = v71;
  v72 = v6 - *(float *)(56 * v4 + a1 + 112556);
  v75 = v72;
  v73 = v7 - *(float *)(56 * v4 + a1 + 112560);
  v76 = v73;
  v58 = 1.0 / v53;
  v9 = sub_45EB00((int)&v77, v58);
  v10 = *(float *)(v9 + 8);
  v11 = *(float *)v9;
  v63 = *(float *)(v9 + 4);
  v54 = *(float *)&dword_7D1158;
  v64 = v10;
  v57 = flt_7D108C - *(float *)&dword_7D1158;
  v62 = v11;
  if ( sub_45CA20((unsigned __int8 *)(LODWORD(v56) + 107456), v4, &v56, COERCE_FLOAT(1))
    && v56 > (double)v54
    && v57 > 0.0 )
  {
    v12 = (v56 - v54) / v57;
    if ( v12 >= 1.0 )
      v12 = 1.0;
    v13 = (flt_7D11A0 - flt_7D117C) * (1.0 - v12) + flt_7D117C;
    if ( fabs(v13 - *v5) > 5.0 )
    {
      *v5 = v13;
      v14 = sqrt(v13);
      v5[1] = v14 * flt_7D11C4 + v14 * flt_7D11C4;
    }
    v15 = v5 + 11;
    v16 = v53 * v5[11];
    v17 = v5 + 8;
    v18 = v53 * v5[12];
    v19 = v5[11];
    v20 = v5[12];
    v21 = v53 * v5[13];
    v73 = v5[13];
    v79 = v21;
    v71 = v19;
    v22 = v18;
    v72 = v20;
    v23 = v16 + v5[8];
    LODWORD(v57) = v5 + 5;
    v74 = v23;
    v75 = v22 + v5[9];
    v76 = v79 + v5[10];
    *(float *)&v68 = v62 - v5[5];
    v77 = v68;
    v69 = v63 - v5[6];
    v78 = v69;
    v70 = v64 - v5[7];
    v79 = v70;
    v24 = (float *)sub_45EB00((int)&v68, v58);
    v25 = *v24;
    v26 = v24[1];
    v61 = v24[2];
    v60 = v26;
    v59 = v25;
    v27 = v61 * v61 + v26 * v26 + v25 * v25;
    if ( v27 > 2500.0 )
    {
      v28 = 50.0 / sqrt(v27);
      v59 = v59 * v28;
      v60 = v60 * v28;
      v61 = v61 * v28;
    }
    v29 = v66;
    v30 = v65;
    *(float *)&v68 = v65 - v74;
    v69 = v66 - v75;
    v70 = v67 - v76;
    v74 = v62 - v71;
    v75 = v63 - v72;
    v76 = v64 - v73;
    if ( v70 * v70 + v69 * v69 + *(float *)&v68 * *(float *)&v68 <= 256.0 )
    {
      v32 = v5[1];
      v33 = v74 * v32;
      v78 = v75 * v32;
      v79 = v76 * v32;
      v34 = *v5;
      v74 = *(float *)&v68 * v34;
      v75 = v69 * v34;
      v76 = v34 * v70;
      v79 = v76 + v79;
      v74 = v74 + v33 + v59;
      *(float *)&v77 = v74 * v53;
      v78 = (v75 + v78 + v60) * v53;
      v35 = (v61 + v79) * v53;
      *v15 = *(float *)&v77 + *v15;
      v5[12] = v78 + v5[12];
      v5[13] = v35 + v5[13];
      v36 = v71 + *v15;
      v37 = v72 + v5[12];
      v79 = v73 + v5[13];
      v38 = v53 * 0.5;
      v55 = v38;
      v74 = v38 * v36;
      v39 = v55 * v37;
      v40 = v55 * v79;
      *v17 = v74 + *v17;
      v5[9] = v39 + v5[9];
      v5[10] = v40 + v5[10];
    }
    else
    {
      v31 = v67;
      *v17 = v65;
      v17[1] = v29;
      v17[2] = v31;
      *v15 = v62;
      v15[1] = v63;
      v15[2] = v64;
    }
    *(float *)(a3 + 8) = *v17;
    *(float *)(a3 + 12) = v17[1];
    *(float *)(a3 + 16) = v17[2];
    result = (float *)LODWORD(v57);
    *(float *)v8 = v30;
    v42 = v62;
    *(float *)(v8 + 4) = v29;
    *(float *)(v8 + 8) = v67;
    v43 = v63;
    *result = v42;
    v44 = v64;
    result[1] = v43;
    result[2] = v44;
  }
  else
  {
    v45 = v66;
    v46 = v67;
    v47 = v65;
    v5[8] = v65;
    v5[9] = v45;
    v5[10] = v46;
    v48 = v5 + 11;
    v49 = v63;
    v5[11] = v11;
    v5[12] = v49;
    v50 = v64;
    *(float *)v8 = v47;
    result = (float *)LODWORD(v67);
    v51 = v5 + 5;
    *(float *)(v8 + 4) = v45;
    v52 = v63;
    *v51 = v11;
    v48[2] = v50;
    v51[1] = v52;
    *(_DWORD *)(v8 + 8) = result;
    v51[2] = v50;
  }
  return result;
}
