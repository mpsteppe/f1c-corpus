int __userpurge sub_540CA1@<eax>(int result@<eax>, int a2@<edx>, int a3@<ecx>, int a4)
{
  *(_DWORD *)(a3 + 5088) = result;
  *(_DWORD *)(a3 + 5084) = a2;
  return result;
}

