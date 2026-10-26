int __usercall sub_4EF302@<eax>(int result@<eax>, int a2@<ecx>)
{
  *(_BYTE *)(result + 20) = a2;
  *(_DWORD *)(result + 24) = a2;
  *(_DWORD *)(result + 28) = 1120403456;
  return result;
}
