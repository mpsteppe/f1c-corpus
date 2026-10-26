// positive sp value has been detected, the output may be wrong!
int __userpurge sub_57F0C8@<eax>(
        int a1@<ebx>,
        _WORD *a2@<ebp>,
        int a3@<edi>,
        const char *a4@<esi>,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18)
{
  unsigned int v18; // eax
  int v20; // [esp-38h] [ebp-38h]

  if ( a3 )
  {
    *(_WORD *)a3 = 2;
    *(_DWORD *)(a3 + 4) = htonl(0);
    *(_WORD *)(a3 + 2) = htons(0);
  }
  else
  {
    a3 = 0;
  }
  v18 = inet_addr(a4);
  if ( v18 == -1 )
  {
    (*(void (__thiscall **)(_WORD *, int))(*(_DWORD *)a2 + 92))(a2, a1);
    return 1;
  }
  else
  {
    *(_DWORD *)(a3 + 4) = v18;
    *(_WORD *)(a3 + 2) = a2[1160];
    NetworkPacketConstructor(*(_DWORD *)(a1 + 72), (_DWORD *)a3);
    ThreadSafeCallWithMutex(a1);
    return v20;
  }
}

