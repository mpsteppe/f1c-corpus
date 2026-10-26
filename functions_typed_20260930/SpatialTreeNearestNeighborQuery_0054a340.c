int __thiscall sub_54A340(_DWORD *this, float *a2)
{
  int v2; // edx
  int v3; // ebp
  int v4; // edi
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c3
  int v9; // edx
  int v10; // ebx
  float *v11; // edi
  double v12; // st6
  double v13; // st5
  double v14; // st3
  double v15; // st7
  int v16; // edx
  float *v17; // esi
  double v18; // st4
  double v19; // st3
  double v20; // st4
  double v21; // st3
  int v22; // edx
  float *v23; // esi
  float v24; // [esp+4h] [ebp-10h]
  float v25; // [esp+8h] [ebp-Ch]
  float v26; // [esp+Ch] [ebp-8h]
  float v27; // [esp+10h] [ebp-4h]
  float v28; // [esp+18h] [ebp+4h]

  v2 = this[105];
  v24 = -a2[9];
  v3 = 0;
  v25 = -a2[10];
  v4 = this[64];
  v28 = -a2[11];
  v26 = 9.9999997e37;
  if ( !v2 )
    goto LABEL_14;
  if ( !(v6 | v7) )
  {
    this[105] = v2;
    return v2;
  }
  v9 = *(_DWORD *)(v2 + 252);
  if ( v9 )
  {
    v10 = v9;
    do
    {
      v11 = *(float **)(v10 + 16);
      v12 = v25 - v11[32];
      v13 = v28 - v11[33];
      v14 = v24 - v11[31];
      v15 = v13 * v13 + v12 * v12 + v14 * v14;
      if ( v15 < v26 )
      {
        v16 = 0;
        v17 = v11 + 35;
        do
        {
          if ( v28 * v17[1] + v24 * *(v17 - 1) + v25 * *v17 + v17[2] < 0.0 )
            break;
          ++v16;
          v17 += 4;
        }
        while ( v16 < 6 );
        if ( v16 == 6 )
        {
          v26 = v15;
          v3 = *(_DWORD *)(v10 + 16);
        }
      }
      v10 = *(_DWORD *)(v10 + 20);
    }
    while ( v10 );
    this[105] = v3;
    return v3;
  }
  else
  {
LABEL_14:
    while ( v4 )
    {
      if ( (*(_BYTE *)(v4 + 4) & 0x40) == 0 )
      {
        v18 = v28 - *(float *)(v4 + 132);
        v19 = v25 - *(float *)(v4 + 128);
        v20 = v18 * v18 + v19 * v19;
        v21 = v24 - *(float *)(v4 + 124);
        v27 = v20 + v21 * v21;
        if ( v27 < *(float *)(v4 + 24) * *(float *)(v4 + 24) && v27 < (double)v26 )
        {
          v22 = 0;
          v23 = (float *)(v4 + 140);
          do
          {
            if ( v28 * v23[1] + v24 * *(v23 - 1) + v25 * *v23 + v23[2] < 0.0 )
              break;
            ++v22;
            v23 += 4;
          }
          while ( v22 < 6 );
          if ( v22 == 6 )
          {
            v26 = v20 + v21 * v21;
            v3 = v4;
          }
        }
      }
      v4 = *(_DWORD *)(v4 + 260);
    }
    this[105] = v3;
    return v3;
  }
}

