char __thiscall sub_5A6A20(int *this)
{
  int v1; // eax
  bool v2; // sf

  v1 = *this + 1;
  v2 = *this - 5 < 0;
  *this = v1;
  return v2 ^ __OFSUB__(v1, 6);
}
