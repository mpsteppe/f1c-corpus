int __thiscall sub_477B90(int *this)
{
  int *v2; // edi
  int result; // eax

  v2 = this + 139;
  sub_477B50(this + 139);
  result = 7 * this[136];
  dword_76A67C[result] = *v2;
  dword_76A680[result] = v2[1];
  return result * 4;
}
