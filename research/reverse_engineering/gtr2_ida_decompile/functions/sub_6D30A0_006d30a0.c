int __stdcall sub_6D30A0(int a1)
{
  int result; // eax
  int v2; // ecx

  result = *(_DWORD *)(a1 + 456);
  v2 = *(_DWORD *)(a1 + 116);
  *(_DWORD *)(result + 36) = 0;
  *(_DWORD *)(result + 44) = v2;
  return result;
}
