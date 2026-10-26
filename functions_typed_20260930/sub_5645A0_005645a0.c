int __fastcall sub_5645A0(char **a1, unsigned int a2)
{
  char *v2; // esi
  unsigned int v3; // edi
  char v5; // al

  v2 = *a1;
  v3 = 0;
  v5 = **a1;
  if ( v5 )
  {
    do
    {
      ++v2;
      v3 = sub_58B465(v5) - 1664117991 * v3;
      v5 = *v2;
    }
    while ( *v2 );
  }
  return v3 % a2;
}

