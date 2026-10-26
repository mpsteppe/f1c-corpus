char __cdecl sub_565C6D(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  char result; // al

  result = *(_BYTE *)((((*a3 * **(__int16 **)(a2 + 80) + 4) >> 3) & 0x3FF) + *(_DWORD *)(a1 + 284) + 128);
  *(_BYTE *)(a5 + *a4) = result;
  return result;
}
