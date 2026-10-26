int __thiscall sub_57D120(int this, double *a2, double *a3)
{
  int result; // eax
  int v4; // eax
  double v5; // st7
  int v6; // eax
  int v7; // edx
  double v8; // st7
  double v9; // st6
  char v10; // bl
  double v11; // st5
  double v12; // st4
  double v13; // st3
  double *v14; // eax
  double v15; // st5
  double *v16; // eax
  double *v17; // eax
  bool v18; // cc
  int v19; // [esp+10h] [ebp-88h]
  int v20; // [esp+14h] [ebp-84h]
  double v21; // [esp+20h] [ebp-78h]
  double v22; // [esp+20h] [ebp-78h]
  double v23; // [esp+28h] [ebp-70h]
  double v24; // [esp+28h] [ebp-70h]
  double v25; // [esp+30h] [ebp-68h]
  double v26; // [esp+60h] [ebp-38h]

  result = 0;
  v20 = 0;
  if ( *(int *)(this + 556) > 0 )
  {
    v19 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 560);
      v5 = *(double *)(v4 + v19 + 40);
      v6 = v19 + v4;
      v7 = *(_DWORD *)(v6 + 48);
      v8 = v5 * *(double *)(this + 132) - *(double *)(v6 + 32) * *(double *)(this + 140);
      v9 = *(double *)(v6 + 24) * *(double *)(this + 140) - *(double *)(v6 + 40) * *(double *)(this + 124);
      v26 = *(double *)(v6 + 32) * *(double *)(this + 124) - *(double *)(v6 + 24) * *(double *)(this + 132);
      v21 = *(double *)(v6 + 40) * a2[1]
          - *(double *)(v6 + 32) * a2[2]
          + *a3
          + v26 * *(double *)(this + 132)
          - v9 * *(double *)(this + 140);
      v23 = *(double *)(v6 + 24) * a2[2]
          - *(double *)(v6 + 40) * *a2
          + a3[1]
          + v8 * *(double *)(this + 140)
          - v26 * *(double *)(this + 124);
      v10 = *(_BYTE *)(v6 + 52);
      v25 = *(double *)(v6 + 32) * *a2
          - *(double *)(v6 + 24) * a2[1]
          + v9 * *(double *)(this + 124)
          - v8 * *(double *)(this + 132)
          + a3[2];
      v11 = *(double *)(this + 4) + *(double *)(v6 + 24);
      v12 = *(double *)(v6 + 32) + *(double *)(this + 12);
      v13 = *(double *)(this + 20) + *(double *)(v6 + 40);
      v14 = (double *)(*(_DWORD *)(this + 548) + 8 * v7);
      v22 = dbl_61B430 * v11 + (v8 + *(double *)(this + 100)) * dbl_61B438 + v21;
      v24 = dbl_61B430 * v12 + (v9 + *(double *)(this + 108)) * dbl_61B438 + v23;
      v15 = dbl_61B430 * v13 + (v26 + *(double *)(this + 116)) * dbl_61B438 + v25;
      if ( v10 )
      {
        *v14 = *v14 - v22;
        *(double *)(*(_DWORD *)(this + 548) + 8 * v7 + 8) = *(double *)(*(_DWORD *)(this + 548) + 8 * v7 + 8) - v24;
        *(double *)(*(_DWORD *)(this + 548) + 8 * v7 + 16) = *(double *)(*(_DWORD *)(this + 548) + 8 * v7 + 16) - v15;
      }
      else
      {
        *v14 = v22 + *v14;
        v16 = (double *)(*(_DWORD *)(this + 548) + 8 * v7 + 8);
        *v16 = v24 + *v16;
        v17 = (double *)(*(_DWORD *)(this + 548) + 8 * v7 + 16);
        *v17 = v15 + *v17;
      }
      result = v20 + 1;
      v18 = ++v20 < *(_DWORD *)(this + 556);
      v19 += 56;
    }
    while ( v18 );
  }
  return result;
}
