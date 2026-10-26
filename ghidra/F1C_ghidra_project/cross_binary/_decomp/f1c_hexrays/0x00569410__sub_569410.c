// f1c  0x00569410  size=208
void __thiscall sub_569410(int this)
{
  double v1; // st7
  double v2; // st6
  double v3; // [esp+0h] [ebp-30h]

  v3 = (*(double *)(this + 76) * *(double *)(this + 140)
      + *(double *)(this + 52) * *(double *)(this + 132)
      + *(double *)(this + 124) * *(double *)(this + 28))
     * *(double *)(this + 188);
  v1 = (*(double *)(this + 36) * *(double *)(this + 124)
      + *(double *)(this + 84) * *(double *)(this + 140)
      + *(double *)(this + 60) * *(double *)(this + 132))
     * *(double *)(this + 196);
  v2 = (*(double *)(this + 44) * *(double *)(this + 124)
      + *(double *)(this + 92) * *(double *)(this + 140)
      + *(double *)(this + 68) * *(double *)(this + 132))
     * *(double *)(this + 204);
  *(double *)(this + 148) = v2 * *(double *)(this + 44) + v1 * *(double *)(this + 36) + v3 * *(double *)(this + 28);
  *(double *)(this + 156) = v2 * *(double *)(this + 68) + v1 * *(double *)(this + 60) + v3 * *(double *)(this + 52);
  *(double *)(this + 164) = v2 * *(double *)(this + 92) + v1 * *(double *)(this + 84) + v3 * *(double *)(this + 76);
}
