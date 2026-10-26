void __thiscall sub_445010(int this)
{
  int *v2; // esi
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  double v6; // st7
  int v7; // edi
  int v8; // eax
  double v9; // st7
  double *v10; // eax
  double v11; // st7
  double *v12; // eax
  double v13; // st7
  double *v14; // eax
  double *v15; // eax
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19[3]; // [esp+10h] [ebp-18h] BYREF

  v2 = (int *)(this + 6096);
  sub_581920(this + 6096);
  sub_445700(this);
  sub_445FE0(this);
  sub_446620(this);
  if ( *(double *)(this + 428) == 0.0 )
    sub_444D80(this);
  v3 = 0;
  if ( *v2 > 0 )
  {
    v4 = 0;
    do
    {
      v5 = *(_DWORD *)(this + 6100);
      v6 = *(double *)(v5 + v4 + 172);
      v7 = *(_DWORD *)(v5 + v4 + 308);
      v8 = v4 + v5;
      *(_DWORD *)(v8 + 308) = v7;
      *(_DWORD *)(v8 + 312) = *(_DWORD *)(v8 + 312);
      v9 = v6 * -9.81 + *(double *)(v8 + 316);
      *(_DWORD *)(v8 + 324) = *(_DWORD *)(v8 + 324);
      *(_DWORD *)(v8 + 328) = *(_DWORD *)(v8 + 328);
      *(double *)(v8 + 316) = v9;
      ++v3;
      v4 += 580;
    }
    while ( v3 < *v2 );
  }
  sub_444E60(this);
  sub_4380C0((_DWORD *)(this + 508), *(_DWORD *)(this + 6164), *(_DWORD *)(this + 128), *(_DWORD *)(this + 132));
  v10 = *(double **)(this + 6164);
  v11 = *(double *)((char *)v10 + 308);
  v10 = (double *)((char *)v10 + 308);
  *v10 = v11 + *(double *)(this + 252);
  v10[1] = *(double *)(this + 260) + v10[1];
  v10[2] = *(double *)(this + 268) + v10[2];
  v12 = *(double **)(this + 6164);
  v13 = *(double *)((char *)v12 + 332);
  v12 = (double *)((char *)v12 + 332);
  *v12 = v13 + *(double *)(this + 276);
  v12[1] = *(double *)(this + 284) + v12[1];
  v12[2] = *(double *)(this + 292) + v12[2];
  v14 = (double *)(*(_DWORD *)(this + 6164) + 308);
  *v14 = *(double *)(this + 8624) + *v14;
  v14[1] = *(double *)(this + 8632) + v14[1];
  v14[2] = *(double *)(this + 8640) + v14[2];
  v15 = *(double **)(this + 6164);
  v16 = *(double *)((char *)v15 + 332);
  v15 = (double *)((char *)v15 + 332);
  *v15 = v16 + *(double *)(this + 8648);
  v15[1] = *(double *)(this + 8656) + v15[1];
  v15[2] = *(double *)(this + 8664) + v15[2];
  v17 = *(float *)(*(_DWORD *)(this + 8620) + 20832);
  if ( v17 != 0.0 )
  {
    v18 = v17 * *(double *)(this + 8) * -64.0;
    qmemcpy(v19, (const void *)(*(_DWORD *)(this + 6164) + 100), sizeof(v19));
    v19[0] = v19[0] * v18;
    v19[1] = v19[1] * v18;
    v19[2] = v19[2] * v18;
    sub_57C860(this + 6176, v19);
  }
}
