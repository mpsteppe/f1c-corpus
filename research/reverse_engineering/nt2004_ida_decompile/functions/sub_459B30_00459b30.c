int __thiscall sub_459B30(int *this)
{
  int result; // eax
  int v2; // ecx

  v2 = *this;
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(v2 + 104);
  result = *(_DWORD *)(v2 + 112);
  *(_DWORD *)(v2 + 36) = *(_DWORD *)(v2 + 108);
  *(_DWORD *)(v2 + 132) = 0;
  *(_DWORD *)(v2 + 40) = result;
  *(_BYTE *)(v2 + 116) = 1;
  return result;
}
