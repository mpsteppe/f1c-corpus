_UNKNOWN **__cdecl sub_594A5E(LPVOID *lpMem)
{
  _UNKNOWN **result; // eax

  result = (_UNKNOWN **)VirtualFree(lpMem[4], 0, 0x8000u);
  if ( off_5E9988 == (_UNKNOWN **)lpMem )
  {
    result = (_UNKNOWN **)lpMem[1];
    off_5E9988 = result;
  }
  if ( lpMem == (LPVOID *)&off_5E7968 )
  {
    dword_5E7978 = -1;
  }
  else
  {
    *(_DWORD *)lpMem[1] = *lpMem;
    *((_DWORD *)*lpMem + 1) = lpMem[1];
    return (_UNKNOWN **)HeapFree(hHeap, 0, lpMem);
  }
  return result;
}
