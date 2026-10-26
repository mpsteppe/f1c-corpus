int __thiscall sub_44BEC0(_DWORD *this, int a2, char a3)
{
  int i; // edx
  float *v5; // ecx
  float *v6; // eax
  int v7; // ebx
  int v8; // ebx
  float *v9; // ebx
  double v10; // st7
  double v11; // st7
  double v12; // st7
  int v13; // ebx
  int v14; // edx
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // ecx
  float v19; // edx
  int v20; // ecx
  unsigned int v21; // eax
  int v22; // edx
  double v23; // st7
  double v24; // st6
  double v25; // st5
  int v26; // edx
  float *v27; // edx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  int v40; // eax
  int v41; // edx
  double *v42; // eax
  int v43; // ecx
  int v45; // edx
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  int v49; // eax
  int v50; // ecx
  char v51; // [esp+0h] [ebp-1A0h]
  float *v52; // [esp+Ch] [ebp-194h]
  float v53; // [esp+Ch] [ebp-194h]
  float v54; // [esp+10h] [ebp-190h]
  float v55; // [esp+14h] [ebp-18Ch]
  float v56; // [esp+18h] [ebp-188h]
  float v57; // [esp+1Ch] [ebp-184h]
  int v58; // [esp+20h] [ebp-180h]
  int v59; // [esp+24h] [ebp-17Ch]
  int v60; // [esp+28h] [ebp-178h]
  int v61; // [esp+2Ch] [ebp-174h]
  int v62; // [esp+30h] [ebp-170h]
  int v63; // [esp+34h] [ebp-16Ch]
  _DWORD v64[8]; // [esp+38h] [ebp-168h] BYREF
  double v65[2]; // [esp+58h] [ebp-148h] BYREF
  _DWORD v66[6]; // [esp+68h] [ebp-138h]
  double v67[4]; // [esp+80h] [ebp-120h]
  int v68; // [esp+A0h] [ebp-100h]
  int v69; // [esp+A4h] [ebp-FCh]
  double v70; // [esp+B8h] [ebp-E8h]
  int v71; // [esp+D8h] [ebp-C8h]
  int v72; // [esp+DCh] [ebp-C4h]
  double v73; // [esp+F0h] [ebp-B0h]
  double v74; // [esp+128h] [ebp-78h]
  double v75; // [esp+160h] [ebp-40h]
  double v76; // [esp+198h] [ebp-8h]

  this[21] = sub_4F63D0(*(unsigned __int16 *)(a2 + 26));
  *((_BYTE *)this + 88) = *(_BYTE *)(a2 + 24);
  for ( i = 0; i < 3; *(&v54 + i) = *v5 * *v5 + v5[1] * v5[1] )
  {
    v5 = (float *)&this[3 * i + 12];
    v6 = *(float **)(a2 + 8 * i);
    if ( i == 2 )
      v7 = 0;
    else
      v7 = i + 1;
    v54 = *(float *)(a2 + 8 * v7);
    v8 = 2;
    if ( i )
      v8 = i - 1;
    v52 = *(float **)(a2 + 8 * v8);
    v9 = (float *)LODWORD(v54);
    *v5 = v6[3] - *(float *)(LODWORD(v54) + 12);
    v10 = *v9 - *v6;
    v5[1] = v10;
    v11 = v10 * v6[3] + *v6 * *v5;
    v5[2] = v11;
    if ( v52[3] * v5[1] + *v5 * *v52 < v11 )
    {
      *v5 = -*v5;
      v5[1] = -v5[1];
      v5[2] = -v5[2];
    }
    ++i;
  }
  v12 = v56;
  while ( 1 )
  {
    while ( v55 < v12 )
    {
      v61 = this[12];
      v16 = this[13];
      v63 = this[14];
      v62 = v16;
      this[12] = this[15];
      this[13] = this[16];
      this[14] = this[17];
      v17 = v62;
      this[15] = v61;
      v18 = v63;
      this[16] = v17;
      v19 = v55;
      v55 = v12;
      v54 = v19;
      v12 = v19;
      this[17] = v18;
    }
    if ( v12 >= v57 )
      break;
    v53 = v12;
    v12 = v57;
    v58 = this[15];
    v13 = this[16];
    v60 = this[17];
    v59 = v13;
    this[15] = this[18];
    this[16] = this[19];
    this[17] = this[20];
    v14 = v59;
    this[18] = v58;
    v15 = v60;
    this[19] = v14;
    this[20] = v15;
    v57 = v53;
  }
  v20 = 0;
  do
  {
    v21 = 56 * v20;
    v64[v20] = &v64[14 * v20 + 6];
    if ( v20 >= 3 )
    {
      if ( v20 == 5 )
        v26 = 0;
      else
        v26 = v20 - 2;
      v27 = *(float **)(a2 + 8 * v26);
      v23 = (*v27 + **(float **)(a2 + 8 * v20 - 24)) * 0.5;
      v24 = *(double *)(*(_DWORD *)(a2 + 8 * v20 - 20) + 16);
      v25 = (v27[3] + *(float *)(*(_DWORD *)(a2 + 8 * v20 - 24) + 12)) * 0.5;
    }
    else
    {
      v22 = *(_DWORD *)(a2 + 8 * v20);
      v23 = *(float *)v22;
      v24 = *(double *)(v22 + 16);
      v25 = *(float *)(v22 + 12);
    }
    ++v20;
    v66[v21 / 4 + 4] = 0;
    v66[v21 / 4 + 5] = 1072693248;
    *(double *)&v64[v21 / 4 + 6] = v23 * v23;
    v65[v21 / 8] = v25 * v25;
    v65[v21 / 8 + 1] = v25 * v23;
    *(double *)&v66[v21 / 4] = v23;
    *(double *)&v66[v21 / 4 + 2] = v25;
    v67[v21 / 8] = v24;
  }
  while ( v20 < 6 );
  if ( sub_579F40(v64, 6) && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_0, 301) )
    sub_500FE0((int)&unk_7D7920, aGaussianElimin, v51);
  v28 = LODWORD(v67[0]);
  v29 = LODWORD(v70);
  this[1] = HIDWORD(v67[0]);
  v30 = LODWORD(v73);
  *this = v28;
  v31 = HIDWORD(v70);
  this[2] = v29;
  v32 = HIDWORD(v73);
  this[4] = v30;
  v33 = HIDWORD(v74);
  this[3] = v31;
  v34 = LODWORD(v74);
  this[5] = v32;
  v35 = LODWORD(v75);
  this[7] = v33;
  v36 = LODWORD(v76);
  this[6] = v34;
  v37 = HIDWORD(v75);
  this[8] = v35;
  v38 = HIDWORD(v76);
  this[10] = v36;
  this[9] = v37;
  this[11] = v38;
  v39 = 0;
  while ( 1 )
  {
    v40 = *(_DWORD *)(a2 + 8 * v39);
    if ( fabs(
           (*(float *)(v40 + 12) * v73 + *(float *)v40 * v67[0] + v74) * *(float *)v40
         + (*(float *)(v40 + 12) * v70 + v75) * *(float *)(v40 + 12)
         + v76
         - *(double *)(v40 + 16)) > 0.001 )
      break;
    if ( ++v39 >= 3 )
      goto LABEL_37;
  }
  v41 = 0;
  v42 = v65;
  do
  {
    v43 = *(_DWORD *)(a2 + 8 * v41++);
    *(v42 - 1) = *(float *)v43;
    v42 += 7;
    *(v42 - 7) = *(float *)(v43 + 12);
    *((_DWORD *)v42 - 12) = 0;
    *((_DWORD *)v42 - 11) = 1072693248;
    *((_DWORD *)v42 - 10) = *(_DWORD *)(v43 + 16);
    *((_DWORD *)v42 - 9) = *(_DWORD *)(v43 + 20);
  }
  while ( v41 < 3 );
  if ( !sub_579F40(v64, 3) )
  {
    v45 = v66[0];
    v46 = v68;
    *this = 0;
    this[1] = 0;
    this[2] = 0;
    this[3] = 0;
    this[4] = 0;
    this[5] = 0;
    v47 = v66[1];
    this[6] = v45;
    v48 = v69;
    this[7] = v47;
    v49 = v71;
    this[8] = v46;
    v50 = v72;
    this[9] = v48;
    this[10] = v49;
    this[11] = v50;
LABEL_37:
    if ( a3 )
      *((double *)this + 5) = *((double *)this + 5) - *(double *)(this[21] + 96);
    return 0;
  }
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_0, 339) )
    sub_500FE0((int)&unk_7D7920, aGaussianElimin_0, v51);
  return -1;
}
