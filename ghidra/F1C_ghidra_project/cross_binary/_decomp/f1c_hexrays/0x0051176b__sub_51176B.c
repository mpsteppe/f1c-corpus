// f1c  0x0051176b  size=17
int __cdecl sub_51176B(int *a1)
{
  int result; // eax

  *(_DWORD *)(*a1 + 108) = 0;
  result = *a1;
  *(_DWORD *)(*a1 + 20) = 0;
  return result;
}
