int __usercall sub_58D6C1@<eax>(int a1@<eax>, _DWORD *a2@<edx>, int a3@<ecx>)
{
  int result; // eax

  LOBYTE(a3) = *(_BYTE *)(a1 + 9);
  result = 1;
  *a2 = a3;
  return result;
}
