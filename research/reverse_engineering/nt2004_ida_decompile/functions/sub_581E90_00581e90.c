int __thiscall sub_581E90(int *this, int a2, double *a3, long double *a4, char a5)
{
  int *v5; // ebx
  signed int v6; // edx
  signed int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // ebp
  int v12; // edi
  int v13; // ebp
  int v14; // esi
  int v15; // ecx
  int v16; // eax
  bool v17; // zf
  int v18; // ebp
  signed int v19; // edi
  int v20; // esi
  int v21; // ecx
  int v22; // edx
  signed int v23; // eax
  char v24; // cl
  _BYTE *v25; // eax
  unsigned int v26; // ecx
  int result; // eax
  int v28; // ebx
  double v29; // st7
  double v30; // st6
  double v31; // st5
  double v32; // st7
  char v33; // [esp+13h] [ebp-22Dh]
  int v34; // [esp+14h] [ebp-22Ch]
  int v35; // [esp+14h] [ebp-22Ch]
  int v36; // [esp+18h] [ebp-228h]
  int v37; // [esp+18h] [ebp-228h]
  int v38; // [esp+1Ch] [ebp-224h]
  int v40; // [esp+24h] [ebp-21Ch]
  signed int v41; // [esp+28h] [ebp-218h]
  int v42; // [esp+2Ch] [ebp-214h]
  int v43; // [esp+30h] [ebp-210h]
  int v44; // [esp+34h] [ebp-20Ch]
  int v45; // [esp+38h] [ebp-208h]
  int v46; // [esp+3Ch] [ebp-204h]
  double v47[9]; // [esp+40h] [ebp-200h] BYREF
  double v48; // [esp+88h] [ebp-1B8h]
  double v49; // [esp+90h] [ebp-1B0h]
  long double v50; // [esp+A0h] [ebp-1A0h] BYREF
  long double v51; // [esp+A8h] [ebp-198h]
  long double v52; // [esp+B0h] [ebp-190h]
  double v53[9]; // [esp+B8h] [ebp-188h] BYREF
  _BYTE v54[32]; // [esp+100h] [ebp-140h] BYREF
  double v55[3]; // [esp+120h] [ebp-120h] BYREF
  double v56[3]; // [esp+138h] [ebp-108h] BYREF
  double v57; // [esp+158h] [ebp-E8h]
  double v58; // [esp+160h] [ebp-E0h]
  double v59[9]; // [esp+168h] [ebp-D8h] BYREF
  double v60[5]; // [esp+1B0h] [ebp-90h] BYREF
  long double v61; // [esp+1D8h] [ebp-68h]
  double v62; // [esp+1E0h] [ebp-60h]
  long double v63; // [esp+1F0h] [ebp-50h]
  double v64[9]; // [esp+1F8h] [ebp-48h] BYREF

  v5 = this;
  if ( !a5 )
  {
    v26 = *this;
    if ( *v5 > 0 )
      memset(v54, 1u, 4 * (v26 >> 2) + (*v5 & 3));
    goto LABEL_44;
  }
  v6 = *this;
  v41 = *this;
  if ( *this > 0 )
    memset(v54, 0, v6);
  v7 = 0;
  if ( v6 > 0 )
  {
    v8 = this[1];
    while ( a2 != v8 )
    {
      ++v7;
      v8 += 580;
      if ( v7 >= v6 )
        goto LABEL_10;
    }
    v54[v7] = 1;
  }
LABEL_10:
  v9 = v5[2];
  v10 = v5[4];
  v11 = v9 + v5[6] + v10;
  v45 = v10;
  v42 = v9;
  v44 = v11;
  while ( 2 )
  {
    v12 = 0;
    v33 = 0;
    v40 = 0;
    if ( v11 <= 0 )
      break;
    v13 = v9 + v10;
    v14 = -48 * v9;
    v15 = -72 * (v9 + v10);
    v34 = 0;
    v36 = -48 * v9;
    v46 = v13;
    v43 = v15;
    while ( 2 )
    {
      if ( v12 >= v9 )
      {
        if ( v12 >= v13 )
        {
          v16 = v15 + v5[7];
          v17 = (*(_BYTE *)(v16 + 68) & 1) == 0;
        }
        else
        {
          v16 = v14 + v5[5];
          v17 = (*(_BYTE *)(v16 + 44) & 1) == 0;
        }
      }
      else
      {
        v16 = v34 + v5[3];
        v17 = (*(_BYTE *)(v16 + 44) & 1) == 0;
      }
      if ( !v17 )
        goto LABEL_39;
      v18 = *(_DWORD *)(v16 + 4);
      v19 = 0;
      v38 = *(_DWORD *)(v16 + 12);
      if ( v6 <= 0 )
        goto LABEL_38;
      v20 = 0;
      do
      {
        if ( !v54[v19] )
          goto LABEL_36;
        v21 = v5[1];
        if ( v18 == v21 + v20 )
        {
          v22 = v38;
        }
        else
        {
          if ( v38 != v21 + v20 )
            goto LABEL_36;
          v22 = v18;
        }
        v23 = 0;
        while ( v22 != v21 )
        {
          ++v23;
          v21 += 580;
          v5 = this;
          if ( v23 >= v41 )
            goto LABEL_35;
        }
        v24 = v54[v23];
        v25 = &v54[v23];
        if ( !v24 )
          v33 = 1;
        *v25 = 1;
LABEL_35:
        v6 = v41;
LABEL_36:
        ++v19;
        v20 += 580;
      }
      while ( v19 < v6 );
      v14 = v36;
      v15 = v43;
LABEL_38:
      v12 = v40;
LABEL_39:
      v11 = v44;
      ++v12;
      v15 += 72;
      v14 += 48;
      v40 = v12;
      v43 = v15;
      v34 += 48;
      v36 = v14;
      if ( v12 < v44 )
      {
        v13 = v46;
        v9 = v42;
        continue;
      }
      break;
    }
    if ( v33 )
    {
      v10 = v45;
      v9 = v42;
      continue;
    }
    break;
  }
LABEL_44:
  qmemcpy(v56, (const void *)(a2 + 4), sizeof(v56));
  sub_57EAD0(v59, a4);
  qmemcpy(v47, (const void *)(a2 + 28), sizeof(v47));
  v53[0] = v47[0];
  v53[3] = v47[1];
  v53[6] = v47[2];
  v53[1] = v47[3];
  v53[4] = v47[4];
  v53[7] = v47[5];
  v53[2] = v47[6];
  v53[5] = v47[7];
  v53[8] = v47[8];
  sub_57F4D0(v59, v53, v64);
  result = 0;
  v37 = 0;
  if ( *v5 > 0 )
  {
    v35 = 0;
    do
    {
      if ( v54[result] )
      {
        v28 = v35 + v5[1];
        v29 = *(double *)(v28 + 4) - v56[0];
        v30 = *(double *)(v28 + 12) - v56[1];
        v31 = *(double *)(v28 + 20) - v56[2];
        v48 = v47[6] * v31 + v47[3] * v30 + v47[0] * v29;
        v49 = v47[7] * v31 + v47[4] * v30 + v29 * v47[1];
        v32 = v47[8] * v31 + v47[5] * v30 + v47[2] * v29;
        v57 = v59[5] * v32 + v59[4] * v49 + v59[3] * v48;
        v58 = v59[8] * v32 + v59[7] * v49 + v59[6] * v48;
        v55[0] = v59[2] * v32 + v59[1] * v49 + v59[0] * v48 + *a3;
        v55[1] = v57 + a3[1];
        v55[2] = v58 + a3[2];
        qmemcpy((void *)(v28 + 4), v55, 0x18u);
        sub_57F4D0(v64, (double *)(v28 + 28), v60);
        v50 = -asin(v61);
        if ( fabs(v61) == 1.0 )
        {
          v52 = 0.0;
          v51 = atan2(-v62, v60[0]);
        }
        else
        {
          v51 = atan2(v60[2], v63);
          v52 = atan2(v60[3], v60[4]);
        }
        sub_57BF60(v28, (int)&v50);
        v5 = this;
        result = v37;
      }
      v37 = ++result;
      v35 += 580;
    }
    while ( result < *v5 );
  }
  return result;
}
