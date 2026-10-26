int __cdecl sub_58E4F0(int a1, int a2)
{
  int result; // eax
  unsigned int v3; // esi

  result = a2 / 8 + 1;
  v3 = ((((*(_BYTE *)(a1 + 4) & 0xF) + 2) * *(unsigned __int8 *)(a1 + 5) + 15) & 0xFFFFFFFC)
     + a1
     + 4 * (*(_BYTE *)(a1 + 4) & 0xF);
  *(_BYTE *)(v3 + result) &= ~(1 << (a2 % 8));
  return result;
}
