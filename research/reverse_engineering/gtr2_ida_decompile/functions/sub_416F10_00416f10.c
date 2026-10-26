int __thiscall sub_416F10(int *this, int a2)
{
  int v2; // esi
  int *v3; // edx
  int result; // eax

  v2 = *this - 1;
  v3 = (int *)(this[4] + 40 * *(_DWORD *)(a2 + 4));
  result = *v3;
  *this = v2;
  *(_DWORD *)(this[2] + 4 * result) = *(_DWORD *)(this[2] + 4 * v2);
  **(_DWORD **)(this[2] + 4 * result) = result;
  *v3 = -1;
  return result;
}
