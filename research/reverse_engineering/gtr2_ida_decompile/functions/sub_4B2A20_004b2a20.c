int __stdcall sub_4B2A20(int a1)
{
  int result; // eax
  int v2; // ecx

  v2 = dword_B73248;
  dword_B73240 += 2 * (a1 != 0) - 1;
  result = dword_B73240;
  if ( dword_B73240 < dword_B73248 || (v2 = dword_B7324C, dword_B73240 > dword_B7324C) )
    dword_B73240 = v2;
  return result;
}
