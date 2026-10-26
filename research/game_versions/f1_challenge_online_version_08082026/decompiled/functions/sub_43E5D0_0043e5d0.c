int __thiscall sub_43E5D0(int this, double *a2, double *a3)
{
  double v3; // st7
  double v4; // st6
  double v5; // st5
  double v7; // [esp+0h] [ebp-18h] BYREF
  double v8; // [esp+8h] [ebp-10h]
  double v9; // [esp+10h] [ebp-8h]

  v3 = *a2 - *(double *)(*(_DWORD *)(this + 5616) + 4);
  v4 = a2[1] - *(double *)(*(_DWORD *)(this + 5616) + 12);
  v5 = a2[2] - *(double *)(*(_DWORD *)(this + 5616) + 20);
  v7 = v4 * a3[2] - v5 * a3[1];
  v8 = v5 * *a3 - v3 * a3[2];
  v9 = v3 * a3[1] - v4 * *a3;
  *(double *)(this + 7940) = *a3 + *(double *)(this + 7940);
  *(double *)(this + 7948) = *(double *)(this + 7948) + a3[1];
  *(double *)(this + 7956) = a3[2] + *(double *)(this + 7956);
  *(double *)(this + 7964) = v7 + *(double *)(this + 7964);
  *(double *)(this + 7972) = v8 + *(double *)(this + 7972);
  *(double *)(this + 7980) = v9 + *(double *)(this + 7980);
  return sub_44FEE0(a3, &v7);
}
