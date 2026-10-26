int __cdecl sub_58FA10(int a1)
{
  __int16 *v1; // eax

  v1 = &word_7FF962;
  do
  {
    *(v1 - 1) = -1;
    *v1 = -1;
    v1 += 2;
  }
  while ( (int)v1 < (int)&word_7FF9E2 );
  dword_7E4CB8 = 0;
  return sub_58FA50(65537 * a1);
}
