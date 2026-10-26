// positive sp value has been detected, the output may be wrong!
void __userpurge sub_405BC8(char a1@<bl>, int a2@<edi>, int a3)
{
  *(_BYTE *)(a2 + 94) += a1;
}
