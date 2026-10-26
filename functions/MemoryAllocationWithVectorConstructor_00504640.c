int __usercall sub_504640@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  unsigned int v8; // ebx
  int v9; // eax
  unsigned int v10; // eax
  unsigned int i; // edi

  SEHHandlerInit();
  v2 = v1;
  v3 = (_DWORD *)v1[1];
  v4 = (_DWORD *)*v1;
  v5 = v3[1046];
  if ( v5 != v4[1046] || v3[1047] != v4[1047] || v3[1048] != v4[1048] )
    return -2147467259;
  v6 = OperatorNewNhMallocWrapper(16 * v5);
  v7 = v6;
  *(_DWORD *)(a1 - 16) = v6;
  *(_DWORD *)(a1 - 4) = 0;
  if ( v6 )
  {
    sub_5008C2(v6, 16, v5, (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a1 - 16) = v7;
  }
  else
  {
    *(_DWORD *)(a1 - 16) = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  v8 = 0;
  if ( !*(_DWORD *)(a1 - 16) )
    return -2147467259;
  v9 = v2[1];
  if ( *(_DWORD *)(v9 + 4192) )
  {
    v10 = *(_DWORD *)(v9 + 4188);
    do
    {
      for ( i = 0; i < v10; ++i )
      {
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, _DWORD))(*(_DWORD *)*v2 + 4))(
          *v2,
          i,
          v8,
          *(_DWORD *)(a1 - 16));
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, _DWORD))(*(_DWORD *)v2[1] + 8))(
          v2[1],
          i,
          v8,
          *(_DWORD *)(a1 - 16));
        v10 = *(_DWORD *)(v2[1] + 4188);
      }
      ++v8;
    }
    while ( v8 < *(_DWORD *)(v2[1] + 4192) );
  }
  FreeWrapper_7bcf(*(LPVOID *)(a1 - 16));
  return 0;
}
