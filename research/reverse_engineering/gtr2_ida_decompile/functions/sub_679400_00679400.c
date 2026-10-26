int __userpurge sub_679400@<eax>(_DWORD *a1@<edi>, _DWORD *a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int i; // eax
  unsigned int v6; // ecx
  unsigned int j; // edi
  int v8; // eax
  int v9; // eax

  v2 = a2[5];
  if ( v2 == 101 || v2 == 102 )
  {
    if ( a2[58] < a2[8] )
    {
      v4 = *a2;
      *(_DWORD *)(v4 + 20) = 67;
      (*(void (__stdcall **)(_DWORD *))v4)(a2);
    }
    (*(void (__stdcall **)(_DWORD *))(a2[85] + 8))(a2);
  }
  else if ( v2 != 103 )
  {
    v3 = *a2;
    *(_DWORD *)(v3 + 20) = 20;
    *(_DWORD *)(v3 + 24) = v2;
    (*(void (__stdcall **)(_DWORD *))v3)(a2);
  }
  for ( i = a2[85]; !*(_DWORD *)(i + 16); i = a2[85] )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD *))i)(a2, a1);
    v6 = a2[62];
    for ( j = 0; j < v6; ++j )
    {
      v8 = a2[2];
      if ( v8 )
      {
        *(_DWORD *)(v8 + 4) = j;
        *(_DWORD *)(v8 + 8) = v6;
        (*(void (__stdcall **)(_DWORD *))v8)(a2);
      }
      if ( !(*(int (__stdcall **)(_DWORD *, _DWORD))(a2[88] + 4))(a2, 0) )
      {
        v9 = *a2;
        *(_DWORD *)(v9 + 20) = 24;
        (*(void (__stdcall **)(_DWORD *))v9)(a2);
      }
      v6 = a2[62];
    }
    a1 = a2;
    (*(void (**)(void))(a2[85] + 8))();
  }
  (*(void (__stdcall **)(_DWORD *))(a2[89] + 12))(a2);
  (*(void (__stdcall **)(_DWORD *))(a2[6] + 16))(a2);
  return sub_6B5EE0(a2);
}
