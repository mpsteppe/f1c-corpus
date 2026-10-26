int __thiscall sub_449620(int this, int a2, double *a3, int a4, int a5)
{
  sub_4388F0(
    (double *)(*(_DWORD *)(this + 6164) + 28),
    (double *)(*(_DWORD *)(this + 6164) + 4),
    (double *)(*(_DWORD *)(1256 * a2 + this + 1016) + 4),
    a3);
  *a3 = *a3 - *(double *)(this + 6176);
  a3[1] = a3[1] - *(double *)(this + 6184);
  a3[2] = a3[2] - *(double *)(this + 6192);
  sub_57F4D0(a4);
  return sub_57F4D0(a5);
}
