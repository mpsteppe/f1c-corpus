int __userpurge sub_4E0D68@<eax>(char a1@<bl>, int a2@<esi>, int a3)
{
  *(_BYTE *)(a2 - 125) += a1;
  return ConditionalResourceRelease(a3);
}
