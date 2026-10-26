int __usercall sub_4EC2E2@<eax>(int result@<eax>, int a2@<edx>, int a3@<ecx>)
{
  *(_DWORD *)(result + 28) = a2;
  *(_DWORD *)(result + 32) = a3;
  *(_WORD *)(result + 36) = a3;
  *(_DWORD *)(result + 40) = a2;
  return result;
}
