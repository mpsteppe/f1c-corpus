unsigned int __fastcall sub_5BC560(void **a1, const char *a2, _DWORD *a3)
{
  unsigned int result; // eax

  if ( !a2 )
    a2 = &byte_629120;
  result = strlen(a2) + 1;
  qmemcpy(*a1, a2, result);
  *a3 += result;
  *a1 = (char *)*a1 + result;
  return result;
}
