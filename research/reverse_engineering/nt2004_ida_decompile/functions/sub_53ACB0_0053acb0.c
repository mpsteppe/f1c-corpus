unsigned int __fastcall sub_53ACB0(unsigned int a1, int a2)
{
  unsigned int v2; // eax
  int v3; // esi

  v2 = 0;
  do
  {
    v3 = a1 & 1;
    a1 >>= 1;
    v2 = 2 * (v3 | v2);
    --a2;
  }
  while ( a2 > 0 );
  return v2 >> 1;
}
