int __fastcall sub_5BA4C0(char *a1, unsigned int a2)
{
  char *v2; // esi
  unsigned int v3; // edi
  char i; // al

  v2 = a1;
  v3 = 0;
  for ( i = *a1; *v2; i = *v2 )
  {
    ++v2;
    v3 = tolower(i) - 1664117991 * v3;
  }
  return v3 % a2;
}
