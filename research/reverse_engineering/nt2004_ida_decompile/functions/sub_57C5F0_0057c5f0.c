int __thiscall sub_57C5F0(int this, double *a2, int a3, char a4)
{
  int result; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st5
  double v8; // rt0
  double v9; // st5
  double v10; // st6

  result = *(_DWORD *)(this + 560) + 56 * (*(_DWORD *)(this + 556))++;
  v5 = *a2 - *(double *)(this + 4);
  v6 = a2[1] - *(double *)(this + 12);
  v7 = a2[2] - *(double *)(this + 20);
  *(double *)result = v7 * *(double *)(this + 76) + v6 * *(double *)(this + 52) + v5 * *(double *)(this + 28);
  *(double *)(result + 8) = v7 * *(double *)(this + 84) + v6 * *(double *)(this + 60) + v5 * *(double *)(this + 36);
  v8 = v7 * *(double *)(this + 92);
  v9 = v6 * *(double *)(this + 68);
  v10 = v5 * *(double *)(this + 44);
  *(_DWORD *)(result + 48) = a3;
  *(_BYTE *)(result + 52) = a4;
  *(double *)(result + 16) = v8 + v9 + v10;
  return result;
}
