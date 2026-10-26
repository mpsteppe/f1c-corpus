int __thiscall sub_662830(int this, int a2, double *a3)
{
  _DWORD *v4; // eax
  double *v5; // edi
  int v6; // ecx
  bool v7; // zf
  double *v8; // eax
  double v9; // st7
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // edx
  int v16; // ecx
  int *v17; // esi
  int v18; // eax
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // esi
  long double v23; // st7
  long double v24; // st7
  long double v25; // st7
  long double v26; // st6
  long double v27; // st7
  double v28; // st7
  long double v29; // st7
  long double v30; // st6
  double v31; // st7
  long double v32; // st7
  long double v33; // st7
  unsigned int v34; // esi
  double v35; // st7
  double v36; // st7
  double v37; // st7
  unsigned int v38; // ecx
  int v39; // eax
  unsigned int v40; // ebx
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  int v44; // ebx
  double v45; // st6
  int v46; // ebx
  int v47; // ebx
  long double v48; // st7
  long double v49; // st7
  unsigned __int8 v51; // c0
  unsigned __int8 v52; // c3
  int v53; // esi
  long double v54; // st7
  long double v55; // [esp+14h] [ebp-54h] BYREF
  long double v56; // [esp+1Ch] [ebp-4Ch]
  double v57; // [esp+24h] [ebp-44h] BYREF
  long double v58; // [esp+2Ch] [ebp-3Ch]
  double v59; // [esp+34h] [ebp-34h] BYREF
  long double v60; // [esp+3Ch] [ebp-2Ch]
  double X; // [esp+44h] [ebp-24h] BYREF
  double v62; // [esp+4Ch] [ebp-1Ch] BYREF
  double v63; // [esp+54h] [ebp-14h] BYREF
  double v64; // [esp+5Ch] [ebp-Ch]
  double *v65; // [esp+64h] [ebp-4h]
  unsigned int v66; // [esp+70h] [ebp+8h]
  int v67; // [esp+70h] [ebp+8h]
  int v68; // [esp+70h] [ebp+8h]

  v4 = *(_DWORD **)(this + 8);
  v5 = *(double **)(v4[5] + 4 * a2);
  v6 = *(_DWORD *)v5;
  v7 = (*(_DWORD *)v5 & 0x100) == 0;
  v65 = (double *)this;
  if ( !v7 )
  {
    v8 = a3;
    if ( a3 )
    {
      *a3 = v5[4];
      v9 = v5[5];
LABEL_7:
      v8[1] = v9;
      return 0;
    }
    return 0;
  }
  if ( (v6 & 0x80u) != 0 )
  {
    v8 = a3;
    if ( a3 )
    {
      *a3 = v5[4];
      v9 = v5[4];
      goto LABEL_7;
    }
    return 0;
  }
  v59 = *(double *)(this + 168);
  v60 = *(double *)(this + 160);
  v11 = *((_DWORD *)v5 + 2);
  if ( v11 == -1 )
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v4[4] + 4 * *((_DWORD *)v5 + 1)) + 4) & 2) == 0 )
      goto LABEL_206;
    v16 = *((_DWORD *)v5 + 18);
    if ( v16 == -1 )
      goto LABEL_206;
    v17 = *(int **)(v4[6] + 4 * v16);
    v18 = *v17;
    v19 = *((_DWORD *)v5 + 4);
    v20 = *v17 & 0xF0000000;
    if ( v20 == 0x10000000 )
    {
      v21 = v18 & 0xFFF00000;
      if ( v21 == 284164096
        || v21 == 285212672
        || v21 == 286261248
        || v21 == 287309824
        || v21 == 288358400
        || v21 == 289406976
        || v21 == 290455552 )
      {
        goto LABEL_206;
      }
      if ( (int)sub_662830(*(_DWORD *)(v17[2] + 4 * v19), &X) < 0 )
        goto LABEL_193;
      v22 = *v17 & 0xFFF00000;
      if ( v22 <= 0x10700000 )
      {
        if ( v22 == 275775488 )
        {
          if ( X < 0.0 )
            goto LABEL_206;
          v59 = 1.0 / sqrt(v62);
          v24 = 1.0 / sqrt(X);
          goto LABEL_205;
        }
        if ( v22 != 0x10000000 )
        {
          switch ( v22 )
          {
            case 0x10100000u:
              v59 = -v62;
              v24 = -X;
              break;
            case 0x10200000u:
              if ( X >= 0.0 )
              {
                if ( X == 0.0 )
                  v28 = 0.0;
                else
                  v28 = X + v65[22];
              }
              else
              {
                v28 = X - v65[22];
              }
              v59 = v28;
              if ( v62 >= 0.0 )
              {
                if ( v62 == 0.0 )
                {
LABEL_190:
                  v24 = 0.0;
                  break;
                }
                v24 = v62 + v65[22];
              }
              else
              {
                v24 = v62 - v65[22];
              }
              break;
            case 0x10300000u:
              if ( X <= 0.0 && v62 >= 0.0 )
                goto LABEL_206;
              v59 = 1.0 / v62;
              v24 = 1.0 / X;
              break;
            case 0x10400000u:
              if ( X == v62 )
              {
                if ( _finite(X) )
                {
                  v27 = X - floor(v62);
LABEL_200:
                  v60 = v27;
                  v59 = v27;
                  goto LABEL_206;
                }
                goto LABEL_75;
              }
              goto LABEL_109;
            case 0x10500000u:
              v59 = pow(2.0, X);
              v25 = 2.0;
              v26 = v62;
              goto LABEL_184;
            case 0x10600000u:
              if ( X <= 0.0 )
                v23 = v65[21];
              else
                v23 = __FYL2X__(X, 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094);
              v59 = v23;
              if ( v62 <= 0.0 )
                v24 = v65[21];
              else
                v24 = __FYL2X__(v62, 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094);
              break;
            default:
LABEL_206:
              v53 = 0;
              goto LABEL_207;
          }
LABEL_205:
          v60 = v24;
          goto LABEL_206;
        }
        goto LABEL_158;
      }
      if ( v22 != 276824064 )
      {
        if ( v22 != 277872640 )
        {
          if ( v22 == 278921216 )
          {
            if ( X >= -1.0 && v62 <= 1.0 )
            {
              v59 = asin(X);
              v24 = asin(v62);
              goto LABEL_205;
            }
            goto LABEL_87;
          }
          if ( v22 != 279969792 )
          {
            if ( v22 != 281018368 )
            {
              if ( v22 != 282066944 && v22 != 283115520 || X != v62 || !_finite(X) )
                goto LABEL_206;
              goto LABEL_75;
            }
            if ( X == v62 && _finite(X) )
            {
              v29 = X;
              v30 = 1.0;
LABEL_79:
              v27 = atan2(v29, v30);
              goto LABEL_200;
            }
LABEL_87:
            v59 = -1.570796370506287;
            v24 = 1.570796370506287;
            goto LABEL_205;
          }
          if ( X >= -1.0 && v62 <= 1.0 )
          {
            v59 = acos(v62);
            v24 = acos(X);
            goto LABEL_205;
          }
          v31 = 0.0;
LABEL_132:
          v59 = v31;
          v24 = 3.141592741012573;
          goto LABEL_205;
        }
        if ( X == v62 && _finite(X) )
        {
          v32 = X;
LABEL_202:
          v27 = cos(v32);
          goto LABEL_200;
        }
LABEL_203:
        v35 = -1.0;
        goto LABEL_204;
      }
      if ( X != v62 || !_finite(X) )
        goto LABEL_203;
      v33 = X;
LABEL_199:
      v27 = sin(v33);
      goto LABEL_200;
    }
    if ( v20 != 0x20000000 )
    {
      v38 = v18 & 0xFFF00000;
      if ( (v18 & 0xFFF00000) == 0x50000000 )
      {
        v39 = v18 & 0xFFFFF;
        v59 = 0.0;
        HIDWORD(v64) = v39;
        v60 = 0.0;
        v40 = 0;
        if ( v39 )
        {
          v67 = 4 * v39;
          while ( (int)sub_662830(*(_DWORD *)(v17[2] + 4 * v40), &X) >= 0
               && (int)sub_662830(*(_DWORD *)(v67 + v17[2]), &v57) >= 0 )
          {
            sub_66278D(v65, &v55, &X, &v57, *(_DWORD *)v5);
            v67 += 4;
            ++v40;
            v59 = v55 + v59;
            v60 = v56 + v60;
            if ( v40 >= HIDWORD(v64) )
              goto LABEL_206;
          }
          goto LABEL_193;
        }
        goto LABEL_206;
      }
      if ( v38 != 805306368 )
      {
        if ( v38 != 1343225856 )
        {
          if ( v38 != 1345323008 )
            goto LABEL_206;
          if ( (int)sub_662830(*(_DWORD *)v17[2], &v57) < 0 )
            goto LABEL_193;
          if ( v57 != v58 || !_finite(v57) )
            goto LABEL_203;
          if ( !v19 )
          {
            v32 = v57;
            goto LABEL_202;
          }
          if ( v19 != 1 )
            goto LABEL_206;
          v33 = v57;
          goto LABEL_199;
        }
        if ( v19 )
        {
          v46 = v19 - 1;
          if ( !v46 )
          {
            if ( (int)sub_662830(*(_DWORD *)v17[2], &v57) < 0 )
              goto LABEL_193;
            if ( v57 <= 0.0 )
            {
              v59 = 0.0;
              if ( v51 | v52 )
                goto LABEL_190;
            }
            else
            {
              v59 = v57;
            }
            v24 = v58;
            goto LABEL_205;
          }
          v47 = v46 - 1;
          if ( !v47 )
          {
            if ( (int)sub_662830(*(_DWORD *)v17[2], &v57) < 0 )
              goto LABEL_193;
            if ( v58 > 0.0 )
            {
              if ( (int)sub_662830(*(_DWORD *)(v17[2] + 4), &X) < 0 )
                goto LABEL_193;
              if ( v62 > 0.0 )
              {
                if ( (int)sub_662830(*(_DWORD *)(v17[2] + 12), &v55) < 0 )
                  goto LABEL_193;
                if ( X >= 1.0 )
                  v48 = v55;
                else
                  v48 = v56;
                v64 = v48;
                v59 = pow(X, v48);
                if ( v62 >= 1.0 )
                  v49 = v56;
                else
                  v49 = v55;
                v64 = v49;
                v25 = v62;
                v26 = v64;
LABEL_184:
                v24 = pow(v25, v26);
                goto LABEL_205;
              }
            }
            goto LABEL_75;
          }
          if ( v47 != 1 )
            goto LABEL_206;
        }
        goto LABEL_106;
      }
      v41 = v17[2];
      v68 = *(_DWORD *)(v41 + 4 * v19);
      v42 = v17[3];
      v43 = *(_DWORD *)(v41 + 4 * (v42 + v19));
      v44 = *(_DWORD *)(v41 + 4 * (v19 + 2 * v42));
      HIDWORD(v64) = v43;
      if ( (int)sub_662830(v68, &v55) < 0 || (int)sub_662830(HIDWORD(v64), &X) < 0 || (int)sub_662830(v44, &v57) < 0 )
        goto LABEL_193;
      if ( (*v17 & 0xFFF00000) != 0x30000000 )
        goto LABEL_206;
      if ( v68 == HIDWORD(v64) )
      {
        if ( X < 0.0 )
          X = 0.0;
        if ( v62 < 0.0 )
          v62 = 0.0;
      }
      if ( v68 == v44 )
      {
        if ( v57 > 0.0 )
          v57 = 0.0;
        v24 = v58;
        if ( v58 > 0.0 )
          v24 = 0.0;
      }
      else
      {
        v24 = v58;
      }
      if ( v55 >= 0.0 )
      {
LABEL_158:
        v59 = X;
        goto LABEL_165;
      }
      if ( v56 < 0.0 )
      {
        v59 = v57;
        goto LABEL_205;
      }
      if ( X >= v57 )
        v45 = v57;
      else
        v45 = X;
      v59 = v45;
      if ( v62 <= v24 )
        goto LABEL_205;
      goto LABEL_165;
    }
    if ( (v18 & 0xFFF00000) == 0x20900000 )
      goto LABEL_206;
    if ( (int)sub_662830(*(_DWORD *)(v17[2] + 4 * v19), &v63) < 0
      || (int)sub_662830(*(_DWORD *)(v17[2] + 4 * (v19 + v17[3])), &X) < 0 )
    {
      goto LABEL_193;
    }
    v34 = *v17 & 0xFFF00000;
    if ( v34 > 0x20400000 )
    {
      if ( v34 == 542113792 )
      {
        sub_66278D(v65, &v59, &v63, &X, *(_DWORD *)v5);
        goto LABEL_206;
      }
      if ( v34 == 543162368 )
      {
        if ( v63 == v64 && _finite(v63) && X == v62 && _finite(X) )
        {
          v29 = v63;
          v30 = X;
          goto LABEL_79;
        }
        v31 = -3.141592741012573;
        goto LABEL_132;
      }
      if ( v34 != 544210944 && v34 != 545259520 )
        goto LABEL_206;
      if ( v63 < X )
      {
LABEL_111:
        v36 = v63;
        goto LABEL_124;
      }
    }
    else
    {
      if ( v34 == 541065216 )
      {
        v59 = X + v63;
        v24 = v62 + v64;
        goto LABEL_205;
      }
      if ( v34 == 0x20000000 )
      {
        if ( v63 >= X )
          v37 = X;
        else
          v37 = v63;
        v59 = v37;
        if ( v64 >= v62 )
          goto LABEL_165;
LABEL_125:
        v24 = v64;
        goto LABEL_205;
      }
      if ( v34 != 537919488 )
      {
        if ( v34 != 538968064 )
        {
          if ( v34 != 540016640 )
            goto LABEL_206;
          if ( v64 < X )
            goto LABEL_75;
          if ( v63 >= v62 )
            goto LABEL_106;
LABEL_109:
          v35 = 0.0;
          goto LABEL_204;
        }
        if ( v63 >= v62 )
        {
LABEL_75:
          v59 = 0.0;
          goto LABEL_190;
        }
        if ( v64 >= X )
          goto LABEL_109;
LABEL_106:
        v35 = 1.0;
LABEL_204:
        v59 = v35;
        v24 = 1.0;
        goto LABEL_205;
      }
      if ( v63 > X )
        goto LABEL_111;
    }
    v36 = X;
LABEL_124:
    v59 = v36;
    if ( v64 > v62 )
      goto LABEL_125;
LABEL_165:
    v24 = v62;
    goto LABEL_205;
  }
  if ( (int)sub_6640D2(v11, &v62) < 0 )
    goto LABEL_206;
  v12 = *(_DWORD *)(this + 8);
  v13 = *((_DWORD *)v5 + 3) + (__int64)v62;
  v66 = 0;
  HIDWORD(v64) = *(_DWORD *)(v12 + 8);
  if ( !HIDWORD(v64) )
    goto LABEL_206;
  v14 = *(_DWORD *)(v12 + 20);
  while ( 1 )
  {
    v15 = *(_DWORD **)v14;
    if ( *(_DWORD *)(*(_DWORD *)v14 + 4) == *((_DWORD *)v5 + 1)
      && v15[2] == -1
      && v15[3] == v13
      && v15[4] == *((_DWORD *)v5 + 4) )
    {
      break;
    }
    ++v66;
    v14 += 4;
    if ( v66 >= HIDWORD(v64) )
      goto LABEL_206;
  }
  if ( (int)sub_662830(v66, &v59) >= 0 )
    goto LABEL_206;
LABEL_193:
  v53 = -2147467259;
  v59 = v65[21];
  v60 = v65[20];
LABEL_207:
  if ( (*(_DWORD *)v5 & 4) != 0 )
  {
    if ( v59 <= 0.0 )
      v59 = 0.0;
    if ( v60 <= 0.0 )
      v60 = 0.0;
  }
  else if ( v59 >= 0.0 )
  {
    *(_DWORD *)v5 |= 4u;
  }
  if ( (*(_DWORD *)v5 & 8) != 0 )
  {
    if ( v59 >= 0.0 )
      v59 = 0.0;
    if ( v60 >= 0.0 )
      v60 = 0.0;
  }
  else if ( v60 <= 0.0 )
  {
    *(_DWORD *)v5 |= 8u;
  }
  if ( (*(_DWORD *)v5 & 0x10) != 0 )
  {
    if ( v59 <= -1.0 )
      v59 = -1.0;
    if ( v60 <= -1.0 )
      v60 = -1.0;
    if ( v59 >= 1.0 )
      v59 = 1.0;
    if ( v60 >= 1.0 )
      v60 = 1.0;
  }
  else if ( v59 >= -1.0 && v60 <= 1.0 )
  {
    *(_DWORD *)v5 |= 0x10u;
  }
  if ( v59 == v60 && _finite(v59) )
  {
    *(_BYTE *)v5 |= 0x80u;
    if ( 0.0 == v59 || 1.0 == v59 )
      *(_DWORD *)v5 |= 1u;
    if ( fabs(v59 - (double)(int)(__int64)v59) < 0.000001 )
      *(_DWORD *)v5 |= 2u;
  }
  v5[4] = v59;
  v54 = v60;
  *((_BYTE *)v5 + 1) |= 1u;
  v5[5] = v54;
  if ( a3 )
  {
    *a3 = v59;
    a3[1] = v60;
  }
  return v53;
}
