int __cdecl sub_596030(LPSTR lpMultiByteStr, WCHAR WideCharStr)
{
  int v2; // ebx
  int WideCharStra; // [esp+18h] [ebp+Ch]

  InterlockedIncrement(&dword_8D5A5C);
  v2 = 0;
  if ( dword_8D5A58 )
  {
    InterlockedDecrement(&dword_8D5A5C);
    CriticalSectionLazyInitEnter(19);
    v2 = 1;
  }
  WideCharStra = sub_596089(lpMultiByteStr, WideCharStr);
  if ( v2 )
    CritSectLeave(19);
  else
    InterlockedDecrement(&dword_8D5A5C);
  return WideCharStra;
}

