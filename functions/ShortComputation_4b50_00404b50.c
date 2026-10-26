int __thiscall sub_404B50(int *this)
{
  int result; // eax

  result = *this;
  *(_BYTE *)(result + 20) = 0;
  *(_BYTE *)(result + 21) = 0;
  *(_DWORD *)(result + 28) = 0;
  return result;
}
