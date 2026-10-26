int __userpurge sub_526C08@<eax>(int a1@<eax>, _DWORD *a2@<ecx>, int a3, int a4, int a5, int a6, int a7)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 24);
  *a2 = result;
  return result;
}
