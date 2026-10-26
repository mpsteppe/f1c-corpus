_DWORD *__stdcall sub_5D8CB0(_DWORD *a1, char *a2)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1 )
    *a1 = dword_FB2748;
  if ( a2 )
    strcpy(a2, &byte_FB2320);
  return result;
}
