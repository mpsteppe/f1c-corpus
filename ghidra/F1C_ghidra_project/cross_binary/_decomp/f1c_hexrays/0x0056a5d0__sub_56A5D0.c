// f1c  0x0056a5d0  size=617
int __thiscall sub_56A5D0(int this, double *a2)
{
  int result; // eax
  int v4; // esi
  double v5; // st7
  int v6; // esi
  int v7; // ebx
  char v8; // al
  double *v9; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st5
  double *v13; // ebx
  double v14; // st7
  int v15; // [esp+10h] [ebp-88h]
  int v16; // [esp+14h] [ebp-84h]
  double v17; // [esp+18h] [ebp-80h]
  int v18; // [esp+24h] [ebp-74h]
  double v19; // [esp+28h] [ebp-70h]
  double v20; // [esp+30h] [ebp-68h]
  double v21; // [esp+38h] [ebp-60h]
  double v22; // [esp+40h] [ebp-58h] BYREF
  double v23; // [esp+48h] [ebp-50h]
  double v24; // [esp+50h] [ebp-48h]
  double v25; // [esp+58h] [ebp-40h]
  double v26; // [esp+60h] [ebp-38h]
  double v27[3]; // [esp+68h] [ebp-30h] BYREF
  double v28[3]; // [esp+80h] [ebp-18h] BYREF

  v19 = dbl_5E5240 * *(double *)(this + 124) + *a2;
  v20 = dbl_5E5240 * *(double *)(this + 132) + a2[1];
  result = 0;
  v21 = dbl_5E5240 * *(double *)(this + 140) + a2[2];
  v16 = 0;
  if ( *(int *)(this + 564) > 0 )
  {
    v15 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 568);
      v5 = *(double *)(v4 + v15 + 112);
      v6 = v15 + v4;
      v7 = *(_DWORD *)(v6 + 124);
      v18 = *(_DWORD *)(v6 + 120);
      v8 = *(_BYTE *)(v6 + 128);
      v17 = (*(double *)(v6 + 104) * *(double *)(v6 + 72) - *(double *)(v6 + 96) * *(double *)(v6 + 80))
          * *(double *)(this + 140)
          + (*(double *)(v6 + 96) * *(double *)(v6 + 88) - *(double *)(v6 + 112) * *(double *)(v6 + 72))
          * *(double *)(this + 132)
          + (v5 * *(double *)(v6 + 80) - *(double *)(v6 + 104) * *(double *)(v6 + 88)) * *(double *)(this + 124);
      v26 = *(double *)(this + 140) * *(double *)(v6 + 88)
          + *(double *)(this + 132) * *(double *)(v6 + 80)
          + *(double *)(v6 + 72) * *(double *)(this + 124);
      v25 = *(double *)(v6 + 112) * *(double *)(this + 140)
          + *(double *)(v6 + 104) * *(double *)(this + 132)
          + *(double *)(v6 + 96) * *(double *)(this + 124);
      if ( v8 )
      {
        sub_435E00((double *)(this + 28), (double *)v6, v27);
        sub_435E00((double *)(*(_DWORD *)(v18 + 12) + 28), *(double **)(v18 + 16), v28);
        sub_56C540(&v22);
        v9 = (double *)(*(_DWORD *)(this + 548) + 8 * v7);
        v22 = v22 * dbl_5E5238;
        v23 = v23 * dbl_5E5238;
        v24 = v24 * dbl_5E5238;
        v10 = v22 + v19;
        v11 = v23 + v20;
        v12 = v24 + v21;
        *v9 = *v9
            - ((v22 + v19) * *(double *)(v6 + 72)
             + (v24 + v21) * *(double *)(v6 + 88)
             + (v23 + v20) * *(double *)(v6 + 80)
             - v25 * v17);
        v13 = (double *)(*(_DWORD *)(this + 548) + 8 * v7 + 8);
        v14 = *v13
            - (v12 * *(double *)(v6 + 112)
             + v11 * *(double *)(v6 + 104)
             + v10 * *(double *)(v6 + 96)
             + v26 * v17);
      }
      else
      {
        *(double *)(*(_DWORD *)(this + 548) + 8 * v7) = v19 * *(double *)(v6 + 72)
                                                      + v21 * *(double *)(v6 + 88)
                                                      + v20 * *(double *)(v6 + 80)
                                                      - v25 * v17
                                                      + *(double *)(*(_DWORD *)(this + 548) + 8 * v7);
        v13 = (double *)(*(_DWORD *)(this + 548) + 8 * v7 + 8);
        v14 = v21 * *(double *)(v6 + 112) + v20 * *(double *)(v6 + 104) + v19 * *(double *)(v6 + 96) + v26 * v17 + *v13;
      }
      *v13 = v14;
      result = v16 + 1;
      v16 = result;
      v15 += 132;
    }
    while ( result < *(_DWORD *)(this + 564) );
  }
  return result;
}
