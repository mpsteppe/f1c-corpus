signed int __thiscall sub_61E140(unsigned int *this, double *a2, double *a3, long double *a4, char a5)
{
  signed int v6; // edx
  signed int v7; // eax
  double *v8; // ecx
  int v9; // esi
  int v10; // edi
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // edi
  signed int v23; // eax
  char v24; // cl
  _BYTE *v25; // eax
  bool v26; // cc
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // ecx
  signed int result; // eax
  unsigned int v31; // esi
  double v32; // st7
  double *v33; // esi
  double v34; // st7
  double v35; // st6
  double v36; // st5
  double v37; // st7
  double v38; // kr00_8
  double v39; // st7
  long double v40; // st7
  char v41; // [esp+13h] [ebp-22Dh]
  int v42; // [esp+14h] [ebp-22Ch]
  int v43; // [esp+14h] [ebp-22Ch]
  int v44; // [esp+18h] [ebp-228h]
  signed int v45; // [esp+18h] [ebp-228h]
  int v46; // [esp+1Ch] [ebp-224h]
  int v47; // [esp+20h] [ebp-220h]
  int v48; // [esp+24h] [ebp-21Ch]
  int v49; // [esp+28h] [ebp-218h]
  int v50; // [esp+2Ch] [ebp-214h]
  int v51; // [esp+30h] [ebp-210h]
  int v52; // [esp+34h] [ebp-20Ch]
  double v53; // [esp+38h] [ebp-208h]
  double v54; // [esp+40h] [ebp-200h]
  double v55; // [esp+48h] [ebp-1F8h]
  double v56; // [esp+58h] [ebp-1E8h]
  double v57; // [esp+68h] [ebp-1D8h]
  double v58; // [esp+70h] [ebp-1D0h]
  double v59[9]; // [esp+80h] [ebp-1C0h] BYREF
  long double v60; // [esp+C8h] [ebp-178h] BYREF
  long double v61; // [esp+D0h] [ebp-170h]
  long double v62; // [esp+D8h] [ebp-168h]
  double v63; // [esp+E8h] [ebp-158h]
  double v64; // [esp+F0h] [ebp-150h]
  double v65[9]; // [esp+F8h] [ebp-148h] BYREF
  double v66[9]; // [esp+140h] [ebp-100h] BYREF
  double v67[5]; // [esp+188h] [ebp-B8h] BYREF
  long double v68; // [esp+1B0h] [ebp-90h]
  double v69; // [esp+1B8h] [ebp-88h]
  long double v70; // [esp+1C8h] [ebp-78h]
  double v71[9]; // [esp+1D0h] [ebp-70h] BYREF
  _BYTE v72[32]; // [esp+21Ch] [ebp-24h] BYREF
  int v73; // [esp+23Ch] [ebp-4h]

  v73 = dword_912B08;
  if ( !a5 )
  {
    v27 = *this;
    if ( (int)*this > 0 )
    {
      v28 = *this;
      v29 = v27 >> 2;
      memset32(v72, (int)&nullsub_12, v29);
      memset(&v72[4 * v29], (char)&nullsub_12, v28 & 3);
    }
    goto LABEL_45;
  }
  v6 = *this;
  if ( (int)*this > 0 )
    memset(v72, 0, v6);
  v7 = 0;
  if ( v6 > 0 )
  {
    v8 = (double *)this[1];
    while ( a2 != v8 )
    {
      ++v7;
      v8 += 73;
      if ( v7 >= v6 )
        goto LABEL_10;
    }
    v72[v7] = 1;
  }
LABEL_10:
  v9 = this[4] + this[2] + this[6];
  v51 = v9;
  do
  {
    v10 = 0;
    v41 = 0;
    v49 = 0;
    if ( v9 <= 0 )
      break;
    v42 = -56 * this[2];
    v11 = this[2] + this[4];
    v12 = -80 * v11;
    v47 = 0;
    v52 = v11;
    v50 = -80 * v11;
    while ( 2 )
    {
      if ( v10 >= (int)this[2] )
      {
        if ( v10 < v11 )
        {
          if ( (*(_BYTE *)(v42 + this[5] + 48) & 1) != 0 )
            goto LABEL_40;
          v15 = this[5];
          v16 = 56 * (v10 - this[2]);
          v17 = *(_DWORD *)(v15 + v16 + 4);
          v46 = *(_DWORD *)(v16 + v15 + 12);
          goto LABEL_23;
        }
        if ( (*(_BYTE *)(this[7] + v12 + 72) & 1) != 0 )
          goto LABEL_40;
        v13 = this[7];
        v14 = 80 * (v10 - this[4] - this[2]);
      }
      else
      {
        v13 = this[3];
        v14 = v47;
        if ( (*(_BYTE *)(v47 + v13 + 48) & 1) != 0 )
          goto LABEL_40;
      }
      v17 = *(_DWORD *)(v14 + v13 + 4);
      v46 = *(_DWORD *)(v13 + v14 + 12);
LABEL_23:
      v18 = 0;
      v44 = 0;
      if ( v6 <= 0 )
        goto LABEL_39;
      v19 = 0;
      v48 = 0;
      do
      {
        if ( !v72[v18] )
          goto LABEL_37;
        v20 = this[1];
        v21 = v20 + v19;
        if ( v17 == v21 )
        {
          v22 = v46;
        }
        else
        {
          if ( v46 != v21 )
            goto LABEL_37;
          v22 = v17;
        }
        v23 = 0;
        while ( v22 != v20 )
        {
          ++v23;
          v20 += 584;
          if ( v23 >= v6 )
            goto LABEL_37;
        }
        v24 = v72[v23];
        v25 = &v72[v23];
        if ( !v24 )
          v41 = 1;
        *v25 = 1;
LABEL_37:
        v18 = v44 + 1;
        v19 = v48 + 584;
        v26 = ++v44 < v6;
        v48 += 584;
      }
      while ( v26 );
      v10 = v49;
LABEL_39:
      v9 = v51;
LABEL_40:
      v47 += 56;
      ++v10;
      v12 = v50 + 80;
      v49 = v10;
      v50 += 80;
      v42 += 56;
      if ( v10 < v9 )
      {
        v11 = v52;
        continue;
      }
      break;
    }
  }
  while ( v41 );
LABEL_45:
  v53 = a2[1];
  v54 = a2[2];
  v55 = a2[3];
  sub_61B860(v65, a4);
  qmemcpy(v59, a2 + 4, sizeof(v59));
  v66[0] = v59[0];
  v66[3] = v59[1];
  v66[6] = v59[2];
  v66[1] = v59[3];
  v66[4] = v59[4];
  v66[7] = v59[5];
  v66[2] = v59[6];
  v66[5] = v59[7];
  v66[8] = v59[8];
  sub_61C060(v65, v66, v71);
  result = 0;
  v45 = 0;
  if ( (int)*this > 0 )
  {
    v43 = 0;
    do
    {
      if ( v72[result] )
      {
        v31 = this[1];
        v32 = *(double *)(v31 + v43 + 8);
        v33 = (double *)(v43 + v31);
        v34 = v32 - v53;
        v35 = v33[2] - v54;
        v36 = v33[3] - v55;
        v57 = v59[6] * v36 + v59[3] * v35 + v59[0] * v34;
        v58 = v59[7] * v36 + v59[4] * v35 + v59[1] * v34;
        v37 = v59[8] * v36 + v59[5] * v35 + v59[2] * v34;
        v63 = v65[5] * v37 + v65[4] * v58 + v65[3] * v57;
        v64 = v65[8] * v37 + v65[7] * v58 + v65[6] * v57;
        v38 = v65[2] * v37 + v65[1] * v58 + v65[0] * v57 + *a3;
        v56 = v63 + a3[1];
        v39 = v64 + a3[2];
        v33[1] = v38;
        v33[2] = v56;
        v33[3] = v39;
        sub_61C060(v71, v33 + 4, v67);
        v60 = -asin(v68);
        if ( 1.0 == fabs(v68) )
        {
          v61 = atan2(-v69, v67[0]);
          v40 = 0.0;
        }
        else
        {
          v61 = atan2(v67[2], v70);
          v40 = atan2(v67[3], v67[4]);
        }
        v62 = v40;
        sub_61B6E0(v33, (int)&v60);
        result = v45;
      }
      v45 = ++result;
      v43 += 584;
    }
    while ( result < (int)*this );
  }
  return result;
}
