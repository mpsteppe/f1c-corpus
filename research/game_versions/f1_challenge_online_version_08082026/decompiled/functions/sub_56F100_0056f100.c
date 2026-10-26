int __thiscall sub_56F100(int *this, int a2, double *a3, long double *a4, char a5)
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
  long double v33; // st7
  int v34; // ecx
  char v35; // [esp+13h] [ebp-22Dh]
  int v36; // [esp+14h] [ebp-22Ch]
  int v37; // [esp+14h] [ebp-22Ch]
  int v38; // [esp+18h] [ebp-228h]
  int v39; // [esp+18h] [ebp-228h]
  int v40; // [esp+1Ch] [ebp-224h]
  int v42; // [esp+24h] [ebp-21Ch]
  signed int v43; // [esp+28h] [ebp-218h]
  int v44; // [esp+2Ch] [ebp-214h]
  int v45; // [esp+30h] [ebp-210h]
  int v46; // [esp+34h] [ebp-20Ch]
  int v47; // [esp+38h] [ebp-208h]
  int v48; // [esp+3Ch] [ebp-204h]
  double v49[9]; // [esp+40h] [ebp-200h] BYREF
  double v50; // [esp+88h] [ebp-1B8h]
  double v51; // [esp+90h] [ebp-1B0h]
  long double v52; // [esp+A0h] [ebp-1A0h] BYREF
  long double v53; // [esp+A8h] [ebp-198h]
  long double v54; // [esp+B0h] [ebp-190h]
  double v55[9]; // [esp+B8h] [ebp-188h] BYREF
  _BYTE v56[32]; // [esp+100h] [ebp-140h] BYREF
  double v57[3]; // [esp+120h] [ebp-120h] BYREF
  double v58[3]; // [esp+138h] [ebp-108h] BYREF
  double v59; // [esp+158h] [ebp-E8h]
  double v60; // [esp+160h] [ebp-E0h]
  double v61[9]; // [esp+168h] [ebp-D8h] BYREF
  double v62[5]; // [esp+1B0h] [ebp-90h] BYREF
  long double v63; // [esp+1D8h] [ebp-68h]
  double v64; // [esp+1E0h] [ebp-60h]
  long double v65; // [esp+1F0h] [ebp-50h]
  double v66[9]; // [esp+1F8h] [ebp-48h] BYREF

  v5 = this;
  if ( !a5 )
  {
    v26 = *this;
    if ( *v5 > 0 )
      memset(v56, 1u, 4 * (v26 >> 2) + (*v5 & 3));
    goto LABEL_44;
  }
  v6 = *this;
  v43 = *this;
  if ( *this > 0 )
    memset(v56, 0, v6);
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
    v56[v7] = 1;
  }
LABEL_10:
  v9 = v5[2];
  v10 = v5[4];
  v11 = v9 + v5[6] + v10;
  v47 = v10;
  v44 = v9;
  v46 = v11;
  while ( 2 )
  {
    v12 = 0;
    v35 = 0;
    v42 = 0;
    if ( v11 <= 0 )
      break;
    v13 = v9 + v10;
    v14 = -48 * v9;
    v15 = -72 * (v9 + v10);
    v36 = 0;
    v38 = -48 * v9;
    v48 = v13;
    v45 = v15;
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
        v16 = v36 + v5[3];
        v17 = (*(_BYTE *)(v16 + 44) & 1) == 0;
      }
      if ( !v17 )
        goto LABEL_39;
      v18 = *(_DWORD *)(v16 + 4);
      v19 = 0;
      v40 = *(_DWORD *)(v16 + 12);
      if ( v6 <= 0 )
        goto LABEL_38;
      v20 = 0;
      do
      {
        if ( !v56[v19] )
          goto LABEL_36;
        v21 = v5[1];
        if ( v18 == v21 + v20 )
        {
          v22 = v40;
        }
        else
        {
          if ( v40 != v21 + v20 )
            goto LABEL_36;
          v22 = v18;
        }
        v23 = 0;
        while ( v22 != v21 )
        {
          ++v23;
          v21 += 580;
          v5 = this;
          if ( v23 >= v43 )
            goto LABEL_35;
        }
        v24 = v56[v23];
        v25 = &v56[v23];
        if ( !v24 )
          v35 = 1;
        *v25 = 1;
LABEL_35:
        v6 = v43;
LABEL_36:
        ++v19;
        v20 += 580;
      }
      while ( v19 < v6 );
      v14 = v38;
      v15 = v45;
LABEL_38:
      v12 = v42;
LABEL_39:
      v11 = v46;
      ++v12;
      v15 += 72;
      v14 += 48;
      v42 = v12;
      v45 = v15;
      v36 += 48;
      v38 = v14;
      if ( v12 < v46 )
      {
        v13 = v48;
        v9 = v44;
        continue;
      }
      break;
    }
    if ( v35 )
    {
      v10 = v47;
      v9 = v44;
      continue;
    }
    break;
  }
LABEL_44:
  qmemcpy(v58, (const void *)(a2 + 4), sizeof(v58));
  sub_56BD40(v61, a4);
  qmemcpy(v49, (const void *)(a2 + 28), sizeof(v49));
  v55[0] = v49[0];
  v55[3] = v49[1];
  v55[6] = v49[2];
  v55[1] = v49[3];
  v55[4] = v49[4];
  v55[7] = v49[5];
  v55[2] = v49[6];
  v55[5] = v49[7];
  v55[8] = v49[8];
  sub_56C740(v61, v55, v66);
  result = 0;
  v39 = 0;
  if ( *v5 > 0 )
  {
    v37 = 0;
    do
    {
      if ( v56[result] )
      {
        v28 = v37 + v5[1];
        v29 = *(double *)(v28 + 4) - v58[0];
        v30 = *(double *)(v28 + 12) - v58[1];
        v31 = *(double *)(v28 + 20) - v58[2];
        v50 = v49[6] * v31 + v49[3] * v30 + v49[0] * v29;
        v51 = v49[7] * v31 + v49[4] * v30 + v29 * v49[1];
        v32 = v49[8] * v31 + v49[5] * v30 + v49[2] * v29;
        v59 = v61[5] * v32 + v61[4] * v51 + v61[3] * v50;
        v60 = v61[8] * v32 + v61[7] * v51 + v61[6] * v50;
        v57[0] = v61[2] * v32 + v61[1] * v51 + v61[0] * v50 + *a3;
        v57[1] = v59 + a3[1];
        v57[2] = v60 + a3[2];
        qmemcpy((void *)(v28 + 4), v57, 0x18u);
        sub_56C740(v66, (double *)(v28 + 28), v62);
        v33 = v63;
        sub_588570(v34);
        v52 = -v33;
        if ( fabs(v63) == 1.0 )
        {
          v54 = 0.0;
          v53 = atan2(-v64, v62[0]);
        }
        else
        {
          v53 = atan2(v62[2], v65);
          v54 = atan2(v62[3], v62[4]);
        }
        sub_5691D0(v28, (int)&v52);
        v5 = this;
        result = v39;
      }
      v39 = ++result;
      v37 += 580;
    }
    while ( result < *v5 );
  }
  return result;
}
