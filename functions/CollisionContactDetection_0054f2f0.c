int __thiscall sub_54F2F0(_DWORD *this, int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  _DWORD *v6; // eax
  int v7; // edx
  bool v8; // cc
  unsigned __int16 *v9; // edi
  int v10; // edx
  char v12; // c0
  int v13; // eax
  float *v14; // ecx
  _DWORD *v15; // eax
  float *v16; // esi
  int v17; // ebx
  double v18; // st7
  float *v19; // ebp
  double v20; // st7
  int v21; // ecx
  double v22; // st7
  float *v23; // eax
  double v24; // st6
  double v25; // st5
  _DWORD *v27; // [esp+10h] [ebp-40h]
  int v28; // [esp+14h] [ebp-3Ch]
  int v29; // [esp+18h] [ebp-38h]
  float v30; // [esp+1Ch] [ebp-34h]
  int v32; // [esp+24h] [ebp-2Ch]
  int v33; // [esp+28h] [ebp-28h]
  float v34; // [esp+2Ch] [ebp-24h] BYREF
  float v35; // [esp+30h] [ebp-20h]
  float v36; // [esp+34h] [ebp-1Ch]
  int v37; // [esp+38h] [ebp-18h]
  int v38; // [esp+3Ch] [ebp-14h]
  int v39; // [esp+40h] [ebp-10h]
  float *v40[3]; // [esp+44h] [ebp-Ch] BYREF

  v4 = a3;
  v5 = this;
  v33 = a3[75];
  v6 = (_DWORD *)this[129];
  v37 = v6[58];
  v7 = v6[59];
  v39 = v6[60];
  v8 = a3[72] <= 0;
  v9 = (unsigned __int16 *)a3[73];
  v29 = 0;
  v38 = v7;
  v32 = 0;
  if ( v8 )
    return 0;
  do
  {
    v10 = v5[120];
    if ( !v12 )
    {
      v13 = *(_DWORD *)(*((_DWORD *)v9 + 2) + 12);
      v40[0] = (float *)(v13 + 48 * *v9);
      v40[1] = (float *)(v13 + 48 * v9[1]);
      v14 = (float *)(v13 + 48 * v9[2]);
      v15 = *(_DWORD **)(v10 + 8);
      v40[2] = v14;
      v27 = v15;
      v28 = 0;
      if ( *(int *)(v10 + 4) > 0 )
      {
        v16 = (float *)(v15 + 6);
        do
        {
          if ( *v15 != 6 )
          {
            v17 = v33 + 16 * *((_DWORD *)v9 + 3);
            v18 = ((double (__stdcall *)(int, float *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(v17, v16 - 2);
            v30 = v18;
            if ( v18 > *((float *)v9 + 8) )
            {
              v19 = v16 + 4;
              v20 = ((double (__thiscall *)(int, int, float *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(
                      dword_8B8F24,
                      v17,
                      v16 + 4);
              if ( v20 < *((float *)v9 + 8) )
              {
                v21 = (__int16)v9[3];
                v22 = (*((float *)v9 + 8) - v30) / (v20 - v30);
                v34 = (*v19 - *(v16 - 2)) * v22 + *(v16 - 2);
                v35 = (v16[5] - *(v16 - 1)) * v22 + *(v16 - 1);
                v36 = (v16[6] - *v16) * v22 + *v16;
                if ( F_2D3DTrianglePointTest(v21, v40, &v34) )
                {
                  *v27 = 1;
                  *((_DWORD *)v16 + 9) = a2;
                  *((_DWORD *)v16 + 10) = a3;
                  *((_DWORD *)v16 + 7) = this;
                  v16[8] = 0.0;
                  v16[11] = *(float *)(*((_DWORD *)v9 + 2) + 4);
                  *((_DWORD *)v16 + 12) = v28;
                  v16[19] = v34;
                  v16[20] = v35;
                  v16[21] = v36;
                  *((_DWORD *)v16 + 13) = v9;
                  v16[14] = 0.0;
                  v23 = (float *)(a3[75] + 16 * *((_DWORD *)v9 + 3));
                  v16[16] = *v23;
                  v16[17] = v23[1];
                  v16[18] = v23[2];
                  v24 = v16[5] - v35;
                  v25 = v16[6] - v36;
                  ++v29;
                  v16[22] = sqrt(v25 * v25 + v24 * v24 + (*v19 - v34) * (*v19 - v34));
                  SingleFunctionCallWrapper_9a30(v16 + 7);
                }
              }
            }
          }
          v5 = this;
          v15 = v27 + 29;
          v16 += 29;
          v8 = v28 + 1 < *(_DWORD *)(this[120] + 4);
          v27 += 29;
          ++v28;
        }
        while ( v8 );
        v4 = a3;
      }
    }
    v9 += 18;
    ++v32;
  }
  while ( v32 < v4[72] );
  return v29;
}
