int __cdecl _Mbrtowc(wchar_t *lpWideCharStr, const char *a2, size_t a3, mbstate_t *lpMultiByteStr, const _Cvtvec *a5)
{
  int v5; // ebx
  const _Cvtvec *v7; // [esp+24h] [ebp+18h]

  InterlockedIncrement(&dword_80151C);
  v5 = 0;
  if ( dword_801518 )
  {
    InterlockedDecrement(&dword_80151C);
    _lock(19);
    v5 = 1;
  }
  v7 = (const _Cvtvec *)_Mbrtowc_lk(lpWideCharStr, a2, a3, (LPCCH)lpMultiByteStr, (int)a5);
  if ( v5 )
    _unlock(19);
  else
    InterlockedDecrement(&dword_80151C);
  return (int)v7;
}
