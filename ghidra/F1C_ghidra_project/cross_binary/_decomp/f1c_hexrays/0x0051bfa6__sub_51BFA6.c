// f1c  0x0051bfa6  size=26
int __cdecl sub_51BFA6(_DWORD *a1)
{
  int v1; // ecx
  int result; // eax

  v1 = a1[103];
  *(_DWORD *)(v1 + 92) = a1[68];
  result = a1[24];
  *(_DWORD *)(v1 + 96) = result;
  return result;
}
