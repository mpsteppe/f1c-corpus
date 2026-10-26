void __usercall sub_46EA51(unsigned int a1@<eax>, char a2)
{
  char *v2; // ecx

  if ( a1 < dword_16C9A24 )
    __asm { retn }
  v2 = &a2;
  do
  {
    v2 -= 4096;
    a1 -= 4096;
  }
  while ( a1 >= 0x1000 );
  __asm { retn }
}
