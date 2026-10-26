char __usercall sub_5F6650@<al>(const char *a1@<eax>, char *a2@<edi>, const char *a3@<esi>)
{
  if ( _stricmp(a2, a1) )
    return 0;
  strcpy(a2, a3);
  return 1;
}
