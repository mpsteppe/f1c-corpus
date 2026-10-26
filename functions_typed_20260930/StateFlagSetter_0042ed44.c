// positive sp value has been detected, the output may be wrong!
char __userpurge sub_42ED44@<al>(char result@<al>, _BYTE *a2@<ecx>, _BYTE *a3@<esi>, int a4, int a5, int a6)
{
  *a2 += result;
  *a3 = 1;
  return result;
}

