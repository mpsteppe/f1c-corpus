char *__cdecl AdjustPointer(char *a1, const struct PMD *a2)
{
  int pdisp; // edx
  char *result; // eax

  pdisp = a2->pdisp;
  result = &a1[a2->mdisp];
  if ( pdisp >= 0 )
    result += pdisp + *(_DWORD *)(*(_DWORD *)&a1[pdisp] + a2->vdisp);
  return result;
}
