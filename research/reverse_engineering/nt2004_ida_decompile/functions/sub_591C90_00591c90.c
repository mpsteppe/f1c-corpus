_DWORD *__stdcall sub_591C90(_DWORD *a1, char *a2)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1 )
    *a1 = dword_7E5D4C;
  if ( a2 )
    strcpy(a2, &byte_7E5D60);
  return result;
}
