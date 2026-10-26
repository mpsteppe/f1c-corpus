// f1c  0x00515f0e  size=21
int __usercall sub_515F0E@<eax>(int a1@<eax>, int a2@<edx>)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 53;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
  return (**(int (__cdecl ***)(int))a1)(a1);
}
