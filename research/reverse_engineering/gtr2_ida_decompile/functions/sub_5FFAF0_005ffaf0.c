int __userpurge sub_5FFAF0@<eax>(
        int *a1@<ecx>,
        __int32 a2@<ebx>,
        int a3@<edi>,
        int a4,
        int a5,
        _DWORD *a6,
        float a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int *v12; // eax
  int *v13; // eax

  if ( (*(_BYTE *)a1 & 1) == 0 )
  {
    if ( sub_5FF750(a1, a2, a3, a4, a5, a6, a7, a8, a11) )
      return -1;
    a1[60] = a9;
    if ( !a9 )
      a1[60] = 64;
    a1[61] = a10;
    if ( !a10 )
      a1[61] = 64;
    a11 = 0;
    sub_5E2B30(a1 + 60, a1 + 61, &a11, dword_FB272C - 1 < 0 ? 0 : dword_FB272C - 1);
    v12 = (int *)operator new(0x1E4u);
    v13 = v12 ? sub_5E38B0(v12) : 0;
    a1[67] = (int)v13;
    if ( sub_5FEB60(a1, 0) )
      return -1;
    *a1 |= 5u;
  }
  return 0;
}
