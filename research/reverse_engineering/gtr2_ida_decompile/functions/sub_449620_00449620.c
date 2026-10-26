int __thiscall sub_449620(int this, int a2, double *a3, int a4, int a5)
{
  sub_43A3E0(
    (double *)(*(_DWORD *)(this + 6312) + 32),
    (double *)(*(_DWORD *)(this + 6312) + 8),
    (double *)(*(_DWORD *)(1280 * a2 + this + 1064) + 8),
    a3);
  *a3 = *a3 - *(double *)(this + 6328);
  a3[1] = a3[1] - *(double *)(this + 6336);
  a3[2] = a3[2] - *(double *)(this + 6344);
  sub_61C060(a4);
  return sub_61C060(a5);
}
