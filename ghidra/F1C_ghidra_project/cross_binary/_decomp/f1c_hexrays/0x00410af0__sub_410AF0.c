// f1c  0x00410af0  size=43
int __thiscall sub_410AF0(int *this, int *a2)
{
  int result; // eax
  int v3; // edx

  result = *a2;
  v3 = *this - 1;
  *this = v3;
  *(_DWORD *)(this[2] + 4 * result) = *(_DWORD *)(this[2] + 4 * v3);
  **(_DWORD **)(this[2] + 4 * result) = result;
  *a2 = -1;
  return result;
}
