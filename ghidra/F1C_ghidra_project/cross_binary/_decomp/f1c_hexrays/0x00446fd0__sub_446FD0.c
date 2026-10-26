// f1c  0x00446fd0  size=297
int __thiscall sub_446FD0(int this, int a2, double *a3, int a4, int a5)
{
  sub_4361D0(
    (double *)(*(_DWORD *)(this + 5616) + 28),
    (double *)(*(_DWORD *)(this + 5616) + 4),
    (double *)(*(_DWORD *)(1124 * a2 + this + 1000) + 4),
    a3);
  *a3 = *a3 - *(double *)(this + 5628);
  a3[1] = a3[1] - *(double *)(this + 5636);
  a3[2] = a3[2] - *(double *)(this + 5644);
  sub_56C740(a4);
  return sub_56C740(a5);
}
