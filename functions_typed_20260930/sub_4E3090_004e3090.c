char __thiscall sub_4E3090(_DWORD *this, int a2)
{
  int v2; // eax
  double v3; // st7
  long double v4; // st7
  long double v5; // st6
  long double v6; // st6
  long double v7; // st6
  int v8; // esi
  int v9; // edi
  int v10; // eax
  double v11; // st5
  int v12; // eax
  double v13; // st5
  float v15; // [esp+0h] [ebp-3Ch]
  float v16; // [esp+4h] [ebp-38h]
  float v17; // [esp+4h] [ebp-38h]
  float v18; // [esp+Ch] [ebp-30h]
  float v19; // [esp+Ch] [ebp-30h]
  float v20; // [esp+10h] [ebp-2Ch]
  float v21; // [esp+10h] [ebp-2Ch]
  float v22; // [esp+14h] [ebp-28h]
  float v23; // [esp+14h] [ebp-28h]
  float v24; // [esp+18h] [ebp-24h]
  float v25; // [esp+1Ch] [ebp-20h]
  float v26; // [esp+24h] [ebp-18h]
  float v27; // [esp+28h] [ebp-14h]
  float v28; // [esp+2Ch] [ebp-10h]
  float v29; // [esp+30h] [ebp-Ch]
  float v30; // [esp+38h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 112);
  if ( v2 )
  {
    LOBYTE(v2) = *(_BYTE *)(a2 + 176);
    if ( (_BYTE)v2 )
    {
      v2 = this[569];
      if ( v2 )
      {
        v3 = *(float *)(a2 + 212);
        v26 = *(float *)(a2 + 116);
        v28 = *(float *)(a2 + 292);
        v16 = *(float *)(a2 + 224);
        v27 = *(float *)(a2 + 120);
        if ( v3 == 0.0 && v16 == 0.0 )
        {
          v15 = 0.0;
          v4 = 0.0;
          v17 = 1.0;
        }
        else
        {
          v5 = 1.0 / sqrt(v16 * v16 + v3 * v3);
          v15 = v5 * v3;
          v17 = v16 * v5;
          v4 = v5 * 0.0;
        }
        v18 = v17 - 0.0 * v4;
        v20 = 0.0 * v4 - v15;
        v22 = v15 * 0.0 - v17 * 0.0;
        if ( v18 == 0.0 && v20 == 0.0 && v22 == 0.0 )
        {
          v6 = 0.0;
          v24 = 1.0;
          v25 = 0.0;
        }
        else
        {
          v7 = 1.0 / sqrt(v22 * v22 + v20 * v20 + v18 * v18);
          v24 = v18 * v7;
          v25 = v20 * v7;
          v6 = v7 * v22;
        }
        v8 = 0;
        if ( *(int *)(a2 + 284) > 0 )
        {
          v9 = 0;
          do
          {
            v10 = *(_DWORD *)(a2 + 288);
            v11 = v24 * *(float *)(v10 + v9 + 12);
            v12 = v9 + v10;
            ++v8;
            v9 += 32;
            v23 = v17 * v24 - v25 * v15;
            v30 = v6 * *(float *)(v12 + 12) + v4 * *(float *)(v12 + 16) + v23 * *(float *)(v12 + 20);
            v19 = v25 * v4 - v6 * v17;
            v29 = v26 + v11 + v15 * *(float *)(v12 + 16) + v19 * *(float *)(v12 + 20);
            v21 = v15 * v6 - v24 * v4;
            v13 = v27 + v25 * *(float *)(v12 + 12) + v17 * *(float *)(v12 + 16) + v21 * *(float *)(v12 + 20);
            **(float **)(v12 + 28) = (v29 - *(float *)v12) * *(float *)(v12 + 24) + *(float *)v12;
            *(float *)(*(_DWORD *)(v12 + 28) + 4) = (v13 - *(float *)(v12 + 4)) * *(float *)(v12 + 24)
                                                  + *(float *)(v12 + 4);
            *(float *)(*(_DWORD *)(v12 + 28) + 8) = (v30 + v28 - *(float *)(v12 + 8)) * *(float *)(v12 + 24)
                                                  + *(float *)(v12 + 8);
          }
          while ( v8 < *(_DWORD *)(a2 + 284) );
        }
        v2 = this[569];
        *(_DWORD *)(v2 + 20) &= 0xFEFFFFDF;
      }
    }
  }
  return v2;
}

