int __cdecl sub_593446(int a1, int a2, int a3, int a4, _DWORD *a5, int a6, void *a7, unsigned __int8 a8)
{
  int (__cdecl *v8)(int, int, int, int, _DWORD *, int, void *, _DWORD); // ecx

  if ( *a5 != 429065504 )
    SEHGuardedFunctionPointerCall();
  if ( (*(_BYTE *)(a1 + 4) & 0x66) != 0 )
  {
    if ( a5[1] )
    {
      if ( !a6 )
        SEHAwareVirtualCallDispatchLoop(a2, a4, a5, -1);
    }
  }
  else if ( a5[3] )
  {
    if ( *(_DWORD *)a1 == -529697949 && *(_DWORD *)(a1 + 20) > 0x19930520u )
    {
      v8 = *(int (__cdecl **)(int, int, int, int, _DWORD *, int, void *, _DWORD))(*(_DWORD *)(a1 + 28) + 8);
      if ( v8 )
        return v8(a1, a2, a3, a4, a5, a6, a7, a8);
    }
    sub_5934E1((PEXCEPTION_RECORD)a1, a2, a3, a4, a5, a8, a6, a7);
  }
  return 1;
}
