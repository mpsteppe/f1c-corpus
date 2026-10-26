int __thiscall sub_57D5D0(int this, double *a2, double *a3)
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
  int v12; // [esp+10h] [ebp-88h]
  int v13; // [esp+14h] [ebp-84h]
  double v14; // [esp+78h] [ebp-20h]

  result = 0;
  v13 = 0;
  if ( *(int *)(this + 572) > 0 )
  {
    v12 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 576);
      v5 = *(double *)(this + 132) * *(double *)(v4 + v12 + 40);
      v6 = v12 + v4;
      v7 = v5 - *(double *)(this + 140) * *(double *)(v6 + 32);
      v8 = *(double *)(this + 140) * *(double *)(v6 + 24) - *(double *)(this + 124) * *(double *)(v6 + 40);
      v14 = *(double *)(this + 124) * *(double *)(v6 + 32) - *(double *)(this + 132) * *(double *)(v6 + 24);
      v9 = (dbl_61B430 * (*(double *)(this + 20) + *(double *)(v6 + 40))
          + *a2 * *(double *)(v6 + 32)
          - *(double *)(v6 + 24) * a2[1]
          + v8 * *(double *)(this + 124)
          - v7 * *(double *)(this + 132)
          + (v14 + *(double *)(this + 116)) * dbl_61B438
          + a3[2])
         * *(double *)(v6 + 80)
         + (dbl_61B430 * (*(double *)(this + 12) + *(double *)(v6 + 32))
          + a3[1]
          + *(double *)(v6 + 24) * a2[2]
          - *a2 * *(double *)(v6 + 40)
          + v7 * *(double *)(this + 140)
          - v14 * *(double *)(this + 124)
          + (v8 + *(double *)(this + 108)) * dbl_61B438)
         * *(double *)(v6 + 72)
         + (dbl_61B430 * (*(double *)(v6 + 24) + *(double *)(this + 4))
          + *a3
          + a2[1] * *(double *)(v6 + 40)
          - a2[2] * *(double *)(v6 + 32)
          + v14 * *(double *)(this + 132)
          - v8 * *(double *)(this + 140)
          + (v7 + *(double *)(this + 100)) * dbl_61B438)
         * *(double *)(v6 + 64);
      if ( *(_BYTE *)(v6 + 52) )
      {
        v10 = (double *)(*(_DWORD *)(this + 548) + 8 * *(_DWORD *)(v6 + 48));
        *v10 = *v10 - (v9 - dbl_61B430 * *(double *)(v6 + 56));
      }
      else
      {
        *(double *)(*(_DWORD *)(this + 548) + 8 * *(_DWORD *)(v6 + 48)) = v9
                                                                        + *(double *)(*(_DWORD *)(this + 548)
                                                                                    + 8 * *(_DWORD *)(v6 + 48));
      }
      result = v13 + 1;
      v11 = ++v13 < *(_DWORD *)(this + 572);
      v12 += 88;
    }
    while ( v11 );
  }
  return result;
}
