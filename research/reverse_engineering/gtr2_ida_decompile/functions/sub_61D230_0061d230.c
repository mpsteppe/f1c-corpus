double *__thiscall sub_61D230(int this)
{
  double *v2; // edi
  double *result; // eax
  double v4; // st7
  double v5; // [esp+8h] [ebp-30h] BYREF
  double v6; // [esp+10h] [ebp-28h]
  double v7; // [esp+18h] [ebp-20h]
  double v8; // [esp+20h] [ebp-18h] BYREF
  double v9; // [esp+28h] [ebp-10h]
  double v10; // [esp+30h] [ebp-8h]

  v2 = *(double **)(this + 8);
  sub_43A370((double *)(*(_DWORD *)(this + 4) + 32), (double *)(*(_DWORD *)(this + 4) + 8), v2, &v5);
  result = sub_43A370(
             (double *)(*(_DWORD *)(this + 12) + 32),
             (double *)(*(_DWORD *)(this + 12) + 8),
             *(double **)(this + 16),
             &v8);
  v4 = sqrt((v7 - v10) * (v7 - v10) + (v6 - v9) * (v6 - v9) + (v5 - v8) * (v5 - v8));
  v2[7] = v4;
  *(double *)(*(_DWORD *)(this + 16) + 56) = v4;
  return result;
}
