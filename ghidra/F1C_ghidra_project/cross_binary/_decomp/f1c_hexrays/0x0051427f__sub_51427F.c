// f1c  0x0051427f  size=1387
float *__cdecl sub_51427F(float *a1, float *a2, int a3, int a4)
{
  double v4; // st7
  float *v5; // ecx
  int v6; // edx
  double v7; // st6
  double v8; // st5
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  float *result; // eax
  float v13; // ecx
  float *v14; // eax
  double v15; // st5
  int v16; // ecx
  double v17; // st6
  double v18; // st5
  double v19; // st5
  double v20; // st3
  double v21; // st3
  double v22; // st4
  char v23; // bl
  unsigned int i; // edx
  float *v25; // ecx
  float v26; // eax
  float v27; // eax
  double v29; // st7
  float *v30; // eax
  float *v31; // ecx
  int v32; // edx
  int v33; // esi
  double v34; // st6
  double v35; // st5
  double v36; // st6
  double v37; // st5
  double v38; // st4
  double v39; // st4
  float *v40; // ecx
  int v41; // esi
  double v42; // st6
  int v43; // edx
  double v44; // st6
  double v45; // st5
  int v46; // eax
  float *v47; // edx
  double v48; // st4
  float *v49; // eax
  double v50; // st4
  double v51; // st3
  double v52; // st6
  double v53; // st6
  float v55[15]; // [esp+4h] [ebp-54h] BYREF
  float *v56; // [esp+40h] [ebp-18h]
  int v57; // [esp+44h] [ebp-14h]
  float v58; // [esp+48h] [ebp-10h]
  float v59; // [esp+4Ch] [ebp-Ch]
  float v60; // [esp+50h] [ebp-8h]
  float *v61; // [esp+58h] [ebp+0h]
  _BYTE *v62; // [esp+5Ch] [ebp+4h]
  float v63; // [esp+60h] [ebp+8h]
  float v64; // [esp+64h] [ebp+Ch]
  float v65; // [esp+68h] [ebp+10h]
  float v66; // [esp+6Ch] [ebp+14h]
  float v67; // [esp+70h] [ebp+18h]
  float v68; // [esp+74h] [ebp+1Ch]
  float v69; // [esp+7Ch] [ebp+24h]
  float v70; // [esp+80h] [ebp+28h]
  float v71; // [esp+84h] [ebp+2Ch]
  float v72; // [esp+88h] [ebp+30h]
  float v73; // [esp+90h] [ebp+38h] BYREF
  float v74; // [esp+94h] [ebp+3Ch]
  float v75; // [esp+98h] [ebp+40h]
  float v76; // [esp+9Ch] [ebp+44h]
  float v77; // [esp+A0h] [ebp+48h]
  float v78; // [esp+A4h] [ebp+4Ch]
  float v79; // [esp+A8h] [ebp+50h]
  float v80; // [esp+B0h] [ebp+58h]
  float v81; // [esp+B4h] [ebp+5Ch]
  float v82; // [esp+B8h] [ebp+60h]
  int v83; // [esp+BCh] [ebp+64h]
  float v84; // [esp+D4h] [ebp+7Ch]

  if ( a4 == 3 )
  {
    v61 = (float *)&unk_5AF60C;
    v62 = &unk_5AF600;
  }
  else
  {
    v61 = (float *)&unk_5AF5F0;
    v62 = &unk_5AF5E0;
  }
  v77 = 0.0;
  v4 = 0.0;
  v78 = 0.0;
  v80 = flt_5D79BC;
  v81 = flt_5D79C0;
  v79 = 0.0;
  v82 = flt_5D79C4;
  v83 = unk_5D79C8;
  v56 = (float *)(a3 + 8);
  v5 = (float *)(a3 + 8);
  v6 = 16;
  do
  {
    if ( *(v5 - 2) < (double)v80 )
      v80 = *(v5 - 2);
    if ( *(v5 - 1) < (double)v81 )
      v81 = *(v5 - 1);
    if ( *v5 < (double)v82 )
      v82 = *v5;
    if ( *(v5 - 2) > (double)v77 )
      v77 = *(v5 - 2);
    if ( v4 < *(v5 - 1) )
      v4 = *(v5 - 1);
    if ( *v5 > (double)v79 )
      v79 = *v5;
    v5 += 4;
    --v6;
  }
  while ( v6 );
  v78 = v4;
  v70 = v77 - v80;
  v71 = v4 - v81;
  v7 = v79 - v82;
  v8 = v7 * v7 + v71 * v71 + v70 * v70;
  v69 = v8;
  if ( v10 | v11 )
    goto LABEL_19;
  v14 = (float *)(a3 + 8);
  v15 = 1.0 / v8;
  v16 = 16;
  v58 = v70 * v15;
  v59 = v71 * v15;
  v60 = v15 * v7;
  v66 = (v77 + v80) * 0.5;
  v67 = (v4 + v81) * 0.5;
  v68 = (v79 + v82) * 0.5;
  v76 = 0.0;
  v75 = 0.0;
  v74 = 0.0;
  v17 = 0.0;
  do
  {
    v70 = (*(v14 - 2) - v66) * v58;
    v71 = (*(v14 - 1) - v67) * v59;
    v18 = *v14;
    v14 += 4;
    --v16;
    v19 = (v18 - v68) * v60;
    v20 = v71 + v19 + v70;
    v17 = v17 + v20 * v20;
    v21 = v71 + v70 - v19;
    v74 = v21 * v21 + v74;
    v22 = v70 - v71;
    v75 = (v22 + v19) * (v22 + v19) + v75;
    v76 = (v22 - v19) * (v22 - v19) + v76;
  }
  while ( v16 );
  v73 = v17;
  v23 = 0;
  for ( i = 1; i < 4; ++i )
  {
    v25 = &v73 + i;
    if ( v17 < *v25 )
    {
      v23 = i;
      v17 = *v25;
    }
  }
  if ( (v23 & 2) != 0 )
  {
    v26 = v81;
    v81 = v4;
    v64 = v26;
    v4 = v26;
    v78 = v26;
  }
  if ( (v23 & 1) != 0 )
  {
    v27 = v79;
    v79 = v82;
    v82 = v27;
  }
  if ( v69 < 0.00024414062 )
  {
LABEL_19:
    *a1 = v80;
    a1[1] = v81;
    a1[2] = v82;
    result = a2;
    v13 = v77;
    a2[1] = v4;
    *a2 = v13;
  }
  else
  {
    v64 = (float)(unsigned int)(a4 - 1);
    sub_513E5D();
    v69 = 0.0;
    v29 = 0.000015258789;
    do
    {
      if ( a4 )
      {
        v30 = v61;
        v31 = v55;
        v32 = v62 - (_BYTE *)v61;
        v33 = a4;
        do
        {
          *(v31 - 1) = v80 * *v30 + v77 * *(float *)((char *)v30 + v32);
          *v31 = v81 * *v30 + v78 * *(float *)((char *)v30 + v32);
          v34 = v82 * *v30;
          v35 = v79 * *(float *)((char *)v30++ + v32);
          v31[1] = v34 + v35;
          v31 += 4;
          --v33;
        }
        while ( v33 );
      }
      v36 = v77 - v80;
      v71 = v78 - v81;
      v37 = v79 - v82;
      v38 = v37 * v37 + v71 * v71 + v36 * v36;
      if ( v38 < 0.00024414062 )
        break;
      v39 = v64 / v38;
      v40 = v56;
      v41 = 16;
      v70 = v39 * v36;
      v71 = v71 * v39;
      v72 = v39 * v37;
      v75 = 0.0;
      v74 = 0.0;
      v73 = 0.0;
      v68 = 0.0;
      v67 = 0.0;
      v66 = 0.0;
      v65 = 0.0;
      v84 = 0.0;
      do
      {
        v42 = (*(v40 - 1) - v81) * v71 + (*(v40 - 2) - v80) * v70 + (*v40 - v82) * v72;
        v63 = v42;
        if ( v42 < v64 )
        {
          v63 = v63 + 0.5;
          v57 = (int)v63;
          v43 = v57;
          v29 = 0.000015258789;
        }
        else
        {
          v43 = a4 - 1;
        }
        v44 = v55[4 * v43 - 1] - *(v40 - 2);
        v59 = v55[4 * v43] - *(v40 - 1);
        v45 = v55[4 * v43 + 1] - *v40;
        v46 = v43;
        v47 = &v61[v46];
        v48 = v61[v46];
        v49 = (float *)&v62[v46 * 4];
        v50 = v48 * 0.125;
        v40 += 4;
        --v41;
        v51 = *v49 * 0.125;
        v84 = v50 * *v47 + v84;
        v66 = v50 * v44 + v66;
        v67 = v50 * v59 + v67;
        v68 = v50 * v45 + v68;
        v65 = v51 * *v49 + v65;
        v73 = v51 * v44 + v73;
        v74 = v59 * v51 + v74;
        v75 = v51 * v45 + v75;
      }
      while ( v41 );
      if ( v84 > 0.0 )
      {
        v52 = -1.0 / v84;
        v80 = v66 * v52 + v80;
        v81 = v67 * v52 + v81;
        v82 = v52 * v68 + v82;
      }
      if ( v65 > 0.0 )
      {
        v53 = -1.0 / v65;
        v77 = v73 * v53 + v77;
        v78 = v74 * v53 + v78;
        v79 = v53 * v75 + v79;
      }
      if ( v66 * v66 < v29
        && v67 * v67 < v29
        && v68 * v68 < v29
        && v73 * v73 < v29
        && v74 * v74 < v29
        && v75 * v75 < v29 )
      {
        break;
      }
      ++LODWORD(v69);
    }
    while ( LODWORD(v69) < 8 );
    *a1 = v80;
    a1[1] = v81;
    a1[2] = v82;
    result = a2;
    *a2 = v77;
    a2[1] = v78;
  }
  result[2] = v79;
  return result;
}
