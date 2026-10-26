char __stdcall sub_585E80(unsigned int a1, unsigned int *a2, _BYTE *a3)
{
  char result; // al

  *a2 = a1 >> 3;
  result = 1 << (a1 & 7);
  *a3 = result;
  return result;
}
