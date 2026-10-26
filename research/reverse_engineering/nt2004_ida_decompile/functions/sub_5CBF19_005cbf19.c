_UNKNOWN **__cdecl sub_5CBF19(LPVOID *lpMem)
{
  _UNKNOWN **result; // eax

  result = (_UNKNOWN **)VirtualFree(lpMem[4], 0, 0x8000u);
  if ( off_628628 == (_UNKNOWN **)lpMem )
  {
    result = (_UNKNOWN **)lpMem[1];
    off_628628 = result;
  }
  if ( lpMem == (LPVOID *)&off_626608 )
  {
    dword_626618 = -1;
  }
  else
  {
    *(_DWORD *)lpMem[1] = *lpMem;
    *((_DWORD *)*lpMem + 1) = lpMem[1];
    return (_UNKNOWN **)HeapFree(hHeap, 0, lpMem);
  }
  return result;
}
