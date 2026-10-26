int __thiscall sub_6834BF(_DWORD *this, int a2, int *a3, int *a4, int *a5, __int64 a6)
{
  int v7; // eax
  int result; // eax
  _DWORD *v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  _DWORD *v12; // esi
  unsigned int v13; // esi
  int v14; // edx
  int v15; // esi
  int v16; // ebx
  int v17; // edx
  int v18; // esi
  int v19; // edx
  int *v20; // ecx
  int *v21; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // esi
  int v25; // edi
  int v26; // ebx
  int v27; // eax
  _DWORD *v28; // esi
  int v29; // edi
  int v30; // ecx
  int v31; // eax
  _DWORD *v32; // edi
  unsigned int v33; // eax
  unsigned int v34; // eax
  int v35; // edx
  int *v36; // ecx
  _DWORD *v37; // ecx
  _DWORD *i; // edx
  int *v39; // edi
  int *v40; // edi
  int v41; // [esp+14h] [ebp-18h]
  int v42; // [esp+18h] [ebp-14h]
  _DWORD *v44; // [esp+20h] [ebp-Ch]
  int *v45; // [esp+20h] [ebp-Ch]
  int v46; // [esp+20h] [ebp-Ch]
  unsigned int v47; // [esp+28h] [ebp-4h]
  unsigned int v48; // [esp+34h] [ebp+8h]
  int v49; // [esp+34h] [ebp+8h]
  int v50; // [esp+40h] [ebp+14h]

  v7 = *(_DWORD *)(this[5] + 4 * a2);
  if ( *(_DWORD *)(v7 + 8) != -1
    || (*(_BYTE *)v7 & 1) == 0
    || (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v7 + 4)) + 4) & 2) == 0 )
  {
    return -2147467259;
  }
  v9 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v7 + 72));
  v10 = v9[3];
  v11 = 0;
  if ( v10 )
  {
    v12 = (_DWORD *)v9[4];
    do
    {
      if ( *v12 == a2 )
        break;
      ++v11;
      ++v12;
    }
    while ( v11 < v10 );
  }
  if ( v11 != v10 )
  {
    v13 = *v9 & 0xFFF00000;
    switch ( v13 )
    {
      case 0x10000000u:
        result = sub_6834BF(*(_DWORD *)(v9[2] + 4 * v11), a3, a4, a5, a6, HIDWORD(a6));
        goto LABEL_16;
      case 0x20500000u:
        v14 = v9[2];
        v15 = *(_DWORD *)(v14 + 4 * v11);
        v16 = *(_DWORD *)(v14 + 4 * (v11 + v10));
        result = sub_6834BF(v15, a3, a4, a5, a6, HIDWORD(a6));
        if ( result < 0 )
          return result;
        if ( v15 != v16 )
        {
          result = sub_6834BF(v16, a3, a4, a5, a6, HIDWORD(a6));
LABEL_16:
          if ( result < 0 )
            return result;
          return 0;
        }
        return 0;
      case 0x20200000u:
        v17 = v9[2];
        v18 = *(_DWORD *)(v17 + 4 * v11);
        v19 = *(_DWORD *)(v17 + 4 * (v11 + v10));
        if ( (*a3 == -1 || v19 == *a3)
          && (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v18) + 4)) + 4) & 0x100) != 0
          && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v18) + 8) == -1 )
        {
          v20 = a4;
          if ( *a4 != -1
            && *(double *)(*(_DWORD *)(this[5] + 4 * *a4) + 32) >= *(double *)(*(_DWORD *)(this[5] + 4 * v18) + 32) )
          {
            return 0;
          }
          goto LABEL_41;
        }
        if ( (*a3 == -1 || v18 == *a3)
          && (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v19) + 4)) + 4) & 0x100) != 0
          && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v19) + 8) == -1 )
        {
          v21 = (int *)HIDWORD(a6);
          if ( *(_DWORD *)HIDWORD(a6) != -1
            && *(double *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)HIDWORD(a6)) + 32) <= *(double *)(*(_DWORD *)(this[5] + 4 * v19)
                                                                                                + 32) )
          {
            return 0;
          }
          goto LABEL_32;
        }
        return -2147467259;
      case 0x20300000u:
        v22 = v9[2];
        v18 = *(_DWORD *)(v22 + 4 * v11);
        v19 = *(_DWORD *)(v22 + 4 * (v11 + v10));
        if ( (*a3 == -1 || v19 == *a3)
          && (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v18) + 4)) + 4) & 0x100) != 0
          && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v18) + 8) == -1 )
        {
          v20 = (int *)a6;
          if ( *(_DWORD *)a6 != -1
            && *(double *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)a6) + 32) <= *(double *)(*(_DWORD *)(this[5] + 4 * v18)
                                                                                       + 32) )
          {
            return 0;
          }
LABEL_41:
          *a3 = v19;
          *v20 = v18;
          return 0;
        }
        if ( (*a3 == -1 || v18 == *a3)
          && (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v19) + 4)) + 4) & 0x100) != 0
          && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v19) + 8) == -1 )
        {
          v21 = a5;
          if ( *a5 != -1
            && *(double *)(*(_DWORD *)(this[5] + 4 * *a5) + 32) >= *(double *)(*(_DWORD *)(this[5] + 4 * v19) + 32) )
          {
            return 0;
          }
LABEL_32:
          *a3 = v18;
          *v21 = v19;
          return 0;
        }
        return -2147467259;
      case 0x30000000u:
        v23 = v9[3];
        v24 = v9[2];
        v25 = this[5];
        v26 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(v24 + 4 * (v11 + v23)));
        v27 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(v24 + 4 * (v11 + 2 * v23)));
        v28 = this;
        v29 = this[4];
        if ( (*(_DWORD *)(*(_DWORD *)(v29 + 4 * *(_DWORD *)(v26 + 4)) + 4) & 0x100) != 0
          && *(_DWORD *)(v26 + 8) == -1
          && (*(_DWORD *)(*(_DWORD *)(v29 + 4 * *(_DWORD *)(v27 + 4)) + 4) & 0x100) != 0
          && *(_DWORD *)(v27 + 8) == -1
          && (0.0 == *(double *)(v26 + 32) && 1.0 == *(double *)(v27 + 32)
           || 1.0 == *(double *)(v26 + 32) && 0.0 == *(double *)(v27 + 32)) )
        {
          v30 = *(_DWORD *)(v9[2] + 4 * v11);
          v31 = *(_DWORD *)(this[5] + 4 * v30);
          if ( (*(_BYTE *)(*(_DWORD *)(v29 + 4 * *(_DWORD *)(v31 + 4)) + 4) & 2) != 0 )
          {
            v32 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v31 + 72));
            v33 = *v32 & 0xFFF00000;
            if ( v33 == 541065216 || v33 == 269484032 )
            {
              v34 = v32[3];
              v48 = 0;
              if ( v34 )
              {
                v44 = (_DWORD *)v32[4];
                do
                {
                  if ( *v44 == v30 )
                    break;
                  ++v48;
                  ++v44;
                }
                while ( v48 < v34 );
              }
              if ( (*v32 & 0xFFF00000) == 0x10100000 )
              {
                v35 = sub_681AAA(v28, v28[30], 0, 0, 0.0);
                v36 = *(int **)(v32[2] + 4 * v48);
                if ( v35 == -1 )
                  return -2147024882;
              }
              else
              {
                v47 = 0;
                v41 = v32[2];
                v45 = (int *)(v41 + 4 * (v34 + v48));
                while ( 1 )
                {
                  v42 = *v45;
                  if ( (*(_BYTE *)(*(_DWORD *)(v28[4] + 4 * *(_DWORD *)(*(_DWORD *)(v28[5] + 4 * *v45) + 4)) + 4) & 2) != 0 )
                  {
                    v37 = *(_DWORD **)(v28[6] + 4 * *(_DWORD *)(*(_DWORD *)(v28[5] + 4 * *v45) + 72));
                    if ( (*v37 & 0xFFF00000) == 0x10100000 )
                      break;
                  }
                  ++v47;
                  v45 -= v34;
                  if ( v47 >= 2 )
                  {
                    v35 = (int)a3;
                    v36 = a3;
                    goto LABEL_79;
                  }
                }
                v46 = 0;
                if ( v37[3] )
                {
                  for ( i = (_DWORD *)v37[4]; v42 != *i; ++i )
                  {
                    if ( (unsigned int)++v46 >= v37[3] )
                      break;
                  }
                }
                v35 = *(_DWORD *)(v41 + 4 * (v48 + v47 * v34));
                v36 = *(int **)(v37[2] + 4 * v46);
LABEL_79:
                if ( v47 == 2 )
                  return -2147467259;
              }
              if ( *a3 == -1 || v35 == *a3 )
              {
                v49 = *(_DWORD *)(v28[5] + 4 * (_DWORD)v36);
                if ( (*(_DWORD *)(*(_DWORD *)(v28[4] + 4 * *(_DWORD *)(v49 + 4)) + 4) & 0x100) != 0
                  && *(_DWORD *)(v49 + 8) == -1 )
                {
                  if ( 1.0 == *(double *)(v26 + 32) )
                  {
                    v39 = a5;
                    if ( *a5 != -1
                      && *(double *)(*(_DWORD *)(v28[5] + 4 * *a5) + 32) >= *(double *)(*(_DWORD *)(v28[5]
                                                                                                  + 4 * (_DWORD)v36)
                                                                                      + 32) )
                    {
                      return 0;
                    }
                  }
                  else
                  {
                    v39 = (int *)HIDWORD(a6);
                    if ( *(_DWORD *)HIDWORD(a6) != -1
                      && *(double *)(*(_DWORD *)(v28[5] + 4 * *(_DWORD *)HIDWORD(a6)) + 32) <= *(double *)(*(_DWORD *)(v28[5] + 4 * (_DWORD)v36) + 32) )
                    {
                      return 0;
                    }
                  }
                  *a3 = v35;
                  *v39 = (int)v36;
                  return 0;
                }
              }
              if ( *a3 == -1 || v36 == (int *)*a3 )
              {
                v50 = *(_DWORD *)(v28[5] + 4 * v35);
                if ( (*(_DWORD *)(*(_DWORD *)(v28[4] + 4 * *(_DWORD *)(v50 + 4)) + 4) & 0x100) != 0
                  && *(_DWORD *)(v50 + 8) == -1 )
                {
                  if ( 1.0 == *(double *)(v26 + 32) )
                  {
                    v40 = (int *)a6;
                    if ( *(_DWORD *)a6 != -1
                      && *(double *)(*(_DWORD *)(v28[5] + 4 * *(_DWORD *)a6) + 32) <= *(double *)(*(_DWORD *)(v28[5] + 4 * v35)
                                                                                                + 32) )
                    {
                      return 0;
                    }
                  }
                  else
                  {
                    v40 = a4;
                    if ( *a4 != -1
                      && *(double *)(*(_DWORD *)(v28[5] + 4 * *a4) + 32) >= *(double *)(*(_DWORD *)(v28[5] + 4 * v35)
                                                                                      + 32) )
                    {
                      return 0;
                    }
                  }
                  *a3 = (int)v36;
                  *v40 = v35;
                  return 0;
                }
              }
            }
          }
        }
        break;
    }
  }
  return -2147467259;
}
