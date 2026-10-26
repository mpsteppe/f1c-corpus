void __thiscall sub_573C60(void *this, float *a2, float *a3)
{
  int v4; // eax
  double *v5; // eax
  long double v6; // st7
  int v8; // ecx
  double v9; // st7
  double v10; // st6
  long double v11; // st6
  long double v12; // st6
  float v13; // [esp+4h] [ebp-54h]
  float v14; // [esp+8h] [ebp-50h] BYREF
  float v15; // [esp+Ch] [ebp-4Ch]
  float v16; // [esp+10h] [ebp-48h]
  float v17[3]; // [esp+14h] [ebp-44h] BYREF
  double v18[6]; // [esp+20h] [ebp-38h] BYREF
  int v19; // [esp+50h] [ebp-8h]
  float v20; // [esp+5Ch] [ebp+4h]
  float v21; // [esp+5Ch] [ebp+4h]

  v4 = *((_DWORD *)this + 59);
  v18[0] = *(float *)this;
  v18[1] = *((float *)this + 1);
  v18[2] = *((float *)this + 2);
  v19 = v4;
  v18[3] = 1.200000047683716;
  v18[4] = 9.999999933815813e36;
  v5 = sub_45D210(dbl_B68610, v18, &v14);
  *((_DWORD *)this + 59) = v5;
  if ( v5 )
  {
    v6 = (*((float *)this + 1)
        - ((sin(*((float *)this + 2) * *(float *)(*((_DWORD *)v5 + 21) + 24))
          + sin(*(float *)(*((_DWORD *)v5 + 21) + 24) * *(float *)this))
         * *(float *)(*((_DWORD *)v5 + 21) + 20)
         + v18[5])
        - *((float *)this + 58))
       * v15;
  }
  else
  {
    v6 = 9.9999999e36;
    v14 = 0.0;
    v15 = 1.0;
    v16 = 0.0;
  }
  *((float *)this + 14) = v16 * a2[6] + v15 * a2[3] + v14 * *a2;
  *((float *)this + 15) = v16 * a2[7] + v14 * a2[1] + v15 * a2[4];
  *((float *)this + 16) = v16 * a2[8] + v14 * a2[2] + v15 * a2[5];
  v20 = *((float *)this + 36) - v6;
  *((float *)this + 29) = v20;
  if ( v20 >= 0.0 )
  {
    v13 = *((float *)this + 8) * *((float *)this + 16)
        + *((float *)this + 7) * *((float *)this + 15)
        + *((float *)this + 6) * *((float *)this + 14);
    if ( *((float *)this + 15) <= 0.98500001 )
    {
      v11 = fabs(v13);
      if ( v11 > *((float *)this + 31) )
      {
        v12 = (*((float *)this + 31) + *((float *)this + 31)) / (v11 + *((float *)this + 31));
        v13 = v13 * v12;
        *((float *)this + 29) = v20 * v12;
      }
      *((float *)this + 13) = *((float *)this + 30) * *((float *)this + 15) * *((float *)this + 29);
      v17[0] = *(float *)this - v14 * v6;
      v17[1] = *((float *)this + 1) - v15 * v6;
      v17[2] = *((float *)this + 2) - v16 * v6;
      sub_4F09D0(a2, a3, v17, (float *)this + 52);
    }
    else
    {
      v8 = *((_DWORD *)this + 3);
      v21 = v20 * *((float *)this + 30);
      *((float *)this + 13) = v21;
      v9 = *((float *)this + 5);
      v10 = v21 + *((float *)this + 24) - *((float *)this + 36);
      *((_DWORD *)this + 52) = v8;
      *((float *)this + 53) = v10;
      *((float *)this + 54) = v9;
    }
    *((float *)this + 17) = *((float *)this + 60) * *((float *)this + 29) - v13 * *((float *)this + 61);
  }
  else
  {
    *((_DWORD *)this + 17) = 0;
    *((_DWORD *)this + 13) = 0;
  }
}
