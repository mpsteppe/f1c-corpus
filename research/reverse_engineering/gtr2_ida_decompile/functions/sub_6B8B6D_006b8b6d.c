int __stdcall sub_6B8B6D(int a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // eax

  if ( !a1 )
    return -2;
  v1 = *(_DWORD *)(a1 + 28);
  if ( !v1 )
    return -2;
  v2 = *(_DWORD *)(v1 + 4);
  if ( v2 != 42 && v2 != 113 && v2 != 666 )
    return -2;
  if ( *(_DWORD *)(v1 + 8) )
    (*(void (__stdcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), *(_DWORD *)(v1 + 8));
  v3 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v3 + 60) )
    (*(void (__stdcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), *(_DWORD *)(v3 + 60));
  v4 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v4 + 56) )
    (*(void (__stdcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), *(_DWORD *)(v4 + 56));
  v5 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v5 + 48) )
    (*(void (__stdcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), *(_DWORD *)(v5 + 48));
  (*(void (__stdcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), *(_DWORD *)(a1 + 28));
  *(_DWORD *)(a1 + 28) = 0;
  if ( v2 != 113 )
    return 0;
  return -3;
}
