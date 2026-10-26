int __thiscall sub_619350(int this, double *a2, int a3, char a4, double a5)
{
  int v5; // esi

  v5 = *(_DWORD *)(this + 580) + 88 * (*(_DWORD *)(this + 576))++;
  sub_43A3E0((double *)(this + 32), (double *)(this + 8), a2, (double *)v5);
  *(_DWORD *)(v5 + 48) = a3;
  *(double *)(v5 + 56) = a5;
  *(_BYTE *)(v5 + 52) = a4;
  return v5;
}
