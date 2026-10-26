_DWORD *__thiscall sub_609430(_DWORD *this, int a2, int a3)
{
  int v3; // ebp
  _DWORD *result; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  double v8; // st7
  _DWORD *v9; // eax
  _DWORD *v10; // ebx
  double v11; // st7
  int v12; // esi
  int v13; // ecx
  int *v14; // eax
  int v15; // eax
  int v16; // ecx
  float *v17; // edx
  int v18; // esi
  int v19; // edi
  _DWORD *v20; // eax
  int v21; // esi
  int v22; // ecx
  int v23; // eax
  _DWORD *v24; // edi
  int v25; // ebp
  int v26; // esi
  int v27; // ebx
  unsigned __int64 v28; // rax
  _DWORD *v29; // esi
  _DWORD *v30; // eax
  int v31; // edx
  bool v32; // cc
  int v33; // eax
  _DWORD *v34; // eax
  _BYTE **v35; // eax
  _BYTE *i; // eax
  int v37; // eax
  _BYTE **v38; // eax
  float v39; // [esp+4h] [ebp-54h]
  float v40; // [esp+8h] [ebp-50h]
  int v41; // [esp+Ch] [ebp-4Ch]
  float v43; // [esp+14h] [ebp-44h]
  float v44; // [esp+18h] [ebp-40h]
  float v45; // [esp+1Ch] [ebp-3Ch]
  int v46; // [esp+20h] [ebp-38h]
  int v47; // [esp+24h] [ebp-34h]
  int v48; // [esp+28h] [ebp-30h]
  int v49; // [esp+2Ch] [ebp-2Ch]
  int v50; // [esp+30h] [ebp-28h]
  int v51; // [esp+34h] [ebp-24h]
  _DWORD *v52; // [esp+38h] [ebp-20h]
  int v53; // [esp+3Ch] [ebp-1Ch]
  float v54; // [esp+40h] [ebp-18h] BYREF
  float v55; // [esp+44h] [ebp-14h] BYREF
  int v56; // [esp+48h] [ebp-10h] BYREF
  int v57; // [esp+54h] [ebp-4h]
  char v58; // [esp+5Ch] [ebp+4h]
  int v59; // [esp+60h] [ebp+8h]

  v3 = (int)this;
  result = (_DWORD *)this[207];
  if ( !result )
  {
    result = (_DWORD *)this[116];
    if ( (int)result > 0 )
    {
      v5 = operator new(0x1278u);
      v55 = *(float *)&v5;
      v57 = 0;
      if ( v5 )
        v6 = sub_609190(v5, a2);
      else
        v6 = 0;
      v57 = -1;
      *(_DWORD *)(v3 + 828) = v6;
      sub_607E40(v6, v3, a3);
      if ( (a3 & 1) != 0 )
      {
        sub_609350(*(_DWORD **)(v3 + 828), *(_DWORD *)(*(_DWORD *)(v3 + 828) + 48));
        *(_DWORD *)(*(_DWORD *)(v3 + 828) + 12) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 24);
        *(_DWORD *)(*(_DWORD *)(v3 + 828) + 16) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 28);
        *(_DWORD *)(*(_DWORD *)(v3 + 828) + 20) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 32);
        *(_DWORD *)(*(_DWORD *)(v3 + 828) + 24) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 36);
        *(_DWORD *)(*(_DWORD *)(v3 + 828) + 28) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 40);
        *(_DWORD *)(*(_DWORD *)(v3 + 828) + 32) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 44);
        *(float *)(*(_DWORD *)(v3 + 828) + 36) = fabs(
                                                   (*(float *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 36)
                                                  - *(float *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 24))
                                                 / (double)*(int *)(*(_DWORD *)(v3 + 828) + 4));
        *(float *)(*(_DWORD *)(v3 + 828) + 44) = fabs(
                                                   (*(float *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 44)
                                                  - *(float *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 32))
                                                 / (double)*(int *)(*(_DWORD *)(v3 + 828) + 4));
        sub_607D30(*(float **)(v3 + 828), *(_DWORD *)(*(_DWORD *)(v3 + 828) + 48));
        v7 = *(_DWORD *)(v3 + 828);
        v59 = *(_DWORD *)(v7 + 4) - 1;
        v40 = 1.0 / *(float *)(v7 + 36);
        v8 = 1.0 / *(float *)(v7 + 44);
        v9 = *(_DWORD **)(v3 + 452);
        *(_DWORD *)(v3 + 460) = v9;
        v45 = v8;
        if ( v9 )
        {
          v10 = (_DWORD *)*v9;
          v52 = (_DWORD *)*v9;
          if ( *v9 )
          {
            while ( 1 )
            {
              v11 = -1.0e12;
              v12 = 0;
              v43 = 1.0e12;
              v44 = 1.0e12;
              v39 = -1.0e12;
              if ( (int)v10[136] <= 0 )
                goto LABEL_80;
              do
              {
                v13 = v12;
                if ( v12 >= 0 && v12 < v10[136] )
                {
                  v14 = (int *)v10[133];
                  if ( v12 <= 0 )
                  {
LABEL_15:
                    if ( v14 )
                    {
                      v15 = *v14;
                      goto LABEL_18;
                    }
                  }
                  else
                  {
                    while ( v14 )
                    {
                      v14 = (int *)v14[1];
                      if ( --v13 <= 0 )
                        goto LABEL_15;
                    }
                  }
                }
                v15 = 0;
LABEL_18:
                v16 = 0;
                v17 = (float *)(v15 + 120);
                do
                {
                  if ( *(v16 >= 8 ? 0 : v17) < (double)v43 )
                    v43 = *(v16 >= 8 ? 0 : v17);
                  if ( *(v16 >= 8 ? (float *)8 : v17 + 2) < (double)v44 )
                    v44 = *(v16 >= 8 ? (float *)8 : v17 + 2);
                  if ( *(v16 >= 8 ? 0 : v17) > (double)v39 )
                    v39 = *(v16 >= 8 ? 0 : v17);
                  if ( v11 < *(v16 >= 8 ? (float *)8 : v17 + 2) )
                    v11 = *(v16 >= 8 ? (float *)8 : v17 + 2);
                  ++v16;
                  v17 += 3;
                }
                while ( v16 < 8 );
                ++v12;
              }
              while ( v12 < v10[136] );
              v18 = *(_DWORD *)(v3 + 828);
              v19 = (unsigned __int64)((v43 - *(float *)(v18 + 12)) * v40);
              v53 = (unsigned __int64)((v44 - *(float *)(v18 + 20)) * v45);
              if ( v59 >= (int)(unsigned __int64)((v39 - *(float *)(v18 + 12)) * v40) )
                v51 = (unsigned __int64)((v39 - *(float *)(v18 + 12)) * v40);
              else
                v51 = v59;
              if ( v59 >= (int)(unsigned __int64)((v11 - *(float *)(v18 + 20)) * v45) )
                v48 = (unsigned __int64)((v11 - *(float *)(v18 + 20)) * v45);
              else
                v48 = v59;
              v49 = (unsigned __int64)((v43 - *(float *)(v18 + 12)) * v40);
              if ( v19 <= v51 )
              {
                v50 = 292 * (v53 + 4 * v19);
                while ( 1 )
                {
                  v47 = v53;
                  if ( v53 > v48 )
                    goto LABEL_78;
                  v41 = v50;
                  do
                  {
                    v20 = *(_DWORD **)(v41 + this[207] + 320);
                    if ( v20 )
                    {
                      while ( !*v20 || (_DWORD *)*v20 != v10 )
                      {
                        v20 = (_DWORD *)v20[1];
                        if ( !v20 )
                          goto LABEL_45;
                      }
                      if ( *v20 )
                        goto LABEL_77;
                    }
LABEL_45:
                    v21 = 0;
                    v58 = 1;
                    v46 = 0;
                    if ( (int)v10[136] <= 0 )
                      goto LABEL_77;
                    do
                    {
                      v22 = v21;
                      if ( v21 < 0 || v21 >= v10[136] )
                        goto LABEL_52;
                      v23 = v10[133];
                      if ( v21 > 0 )
                      {
                        while ( v23 )
                        {
                          v23 = *(_DWORD *)(v23 + 4);
                          if ( --v22 <= 0 )
                            goto LABEL_51;
                        }
LABEL_52:
                        v24 = 0;
                        goto LABEL_54;
                      }
LABEL_51:
                      if ( !v23 )
                        goto LABEL_52;
                      v24 = *(_DWORD **)v23;
LABEL_54:
                      if ( ((unsigned int)&dword_1000000 & *v24) == 0 )
                      {
                        v25 = 0;
                        if ( sub_5EA5B0(v24) > 0 )
                        {
                          while ( 1 )
                          {
                            sub_5EC540(v24, v25, &v54, &v56, &v55);
                            v26 = this[207];
                            v27 = v59;
                            if ( v59 >= (int)(unsigned __int64)((v54 - *(float *)(v26 + 12)) * v40) )
                              v27 = (unsigned __int64)((v54 - *(float *)(v26 + 12)) * v40);
                            v28 = (unsigned __int64)((v55 - *(float *)(v26 + 20)) * v45);
                            if ( v59 < (int)v28 )
                              LODWORD(v28) = v59;
                            if ( v27 == v49 && (_DWORD)v28 == v47 )
                              break;
                            if ( ++v25 >= sub_5EA5B0(v24) )
                              goto LABEL_65;
                          }
                          v58 = 0;
LABEL_65:
                          v10 = v52;
                          v21 = v46;
                        }
                        if ( v25 != sub_5EA5B0(v24) )
                          break;
                      }
                      v46 = ++v21;
                    }
                    while ( v21 < v10[136] );
                    if ( !v58 )
                    {
                      v29 = (_DWORD *)(v41 + this[207] + 320);
                      v30 = operator new(0xCu);
                      if ( v30 )
                      {
                        *v30 = v10;
                        v30[1] = 0;
                        *((_BYTE *)v30 + 8) = 0;
                      }
                      else
                      {
                        v30 = 0;
                      }
                      if ( *v29 )
                      {
                        *(_DWORD *)(v29[1] + 4) = v30;
                      }
                      else
                      {
                        *v29 = v30;
                        v29[2] = v30;
                      }
                      v31 = v29[3] + 1;
                      v29[1] = v30;
                      v29[3] = v31;
                      if ( v10[2] == -1 )
                        v10[2] = 0;
                    }
LABEL_77:
                    v32 = ++v47 <= v48;
                    v41 += 292;
                  }
                  while ( v32 );
LABEL_78:
                  v32 = ++v49 <= v51;
                  v50 += 1168;
                  if ( !v32 )
                  {
                    v3 = (int)this;
                    break;
                  }
                }
              }
LABEL_80:
              v33 = *(_DWORD *)(v3 + 460);
              if ( v33 )
              {
                v34 = *(_DWORD **)(v33 + 4);
                *(_DWORD *)(v3 + 460) = v34;
                if ( v34 )
                {
                  v10 = (_DWORD *)*v34;
                  v52 = (_DWORD *)*v34;
                  if ( *v34 )
                    continue;
                }
              }
              return (_DWORD *)sub_6093A0();
            }
          }
        }
        return (_DWORD *)sub_6093A0();
      }
      else
      {
        v35 = *(_BYTE ***)(v3 + 452);
        *(_DWORD *)(v3 + 460) = v35;
        if ( v35 )
        {
          for ( i = *v35; i; i = *v38 )
          {
            if ( (*i & 4) == 0 )
              sub_5FDFB0((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 828) + 48) + 268), (int)i, 0);
            v37 = *(_DWORD *)(v3 + 460);
            if ( !v37 )
              break;
            v38 = *(_BYTE ***)(v37 + 4);
            *(_DWORD *)(v3 + 460) = v38;
            if ( !v38 )
              break;
          }
        }
        return sub_609300(*(_DWORD **)(v3 + 828), *(_DWORD **)(*(_DWORD *)(v3 + 828) + 48));
      }
    }
  }
  return result;
}
