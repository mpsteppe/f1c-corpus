void __usercall sub_459270(int a1@<ecx>, void (__thiscall *a2)(void *)@<ebp>)
{
  _DWORD *v3; // eax
  int v4; // ecx
  char *v5; // edi
  void **v6; // ecx
  void **v7; // ecx
  unsigned int v8; // kr00_4
  int v9; // ebp
  void (__thiscall *v10[4])(void *); // [esp+0h] [ebp-10h] BYREF

  v3 = *(_DWORD **)(a1 + 8);
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)a1 = 0;
  if ( v3 )
  {
    v4 = *(v3 - 1);
    v5 = (char *)(v3 - 1);
    v10[0] = a2;
    v8 = __readeflags();
    v9 = dword_16C6DD4 ^ dword_16E6D14;
    __writeeflags(v8);
    _InterlockedExchange((volatile __int32 *)v10, v9);
    `eh vector destructor iterator'(v3, 0x20u, v4, v10[0]);
    j_j__free(v5);
    *(_DWORD *)(a1 + 8) = 0;
  }
  v6 = *(void ***)(a1 + 12);
  if ( v6 )
  {
    sub_4584E0(v6);
    j__free(*(void **)(a1 + 12));
    *(_DWORD *)(a1 + 12) = 0;
  }
  v7 = *(void ***)(a1 + 16);
  if ( v7 )
  {
    sub_4584E0(v7);
    j__free(*(void **)(a1 + 16));
    *(_DWORD *)(a1 + 16) = 0;
  }
}
