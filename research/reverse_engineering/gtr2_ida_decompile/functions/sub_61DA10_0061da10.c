void __thiscall sub_61DA10(void *this)
{
  unsigned int v1; // kr00_4
  int v2; // ebx
  void *v3; // ebx
  _DWORD *v5; // eax
  int v6; // ecx
  char *v7; // eax
  char *v8; // ebx
  char *v9; // eax
  char *v10; // ebx
  char *v11; // eax
  char *v12; // ebx
  void (__thiscall *v13[4])(void *); // [esp+0h] [ebp-10h] BYREF

  v5 = (_DWORD *)*((_DWORD *)this + 1);
  *(_DWORD *)this = 0;
  if ( v5 )
  {
    v6 = *(v5 - 1);
    v13[0] = (void (__thiscall *)(void *))(v5 - 1);
    v1 = __readeflags();
    v2 = dword_16C6CB8 ^ dword_125D964;
    __writeeflags(v1);
    v3 = (void *)_InterlockedExchange((volatile __int32 *)v13, v2);
    `eh vector destructor iterator'(v5, 0x248u, v6, v13[0]);
    j__free(v3);
    *((_DWORD *)this + 1) = 0;
  }
  v7 = (char *)*((_DWORD *)this + 3);
  *((_DWORD *)this + 2) = 0;
  if ( v7 )
  {
    v8 = v7 - 4;
    `eh vector destructor iterator'(v7, 0x38u, *((_DWORD *)v7 - 1), (void (__thiscall *)(void *))sub_61CF50);
    j__free(v8);
    *((_DWORD *)this + 3) = 0;
  }
  v9 = (char *)*((_DWORD *)this + 5);
  *((_DWORD *)this + 4) = 0;
  if ( v9 )
  {
    v10 = v9 - 4;
    `eh vector destructor iterator'(v9, 0x38u, *((_DWORD *)v9 - 1), (void (__thiscall *)(void *))sub_61CF50);
    j__free(v10);
    *((_DWORD *)this + 5) = 0;
  }
  v11 = (char *)*((_DWORD *)this + 7);
  *((_DWORD *)this + 6) = 0;
  if ( v11 )
  {
    v12 = v11 - 4;
    `eh vector destructor iterator'(v11, 0x50u, *((_DWORD *)v11 - 1), (void (__thiscall *)(void *))sub_61CF50);
    j__free(v12);
    *((_DWORD *)this + 7) = 0;
  }
  if ( *((_DWORD *)this + 9) )
  {
    j__free(*((void **)this + 9));
    if ( *((_DWORD *)this + 10) )
      j__free(*((void **)this + 10));
    if ( *((_DWORD *)this + 11) )
      j__free(*((void **)this + 11));
  }
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  sub_61C300((void **)this + 13);
}
