unsigned int *__fastcall sub_5FF0E0(int a1, int a2, _DWORD *a3)
{
  float v3; // ebx
  unsigned int *result; // eax
  _DWORD *v5; // edi
  unsigned int *v6; // ebp
  unsigned int v7; // esi
  _DWORD *v8; // ecx
  int v9; // eax
  int v10; // ebx
  float *v11; // esi
  int v12; // edx
  float *v13; // ecx
  int v14; // eax
  bool v15; // cc
  float *v16; // ebx
  float *v17; // esi
  int v18; // edx
  float *v19; // ecx
  signed int v20; // eax
  float *v21; // eax
  int v22; // ebp
  int v23; // eax
  int v24; // edx
  int v25; // edi
  int v26; // esi
  int v27; // ebp
  int v28; // ecx
  int v29; // esi
  int v30; // eax
  int v31; // edi
  int v32; // esi
  int v33; // eax
  int v34; // edi
  float *v35; // ebp
  _DWORD *v36; // ebp
  char v37; // [esp+0h] [ebp-4Ah]
  bool v38; // [esp+1h] [ebp-49h]
  _DWORD *v39; // [esp+2h] [ebp-48h]
  float *v40; // [esp+2h] [ebp-48h]
  unsigned __int16 *v41; // [esp+6h] [ebp-44h]
  unsigned int *v42; // [esp+Ah] [ebp-40h]
  int v43; // [esp+Ah] [ebp-40h]
  _DWORD *v44; // [esp+Eh] [ebp-3Ch]
  signed int v45; // [esp+12h] [ebp-38h]
  int v46; // [esp+16h] [ebp-34h]
  float v48; // [esp+1Eh] [ebp-2Ch]
  float v49; // [esp+22h] [ebp-28h]
  float v50; // [esp+26h] [ebp-24h] BYREF
  float v51; // [esp+2Ah] [ebp-20h] BYREF
  float v52; // [esp+2Eh] [ebp-1Ch] BYREF
  float v53[6]; // [esp+32h] [ebp-18h] BYREF

  v3 = *(float *)&a3;
  result = (unsigned int *)*a3;
  v5 = (_DWORD *)a1;
  if ( (*a3 & 4) == 0 )
  {
    sub_5E4D90(*(void **)(a1 + 272), (int)&v50, (int)&v51, (int)&v52);
    result = (unsigned int *)a3[133];
    a3[135] = result;
    if ( result )
    {
      v6 = (unsigned int *)*result;
      v42 = (unsigned int *)*result;
      if ( *result )
      {
        while ( 1 )
        {
          v7 = *v6;
          if ( (*v6 & v5[66]) != 0 && sub_5FE610(v5, (int)v6) == 1 )
            break;
LABEL_58:
          result = *(unsigned int **)(LODWORD(v3) + 540);
          if ( !result )
            return result;
          result = (unsigned int *)result[1];
          *(_DWORD *)(LODWORD(v3) + 540) = result;
          if ( !result )
            return result;
          result = (unsigned int *)*result;
          v42 = result;
          if ( !result )
            return result;
          v6 = result;
        }
        v46 = v7 & 0xF;
        if ( v37 )
          sub_5EC2A0(v6, 0);
        sub_5EC450((int *)v6, v5[68]);
        if ( (*(_BYTE *)v6 & 3) == 0 )
          goto LABEL_57;
        if ( (*v5 & 0x100) == 0 )
        {
          v40 = (float *)(v6[98] + 180);
          v38 = sub_5D82B0(v40) == 0;
          v45 = 0;
          v41 = (unsigned __int16 *)v6[93];
          if ( (int)v6[92] > 0 )
          {
            v16 = (float *)(v6[93] + 20);
            do
            {
              if ( (**((_DWORD **)v16 - 3) & 0x40000) == 0 )
              {
                v17 = v16;
                if ( v37 )
                {
                  sub_5D7810(v16, v53, v40 + 1);
                  v17 = v53;
                }
                v18 = 0;
                v19 = (float *)(v5[68] + 252);
                do
                {
                  if ( *(v19 - 1) * *v17 + v19[1] * v17[2] + v17[1] * *v19 + v19[2] > v16[3] )
                    break;
                  ++v18;
                  v19 += 4;
                }
                while ( v18 < 6 );
                if ( v18 == 6 )
                {
                  v20 = *((_DWORD *)v16 - 2);
                  v21 = v20 >= (int)v6[94] ? 0 : (float *)(v6[95] + 16 * v20);
                  v50 = *v17 - *(float *)&a1;
                  v51 = v17[1] - v48;
                  v52 = v17[2] - v49;
                  if ( sub_5D7920(&v50, v21) >= 0.0 )
                  {
                    v22 = v5[38];
                    if ( v22 > v5[39] - 3 )
                    {
                      v5[40] += 3;
                    }
                    else
                    {
                      v23 = *((_DWORD *)v16 - 3);
                      v24 = v5[42];
                      v25 = *((unsigned __int16 *)v16 - 8);
                      v26 = *((unsigned __int16 *)v16 - 9);
                      v27 = v24 + 32 * v22;
                      v28 = *(_DWORD *)(v23 + 32);
                      if ( (*(_BYTE *)v23 & 8) != 0 )
                      {
                        v29 = 88 * v26;
                        v30 = 88 * *v41;
                        v31 = 88 * v25;
                      }
                      else
                      {
                        v30 = *v41 << 6;
                        v29 = v26 << 6;
                        v31 = v25 << 6;
                      }
                      v32 = v28 + v29;
                      v33 = v28 + v30;
                      v34 = v28 + v31;
                      if ( v38 )
                      {
                        sub_5D7810((float *)v33, (float *)v27, v40 + 1);
                        v35 = (float *)(v27 + 32);
                        sub_5D7810((float *)v32, v35, v40 + 1);
                        sub_5D7810((float *)v34, v35 + 8, v40 + 1);
                      }
                      else
                      {
                        *(_DWORD *)v27 = *(_DWORD *)v33;
                        *(_DWORD *)(v27 + 4) = *(_DWORD *)(v33 + 4);
                        *(_DWORD *)(v27 + 8) = *(_DWORD *)(v33 + 8);
                        *(_DWORD *)(v27 + 32) = *(_DWORD *)v32;
                        *(_DWORD *)(v27 + 36) = *(_DWORD *)(v32 + 4);
                        *(_DWORD *)(v27 + 40) = *(_DWORD *)(v32 + 8);
                        v36 = (_DWORD *)(v27 + 64);
                        *v36 = *(_DWORD *)v34;
                        v36[1] = *(_DWORD *)(v34 + 4);
                        v36[2] = *(_DWORD *)(v34 + 8);
                      }
                      v44[38] += 3;
                      v5 = v44;
                    }
                    v6 = v42;
                  }
                }
              }
              v41 += 18;
              v16 += 9;
              ++v45;
            }
            while ( v45 < (int)v6[92] );
          }
          goto LABEL_57;
        }
        v8 = (_DWORD *)v6[91];
        v43 = 0;
        v39 = v8;
        if ( (int)v6[90] <= 0 )
          goto LABEL_57;
LABEL_13:
        if ( (*v8 & 0x40000) != 0 )
          goto LABEL_31;
        if ( v37 )
        {
          v9 = v5[43];
          if ( v9 < v5[44] )
          {
            *(_DWORD *)(v5[46] + 4 * v9) = v8;
            ++v5[43];
            *v8 |= 0x40000000u;
            goto LABEL_31;
          }
          goto LABEL_30;
        }
        v10 = 0;
        if ( (int)v6[92] <= 0 )
          goto LABEL_31;
        v11 = (float *)(v6[93] + 24);
        while ( 1 )
        {
          if ( *((_DWORD **)v11 - 4) == v8 )
          {
            v12 = 0;
            v13 = (float *)(v5[68] + 252);
            do
            {
              if ( *(v13 - 1) * *(v11 - 1) + v13[1] * v11[1] + *v13 * *v11 + v13[2] > v11[2] )
                break;
              ++v12;
              v13 += 4;
            }
            while ( v12 < 6 );
            if ( v12 == 6 )
            {
              v14 = v5[43];
              if ( v14 < v5[44] )
              {
                *(_DWORD *)(v5[46] + 4 * v14) = v39;
                ++v5[43];
                v8 = v39;
                goto LABEL_31;
              }
              v8 = v39;
LABEL_30:
              ++v5[45];
LABEL_31:
              v8 += 27;
              v15 = v43 + 1 < (int)v6[90];
              v39 = v8;
              ++v43;
              if ( !v15 )
              {
LABEL_57:
                v3 = v53[4];
                *v6 = v46 | *v6 & 0xFFFFFFF0;
                goto LABEL_58;
              }
              goto LABEL_13;
            }
            v8 = v39;
          }
          v11 += 9;
          if ( ++v10 >= (int)v6[92] )
            goto LABEL_31;
        }
      }
    }
  }
  return result;
}
