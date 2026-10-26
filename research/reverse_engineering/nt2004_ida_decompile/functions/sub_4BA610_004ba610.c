char *__stdcall sub_4BA610(char *Str)
{
  char *result; // eax

  if ( strstr(Str, aAltosc) )
    byte_766190 = 1;
  result = strstr(Str, aSkipoptions);
  if ( result )
    dword_76618C = 2;
  return result;
}
