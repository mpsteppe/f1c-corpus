int __thiscall sub_50FDB0(int this)
{
  int v2; // eax
  float *v3; // ecx
  double v4; // st7
  long double v5; // st7
  long double v6; // st6
  int v7; // eax
  double *v8; // ecx
  int v9; // edx
  double v10; // st7
  int v11; // eax
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  int result; // eax
  double v19; // st7
  double v20; // [esp+10h] [ebp-20h]
  double v21[3]; // [esp+18h] [ebp-18h] BYREF

  sub_43D900((double *)(dword_760144 + 28), (double *)(dword_760144 + 4), &dbl_760150, v21);
  *(float *)(this + 17520) = v21[0];
  v2 = 0;
  *(float *)(this + 17524) = v21[1];
  v3 = (float *)(this + 17484);
  *(float *)(this + 17528) = v21[2];
  do
  {
    v4 = *(double *)(v2 + dword_760144 + 28);
    v2 += 8;
    *v3++ = v4;
  }
  while ( v2 < 72 );
  *(float *)(this + 17532) = -asin(*(float *)(this + 17504));
  if ( fabs(*(float *)(this + 17504)) == 1.0 )
  {
    v5 = -*(float *)(this + 17508);
    v6 = *(float *)(this + 17484);
    *(_DWORD *)(this + 17540) = 0;
    *(float *)(this + 17536) = atan2(v5, v6);
  }
  else
  {
    *(float *)(this + 17536) = atan2(*(float *)(this + 17492), *(float *)(this + 17516));
    *(float *)(this + 17540) = atan2(*(float *)(this + 17496), *(float *)(this + 17500));
  }
  qmemcpy(v21, (const void *)(dword_760144 + 100), sizeof(v21));
  *(float *)(this + 17544) = v21[0];
  *(float *)(this + 17548) = v21[1];
  *(float *)(this + 17552) = v21[2];
  *(float *)(this + 17556) = *(float *)(this + 17508) * *(float *)(this + 17552)
                           + *(float *)(this + 17496) * *(float *)(this + 17548)
                           + *(float *)(this + 17484) * *(float *)(this + 17544);
  *(float *)(this + 17560) = *(float *)(this + 17512) * *(float *)(this + 17552)
                           + *(float *)(this + 17500) * *(float *)(this + 17548)
                           + *(float *)(this + 17488) * *(float *)(this + 17544);
  *(float *)(this + 17564) = *(float *)(this + 17516) * *(float *)(this + 17552)
                           + *(float *)(this + 17504) * *(float *)(this + 17548)
                           + *(float *)(this + 17492) * *(float *)(this + 17544);
  v21[0] = *(double *)(dword_760144 + 76) * *(double *)(dword_760144 + 140)
         + *(double *)(dword_760144 + 52) * *(double *)(dword_760144 + 132)
         + *(double *)(dword_760144 + 124) * *(double *)(dword_760144 + 28);
  v21[1] = *(double *)(dword_760144 + 36) * *(double *)(dword_760144 + 124)
         + *(double *)(dword_760144 + 84) * *(double *)(dword_760144 + 140)
         + *(double *)(dword_760144 + 60) * *(double *)(dword_760144 + 132);
  v7 = this + 17924;
  v8 = (double *)&unk_75EE68;
  v21[2] = *(double *)(dword_760144 + 44) * *(double *)(dword_760144 + 124)
         + *(double *)(dword_760144 + 92) * *(double *)(dword_760144 + 140)
         + *(double *)(dword_760144 + 68) * *(double *)(dword_760144 + 132);
  v9 = 4;
  v10 = v21[1];
  *(float *)(this + 17568) = v21[0];
  *(float *)(this + 17572) = v10;
  *(float *)(this + 17576) = v21[2];
  do
  {
    v7 += 248;
    *(float *)(v7 - 432) = *(v8 - 60);
    *(_DWORD *)(v7 - 248) = *(_DWORD *)v8;
    *(float *)(v7 - 408) = *(v8 - 45);
    v8 += 157;
    --v9;
    *(float *)(v7 - 404) = *(v8 - 201);
    *(float *)(v7 - 400) = *(v8 - 200);
    *(float *)(v7 - 388) = *(double *)((char *)v8 - 764);
  }
  while ( v9 );
  v11 = *(_DWORD *)(this + 18768);
  if ( !v11 )
  {
    v13 = *(float *)(this + 18484) + *(float *)(this + 18236);
LABEL_14:
    v14 = v13 * 0.5;
    goto LABEL_15;
  }
  v12 = v11 - 1;
  if ( v12 )
  {
    if ( v12 != 1 )
      goto LABEL_16;
    v13 = *(float *)(this + 17988) + *(float *)(this + 17740);
    goto LABEL_14;
  }
  v14 = (*(float *)(this + 18484) + *(float *)(this + 18236) + *(float *)(this + 17988) + *(float *)(this + 17740))
      * 0.25;
LABEL_15:
  *(float *)(this + 18688) = v14;
LABEL_16:
  *(_DWORD *)(this + 18828) = dword_760ACC;
  if ( dbl_760830 >= 0.0 )
  {
    if ( dbl_760830 <= dbl_7608C8 )
      v15 = dbl_760830;
    else
      v15 = dbl_7608C8;
  }
  else
  {
    v15 = 0.0;
  }
  *(float *)(this + 18736) = v15;
  *(float *)(this + 17676) = dbl_75E938;
  *(float *)(this + 17680) = dbl_75E9A8 * dbl_75E930;
  *(float *)(this + 17684) = dbl_75E940;
  if ( dbl_760988 <= 0.0 )
  {
    if ( *(float *)(this + 19724) >= 0.0 )
      *(_DWORD *)(this + 19724) = -1082130432;
    *(float *)(this + 19696) = dbl_7609B8;
    *(float *)(this + 19700) = dbl_7609C0;
    *(float *)(this + 19704) = dbl_7609C8;
  }
  v16 = dbl_75EADC;
  *(float *)(this + 18708) = dbl_75EADC;
  v17 = v16 * 0.72600001 + *(float *)(this + 17580);
  *(float *)(this + 17584) = v17;
  *(float *)(this + 17588) = 1.0 / v17;
  result = dword_760144;
  qmemcpy(v21, (const void *)(dword_760144 + 308), sizeof(v21));
  v20 = *(double *)(dword_760144 + 180);
  v21[2] = v20 * v21[2];
  v19 = v20 * v21[1];
  *(float *)(this + 17616) = v20 * v21[0];
  *(float *)(this + 17620) = v19;
  *(float *)(this + 17624) = v21[2];
  *(float *)(this + 17628) = *(float *)(this + 17508) * *(float *)(this + 17624)
                           + *(float *)(this + 17496) * *(float *)(this + 17620)
                           + *(float *)(this + 17616) * *(float *)(this + 17484);
  *(float *)(this + 17632) = *(float *)(this + 17512) * *(float *)(this + 17624)
                           + *(float *)(this + 17500) * *(float *)(this + 17620)
                           + *(float *)(this + 17488) * *(float *)(this + 17616);
  *(float *)(this + 17636) = *(float *)(this + 17516) * *(float *)(this + 17624)
                           + *(float *)(this + 17504) * *(float *)(this + 17620)
                           + *(float *)(this + 17492) * *(float *)(this + 17616);
  return result;
}
