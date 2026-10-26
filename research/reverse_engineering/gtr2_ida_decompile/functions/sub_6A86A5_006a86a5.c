int __thiscall sub_6A86A5(_DWORD *this, int a2, unsigned int a3, int a4)
{
  int v4; // eax
  int *v5; // ebx
  int *v6; // eax
  _DWORD *v7; // ecx
  int v8; // esi
  int v9; // edx
  unsigned int v10; // eax
  unsigned int v12; // esi
  _DWORD *v13; // eax
  int v14; // edi
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  int v17; // ecx
  int v18; // edx
  _DWORD *v19; // eax
  int *v20; // edi
  int v21; // eax
  int v22; // esi
  int v23; // eax
  int v24; // [esp+14h] [ebp-30h]
  unsigned int v25; // [esp+18h] [ebp-2Ch]
  unsigned int v26; // [esp+1Ch] [ebp-28h]
  int v27; // [esp+20h] [ebp-24h]
  int v28; // [esp+20h] [ebp-24h]
  int v29; // [esp+20h] [ebp-24h]
  unsigned int v30; // [esp+24h] [ebp-20h]
  unsigned int v31; // [esp+28h] [ebp-1Ch]
  int *v32; // [esp+28h] [ebp-1Ch]
  unsigned int v33; // [esp+2Ch] [ebp-18h]
  unsigned int v34; // [esp+30h] [ebp-14h]
  unsigned int v35; // [esp+34h] [ebp-10h]
  int v36; // [esp+34h] [ebp-10h]
  int v37; // [esp+38h] [ebp-Ch]
  int v38; // [esp+3Ch] [ebp-8h]
  int v40; // [esp+4Ch] [ebp+8h]
  char *v41; // [esp+50h] [ebp+Ch]

  v4 = 0;
  v5 = 0;
  v35 = 0;
  if ( a3 )
  {
    while ( 1 )
    {
      v6 = *(int **)(a2 + 4 * v4);
      if ( v6 )
      {
        if ( (*v6 & 0xFFF00000) != 0 && (*v6 & 0xFFFFF) != 0 )
        {
          v31 = v6[3];
          if ( v31 )
          {
            v7 = (_DWORD *)v6[4];
            v8 = this[5];
            v9 = *(_DWORD *)(v8 + 4 * *v7);
            if ( *(_DWORD *)(v9 + 12) == a4 && *(_DWORD *)(v9 + 4) == this[34] )
            {
              v5 = v6;
              v34 = v35;
              v10 = 0;
              if ( v31 )
                break;
            }
          }
        }
      }
LABEL_11:
      v4 = ++v35;
      if ( v35 >= a3 )
      {
        if ( !v5 )
          goto LABEL_13;
        v12 = *v5 & 0xFFFFF;
        v26 = v12;
        if ( (*v5 & 0xFFF00000) == 0x50000000 )
        {
          v13 = (_DWORD *)sub_681186(116);
          if ( v13 )
            v41 = (char *)sub_680CEC(v13);
          else
            v41 = 0;
          if ( v41 )
          {
            v14 = sub_6811D1(v41, *v5, v5[1], v5[3] + 1, 0);
            if ( v14 >= 0 )
            {
              v32 = (int *)(a2 + 4 * v34);
              v14 = sub_680D22(v41, *v32);
              if ( v14 >= 0 )
              {
                v40 = sub_681AAA(this, this[34], a4, 2, 0.0);
                if ( v40 == -1 )
                  goto LABEL_23;
                qmemcpy(*((void **)v41 + 2), (const void *)v5[2], 4 * *((_DWORD *)v41 + 1));
                qmemcpy(*((void **)v41 + 4), (const void *)v5[4], 4 * v5[3]);
                *(_DWORD *)(*((_DWORD *)v41 + 4) + 4 * v5[3]) = v40;
                sub_681430((char *)*v32, v41);
LABEL_49:
                sub_66238F(v41, 1);
                v41 = 0;
                v14 = 0;
              }
            }
            goto LABEL_50;
          }
          return -2147024882;
        }
        else
        {
          v15 = (_DWORD *)sub_681186(116);
          if ( v15 )
            v41 = (char *)sub_680CEC(v15);
          else
            v41 = 0;
          if ( !v41 )
            return -2147024882;
          v25 = v5[1] / v12;
          v14 = sub_6811D1(v41, *v5 ^ (*v5 ^ (v12 + 1)) & 0xFFFFF, v25 + v5[1], v5[3] + 1, 0);
          if ( v14 >= 0 )
          {
            v14 = sub_680D22(v41, *(_DWORD *)(a2 + 4 * v34));
            if ( v14 >= 0 )
            {
              v33 = 0;
              if ( !v25 )
              {
LABEL_48:
                sub_681430(*(char **)(a2 + 4 * v34), v41);
                goto LABEL_49;
              }
              v37 = 0;
              v38 = 0;
              v24 = 4 * v12 + 4;
              v36 = 4 * v12;
              while ( 1 )
              {
                v27 = 1;
                if ( v12 > 1 )
                {
                  v16 = (_DWORD *)(v38 + v5[2]);
                  v17 = this[5];
                  v18 = *(_DWORD *)(*(_DWORD *)(v17 + 4 * *v16) + 16);
                  v19 = v16 + 1;
                  v30 = v12 - 1;
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(v17 + 4 * *v19) + 16) != v18 )
                      v27 = 0;
                    ++v19;
                    --v30;
                  }
                  while ( v30 );
                }
                qmemcpy((void *)(v37 + *((_DWORD *)v41 + 2)), (const void *)(v38 + v5[2]), 4 * v12);
                v20 = this;
                v21 = *((_DWORD *)v41 + 2);
                if ( v27 )
                {
                  *(_DWORD *)(v36 + v21) = *(_DWORD *)(v38 + v5[2]);
                }
                else
                {
                  v22 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v37 + v21));
                  v28 = *(_DWORD *)(v22 + 12);
                  v23 = sub_681AAA(this, *(_DWORD *)(v22 + 4), v28, 2, 0.0);
                  if ( v23 == -1 )
                    break;
                  *(_DWORD *)(v36 + *((_DWORD *)v41 + 2)) = v23;
                  if ( *(_DWORD *)(v22 + 4) == this[34] )
                  {
                    v14 = sub_6A86A5(a2, v34, v28);
                    if ( v14 < 0 )
                      goto LABEL_50;
                    v20 = this;
                  }
                }
                v29 = sub_681AAA(v20, v20[34], a4, 2, 0.0);
                if ( v29 == -1 )
                  break;
                qmemcpy(*((void **)v41 + 4), (const void *)v5[4], 4 * v5[3]);
                ++v33;
                *(_DWORD *)(*((_DWORD *)v41 + 4) + 4 * v5[3]) = v29;
                v38 += 4 * v26;
                v37 += v24;
                v36 += v24;
                if ( v33 >= v25 )
                  goto LABEL_48;
                v12 = v26;
              }
LABEL_23:
              v14 = -2147024882;
            }
          }
LABEL_50:
          if ( v41 )
            sub_66238F(v41, 1);
        }
        return v14;
      }
    }
    while ( *(_DWORD *)(*(_DWORD *)(v8 + 4 * *v7) + 16) != 2 )
    {
      ++v10;
      ++v7;
      if ( v10 >= v31 )
        goto LABEL_11;
    }
    return 0;
  }
  else
  {
LABEL_13:
    sub_686791((int)this, 0, 4823, "internal error: uppropagation failed");
    return -2147467259;
  }
}
