// positive sp value has been detected, the output may be wrong!
int __usercall sub_4D82C4@<eax>(int a1@<edx>, char a2@<ch>, int a3@<esi>)
{
  *(_BYTE *)(a1 - 1) += a2;
  return ((int (__thiscall *)(int))loc_4D879C)(a3);
}

