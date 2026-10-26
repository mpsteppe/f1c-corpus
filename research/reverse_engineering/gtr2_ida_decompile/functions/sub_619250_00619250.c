int __thiscall sub_619250(int this, double *a2, int a3, char a4)
{
  int v4; // esi

  v4 = *(_DWORD *)(this + 564) + 56 * (*(_DWORD *)(this + 560))++;
  sub_43A3E0((double *)(this + 32), (double *)(this + 8), a2, (double *)v4);
  *(_DWORD *)(v4 + 48) = a3;
  *(_BYTE *)(v4 + 52) = a4;
  return v4;
}
