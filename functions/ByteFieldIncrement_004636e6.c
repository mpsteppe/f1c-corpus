// positive sp value has been detected, the output may be wrong!
char __userpurge sub_4636E6@<al>(char a1@<bl>, int a2@<edi>, int a3)
{
  *(_BYTE *)(a2 + 94) += a1;
  return a1;
}
