int __userpurge sub_5076FE@<eax>(int a1@<ebp>, int a2)
{
  int v2; // ecx
  int v3; // esi
  int v4; // edi
  int v5; // ebx
  int v6; // eax

  SEHHandlerInit();
  v3 = v2;
  if ( *(_DWORD *)(v2 + 8) != *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) )
  {
    v4 = *(_DWORD *)(v2 + 4184);
    v5 = OperatorNewNhMallocWrapper(16 * v4);
    *(_DWORD *)(a1 - 16) = v5;
    v6 = 0;
    *(_DWORD *)(a1 - 4) = 0;
    if ( v5 )
    {
      sub_5008C2(v5, 16, v4, (int (__thiscall *)(int))sub_5007EC);
      v6 = v5;
    }
    *(_DWORD *)(v3 + 4172) = v6;
    if ( !v6 )
      return -2147024882;
    *(_DWORD *)(v3 + 4168) = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8);
  }
  return 0;
}
