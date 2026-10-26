int __userpurge sub_4C0C67@<eax>(int result@<eax>, int a2@<ecx>, int a3)
{
  *(_DWORD *)(a2 + 32) = result;
  *(_DWORD *)(a2 + 36) = result;
  return result;
}
