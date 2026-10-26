int __thiscall sub_689020(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int v5; // eax
  _DWORD *v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  double v15; // st7
  _DWORD *v16; // eax
  _DWORD *i; // ecx
  _DWORD *v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // edx
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edi
  _DWORD *v25; // ebx
  _DWORD *v26; // ecx
  _DWORD *v27; // eax
  _DWORD *v28; // ecx
  _DWORD *v29; // eax
  unsigned int v30; // ecx
  int v31; // edi
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  _DWORD *j; // ecx
  int v35; // eax
  int v37; // [esp+14h] [ebp-24h]
  int v38; // [esp+18h] [ebp-20h]
  int v39; // [esp+18h] [ebp-20h]
  int v40; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v41; // [esp+20h] [ebp-18h]
  int v42; // [esp+24h] [ebp-14h]
  int v43; // [esp+28h] [ebp-10h]
  _DWORD *v44; // [esp+2Ch] [ebp-Ch]
  unsigned int v45; // [esp+30h] [ebp-8h]
  int v46; // [esp+34h] [ebp-4h]
  _DWORD *v47; // [esp+34h] [ebp-4h]
  unsigned int v48; // [esp+40h] [ebp+8h]
  int v49; // [esp+40h] [ebp+8h]
  unsigned int v50; // [esp+40h] [ebp+8h]
  unsigned int v51; // [esp+40h] [ebp+8h]
  int v52; // [esp+40h] [ebp+8h]
  int v53; // [esp+40h] [ebp+8h]
  unsigned int v54; // [esp+44h] [ebp+Ch]
  unsigned int v55; // [esp+44h] [ebp+Ch]
  _DWORD *v56; // [esp+44h] [ebp+Ch]
  unsigned int v57; // [esp+44h] [ebp+Ch]
  int v58; // [esp+48h] [ebp+10h]
  _DWORD *v59; // [esp+48h] [ebp+10h]

  v5 = this[5];
  v6 = *(_DWORD **)(v5 + 4 * a3);
  v7 = *(_DWORD *)(v5 + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * a4) + 48));
  v58 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * a4) + 48);
  v8 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v6[1]) + 4);
  v41 = v6;
  v37 = v7;
  if ( (v8 & 1) == 0 || (v8 & 0x1000) != 0 )
    return 0;
  v54 = *(_DWORD *)v7 & 0x1F;
  v9 = *v6;
  v46 = *v6 & 0x40;
  v10 = *a2 & 0xFFF00000;
  v45 = v10;
  if ( v10 == 0x10000000 )
  {
    v11 = v58;
    *v6 = v54 | v9;
LABEL_140:
    v6[12] = v11;
    return 0;
  }
  v12 = v9 | *(_DWORD *)v7 & 0x40;
  *v6 = v12;
  if ( (v12 & 0xE000000) == 0
    && (v10 == 269484032 || v10 == 271581184 || v10 == 272629760 || v10 == 282066944 || v10 == 283115520) )
  {
    *v6 = v12 | *(_DWORD *)v7 & 0xE000000;
  }
  v13 = 4;
  switch ( v10 )
  {
    case 0x10100000u:
      *v6 |= v54 & 0xFFFFFFF3 | (2 * (v54 & 4)) | (v54 >> 1) & 4;
      break;
    case 0x10300000u:
      if ( (v54 & 4) == 0 || (v54 & 8) == 0 )
        v13 = v54 & 0xC;
      goto LABEL_20;
    case 0x10400000u:
    case 0x10500000u:
    case 0x10700000u:
LABEL_20:
      *v6 |= v13;
      break;
  }
  v14 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v7 + 4)) + 4);
  if ( (v14 & 0x100) == 0 || *(_DWORD *)(v7 + 8) != -1 )
  {
    if ( ((v54 & 1) == 0 || v10 != 272629760) && ((v54 & 2) == 0 || v10 != 272629760) )
    {
      if ( (v54 & 8) != 0 )
      {
        if ( v10 == 274726912 )
        {
          if ( !v46 && (v54 & 4) == 0 )
            sub_686791((int)this, a2[15], 4002, "indefinite logarithm");
          return 0;
        }
        if ( v10 == 275775488 )
        {
          if ( !v46 )
          {
            sub_686791((int)this, a2[15], 4003, "imaginary square root");
            v11 = sub_681AAA(this, this[30], 0, 0, 0.0);
            goto LABEL_140;
          }
          return 0;
        }
      }
      if ( (v14 & 0x200) == 0 || v10 != 282066944 && v10 != 283115520 )
      {
        if ( v46 || (v14 & 2) == 0 )
          return 0;
        if ( v10 == 269484032
          && (v16 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72)), (*v16 & 0xFFF00000) == 0x10100000)
          || v10 == 271581184
          && (v16 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72)), (*v16 & 0xFFF00000) == 0x10300000)
          || v10 == 273678336
          && (v16 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72)), (*v16 & 0xFFF00000) == 0x10600000)
          || v10 == 274726912
          && (v16 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72)), (*v16 & 0xFFF00000) == 0x10500000) )
        {
          v48 = 0;
          if ( v16[3] )
          {
            for ( i = (_DWORD *)v16[4]; *i != v58; ++i )
            {
              if ( ++v48 >= v16[3] )
                break;
            }
          }
          if ( v48 < v16[3] )
          {
            v11 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v16[2] + 4 * v48)) + 48);
            goto LABEL_140;
          }
        }
        if ( v10 == 271581184 )
        {
          v18 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72));
          if ( (*v18 & 0xFFF00000) == 0x20500000 )
          {
            v19 = v18[3];
            v20 = 0;
            if ( v19 )
            {
              v21 = (_DWORD *)v18[4];
              do
              {
                if ( *v21 == v58 )
                  break;
                ++v20;
                ++v21;
              }
              while ( v20 < v19 );
            }
            v22 = v18[3];
            v23 = v18[2];
            v55 = 0;
            v43 = this[5];
            v38 = 4 * v22;
            v24 = -1 * v22;
            v25 = (_DWORD *)(v23 + 4 * v20);
            v26 = (_DWORD *)(v23 + 4 * (v20 + v22));
            v47 = v25;
            v44 = v26;
            while ( 1 )
            {
              v40 = *v26;
              v42 = *v25;
              v49 = *(_DWORD *)(v43 + 4 * *v25);
              if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v49 + 4)) + 4) & 2) != 0 )
              {
                v27 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v49 + 72));
                if ( (*v27 & 0xFFF00000) == 0x10700000 )
                {
                  v50 = 0;
                  if ( v27[3] )
                  {
                    v28 = (_DWORD *)v27[4];
                    do
                    {
                      if ( *v28 == v42 )
                        break;
                      ++v50;
                      ++v28;
                    }
                    while ( v50 < v27[3] );
                  }
                  if ( *(_DWORD *)(v27[2] + 4 * v50) == v40 )
                  {
                    v41[12] = *(_DWORD *)(*(_DWORD *)(v43 + 4 * v42) + 48);
                    return 0;
                  }
                  v25 = v47;
                }
              }
              v25 = (_DWORD *)((char *)v25 + v38);
              ++v55;
              v26 = &v44[v24];
              v47 = v25;
              v44 = (_DWORD *)((char *)v44 + v24 * 4);
              if ( v55 >= 2 )
              {
                v6 = v41;
                v7 = v37;
                break;
              }
            }
          }
        }
        if ( v45 != 273678336 )
          return 0;
        v29 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72));
        if ( (*v29 & 0xFFF00000) != 0x20500000 )
          return 0;
        v30 = v29[3];
        v51 = 0;
        if ( v30 )
        {
          v56 = (_DWORD *)v29[4];
          do
          {
            if ( *v56 == v58 )
              break;
            ++v51;
            ++v56;
          }
          while ( v51 < v30 );
        }
        v57 = 0;
        v31 = this[5];
        v39 = v30;
        v32 = (_DWORD *)(v29[2] + 4 * v51);
        v59 = v32;
        while ( 1 )
        {
          v52 = *(_DWORD *)(v31 + 4 * *v32);
          if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v52 + 4)) + 4) & 2) != 0 )
          {
            v33 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v52 + 72));
            if ( (*v33 & 0xFFF00000) == 0x10600000 )
            {
              v53 = 0;
              if ( v33[3] )
              {
                for ( j = (_DWORD *)v33[4]; *j != *v59; ++j )
                {
                  if ( (unsigned int)++v53 >= v33[3] )
                    break;
                }
              }
              v31 = this[5];
              v35 = **(_DWORD **)(v31 + 4 * *(_DWORD *)(v33[2] + 4 * v53));
              if ( (v35 & 4) != 0 && (v35 & 8) != 0 )
                break;
            }
          }
          v32 = &v59[v39];
          ++v57;
          v59 = (_DWORD *)((char *)v59 + v39 * 4);
          if ( v57 >= 2 )
            return 0;
        }
      }
    }
    v11 = sub_681AAA(this, this[30], 0, 0, 0.0);
    goto LABEL_140;
  }
  if ( v10 > 0x10800000 )
  {
    switch ( v10 )
    {
      case 0x10900000u:
        v15 = cos(*(double *)(v7 + 32));
        goto LABEL_70;
      case 0x10A00000u:
        if ( v46 || *(double *)(v7 + 32) >= -1.0 && *(double *)(v7 + 32) <= 1.0 )
        {
          v15 = asin(*(double *)(v7 + 32));
          goto LABEL_70;
        }
        sub_686791((int)this, a2[15], 4005, "indefinite arcsine");
        goto LABEL_67;
      case 0x10B00000u:
        if ( !v46 && (*(double *)(v7 + 32) < -1.0 || *(double *)(v7 + 32) > 1.0) )
        {
          sub_686791((int)this, a2[15], 4006, "indefinite arccosine");
          goto LABEL_67;
        }
        v15 = acos(*(double *)(v7 + 32));
        goto LABEL_70;
      case 0x10C00000u:
        v15 = atan2(*(double *)(v7 + 32), 1.0);
        goto LABEL_70;
      case 0x10D00000u:
      case 0x10E00000u:
        goto LABEL_67;
    }
  }
  else
  {
    switch ( v10 )
    {
      case 0x10800000u:
        v15 = sin(*(double *)(v7 + 32));
        goto LABEL_70;
      case 0x10100000u:
        v15 = -*(double *)(v7 + 32);
        goto LABEL_70;
      case 0x10300000u:
        if ( !v46 && 0.0 == *(double *)(v7 + 32) )
          goto LABEL_67;
        v15 = 1.0 / *(double *)(v7 + 32);
        goto LABEL_70;
      case 0x10400000u:
        if ( !_finite(*(double *)(v7 + 32)) )
          goto LABEL_67;
        v15 = *(double *)(v7 + 32) - floor(*(double *)(v7 + 32));
        goto LABEL_70;
      case 0x10500000u:
        v15 = pow(2.0, *(double *)(v7 + 32));
        goto LABEL_70;
      case 0x10600000u:
        if ( v46 || *(double *)(v7 + 32) != 0.0 )
        {
          if ( *(double *)(v7 + 32) < 0.0 )
          {
            sub_686791((int)this, a2[15], 4002, "indefinite logarithm");
            goto LABEL_67;
          }
          v15 = __FYL2X__(*(double *)(v7 + 32), 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094);
LABEL_70:
          v11 = sub_681AAA(this, this[30], 0, 0, v15);
          goto LABEL_140;
        }
        break;
      case 0x10700000u:
        if ( !v46 && *(double *)(v7 + 32) < 0.0 )
        {
          sub_686791((int)this, a2[15], 4003, "imaginary square root");
LABEL_67:
          v15 = 0.0;
          goto LABEL_70;
        }
        v15 = 1.0 / sqrt(*(double *)(v7 + 32));
        goto LABEL_70;
    }
  }
  return 0;
}
