// positive sp value has been detected, the output may be wrong!
int __userpurge sub_5BEAB8@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        double a5@<st0>,
        char *a6,
        const char *a7,
        int a8,
        int a9,
        int a10)
{
  bool v10; // cf
  bool v11; // of

  v10 = __CFADD__((_BYTE)a1, BYTE1(a1));
  BYTE1(a1) += a1;
  v11 = __OFSUB__(*(_DWORD *)(a3 - 93), v10 - 99);
  *(_DWORD *)(a3 - 93) -= v10 - 99;
  if ( v11 )
    return sprintf(a6, a7, a8, a9, a10);
  *(_QWORD *)(a3 + 1942449165) = (__int64)a5;
  *(_DWORD *)(a2 + 2967785) += a1;
  *(_DWORD *)(a4 + 1) |= a2;
  return a2 != -1;
}
