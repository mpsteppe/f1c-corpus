char __userpurge sub_4AE978@<al>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        _DWORD *a4@<edi>,
        _DWORD *a5@<esi>,
        int a6,
        int a7)
{
  *a4 = *a5;
  LOBYTE(a1) = a1 & 8;
  *(_DWORD *)(a3 + 88) = a1;
  *(_DWORD *)(a3 + 92) = a2;
  return a1;
}
