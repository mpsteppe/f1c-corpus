int __thiscall sub_5A0AD0(_DWORD *this, int a2, int *a3, int a4)
{
  int *v4; // esi
  _DWORD *v5; // ebx
  int result; // eax
  unsigned __int16 *v7; // edi
  int v8; // edx
  char v10; // c0
  int v11; // eax
  float *v12; // ecx
  _BYTE *v13; // eax
  float *v14; // esi
  int v15; // ebx
  double v16; // st7
  float *v17; // ebp
  double v18; // st7
  int v19; // ecx
  double v20; // st7
  float *v21; // eax
  double v22; // st6
  double v23; // st5
  bool v24; // cc
  float v25; // [esp+10h] [ebp-34h]
  _DWORD *v26; // [esp+14h] [ebp-30h]
  int v27; // [esp+18h] [ebp-2Ch]
  int v28; // [esp+1Ch] [ebp-28h]
  int v30; // [esp+24h] [ebp-20h]
  int v31; // [esp+28h] [ebp-1Ch]
  float v32; // [esp+2Ch] [ebp-18h] BYREF
  float v33; // [esp+30h] [ebp-14h]
  float v34; // [esp+34h] [ebp-10h]
  float *v35[3]; // [esp+38h] [ebp-Ch] BYREF

  v4 = a3;
  v5 = this;
  result = 0;
  v31 = a3[75];
  v7 = (unsigned __int16 *)a3[73];
  v28 = 0;
  v30 = 0;
  if ( a3[72] > 0 )
  {
    do
    {
      v8 = v5[120];
      if ( !v10 )
      {
        v11 = *(_DWORD *)(*((_DWORD *)v7 + 2) + 12);
        v35[0] = (float *)(v11 + 48 * *v7);
        v35[1] = (float *)(v11 + 48 * v7[1]);
        v12 = (float *)(v11 + 48 * v7[2]);
        v13 = *(_BYTE **)(v8 + 8);
        v35[2] = v12;
        v26 = v13;
        v27 = 0;
        if ( *(int *)(v8 + 4) > 0 )
        {
          v14 = (float *)(v13 + 24);
          do
          {
            if ( (*v13 & 6) == 0 )
            {
              v15 = v31 + 16 * *((_DWORD *)v7 + 3);
              v16 = ((double (__stdcall *)(int, float *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(v15, v14 - 2);
              v25 = v16;
              if ( v16 > *((float *)v7 + 8) )
              {
                v17 = v14 + 4;
                v18 = ((double (__thiscall *)(int, int, float *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(
                        dword_7E8E58,
                        v15,
                        v14 + 4);
                if ( v18 < *((float *)v7 + 8) )
                {
                  v19 = (__int16)v7[3];
                  v20 = (*((float *)v7 + 8) - v25) / (v18 - v25);
                  v32 = (*v17 - *(v14 - 2)) * v20 + *(v14 - 2);
                  v33 = (v14[5] - *(v14 - 1)) * v20 + *(v14 - 1);
                  v34 = (v14[6] - *v14) * v20 + *v14;
                  if ( sub_5A0320(v19, v35, &v32) )
                  {
                    *v26 = 1;
                    *((_DWORD *)v14 + 9) = a2;
                    *((_DWORD *)v14 + 10) = a3;
                    *((_DWORD *)v14 + 7) = this;
                    v14[8] = 0.0;
                    v14[11] = *(float *)(*((_DWORD *)v7 + 2) + 4);
                    *((_DWORD *)v14 + 12) = v27;
                    v14[19] = v32;
                    v14[20] = v33;
                    v14[21] = v34;
                    *((_DWORD *)v14 + 13) = v7;
                    v14[14] = 0.0;
                    v21 = (float *)(a3[75] + 16 * *((_DWORD *)v7 + 3));
                    v14[16] = *v21;
                    v14[17] = v21[1];
                    v14[18] = v21[2];
                    v22 = v14[5] - v33;
                    v23 = v14[6] - v34;
                    ++v28;
                    v14[22] = sqrt(v23 * v23 + v22 * v22 + (*v17 - v32) * (*v17 - v32));
                    sub_5B19D0(v14 + 7);
                  }
                }
              }
            }
            v5 = this;
            v13 = v26 + 29;
            v14 += 29;
            v24 = v27 + 1 < *(_DWORD *)(this[120] + 4);
            v26 += 29;
            ++v27;
          }
          while ( v24 );
          v4 = a3;
        }
      }
      v7 += 18;
      ++v30;
    }
    while ( v30 < v4[72] );
    return v28;
  }
  return result;
}
