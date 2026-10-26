int __thiscall sub_51B230(int *this, float *a2, int a3)
{
  int *v3; // ecx
  int v5; // [esp+0h] [ebp-4h]

  v5 = this[1] << 20 >> 20;
  v3 = this + 2;
  *a2 = (double)v5 * 0.0099999998;
  a2[2] = (double)(*(v3 - 1) >> 20) * 0.0099999998;
  a2[1] = ((double)(*(v3 - 1) << 12 >> 24) + 100.0) * 0.0099999998;
  return sub_51A6F0(v3);
}
