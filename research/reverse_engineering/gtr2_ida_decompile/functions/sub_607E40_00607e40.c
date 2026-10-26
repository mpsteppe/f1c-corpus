float *__thiscall sub_607E40(_DWORD *this, int a2, int a3)
{
  int v3; // edx
  int *v4; // eax
  int v5; // ebx
  int *v6; // eax
  int v7; // eax
  int v8; // edx
  float *v9; // esi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // eax
  int *v17; // eax
  int v18; // eax
  int *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  float *result; // eax
  double v27; // st6
  double v28; // st5
  double v29; // st3

  *(_DWORD *)(this[12] + 32) = 1399379109;
  *(_DWORD *)(this[12] + 28) = 1399379109;
  *(_DWORD *)(this[12] + 24) = 1399379109;
  *(_DWORD *)(this[12] + 44) = -748104539;
  *(_DWORD *)(this[12] + 40) = -748104539;
  *(_DWORD *)(this[12] + 36) = -748104539;
  v3 = a2;
  v4 = *(int **)(a2 + 452);
  *(_DWORD *)(a2 + 460) = v4;
  if ( v4 )
  {
    v5 = *v4;
    if ( *v4 )
    {
      do
      {
        v6 = *(int **)(v5 + 532);
        *(_DWORD *)(v5 + 540) = v6;
        if ( v6 )
        {
          v7 = *v6;
          if ( v7 )
          {
            do
            {
              v8 = 0;
              v9 = (float *)(v7 + 120);
              do
              {
                v10 = this[12];
                if ( *(v8 >= 8 ? 0 : v9) < (double)*(float *)(v10 + 24) )
                  *(float *)(v10 + 24) = *(v8 >= 8 ? 0 : v9);
                v11 = this[12];
                if ( *(v8 >= 8 ? (float *)4 : v9 + 1) < (double)*(float *)(v11 + 28) )
                  *(_DWORD *)(v11 + 28) = *(v8 >= 8 ? (_DWORD *)4 : (_DWORD *)(v9 + 1));
                v12 = this[12];
                if ( *(v8 >= 8 ? (float *)8 : v9 + 2) < (double)*(float *)(v12 + 32) )
                  *(_DWORD *)(v12 + 32) = *(v8 >= 8 ? (_DWORD *)8 : (_DWORD *)(v9 + 2));
                v13 = this[12];
                if ( *(v8 >= 8 ? 0 : v9) > (double)*(float *)(v13 + 36) )
                  *(float *)(v13 + 36) = *(v8 >= 8 ? 0 : v9);
                v14 = this[12];
                if ( *(v8 >= 8 ? (float *)4 : v9 + 1) > (double)*(float *)(v14 + 40) )
                  *(_DWORD *)(v14 + 40) = *(v8 >= 8 ? (_DWORD *)4 : (_DWORD *)(v9 + 1));
                v15 = this[12];
                if ( *(v8 >= 8 ? (float *)8 : v9 + 2) > (double)*(float *)(v15 + 44) )
                  *(_DWORD *)(v15 + 44) = *(v8 >= 8 ? (_DWORD *)8 : (_DWORD *)(v9 + 2));
                ++v8;
                v9 += 3;
              }
              while ( v8 < 8 );
              v16 = *(_DWORD *)(v5 + 540);
              if ( !v16 )
                break;
              v17 = *(int **)(v16 + 4);
              *(_DWORD *)(v5 + 540) = v17;
              if ( !v17 )
                break;
              v7 = *v17;
            }
            while ( v7 );
            v3 = a2;
          }
        }
        v18 = *(_DWORD *)(v3 + 460);
        if ( !v18 )
          break;
        v19 = *(int **)(v18 + 4);
        *(_DWORD *)(v3 + 460) = v19;
        if ( !v19 )
          break;
        v5 = *v19;
      }
      while ( *v19 );
    }
  }
  *(float *)(this[12] + 48) = (*(float *)(this[12] + 36) + *(float *)(this[12] + 24)) * 0.5;
  *(float *)(this[12] + 52) = (*(float *)(this[12] + 40) + *(float *)(this[12] + 28)) * 0.5;
  *(float *)(this[12] + 56) = (*(float *)(this[12] + 44) + *(float *)(this[12] + 32)) * 0.5;
  v20 = this[12];
  *(_DWORD *)(v20 + 60) = 1065353216;
  *(_DWORD *)(v20 + 64) = 0;
  *(_DWORD *)(v20 + 68) = 0;
  *(float *)(v20 + 72) = -*(float *)(this[12] + 36);
  v21 = this[12];
  *(_DWORD *)(v21 + 80) = 0;
  *(_DWORD *)(v21 + 84) = 0;
  v21 += 76;
  *(_DWORD *)v21 = -1082130432;
  *(float *)(v21 + 12) = -(*(float *)(this[12] + 24) * -1.0);
  v22 = this[12];
  *(_DWORD *)(v22 + 92) = 0;
  *(_DWORD *)(v22 + 96) = 0;
  *(_DWORD *)(v22 + 100) = 1065353216;
  *(float *)(v22 + 104) = -*(float *)(this[12] + 44);
  v23 = this[12];
  *(_DWORD *)(v23 + 108) = 0;
  *(_DWORD *)(v23 + 112) = 0;
  *(_DWORD *)(v23 + 116) = -1082130432;
  *(float *)(v23 + 120) = -(*(float *)(this[12] + 32) * -1.0);
  v24 = this[12];
  *(_DWORD *)(v24 + 124) = 0;
  *(_DWORD *)(v24 + 128) = 1065353216;
  *(_DWORD *)(v24 + 132) = 0;
  *(float *)(v24 + 136) = -*(float *)(this[12] + 40);
  v25 = this[12] + 140;
  *(_DWORD *)v25 = 0;
  *(_DWORD *)(v25 + 4) = -1082130432;
  *(_DWORD *)(v25 + 8) = 0;
  *(float *)(v25 + 12) = -(*(float *)(this[12] + 28) * -1.0);
  *(_DWORD *)(this[12] + 156) = *(_DWORD *)(this[12] + 36);
  *(_DWORD *)(this[12] + 160) = *(_DWORD *)(this[12] + 28);
  *(_DWORD *)(this[12] + 164) = *(_DWORD *)(this[12] + 32);
  *(_DWORD *)(this[12] + 168) = *(_DWORD *)(this[12] + 36);
  *(_DWORD *)(this[12] + 172) = *(_DWORD *)(this[12] + 28);
  *(_DWORD *)(this[12] + 176) = *(_DWORD *)(this[12] + 44);
  *(_DWORD *)(this[12] + 180) = *(_DWORD *)(this[12] + 24);
  *(_DWORD *)(this[12] + 184) = *(_DWORD *)(this[12] + 28);
  *(_DWORD *)(this[12] + 188) = *(_DWORD *)(this[12] + 44);
  *(_DWORD *)(this[12] + 192) = *(_DWORD *)(this[12] + 24);
  *(_DWORD *)(this[12] + 196) = *(_DWORD *)(this[12] + 28);
  *(_DWORD *)(this[12] + 200) = *(_DWORD *)(this[12] + 32);
  *(_DWORD *)(this[12] + 204) = *(_DWORD *)(this[12] + 36);
  *(_DWORD *)(this[12] + 208) = *(_DWORD *)(this[12] + 40);
  *(_DWORD *)(this[12] + 212) = *(_DWORD *)(this[12] + 32);
  *(_DWORD *)(this[12] + 216) = *(_DWORD *)(this[12] + 36);
  *(_DWORD *)(this[12] + 220) = *(_DWORD *)(this[12] + 40);
  *(_DWORD *)(this[12] + 224) = *(_DWORD *)(this[12] + 44);
  *(_DWORD *)(this[12] + 228) = *(_DWORD *)(this[12] + 24);
  *(_DWORD *)(this[12] + 232) = *(_DWORD *)(this[12] + 40);
  *(_DWORD *)(this[12] + 236) = *(_DWORD *)(this[12] + 44);
  *(_DWORD *)(this[12] + 240) = *(_DWORD *)(this[12] + 24);
  *(_DWORD *)(this[12] + 244) = *(_DWORD *)(this[12] + 40);
  *(_DWORD *)(this[12] + 248) = *(_DWORD *)(this[12] + 32);
  result = (float *)this[12];
  v27 = result[10] - result[13];
  v28 = result[9] - result[12];
  v29 = result[11] - result[14];
  result[5] = sqrt(v28 * v28 + v27 * v27 + v29 * v29);
  return result;
}
