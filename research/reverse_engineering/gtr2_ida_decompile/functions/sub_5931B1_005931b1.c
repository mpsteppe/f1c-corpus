// positive sp value has been detected, the output may be wrong!
int __userpurge sub_5931B1@<eax>(int a1@<edi>, int a2@<esi>, const char *a3, const char *a4)
{
  int *v5; // eax

  if ( (*((_DWORD *)&byte_173DACB - 4129))-- == 1 )
    dword_1739A47 = 405;
  if ( !a3 )
    return a2;
  if ( !--dword_1739A4C )
    dword_1739A4C = 425;
  v5 = *(int **)(a1 + 56);
  *(_DWORD *)(a1 + 64) = v5;
  if ( !v5 )
    return 0;
  if ( !--dword_1739A51 )
    dword_1739A51 = 542;
  a2 = *v5;
  if ( !*v5 )
    return a2;
  if ( !--dword_1739A56 )
    dword_1739A56 = 611;
  return _stricmp(a3, a4);
}
