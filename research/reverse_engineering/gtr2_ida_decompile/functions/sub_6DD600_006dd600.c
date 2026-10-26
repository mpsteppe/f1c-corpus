int __stdcall sub_6DD600(int a1, int a2, unsigned __int16 *a3, int *a4, int a5)
{
  int result; // eax

  result = *a4;
  *(_BYTE *)(a5 + *a4) = *(_BYTE *)((((*a3 * **(unsigned __int16 **)(a2 + 80) + 4) >> 3) & 0x3FF)
                                  + *(_DWORD *)(a1 + 328)
                                  + 128);
  return result;
}
