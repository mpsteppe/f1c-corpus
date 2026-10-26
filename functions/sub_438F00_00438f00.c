int __thiscall sub_438F00(int *this, int a2, float *a3)
{
  double v3; // st7
  double v5; // st7
  int v6; // ecx
  int v7; // eax
  double v8; // st6
  double v9; // rt1
  int v10; // esi
  double v11; // st7
  long double v12; // st7
  long double v13; // st6
  double v15[3]; // [esp+10h] [ebp-60h] BYREF
  double v16; // [esp+28h] [ebp-48h] BYREF
  long double v17; // [esp+30h] [ebp-40h]
  double v18; // [esp+38h] [ebp-38h]
  _DWORD v19[6]; // [esp+40h] [ebp-30h] BYREF
  double v20[3]; // [esp+58h] [ebp-18h] BYREF

  v3 = *a3;
  qmemcpy(v15, this + 1413, sizeof(v15));
  v5 = v3 + v15[0];
  v15[0] = v5;
  v15[1] = a3[1] + v15[1];
  v6 = this[122];
  v15[2] = a3[2] + v15[2];
  memset(v19, 0, sizeof(v19));
  if ( v6 )
  {
    v7 = this[1404];
    v8 = v15[2] * *(double *)(v7 + 44) + v15[1] * *(double *)(v7 + 36) + v5 * *(double *)(v7 + 28);
    v9 = v15[2] * *(double *)(v7 + 68) + v15[1] * *(double *)(v7 + 60) + v5 * *(double *)(v7 + 52);
    v18 = v15[2] * *(double *)(v7 + 92) + v15[1] * *(double *)(v7 + 84) + v5 * *(double *)(v7 + 76);
    v20[0] = v8 + *(double *)(v7 + 4);
    v20[1] = v9 + *(double *)(v7 + 12);
    v20[2] = v18 + *(double *)(v7 + 20);
    qmemcpy((void *)(v6 + 4), v20, 0x18u);
    v10 = this[1404] + 28;
    v11 = *(double *)(this[1404] + 68);
    FloatConvertWrapper();
    v16 = -v11;
    if ( fabs(*(double *)(v10 + 40)) == 1.0 )
    {
      v12 = -*(double *)(v10 + 48);
      v13 = *(double *)v10;
      v18 = 0.0;
      v17 = atan2(v12, v13);
    }
    else
    {
      v17 = atan2(*(double *)(v10 + 16), *(double *)(v10 + 64));
      v18 = atan2(*(double *)(v10 + 24), *(double *)(v10 + 32));
    }
    F_3x3RotationTensorMatrixTransform(&v16);
  }
  return SuspensionSetupSectionReader(this + 123, this[122], a2, v15, v19);
}
