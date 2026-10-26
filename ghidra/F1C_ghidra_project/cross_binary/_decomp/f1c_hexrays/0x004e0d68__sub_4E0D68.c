// f1c  0x004e0d68  size=8
int __userpurge sub_4E0D68@<eax>(char a1@<bl>, int a2@<esi>, int a3)
{
  *(_BYTE *)(a2 - 125) += a1;
  return sub_4E0D70(a3);
}
