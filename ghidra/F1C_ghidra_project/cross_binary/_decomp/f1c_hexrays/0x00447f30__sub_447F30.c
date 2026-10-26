// f1c  0x00447f30  size=487
int __thiscall sub_447F30(double *this, float *a2)
{
  int v2; // eax
  int v3; // esi
  double v4; // st7
  int result; // eax
  double *v6; // edx
  float *v7; // ebx
  double *v8; // ecx
  int v9; // esi
  __int16 v10; // fps
  double v11; // st7
  bool v12; // c0
  char v13; // c2
  bool v14; // c3
  double v15; // st7
  double v17[4]; // [esp+10h] [ebp-30h] BYREF
  double v18; // [esp+30h] [ebp-10h]
  double v19; // [esp+38h] [ebp-8h]

  *a2 = this[12];
  qmemcpy(v17, (const void *)(*((_DWORD *)this + 1404) + 4), 0x18u);
  a2[1] = v17[0];
  a2[2] = v17[1];
  a2[3] = v17[2];
  v2 = *((_DWORD *)this + 1404);
  a2[4] = atan2(
            -(*(double *)(v2 + 76) * *(double *)(v2 + 116)
            + *(double *)(v2 + 52) * *(double *)(v2 + 108)
            + *(double *)(v2 + 28) * *(double *)(v2 + 100)),
            -(*(double *)(v2 + 44) * *(double *)(v2 + 100)
            + *(double *)(v2 + 92) * *(double *)(v2 + 116)
            + *(double *)(v2 + 68) * *(double *)(v2 + 108)));
  v3 = *((_DWORD *)this + 1404);
  sub_4388D0((double *)(v3 + 28), (double *)(v3 + 308), v17);
  v4 = *(double *)(v3 + 180);
  HIWORD(result) = HIWORD(this);
  v18 = v17[1] * v4;
  v19 = v17[2] * v4;
  a2[5] = v17[0] * v4;
  a2[6] = v18;
  a2[7] = v19;
  v6 = this + 734;
  v7 = a2 + 20;
  a2[8] = *(double *)((char *)this + 7260) * 9.549296585513721;
  v8 = (double *)((char *)this + 1140);
  v9 = 4;
  a2[9] = this[967] * 9.549296585513721;
  a2[10] = this[9];
  a2[11] = this[1];
  a2[12] = this[10];
  a2[13] = this[2];
  a2[14] = this[8];
  a2[15] = *this;
  a2[16] = 1.0 - this[4];
  a2[17] = (1.0 - this[3]) * (1.0 - this[4]);
  a2[54] = (float)*((int *)this + 1980);
  a2[55] = *(double *)((char *)this + 7564);
  a2[56] = *(double *)((char *)this + 7500);
  do
  {
    *(v7 - 2) = *(double *)((char *)v8 - 300);
    *(v7 - 1) = *v8;
    v11 = *v6;
    v12 = v11 < 0.0;
    v13 = 0;
    v14 = v11 == 0.0;
    LOWORD(result) = v10;
    if ( v11 >= 0.0 )
      v15 = *v6;
    else
      v15 = 0.0;
    *v7 = v15;
    v7 += 9;
    ++v6;
    *(v7 - 8) = *(double *)((char *)v8 + 356);
    v8 = (double *)((char *)v8 + 1124);
    --v9;
    *(v7 - 7) = *(v8 - 95);
    *(v7 - 6) = *(v8 - 94);
    *(v7 - 5) = *(v8 - 91);
    *(v7 - 4) = *(v8 - 87);
    *(v7 - 3) = *(v8 - 102);
  }
  while ( v9 );
  return result;
}
