int __thiscall sub_548230(_DWORD *this)
{
  double v2; // st7
  int result; // eax
  int v4; // ebp
  int v5; // ecx
  int *v6; // esi
  double v7; // st7
  _DWORD *v8; // ebx
  double v9; // st7
  double v10; // st6
  double v11; // st7
  int v12; // edx
  float v13; // eax
  float i; // [esp+8h] [ebp-60h]
  float v15; // [esp+Ch] [ebp-5Ch]
  float v16; // [esp+10h] [ebp-58h]
  float v17; // [esp+14h] [ebp-54h]
  float v18; // [esp+18h] [ebp-50h]
  float v19; // [esp+1Ch] [ebp-4Ch]

  if ( dword_BE1204 == 2 )
    v2 = sub_5210A0(&dword_BE120C);
  else
    v2 = dbl_FB1D18;
  result = this[27];
  v4 = 0;
  for ( i = v2; v4 < result; ++v4 )
  {
    v5 = this[28];
    v6 = *(int **)(v5 + 4 * v4);
    if ( i > (double)*((float *)v6 + 3) || i < (double)*((float *)v6 + 2) )
    {
      v12 = this[27] - 1;
      this[27] = v12;
      *(_DWORD *)(v5 + 4 * v6[1]) = *(_DWORD *)(v5 + 4 * v12);
      *(_DWORD *)(*(_DWORD *)(this[28] + 4 * v6[1]) + 4) = v6[1];
      v13 = *(float *)v6;
      v6[1] = -1;
      sub_5FCB20(LODWORD(v13));
      --v4;
    }
    else
    {
      if ( dword_BE1204 == 2 )
      {
        if ( sub_5210D0(&dword_BE120C) == 5 )
          v7 = 0.0;
        else
          v7 = sub_5210C0(&dword_BE120C);
      }
      else
      {
        v7 = dbl_FB1D10;
      }
      v8 = v6 + 11;
      *((float *)v6 + 11) = v7 * *((float *)v6 + 14) + *((float *)v6 + 11);
      *((float *)v6 + 12) = v7 * *((float *)v6 + 15) + *((float *)v6 + 12);
      *((float *)v6 + 13) = v7 * *((float *)v6 + 16) + *((float *)v6 + 13);
      *((float *)v6 + 15) = *((float *)v6 + 15) - fabs(v7) * 9.8100004;
      v15 = 1.0 - 3.5 * v7;
      v9 = 1.0 - v7 * 0.75;
      v10 = *((float *)v6 + 13) * *((float *)v6 + 23)
          + *((float *)v6 + 12) * *((float *)v6 + 22)
          + *((float *)v6 + 11) * *((float *)v6 + 21);
      if ( v10 >= *((float *)v6 + 25) )
      {
        *((float *)v6 + 14) = v9 * *((float *)v6 + 14);
        *((float *)v6 + 16) = v9 * *((float *)v6 + 16);
      }
      else
      {
        v16 = v10;
        v11 = *((float *)v6 + 25) - v16;
        v17 = v11 * *((float *)v6 + 21);
        v18 = v11 * *((float *)v6 + 22);
        v19 = v11 * *((float *)v6 + 23);
        *(float *)v8 = v17 + *(float *)v8;
        *((float *)v6 + 12) = v18 + *((float *)v6 + 12);
        *((float *)v6 + 13) = v19 + *((float *)v6 + 13);
        *((float *)v6 + 14) = v15 * *((float *)v6 + 14);
        *((float *)v6 + 16) = v15 * *((float *)v6 + 16);
        if ( *((float *)v6 + 15) >= -1.5 )
          v6[15] = 0;
        else
          *((float *)v6 + 15) = *((float *)v6 + 15) * -0.40000001;
      }
      if ( dword_91E07C
        && fabs(*((float *)dword_91E07C + 698) - *(float *)v8) < 4.0
        && fabs(*((float *)dword_91E07C + 700) - *((float *)v6 + 13)) < 4.0 )
      {
        sub_544170();
      }
      sub_5FCCB0(*v6, *v8, v6[12], v6[13]);
    }
    result = this[27];
  }
  return result;
}
