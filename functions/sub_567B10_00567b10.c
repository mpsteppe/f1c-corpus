char __stdcall sub_567B10(unsigned __int8 *a1, char *a2)
{
  const char *v2; // edx
  unsigned __int8 i; // al
  _BYTE *v4; // eax
  unsigned __int8 *j; // edx
  _BYTE *v6; // edx
  char result; // al

  v2 = (const char *)a1;
  *a2 = 0;
  if ( !a1 )
    return 0;
  for ( i = *a1; i; i = *++v2 )
  {
    if ( !CharacterClassCheck(i) )
      break;
  }
  strcpy(a2, v2);
  v4 = (_BYTE *)sub_587C20(a2, &unk_5C30B8);
  if ( v4 )
    *v4 = 0;
  for ( j = (unsigned __int8 *)&a2[strlen(a2) - 1]; j >= (unsigned __int8 *)a2; j = v6 - 1 )
  {
    if ( !CharacterClassCheck(*j) )
      break;
    *v6 = 0;
  }
  result = 1;
  if ( !strlen(a2) )
    return 0;
  return result;
}
