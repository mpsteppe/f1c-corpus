int __stdcall sub_4BC1B0(char *a1, _BYTE *a2)
{
  const char *v2; // edi
  int result; // eax

  v2 = a1_0;
  if ( !*a2 )
    v2 = a0;
  result = 0;
  strcat(a1, v2);
  return result;
}
