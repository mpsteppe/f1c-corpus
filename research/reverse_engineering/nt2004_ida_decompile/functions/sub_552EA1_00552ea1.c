int __usercall sub_552EA1@<eax>(int a1@<eax>, int a2@<edx>)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 53;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
  return (**(int (__cdecl ***)(int))a1)(a1);
}
