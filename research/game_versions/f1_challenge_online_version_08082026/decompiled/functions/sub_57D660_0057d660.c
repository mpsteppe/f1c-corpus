char __stdcall sub_57D660(unsigned __int16 *a1, int a2)
{
  char *v2; // ebp

  v2 = (char *)(a1 + 2);
  if ( *a1 == (*(_DWORD *)(a2 + 36) >> 3) + ((*(_DWORD *)(a2 + 36) & 7) != 0) )
    qmemcpy(*(void **)(a2 + 20), v2, (*(_DWORD *)(a2 + 36) >> 3) + ((*(_DWORD *)(a2 + 36) & 7) != 0));
  sub_587510(&v2[*a1], a1[1]);
  return 1;
}
