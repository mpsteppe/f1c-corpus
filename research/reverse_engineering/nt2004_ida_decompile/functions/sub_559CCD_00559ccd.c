int __cdecl sub_559CCD(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 412);
  *(_BYTE *)(result + 36) = 0;
  *(_DWORD *)(result + 44) = *(_DWORD *)(a1 + 96);
  return result;
}
