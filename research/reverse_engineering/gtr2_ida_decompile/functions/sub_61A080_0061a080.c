int __thiscall sub_61A080(int this, double *a2, double *a3)
{
  int result; // eax
  int v4; // eax
  double v5; // st7
  int v6; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double *v10; // edi
  bool v11; // cc
  int v12; // [esp+10h] [ebp-80h]
  int v13; // [esp+14h] [ebp-7Ch]
  double v14; // [esp+40h] [ebp-50h]

  result = 0;
  v13 = 0;
  if ( *(int *)(this + 576) > 0 )
  {
    v12 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 580);
      v5 = *(double *)(this + 136) * *(double *)(v4 + v12 + 40);
      v6 = v12 + v4;
      v7 = v5 - *(double *)(this + 144) * *(double *)(v6 + 32);
      v8 = *(double *)(this + 144) * *(double *)(v6 + 24) - *(double *)(this + 128) * *(double *)(v6 + 40);
      v14 = *(double *)(this + 128) * *(double *)(v6 + 32) - *(double *)(this + 136) * *(double *)(v6 + 24);
      v9 = ((*(double *)(this + 24) + *(double *)(v6 + 40)) * dbl_911668
          + a3[2]
          + *a2 * *(double *)(v6 + 32)
          - *(double *)(v6 + 24) * a2[1]
          + v8 * *(double *)(this + 128)
          - v7 * *(double *)(this + 136)
          + (v14 + *(double *)(this + 120)) * dbl_911670)
         * *(double *)(v6 + 80)
         + (dbl_911668 * (*(double *)(this + 16) + *(double *)(v6 + 32))
          + a3[1]
          + *(double *)(v6 + 24) * a2[2]
          - *a2 * *(double *)(v6 + 40)
          + v7 * *(double *)(this + 144)
          - v14 * *(double *)(this + 128)
          + (v8 + *(double *)(this + 112)) * dbl_911670)
         * *(double *)(v6 + 72)
         + (dbl_911668 * (*(double *)(v6 + 24) + *(double *)(this + 8))
          + *a3
          + a2[1] * *(double *)(v6 + 40)
          - *(double *)(v6 + 32) * a2[2]
          + v14 * *(double *)(this + 136)
          - v8 * *(double *)(this + 144)
          + (v7 + *(double *)(this + 104)) * dbl_911670)
         * *(double *)(v6 + 64);
      if ( *(_BYTE *)(v6 + 52) )
      {
        v10 = (double *)(*(_DWORD *)(this + 552) + 8 * *(_DWORD *)(v6 + 48));
        *v10 = *v10 - (v9 - dbl_911668 * *(double *)(v6 + 56));
      }
      else
      {
        *(double *)(*(_DWORD *)(this + 552) + 8 * *(_DWORD *)(v6 + 48)) = v9
                                                                        + *(double *)(*(_DWORD *)(this + 552)
                                                                                    + 8 * *(_DWORD *)(v6 + 48));
      }
      result = v13 + 1;
      v11 = ++v13 < *(_DWORD *)(this + 576);
      v12 += 88;
    }
    while ( v11 );
  }
  return result;
}
