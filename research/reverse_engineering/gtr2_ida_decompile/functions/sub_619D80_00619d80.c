int __thiscall sub_619D80(int this, double *a2)
{
  int result; // eax
  int v4; // esi
  double v5; // st7
  int v6; // esi
  int v7; // ebx
  int v8; // eax
  double *v9; // ecx
  double *v10; // eax
  double v11; // st7
  double *v12; // eax
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double *v16; // ebx
  double v17; // st7
  int v18; // [esp+10h] [ebp-80h]
  int v19; // [esp+14h] [ebp-7Ch]
  double v20; // [esp+18h] [ebp-78h]
  double v21; // [esp+20h] [ebp-70h]
  double v22; // [esp+28h] [ebp-68h]
  double v23; // [esp+30h] [ebp-60h]
  double v24; // [esp+38h] [ebp-58h]
  double v25; // [esp+40h] [ebp-50h]
  double v26; // [esp+48h] [ebp-48h] BYREF
  double v27; // [esp+50h] [ebp-40h]
  double v28; // [esp+58h] [ebp-38h]
  double v29; // [esp+60h] [ebp-30h]
  double v30; // [esp+68h] [ebp-28h]
  double v31; // [esp+70h] [ebp-20h]
  double v32; // [esp+78h] [ebp-18h]
  double v33; // [esp+80h] [ebp-10h]
  double v34; // [esp+88h] [ebp-8h]

  v23 = dbl_911670 * *(double *)(this + 128) + *a2;
  v24 = dbl_911670 * *(double *)(this + 136) + a2[1];
  result = 0;
  v25 = dbl_911670 * *(double *)(this + 144) + a2[2];
  v19 = 0;
  if ( *(int *)(this + 568) > 0 )
  {
    v18 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 572);
      v5 = *(double *)(v4 + v18 + 112);
      v6 = v18 + v4;
      v7 = *(_DWORD *)(v6 + 124);
      v8 = *(_DWORD *)(v6 + 120);
      v20 = (*(double *)(v6 + 104) * *(double *)(v6 + 72) - *(double *)(v6 + 96) * *(double *)(v6 + 80))
          * *(double *)(this + 144)
          + (*(double *)(v6 + 96) * *(double *)(v6 + 88) - *(double *)(v6 + 112) * *(double *)(v6 + 72))
          * *(double *)(this + 136)
          + (v5 * *(double *)(v6 + 80) - *(double *)(v6 + 104) * *(double *)(v6 + 88)) * *(double *)(this + 128);
      v22 = *(double *)(this + 144) * *(double *)(v6 + 88)
          + *(double *)(this + 136) * *(double *)(v6 + 80)
          + *(double *)(v6 + 72) * *(double *)(this + 128);
      v21 = *(double *)(v6 + 112) * *(double *)(this + 144)
          + *(double *)(v6 + 96) * *(double *)(this + 128)
          + *(double *)(this + 136) * *(double *)(v6 + 104);
      if ( *(_BYTE *)(v6 + 128) )
      {
        v29 = *(double *)(this + 48) * *(double *)(v6 + 16)
            + *(double *)(this + 40) * *(double *)(v6 + 8)
            + *(double *)v6 * *(double *)(this + 32);
        v30 = *(double *)(this + 72) * *(double *)(v6 + 16)
            + *(double *)(this + 64) * *(double *)(v6 + 8)
            + *(double *)(this + 56) * *(double *)v6;
        v31 = *(double *)(this + 96) * *(double *)(v6 + 16)
            + *(double *)(this + 88) * *(double *)(v6 + 8)
            + *(double *)(this + 80) * *(double *)v6;
        v9 = *(double **)(v8 + 16);
        v10 = *(double **)(v8 + 12);
        v11 = v10[6];
        v10 += 4;
        v32 = v11 * v9[2] + v10[1] * v9[1] + *v9 * *v10;
        v33 = v10[3] * *v9 + v10[5] * v9[2] + v10[4] * v9[1];
        v34 = v10[6] * *v9 + v10[8] * v9[2] + v10[7] * v9[1];
        sub_61BF60(&v26);
        v12 = (double *)(*(_DWORD *)(this + 552) + 8 * v7);
        v26 = v26 * dbl_911668;
        v27 = v27 * dbl_911668;
        v28 = v28 * dbl_911668;
        v13 = v26 + v23;
        v14 = v27 + v24;
        v15 = v28 + v25;
        *v12 = *v12
             - ((v26 + v23) * *(double *)(v6 + 72)
              + (v28 + v25) * *(double *)(v6 + 88)
              + (v27 + v24) * *(double *)(v6 + 80)
              - v21 * v20);
        v16 = (double *)(*(_DWORD *)(this + 552) + 8 * v7 + 8);
        v17 = *v16
            - (v15 * *(double *)(v6 + 112)
             + v14 * *(double *)(v6 + 104)
             + v13 * *(double *)(v6 + 96)
             + v22 * v20);
      }
      else
      {
        *(double *)(*(_DWORD *)(this + 552) + 8 * v7) = v23 * *(double *)(v6 + 72)
                                                      + v25 * *(double *)(v6 + 88)
                                                      + v24 * *(double *)(v6 + 80)
                                                      - v21 * v20
                                                      + *(double *)(*(_DWORD *)(this + 552) + 8 * v7);
        v16 = (double *)(*(_DWORD *)(this + 552) + 8 * v7 + 8);
        v17 = v25 * *(double *)(v6 + 112) + v24 * *(double *)(v6 + 104) + v23 * *(double *)(v6 + 96) + v22 * v20 + *v16;
      }
      *v16 = v17;
      result = v19 + 1;
      v19 = result;
      v18 += 136;
    }
    while ( result < *(_DWORD *)(this + 568) );
  }
  return result;
}
