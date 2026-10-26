int __usercall sub_4B1A2A@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<esi>)
{
  *(_DWORD *)(a2 + 8 * a3 - 1) -= a1;
  return VTableInitWithDefaults_1a30(a1);
}

