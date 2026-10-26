int __thiscall sub_443380(int this, double *a2, double *a3)
{
  double v3; // st7
  double v4; // st6
  double v5; // st5
  double v7; // [esp+0h] [ebp-18h] BYREF
  double v8; // [esp+8h] [ebp-10h]
  double v9; // [esp+10h] [ebp-8h]

  v3 = *a2 - *(double *)(*(_DWORD *)(this + 6312) + 8);
  v4 = a2[1] - *(double *)(*(_DWORD *)(this + 6312) + 16);
  v5 = a2[2] - *(double *)(*(_DWORD *)(this + 6312) + 24);
  v7 = v4 * a3[2] - v5 * a3[1];
  v8 = v5 * *a3 - v3 * a3[2];
  v9 = v3 * a3[1] - v4 * *a3;
  *(double *)(this + 9400) = *a3 + *(double *)(this + 9400);
  *(double *)(this + 9408) = *(double *)(this + 9408) + a3[1];
  *(double *)(this + 9416) = a3[2] + *(double *)(this + 9416);
  *(double *)(this + 9424) = v7 + *(double *)(this + 9424);
  *(double *)(this + 9432) = v8 + *(double *)(this + 9432);
  *(double *)(this + 9440) = v9 + *(double *)(this + 9440);
  return sub_45F3B0(a3, &v7);
}
