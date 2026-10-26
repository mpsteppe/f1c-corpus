float *__stdcall sub_67D147(float *a1, float *a2, int a3, int a4)
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
  bool v29; // sf
  double v30; // st7
  double v31; // st7
  float *v32; // eax
  float *v33; // ecx
  int v34; // edx
  int v35; // esi
  double v36; // st6
  double v37; // st5
  double v38; // st6
  double v39; // st5
  double v40; // st4
  double v41; // st4
  float *v42; // ecx
  int v43; // esi
  double v44; // st6
  int v45; // edx
  double v46; // st6
  double v47; // st5
  int v48; // eax
  float *v49; // edx
  double v50; // st4
  float *v51; // eax
  double v52; // st4
  double v53; // st3
  double v54; // st6
  double v55; // st6
  float v57[15]; // [esp+4h] [ebp-BCh] BYREF
  int v58; // [esp+40h] [ebp-80h]
  float *v59; // [esp+44h] [ebp-7Ch]
  int v60; // [esp+48h] [ebp-78h]
  float v61; // [esp+4Ch] [ebp-74h]
  float v62; // [esp+50h] [ebp-70h]
  float v63; // [esp+54h] [ebp-6Ch]
  _BYTE *v64; // [esp+5Ch] [ebp-64h]
  unsigned int v65; // [esp+60h] [ebp-60h]
  float v66; // [esp+64h] [ebp-5Ch]
  float *v67; // [esp+68h] [ebp-58h]
  float v68; // [esp+6Ch] [ebp-54h]
  float v69; // [esp+70h] [ebp-50h]
  float v70; // [esp+74h] [ebp-4Ch]
  float v71; // [esp+78h] [ebp-48h]
  float v72; // [esp+80h] [ebp-40h]
  float v73; // [esp+84h] [ebp-3Ch]
  float v74; // [esp+88h] [ebp-38h]
  float v75; // [esp+90h] [ebp-30h] BYREF
  float v76; // [esp+94h] [ebp-2Ch]
  float v77; // [esp+98h] [ebp-28h]
  float v78; // [esp+9Ch] [ebp-24h]
  float v79; // [esp+A0h] [ebp-20h]
  float v80; // [esp+A4h] [ebp-1Ch]
  float v81; // [esp+A8h] [ebp-18h]
  float v82; // [esp+B0h] [ebp-10h]
  float v83; // [esp+B4h] [ebp-Ch]
  float v84; // [esp+B8h] [ebp-8h]
  int v85; // [esp+BCh] [ebp-4h]
  float v86; // [esp+D0h] [ebp+10h]
  int v87; // [esp+D4h] [ebp+14h]
  float v88; // [esp+D4h] [ebp+14h]

  if ( a4 == 3 )
  {
    v67 = (float *)&unk_73CD70;
    v64 = &unk_73CD64;
  }
  else
  {
    v67 = (float *)&unk_73CD54;
    v64 = &unk_73CD44;
  }
  v79 = 0.0;
  v4 = 0.0;
  v80 = 0.0;
  v82 = flt_915650;
  v83 = flt_915654;
  v81 = 0.0;
  v84 = flt_915658;
  v85 = unk_91565C;
  v59 = (float *)(a3 + 8);
  v5 = (float *)(a3 + 8);
  v6 = 16;
  do
  {
    if ( *(v5 - 2) < (double)v82 )
      v82 = *(v5 - 2);
    if ( *(v5 - 1) < (double)v83 )
      v83 = *(v5 - 1);
    if ( *v5 < (double)v84 )
      v84 = *v5;
    if ( *(v5 - 2) > (double)v79 )
      v79 = *(v5 - 2);
    if ( v4 < *(v5 - 1) )
      v4 = *(v5 - 1);
    if ( *v5 > (double)v81 )
      v81 = *v5;
    v5 += 4;
    --v6;
  }
  while ( v6 );
  v80 = v4;
  v72 = v79 - v82;
  v73 = v4 - v83;
  v7 = v81 - v84;
  v8 = v7 * v7 + v73 * v73 + v72 * v72;
  v68 = v8;
  if ( v10 | v11 )
    goto LABEL_19;
  v14 = (float *)(a3 + 8);
  v15 = 1.0 / v8;
  v16 = 16;
  v61 = v72 * v15;
  v62 = v73 * v15;
  v63 = v15 * v7;
  v69 = (v79 + v82) * 0.5;
  v70 = (v4 + v83) * 0.5;
  v71 = (v81 + v84) * 0.5;
  v78 = 0.0;
  v77 = 0.0;
  v76 = 0.0;
  v17 = 0.0;
  do
  {
    v72 = (*(v14 - 2) - v69) * v61;
    v73 = (*(v14 - 1) - v70) * v62;
    v18 = *v14;
    v14 += 4;
    --v16;
    v19 = (v18 - v71) * v63;
    v20 = v73 + v19 + v72;
    v17 = v17 + v20 * v20;
    v21 = v73 + v72 - v19;
    v76 = v21 * v21 + v76;
    v22 = v72 - v73;
    v77 = (v22 + v19) * (v22 + v19) + v77;
    v78 = (v22 - v19) * (v22 - v19) + v78;
  }
  while ( v16 );
  v75 = v17;
  v23 = 0;
  for ( i = 1; i < 4; ++i )
  {
    v25 = &v75 + i;
    if ( v17 < *v25 )
    {
      v23 = i;
      v17 = *v25;
    }
  }
  if ( (v23 & 2) != 0 )
  {
    v26 = v83;
    v83 = v4;
    v4 = v26;
    v80 = v26;
  }
  if ( (v23 & 1) != 0 )
  {
    v27 = v81;
    v81 = v84;
    v84 = v27;
  }
  if ( v68 < 0.00024414062 )
  {
LABEL_19:
    *a1 = v82;
    a1[1] = v83;
    a1[2] = v84;
    result = a2;
    v13 = v79;
    a2[1] = v4;
    *a2 = v13;
  }
  else
  {
    v29 = a4 - 1 < 0;
    v87 = a4 - 1;
    v30 = (double)v87;
    if ( v29 )
      v30 = v30 + 4294967300.0;
    v68 = v30;
    v31 = 0.000015258789;
    v65 = 0;
    v60 = v87;
    do
    {
      if ( a4 )
      {
        v32 = v67;
        v33 = v57;
        v34 = v64 - (_BYTE *)v67;
        v35 = a4;
        do
        {
          *(v33 - 1) = v82 * *v32 + v79 * *(float *)((char *)v32 + v34);
          *v33 = v83 * *v32 + v80 * *(float *)((char *)v32 + v34);
          v36 = v84 * *v32;
          v37 = v81 * *(float *)((char *)v32++ + v34);
          v33[1] = v36 + v37;
          v33 += 4;
          --v35;
        }
        while ( v35 );
      }
      v38 = v79 - v82;
      v73 = v80 - v83;
      v39 = v81 - v84;
      v40 = v39 * v39 + v73 * v73 + v38 * v38;
      if ( v40 < 0.00024414062 )
        break;
      v41 = v68 / v40;
      v42 = v59;
      v43 = 16;
      v72 = v41 * v38;
      v73 = v73 * v41;
      v74 = v41 * v39;
      v77 = 0.0;
      v76 = 0.0;
      v75 = 0.0;
      v71 = 0.0;
      v70 = 0.0;
      v69 = 0.0;
      v86 = 0.0;
      v88 = 0.0;
      do
      {
        v44 = (*(v42 - 1) - v83) * v73 + (*(v42 - 2) - v82) * v72 + (*v42 - v84) * v74;
        v66 = v44;
        if ( v44 < v68 )
        {
          v66 = v66 + 0.5;
          v58 = (int)v66;
          v45 = v58;
          v31 = 0.000015258789;
        }
        else
        {
          v45 = a4 - 1;
        }
        v46 = v57[4 * v45 - 1] - *(v42 - 2);
        v62 = v57[4 * v45] - *(v42 - 1);
        v47 = v57[4 * v45 + 1] - *v42;
        v48 = v45;
        v49 = &v67[v48];
        v50 = v67[v48];
        v51 = (float *)&v64[v48 * 4];
        v52 = v50 * 0.125;
        v42 += 4;
        --v43;
        v53 = *v51 * 0.125;
        v88 = v52 * *v49 + v88;
        v69 = v52 * v46 + v69;
        v70 = v52 * v62 + v70;
        v71 = v52 * v47 + v71;
        v86 = v53 * *v51 + v86;
        v75 = v53 * v46 + v75;
        v76 = v62 * v53 + v76;
        v77 = v53 * v47 + v77;
      }
      while ( v43 );
      if ( v88 > 0.0 )
      {
        v54 = -1.0 / v88;
        v82 = v69 * v54 + v82;
        v83 = v70 * v54 + v83;
        v84 = v54 * v71 + v84;
      }
      if ( v86 > 0.0 )
      {
        v55 = -1.0 / v86;
        v79 = v75 * v55 + v79;
        v80 = v76 * v55 + v80;
        v81 = v55 * v77 + v81;
      }
      if ( v69 * v69 < v31
        && v70 * v70 < v31
        && v71 * v71 < v31
        && v75 * v75 < v31
        && v76 * v76 < v31
        && v77 * v77 < v31 )
      {
        break;
      }
      ++v65;
    }
    while ( v65 < 8 );
    *a1 = v82;
    a1[1] = v83;
    a1[2] = v84;
    result = a2;
    *a2 = v79;
    a2[1] = v80;
  }
  result[2] = v81;
  return result;
}
