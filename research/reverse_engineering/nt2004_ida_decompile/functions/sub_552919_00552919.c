int __cdecl sub_552919(const void *a1, void *a2, int a3)
{
  int result; // eax

  result = a3 << 7;
  qmemcpy(a2, a1, 4 * ((unsigned int)(a3 << 7) >> 2));
  return result;
}
