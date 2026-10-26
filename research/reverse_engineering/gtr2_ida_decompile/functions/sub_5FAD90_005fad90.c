int __userpurge sub_5FAD90@<eax>(
        _DWORD *a1@<ecx>,
        __int32 a2@<ebp>,
        const char *a3,
        int a4,
        const char *a5,
        int a6,
        int a7,
        const char *a8,
        char a9)
{
  void *v10; // eax
  int v11; // esi
  int v13; // [esp+4h] [ebp-18h]

  v10 = operator new(0x32Cu);
  if ( v10 )
    v11 = sub_5FA9C0((int)v10, a2);
  else
    v11 = 0;
  sub_5F6580(v11, a3, a4, a5, a8);
  if ( (*(int (__thiscall **)(_DWORD *, int, _DWORD, int, int))(*a1 + 620))(a1, v11, 0, a6, a7) )
  {
    sub_5FABB0(v11);
    if ( v11 )
    {
      sub_5FAB30(v13);
      j__free((void *)v11);
    }
    return 0;
  }
  else
  {
    *(_DWORD *)(v11 + 344) = a1[2347];
    *(_BYTE *)(v11 + 808) = a9;
    sub_5FDFB0(v11, 0);
    return v11;
  }
}
