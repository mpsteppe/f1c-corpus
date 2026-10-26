// positive sp value has been detected, the output may be wrong!
int __usercall sub_416155@<eax>(int a1@<eax>, _DWORD *a2@<ebx>, int a3@<edi>, _DWORD *a4@<esi>)
{
  a4[36] = *(_DWORD *)(a1 + 44);
  if ( ((int (__thiscall *)(int))sub_5C3D80)(a3) )
    JUMPOUT(0x4160E5);
  *a4 = *a2;
  return ((int (*)(void))off_16C9650)();
}
