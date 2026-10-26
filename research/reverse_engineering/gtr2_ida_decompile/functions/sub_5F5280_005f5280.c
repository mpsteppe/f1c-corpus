int __stdcall sub_5F5280(int a1)
{
  if ( !a1 )
    return -1;
  if ( (*(_DWORD *)(a1 + 12))-- != 1 )
    return -2;
  BinkClose(*(_DWORD *)(a1 + 4));
  sub_5DB730(&dword_FB27E4, a1, 1);
  return 0;
}
