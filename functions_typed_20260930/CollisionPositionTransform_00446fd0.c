int __thiscall sub_446FD0(int this, int a2, double *a3, int a4, int a5)
{
  F_3DVectorTransformBy33Matrix(
    (double *)(*(_DWORD *)(this + 5616) + 28),
    (double *)(*(_DWORD *)(this + 5616) + 4),
    (double *)(*(_DWORD *)(1124 * a2 + this + 1000) + 4),
    a3);
  *a3 = *a3 - *(double *)(this + 5628);
  a3[1] = a3[1] - *(double *)(this + 5636);
  a3[2] = a3[2] - *(double *)(this + 5644);
  F_33MatrixMultiply(a4);
  return F_33MatrixMultiply(a5);
}

