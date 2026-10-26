int __thiscall sub_61B360(int this)
{
  int result; // eax
  int v2; // ebp
  int v3; // esi
  int v4; // eax
  double v5; // st7
  int v6; // eax
  int v7; // edi
  unsigned __int8 v8; // bl
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st7
  double *v13; // edx
  int v14; // edx
  int v15; // esi
  double v16; // st7
  int v17; // esi
  int v18; // eax
  double v19; // st7
  int v20; // esi
  int v21; // eax
  double v22; // st6
  double *v23; // eax
  int v24; // eax
  double *v25; // eax
  int v26; // [esp+10h] [ebp-68h]
  int v27; // [esp+14h] [ebp-64h]
  double v28; // [esp+18h] [ebp-60h]
  double v29; // [esp+20h] [ebp-58h]
  double v30; // [esp+28h] [ebp-50h]
  double v31; // [esp+30h] [ebp-48h]
  double v32; // [esp+38h] [ebp-40h]
  double v33; // [esp+40h] [ebp-38h]

  result = *(_DWORD *)(this + 576);
  if ( result > 0 )
  {
    v2 = 1;
    v3 = 0;
    v27 = 1;
    v26 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 580);
      v5 = *(double *)(v4 + v3 + 32);
      v6 = v3 + v4;
      v7 = *(_DWORD *)(v6 + 48);
      v8 = *(_BYTE *)(v6 + 52);
      v9 = v5 * *(double *)(v6 + 80) - *(double *)(v6 + 40) * *(double *)(v6 + 72);
      v10 = *(double *)(v6 + 64) * *(double *)(v6 + 40) - *(double *)(v6 + 24) * *(double *)(v6 + 80);
      v11 = *(double *)(v6 + 24) * *(double *)(v6 + 72) - *(double *)(v6 + 64) * *(double *)(v6 + 32);
      v28 = v11 * *(double *)(this + 256) + v10 * *(double *)(this + 248) + v9 * *(double *)(this + 240);
      v29 = v11 * *(double *)(this + 280) + v9 * *(double *)(this + 264) + v10 * *(double *)(this + 272);
      v30 = v11 * *(double *)(this + 304) + v9 * *(double *)(this + 288) + v10 * *(double *)(this + 296);
      v12 = *(double *)(this + 184);
      v31 = v12 * *(double *)(v6 + 64);
      v32 = v12 * *(double *)(v6 + 72);
      v33 = v12 * *(double *)(v6 + 80);
      v13 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7) + 8 * v7);
      *v13 = (v29 * *(double *)(v6 + 40) - v30 * *(double *)(v6 + 32) + v31) * *(double *)(v6 + 64)
           + (v28 * *(double *)(v6 + 32) - v29 * *(double *)(v6 + 24) + v33) * *(double *)(v6 + 80)
           + (v30 * *(double *)(v6 + 24) - v28 * *(double *)(v6 + 40) + v32) * *(double *)(v6 + 72)
           + *v13;
      if ( v2 < *(_DWORD *)(this + 576) )
      {
        v14 = v3 + 88;
        do
        {
          v15 = *(_DWORD *)(this + 580);
          v16 = v29 * *(double *)(v15 + v14 + 40);
          v17 = v14 + v15;
          v18 = *(_DWORD *)(v17 + 48);
          v19 = (v28 * *(double *)(v17 + 32) - v29 * *(double *)(v17 + 24) + v33) * *(double *)(v17 + 80)
              + (v30 * *(double *)(v17 + 24) - v28 * *(double *)(v17 + 40) + v32) * *(double *)(v17 + 72)
              + (v16 - v30 * *(double *)(v17 + 32) + v31) * *(double *)(v17 + 64);
          if ( v8 != *(_BYTE *)(v17 + 52) )
          {
            if ( v7 <= v18 )
            {
              v24 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * *(_DWORD *)(v17 + 48));
              v22 = *(double *)(v24 + 8 * v7);
              v23 = (double *)(v24 + 8 * v7);
            }
            else
            {
              v20 = *(_DWORD *)(v17 + 48);
              v21 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
              v22 = *(double *)(v21 + 8 * v20);
              v23 = (double *)(v21 + 8 * v20);
            }
            *v23 = v22 - v19;
          }
          else
          {
            if ( v7 <= v18 )
              v25 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * *(_DWORD *)(v17 + 48)) + 8 * v7);
            else
              v25 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7) + 8 * *(_DWORD *)(v17 + 48));
            *v25 = v19 + *v25;
          }
          ++v2;
          v14 += 88;
        }
        while ( v2 < *(_DWORD *)(this + 576) );
        v3 = v26;
        v2 = v27;
      }
      result = *(_DWORD *)(this + 576);
      v3 += 88;
      ++v2;
      v26 = v3;
      v27 = v2;
    }
    while ( v2 - 1 < result );
  }
  return result;
}
