int __thiscall sub_43B810(int *this, char *a2, float *a3)
{
  double v3; // st7
  double v5; // st7
  int v6; // ecx
  int v7; // eax
  double v8; // st6
  double v9; // rt1
  int v10; // esi
  long double v11; // st7
  long double v12; // st6
  double v14[3]; // [esp+10h] [ebp-60h] BYREF
  long double v15; // [esp+28h] [ebp-48h] BYREF
  long double v16; // [esp+30h] [ebp-40h]
  double v17; // [esp+38h] [ebp-38h]
  _DWORD v18[6]; // [esp+40h] [ebp-30h] BYREF
  double v19[3]; // [esp+58h] [ebp-18h] BYREF

  v3 = *a3;
  qmemcpy(v14, this + 1550, sizeof(v14));
  v5 = v3 + v14[0];
  v14[0] = v5;
  v14[1] = a3[1] + v14[1];
  v6 = this[126];
  v14[2] = a3[2] + v14[2];
  memset(v18, 0, sizeof(v18));
  if ( v6 )
  {
    v7 = this[1541];
    v8 = v14[2] * *(double *)(v7 + 44) + v14[1] * *(double *)(v7 + 36) + v5 * *(double *)(v7 + 28);
    v9 = v14[2] * *(double *)(v7 + 68) + v14[1] * *(double *)(v7 + 60) + v5 * *(double *)(v7 + 52);
    v17 = v14[2] * *(double *)(v7 + 92) + v14[1] * *(double *)(v7 + 84) + v5 * *(double *)(v7 + 76);
    v19[0] = v8 + *(double *)(v7 + 4);
    v19[1] = v9 + *(double *)(v7 + 12);
    v19[2] = v17 + *(double *)(v7 + 20);
    qmemcpy((void *)(v6 + 4), v19, 0x18u);
    v10 = this[1541] + 28;
    v15 = -asin(*(double *)(this[1541] + 68));
    if ( fabs(*(double *)(v10 + 40)) == 1.0 )
    {
      v11 = -*(double *)(v10 + 48);
      v12 = *(double *)v10;
      v17 = 0.0;
      v16 = atan2(v11, v12);
    }
    else
    {
      v16 = atan2(*(double *)(v10 + 16), *(double *)(v10 + 64));
      v17 = atan2(*(double *)(v10 + 24), *(double *)(v10 + 32));
    }
    sub_57BF60(&v15);
  }
  return sub_437B30(this + 127, this[126], a2, v14, v18);
}
