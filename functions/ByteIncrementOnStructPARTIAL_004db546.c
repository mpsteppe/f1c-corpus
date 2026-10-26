// positive sp value has been detected, the output may be wrong!
char __userpurge sub_4DB546@<al>(char result@<al>, int a2@<ebx>, int a3)
{
  *(_BYTE *)(a2 - 963967804) += result;
  return result;
}
