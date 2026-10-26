int __thiscall sub_4E49B0(int this)
{
  int v2; // eax
  float *v3; // ecx
  double v4; // st7
  double v5; // st7
  long double v6; // st7
  long double v7; // st6
  int v8; // eax
  double *v9; // ecx
  int v10; // edx
  double v11; // st7
  int v12; // eax
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int result; // eax
  double v20; // st7
  double v21; // st6
  double v22; // st7
  double v23; // [esp+10h] [ebp-38h]
  double v24[4]; // [esp+18h] [ebp-30h] BYREF
  double v25; // [esp+38h] [ebp-10h]
  double v26; // [esp+40h] [ebp-8h]

  TransformApply3D((double *)(dword_7C8A18 + 28), (double *)(dword_7C8A18 + 4), &dbl_7C8A24, v24);
  *(float *)(this + 13524) = v24[0];
  v2 = 0;
  *(float *)(this + 13528) = v24[1];
  v3 = (float *)(this + 13488);
  *(float *)(this + 13532) = v24[2];
  do
  {
    v4 = *(double *)(v2 + dword_7C8A18 + 28);
    v2 += 8;
    *v3++ = v4;
  }
  while ( v2 < 72 );
  v5 = *(float *)(this + 13508);
  FloatConvertWrapper(v3);
  *(float *)(this + 13536) = -v5;
  if ( fabs(*(float *)(this + 13508)) == 1.0 )
  {
    v6 = -*(float *)(this + 13512);
    v7 = *(float *)(this + 13488);
    *(_DWORD *)(this + 13544) = 0;
    *(float *)(this + 13540) = atan2(v6, v7);
  }
  else
  {
    *(float *)(this + 13540) = atan2(*(float *)(this + 13496), *(float *)(this + 13520));
    *(float *)(this + 13544) = atan2(*(float *)(this + 13500), *(float *)(this + 13504));
  }
  qmemcpy(v24, (const void *)(dword_7C8A18 + 100), 0x18u);
  *(float *)(this + 13548) = v24[0];
  *(float *)(this + 13552) = v24[1];
  *(float *)(this + 13556) = v24[2];
  *(float *)(this + 13560) = *(float *)(this + 13512) * *(float *)(this + 13556)
                           + *(float *)(this + 13500) * *(float *)(this + 13552)
                           + *(float *)(this + 13488) * *(float *)(this + 13548);
  *(float *)(this + 13564) = *(float *)(this + 13492) * *(float *)(this + 13548)
                           + *(float *)(this + 13516) * *(float *)(this + 13556)
                           + *(float *)(this + 13504) * *(float *)(this + 13552);
  *(float *)(this + 13568) = *(float *)(this + 13496) * *(float *)(this + 13548)
                           + *(float *)(this + 13520) * *(float *)(this + 13556)
                           + *(float *)(this + 13508) * *(float *)(this + 13552);
  v24[0] = *(double *)(dword_7C8A18 + 76) * *(double *)(dword_7C8A18 + 140)
         + *(double *)(dword_7C8A18 + 52) * *(double *)(dword_7C8A18 + 132)
         + *(double *)(dword_7C8A18 + 124) * *(double *)(dword_7C8A18 + 28);
  v24[1] = *(double *)(dword_7C8A18 + 84) * *(double *)(dword_7C8A18 + 140)
         + *(double *)(dword_7C8A18 + 60) * *(double *)(dword_7C8A18 + 132)
         + *(double *)(dword_7C8A18 + 36) * *(double *)(dword_7C8A18 + 124);
  v8 = this + 13928;
  v9 = (double *)&unk_7C7918;
  v24[2] = *(double *)(dword_7C8A18 + 92) * *(double *)(dword_7C8A18 + 140)
         + *(double *)(dword_7C8A18 + 68) * *(double *)(dword_7C8A18 + 132)
         + *(double *)(dword_7C8A18 + 44) * *(double *)(dword_7C8A18 + 124);
  v10 = 4;
  v11 = v24[1];
  *(float *)(this + 13572) = v24[0];
  *(float *)(this + 13576) = v11;
  *(float *)(this + 13580) = v24[2];
  do
  {
    v8 += 248;
    *(float *)(v8 - 432) = *(v9 - 53);
    *(_DWORD *)(v8 - 248) = *(_DWORD *)v9;
    *(float *)(v8 - 408) = *(v9 - 38);
    v9 = (double *)((char *)v9 + 1124);
    --v10;
    *(float *)(v8 - 404) = *(double *)((char *)v9 - 1420);
    *(float *)(v8 - 400) = *(double *)((char *)v9 - 1412);
    *(float *)(v8 - 388) = *(double *)((char *)v9 - 708);
  }
  while ( v10 );
  v12 = *(_DWORD *)(this + 14772);
  if ( !v12 )
  {
    v14 = *(float *)(this + 14488) + *(float *)(this + 14240);
LABEL_14:
    v15 = v14 * 0.5;
    goto LABEL_15;
  }
  v13 = v12 - 1;
  if ( v13 )
  {
    if ( v13 != 1 )
      goto LABEL_16;
    v14 = *(float *)(this + 13992) + *(float *)(this + 13744);
    goto LABEL_14;
  }
  v15 = (*(float *)(this + 14488) + *(float *)(this + 14240) + *(float *)(this + 13992) + *(float *)(this + 13744))
      * 0.25;
LABEL_15:
  *(float *)(this + 14692) = v15;
LABEL_16:
  *(_DWORD *)(this + 14832) = dword_7C9318;
  if ( dbl_7C9084 >= 0.0 )
  {
    if ( dbl_7C9084 <= dbl_7C911C )
      v16 = dbl_7C9084;
    else
      v16 = dbl_7C911C;
  }
  else
  {
    v16 = 0.0;
  }
  *(float *)(this + 14740) = v16;
  *(float *)(this + 13680) = dbl_7C7430;
  *(float *)(this + 13684) = dbl_7C74AC * dbl_7C7428;
  *(float *)(this + 13688) = dbl_7C7438;
  if ( dbl_7C91DC <= 0.0 )
  {
    if ( *(float *)(this + 15716) >= 0.0 )
      *(_DWORD *)(this + 15716) = -1082130432;
    *(float *)(this + 15688) = dbl_7C920C;
    *(float *)(this + 15692) = dbl_7C9214;
    *(float *)(this + 15696) = dbl_7C921C;
  }
  v17 = dbl_7C75C4;
  *(float *)(this + 14712) = dbl_7C75C4;
  v18 = v17 * 0.75 + *(float *)(this + 13584);
  *(float *)(this + 13588) = v18;
  *(float *)(this + 13592) = 1.0 / v18;
  result = dword_7C8A18;
  v20 = *(double *)(dword_7C8A18 + 76) * *(double *)(dword_7C8A18 + 324)
      + *(double *)(dword_7C8A18 + 52) * *(double *)(dword_7C8A18 + 316)
      + *(double *)(dword_7C8A18 + 28) * *(double *)(dword_7C8A18 + 308);
  v25 = *(double *)(dword_7C8A18 + 36) * *(double *)(dword_7C8A18 + 308)
      + *(double *)(dword_7C8A18 + 84) * *(double *)(dword_7C8A18 + 324)
      + *(double *)(dword_7C8A18 + 60) * *(double *)(dword_7C8A18 + 316);
  v26 = *(double *)(dword_7C8A18 + 44) * *(double *)(dword_7C8A18 + 308)
      + *(double *)(dword_7C8A18 + 92) * *(double *)(dword_7C8A18 + 324)
      + *(double *)(dword_7C8A18 + 68) * *(double *)(dword_7C8A18 + 316);
  v23 = *(double *)(dword_7C8A18 + 180);
  v26 = v26 * v23;
  v21 = v20 * v23;
  v22 = v25 * v23;
  *(float *)(this + 13632) = v21;
  *(float *)(this + 13636) = v22;
  *(float *)(this + 13640) = v26;
  *(float *)(this + 13620) = *(float *)(this + 13496) * *(float *)(this + 13640)
                           + *(float *)(this + 13492) * *(float *)(this + 13636)
                           + *(float *)(this + 13632) * *(float *)(this + 13488);
  *(float *)(this + 13624) = *(float *)(this + 13500) * *(float *)(this + 13632)
                           + *(float *)(this + 13508) * *(float *)(this + 13640)
                           + *(float *)(this + 13504) * *(float *)(this + 13636);
  *(float *)(this + 13628) = *(float *)(this + 13512) * *(float *)(this + 13632)
                           + *(float *)(this + 13520) * *(float *)(this + 13640)
                           + *(float *)(this + 13516) * *(float *)(this + 13636);
  return result;
}
