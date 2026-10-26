// positive sp value has been detected, the output may be wrong!
char __userpurge sub_4571E8@<al>(char a1@<al>, _BYTE *a2@<edx>, char *a3@<ecx>, int a4, int a5, int a6)
{
  while ( 1 )
  {
    ++a3;
    *a2++ = a1;
    if ( !a1 )
      break;
    a1 = *a3;
  }
  return 1;
}
