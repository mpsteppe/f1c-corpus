void __thiscall sub_561660(int this, int a2)
{
  int v3; // edx
  _DWORD *v4; // ebp
  int v5; // eax
  char v7; // c0
  float *v8; // ebx
  char v10; // c0
  float *v11; // edi
  int *v12; // eax
  int j; // edi
  int v14; // eax
  double v15; // st7
  int v16; // [esp+Ch] [ebp-34h]
  int v17; // [esp+10h] [ebp-30h]
  _DWORD *i; // [esp+14h] [ebp-2Ch]
  int v19; // [esp+18h] [ebp-28h]
  float v20; // [esp+1Ch] [ebp-24h]
  float v21; // [esp+20h] [ebp-20h]
  float v22; // [esp+24h] [ebp-1Ch]
  float v23; // [esp+28h] [ebp-18h]
  float v24; // [esp+2Ch] [ebp-14h]
  float v25; // [esp+30h] [ebp-10h]
  float v26[3]; // [esp+34h] [ebp-Ch] BYREF
  int v27; // [esp+44h] [ebp+4h]

  v3 = *(_DWORD *)(this + 24) + 232;
  v4 = *(_DWORD **)(a2 + 516);
  v16 = v3;
  for ( i = v4; v4; i = v4 )
  {
    if ( (v4[5] & 0x4000) != 0 )
    {
      v5 = *(_DWORD *)(this + 12);
      v20 = *(float *)(v5 + 12);
      v21 = *(float *)(v5 + 20);
      v22 = 1.0 / (double)*(int *)(v5 + 84);
      v25 = 1.0 / (double)*(int *)(v5 + 88);
      v23 = -*(float *)(v5 + 16);
      v24 = *(float *)(v5 + 24);
      if ( !v7 )
      {
        v27 = v4[73];
        v17 = 0;
        if ( (int)v4[72] > 0 )
        {
          v8 = (float *)(v4[73] + 20);
          do
          {
            if ( !v10 )
            {
              v11 = (float *)(v4[75] + 16 * *((_DWORD *)v8 - 2));
              v19 = *((_DWORD *)v8 - 3);
              if ( ((double (__thiscall *)(int, int, float *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(
                     dword_8B8F24,
                     v3,
                     v11) > v8[3]
                && (v8[1] - *(float *)(*(_DWORD *)(this + 12) + 44)) * v11[2]
                 + (*v8 - *(float *)(*(_DWORD *)(this + 12) + 40)) * v11[1]
                 + (*(v8 - 1) - *(float *)(*(_DWORD *)(this + 12) + 36)) * *v11 > 0.0
                && *(int *)(this + 4) < 2045 )
              {
                v12 = *(int **)(this + 32);
                if ( *v12 < 1023 )
                {
                  *(_DWORD *)(v12[1] + 4 * *v12) = v27;
                  ++**(_DWORD **)(this + 32);
                  for ( j = 0; j < 3; ++j )
                  {
                    v14 = *(_DWORD *)(v19 + 12) + 48 * *(unsigned __int16 *)(v27 + 2 * j);
                    **(float **)(this + 8) = *(float *)(v14 + 12) * 0.050000001 + *(float *)v14;
                    *(float *)(*(_DWORD *)(this + 8) + 4) = *(float *)(v14 + 16) * 0.050000001 + *(float *)(v14 + 4);
                    *(float *)(*(_DWORD *)(this + 8) + 8) = *(float *)(v14 + 20) * 0.050000001 + *(float *)(v14 + 8);
                    *(_DWORD *)(*(_DWORD *)(this + 8) + 12) = *(_DWORD *)(v14 + 24);
                    (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
                      dword_8B8F24,
                      v14,
                      v26,
                      *(_DWORD *)(this + 12) + 348);
                    v15 = 1.0 / v26[2];
                    *(float *)(*(_DWORD *)(this + 8) + 16) = (v26[0] * v15 * v20 + v21) * v22;
                    *(float *)(*(_DWORD *)(this + 8) + 20) = (v26[1] * v15 * v23 + v24) * v25;
                    *(_DWORD *)(this + 8) += 24;
                  }
                  v4 = i;
                  *(_DWORD *)(this + 4) += 3;
                }
              }
              v3 = v16;
            }
            v8 += 9;
            v27 += 36;
            ++v17;
          }
          while ( v17 < v4[72] );
        }
      }
    }
    v4 = (_DWORD *)v4[4];
  }
}
