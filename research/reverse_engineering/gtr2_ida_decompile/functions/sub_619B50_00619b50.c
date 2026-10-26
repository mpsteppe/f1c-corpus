int __thiscall sub_619B50(int this, double *a2, double *a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // eax
  double v6; // st7
  int v7; // eax
  int v8; // edx
  double v9; // st7
  double v10; // st6
  bool v11; // zf
  double v12; // st5
  double v13; // st4
  double v14; // st3
  double *v15; // eax
  double v16; // st5
  double *v17; // eax
  double *v18; // eax
  int v19; // [esp+Ch] [ebp-7Ch]
  double v20; // [esp+10h] [ebp-78h]
  double v21; // [esp+10h] [ebp-78h]
  double v22; // [esp+18h] [ebp-70h]
  double v23; // [esp+18h] [ebp-70h]
  double v24; // [esp+20h] [ebp-68h]
  double v25; // [esp+50h] [ebp-38h]

  result = *(_DWORD *)(this + 560);
  v4 = 0;
  v19 = 0;
  if ( result > 0 )
  {
    do
    {
      v5 = *(_DWORD *)(this + 564);
      v6 = *(double *)(v5 + v4 + 40);
      v7 = v4 + v5;
      v8 = *(_DWORD *)(v7 + 48);
      v9 = v6 * *(double *)(this + 136) - *(double *)(v7 + 32) * *(double *)(this + 144);
      v10 = *(double *)(v7 + 24) * *(double *)(this + 144) - *(double *)(v7 + 40) * *(double *)(this + 128);
      v25 = *(double *)(v7 + 32) * *(double *)(this + 128) - *(double *)(v7 + 24) * *(double *)(this + 136);
      v20 = *(double *)(v7 + 40) * a2[1]
          - *(double *)(v7 + 32) * a2[2]
          + *a3
          + v25 * *(double *)(this + 136)
          - v10 * *(double *)(this + 144);
      v22 = a2[2] * *(double *)(v7 + 24)
          - *(double *)(v7 + 40) * *a2
          + a3[1]
          + v9 * *(double *)(this + 144)
          - v25 * *(double *)(this + 128);
      v24 = *(double *)(v7 + 32) * *a2
          - *(double *)(v7 + 24) * a2[1]
          + v10 * *(double *)(this + 128)
          - v9 * *(double *)(this + 136)
          + a3[2];
      v11 = *(_BYTE *)(v7 + 52) == 0;
      v12 = *(double *)(this + 8) + *(double *)(v7 + 24);
      v13 = *(double *)(v7 + 32) + *(double *)(this + 16);
      v14 = *(double *)(this + 24) + *(double *)(v7 + 40);
      v15 = (double *)(*(_DWORD *)(this + 552) + 8 * v8);
      v21 = v12 * dbl_911668 + (v9 + *(double *)(this + 104)) * dbl_911670 + v20;
      v23 = v13 * dbl_911668 + (v10 + *(double *)(this + 112)) * dbl_911670 + v22;
      v16 = v14 * dbl_911668 + (v25 + *(double *)(this + 120)) * dbl_911670 + v24;
      if ( v11 )
      {
        *v15 = v21 + *v15;
        v17 = (double *)(*(_DWORD *)(this + 552) + 8 * v8 + 8);
        *v17 = v23 + *v17;
        v18 = (double *)(*(_DWORD *)(this + 552) + 8 * v8 + 16);
        *v18 = v16 + *v18;
      }
      else
      {
        *v15 = *v15 - v21;
        *(double *)(*(_DWORD *)(this + 552) + 8 * v8 + 8) = *(double *)(*(_DWORD *)(this + 552) + 8 * v8 + 8) - v23;
        *(double *)(*(_DWORD *)(this + 552) + 8 * v8 + 16) = *(double *)(*(_DWORD *)(this + 552) + 8 * v8 + 16) - v16;
      }
      result = v19 + 1;
      v4 += 56;
      ++v19;
    }
    while ( v19 < *(_DWORD *)(this + 560) );
  }
  return result;
}
