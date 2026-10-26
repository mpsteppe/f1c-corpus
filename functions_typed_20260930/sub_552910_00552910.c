int __thiscall sub_552910(int this, unsigned __int8 a2, int a3, int a4, _DWORD *a5)
{
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  double v11; // st7
  int v12; // eax
  double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st3
  double v17; // st3
  float *v18; // edi
  float *v19; // ebp
  float *v20; // edi
  float *v21; // ebp
  float *v22; // edi
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+1Ch] [ebp+4h]
  float v25; // [esp+1Ch] [ebp+4h]
  float v26; // [esp+20h] [ebp+8h]
  float v27; // [esp+24h] [ebp+Ch]
  float v28; // [esp+28h] [ebp+10h]

  if ( a2 < 0x20u )
    return 0;
  v6 = a2;
  if ( a2 >= *(int *)(this + 68) )
    return 0;
  v7 = *(__int16 *)(this + 8 * a2 - 152);
  v8 = *(_DWORD *)(this + 52) - 1;
  v9 = *(_DWORD *)(this + 56) - 1;
  v23 = v8;
  if ( (*(_DWORD *)(this + 36) & 0x10000) != 0 )
  {
    ClippedRenderRegion(
      *(_DWORD **)(this + 100),
      v7,
      *(__int16 *)(this + 8 * a2 - 150) + 1,
      a5,
      a3,
      a4,
      v8,
      v9 - 1,
      *(_DWORD *)(this + 44),
      0);
  }
  else
  {
    v24 = a3 + v8;
    v11 = (double)a3 * *(float *)(this + 92);
    v12 = *(_DWORD *)(this + 100);
    v13 = (double)a4 * *(float *)(this + 96);
    v14 = (double)v24 * *(float *)(this + 92);
    v15 = (double)(a4 + v9) * *(float *)(this + 96);
    v16 = (double)*(int *)(v12 + 28);
    v25 = (double)v7 / v16;
    v28 = (float)*(int *)(v12 + 32);
    v26 = (double)*(__int16 *)(this + 8 * v6 - 150) / v28;
    v27 = (double)v23 / v16 + v25;
    v17 = (double)v9 / v28 + v26;
    **(float **)(this + 16) = v11;
    *(float *)(*(_DWORD *)(this + 16) + 4) = v13;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 16) = *(_DWORD *)(this + 72);
    *(float *)(*(_DWORD *)(this + 16) + 20) = v25;
    *(float *)(*(_DWORD *)(this + 16) + 24) = v26;
    v18 = (float *)(*(_DWORD *)(this + 16) + 28);
    *(_DWORD *)(this + 16) = v18;
    *v18 = v11;
    *(float *)(*(_DWORD *)(this + 16) + 4) = v15;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 16) = *(_DWORD *)(this + 72);
    *(float *)(*(_DWORD *)(this + 16) + 20) = v25;
    *(float *)(*(_DWORD *)(this + 16) + 24) = v17;
    v19 = (float *)(*(_DWORD *)(this + 16) + 28);
    *(_DWORD *)(this + 16) = v19;
    *v19 = v14;
    *(float *)(*(_DWORD *)(this + 16) + 4) = v15;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 16) = *(_DWORD *)(this + 72);
    *(float *)(*(_DWORD *)(this + 16) + 20) = v27;
    *(float *)(*(_DWORD *)(this + 16) + 24) = v17;
    v20 = (float *)(*(_DWORD *)(this + 16) + 28);
    *(_DWORD *)(this + 16) = v20;
    *v20 = v14;
    *(float *)(*(_DWORD *)(this + 16) + 4) = v15;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 16) = *(_DWORD *)(this + 72);
    *(float *)(*(_DWORD *)(this + 16) + 20) = v27;
    *(float *)(*(_DWORD *)(this + 16) + 24) = v17;
    v21 = (float *)(*(_DWORD *)(this + 16) + 28);
    *(_DWORD *)(this + 16) = v21;
    *v21 = v14;
    *(float *)(*(_DWORD *)(this + 16) + 4) = v13;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 16) = *(_DWORD *)(this + 72);
    *(float *)(*(_DWORD *)(this + 16) + 20) = v27;
    *(float *)(*(_DWORD *)(this + 16) + 24) = v26;
    v22 = (float *)(*(_DWORD *)(this + 16) + 28);
    *(_DWORD *)(this + 16) = v22;
    *v22 = v11;
    *(float *)(*(_DWORD *)(this + 16) + 4) = v13;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 8) = 0;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 12) = 1065353216;
    *(_DWORD *)(*(_DWORD *)(this + 16) + 16) = *(_DWORD *)(this + 72);
    *(float *)(*(_DWORD *)(this + 16) + 20) = v25;
    *(float *)(*(_DWORD *)(this + 16) + 24) = v26;
    *(_DWORD *)(this + 16) += 28;
    *(_DWORD *)(this + 8) += 6;
  }
  return *(unsigned __int8 *)(this + 8 * v6 - 148);
}

