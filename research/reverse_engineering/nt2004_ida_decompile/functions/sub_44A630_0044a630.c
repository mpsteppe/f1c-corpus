int __thiscall sub_44A630(int this, float *a2)
{
  int result; // eax
  int v4; // ecx
  int v5; // ecx
  double v6; // st7
  double *v7; // esi
  int v8; // edx
  int v9; // edi
  double v10; // st6
  float *v11; // ecx
  __int16 v12; // fps
  double v13; // st7
  bool v14; // c0
  char v15; // c2
  bool v16; // c3
  double v17; // st7
  double v18; // st7
  double v19[3]; // [esp+8h] [ebp-18h] BYREF

  HIWORD(result) = HIWORD(a2);
  *a2 = *(double *)(this + 128);
  qmemcpy(v19, (const void *)(*(_DWORD *)(this + 6164) + 4), sizeof(v19));
  a2[1] = v19[0];
  a2[2] = v19[1];
  a2[3] = v19[2];
  v4 = *(_DWORD *)(this + 6164);
  a2[4] = atan2(
            -(*(double *)(v4 + 76) * *(double *)(v4 + 116)
            + *(double *)(v4 + 52) * *(double *)(v4 + 108)
            + *(double *)(v4 + 28) * *(double *)(v4 + 100)),
            -(*(double *)(v4 + 44) * *(double *)(v4 + 100)
            + *(double *)(v4 + 92) * *(double *)(v4 + 116)
            + *(double *)(v4 + 68) * *(double *)(v4 + 108)));
  v5 = *(_DWORD *)(this + 6164);
  v19[0] = *(double *)(v5 + 76) * *(double *)(v5 + 324)
         + *(double *)(v5 + 52) * *(double *)(v5 + 316)
         + *(double *)(v5 + 28) * *(double *)(v5 + 308);
  v6 = *(double *)(v5 + 36) * *(double *)(v5 + 308)
     + *(double *)(v5 + 84) * *(double *)(v5 + 324)
     + *(double *)(v5 + 60) * *(double *)(v5 + 316);
  v7 = (double *)(this + 6420);
  v8 = this + 1156;
  v9 = 4;
  v19[2] = *(double *)(v5 + 44) * *(double *)(v5 + 308)
         + *(double *)(v5 + 92) * *(double *)(v5 + 324)
         + *(double *)(v5 + 68) * *(double *)(v5 + 316);
  v10 = *(double *)(v5 + 180);
  v11 = a2 + 20;
  v19[1] = v10 * v6;
  v19[2] = v10 * v19[2];
  a2[5] = v19[0] * v10;
  a2[6] = v19[1];
  a2[7] = v19[2];
  a2[8] = *(double *)(v8 + 6780) * 9.549296585513721;
  a2[9] = *(double *)(v8 + 7256) * 9.549296585513721;
  a2[10] = *(double *)(v8 - 1084);
  a2[11] = *(double *)(v8 - 1148);
  a2[12] = *(double *)(v8 - 1076);
  a2[13] = *(double *)(v8 - 1140);
  a2[14] = *(double *)(v8 - 1092);
  a2[15] = *(double *)(v8 - 1156);
  a2[16] = 1.0 - *(double *)(v8 - 1124);
  a2[17] = (1.0 - *(double *)(v8 - 1132)) * (1.0 - *(double *)(v8 - 1124));
  a2[54] = (float)*(int *)(v8 + 7448);
  a2[55] = *(double *)(v8 + 7084);
  a2[56] = *(double *)(v8 + 7020);
  do
  {
    *(v11 - 2) = *(double *)(v8 - 300);
    *(v11 - 1) = *(double *)v8;
    v13 = *v7;
    v14 = v13 < 0.0;
    v15 = 0;
    v16 = v13 == 0.0;
    LOWORD(result) = v12;
    if ( v13 >= 0.0 )
      v17 = *v7;
    else
      v17 = 0.0;
    *v11 = v17;
    v11 += 9;
    v18 = *(double *)(v8 + 464);
    v8 += 1256;
    *(v11 - 8) = v18;
    ++v7;
    --v9;
    *(v11 - 7) = *(double *)(v8 - 784);
    *(v11 - 6) = *(double *)(v8 - 776);
    *(v11 - 5) = *(double *)(v8 - 752);
    *(v11 - 4) = *(double *)(v8 - 720);
    *(v11 - 3) = *(double *)(v8 - 892);
  }
  while ( v9 );
  return result;
}
