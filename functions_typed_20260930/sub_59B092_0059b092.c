int __cdecl sub_59B092(LPWSTR lpWideCharStr, LPCCH a2, int a3, LPCCH lpMultiByteStr, int a5)
{
  int v5; // ebx
  int v7; // [esp+24h] [ebp+18h]

  InterlockedIncrement(&dword_8D5A5C);
  v5 = 0;
  if ( dword_8D5A58 )
  {
    InterlockedDecrement(&dword_8D5A5C);
    CriticalSectionLazyInitEnter(19);
    v5 = 1;
  }
  v7 = sub_59B0F5(lpWideCharStr, a2, a3, lpMultiByteStr, a5);
  if ( v5 )
    CritSectLeave(19);
  else
    InterlockedDecrement(&dword_8D5A5C);
  return v7;
}

