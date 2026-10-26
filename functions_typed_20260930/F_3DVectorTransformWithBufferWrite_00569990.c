int __thiscall sub_569990(int this, double *a2, int a3, char a4, int a5, int a6)
{
  int result; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // rt0
  double v11; // st5
  double v12; // st6

  result = *(_DWORD *)(this + 576) + 88 * (*(_DWORD *)(this + 572))++;
  v7 = *a2 - *(double *)(this + 4);
  v8 = a2[1] - *(double *)(this + 12);
  v9 = a2[2] - *(double *)(this + 20);
  *(double *)result = v9 * *(double *)(this + 76) + v8 * *(double *)(this + 52) + v7 * *(double *)(this + 28);
  *(double *)(result + 8) = v9 * *(double *)(this + 84) + v8 * *(double *)(this + 60) + v7 * *(double *)(this + 36);
  v10 = v9 * *(double *)(this + 92);
  v11 = v8 * *(double *)(this + 68);
  v12 = v7 * *(double *)(this + 44);
  *(_DWORD *)(result + 48) = a3;
  *(_BYTE *)(result + 52) = a4;
  *(double *)(result + 16) = v10 + v11 + v12;
  *(_DWORD *)(result + 56) = a5;
  *(_DWORD *)(result + 60) = a6;
  return result;
}

