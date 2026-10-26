LPVOID __cdecl sub_58A973(unsigned int a1)
{
  LPVOID result; // eax
  SIZE_T v2; // esi
  int v3; // eax
  SIZE_T v4; // eax
  void *v5; // [esp+Ch] [ebp-1Ch]
  void *v6; // [esp+Ch] [ebp-1Ch]

  if ( dword_8D4908 == 3 )
  {
    if ( a1 <= dword_8D4900 )
    {
      sub_58DFEA(9);
      v5 = (void *)sub_59416F(a1);
      sub_58E04B(9);
      result = v5;
      if ( v5 )
        return result;
    }
    goto LABEL_12;
  }
  if ( dword_8D4908 != 2 )
  {
LABEL_12:
    v3 = a1;
    if ( !a1 )
      v3 = 1;
    v4 = v3 + 15;
    LOBYTE(v4) = v4 & 0xF0;
    return HeapAlloc(hHeap, 0, v4);
  }
  if ( a1 )
    v2 = (a1 + 15) & 0xFFFFFFF0;
  else
    v2 = 16;
  if ( v2 > dword_5E998C )
    return HeapAlloc(hHeap, 0, v2);
  sub_58DFEA(9);
  v6 = (void *)sub_594C12(v2 >> 4);
  sub_58E04B(9);
  result = v6;
  if ( !v6 )
    return HeapAlloc(hHeap, 0, v2);
  return result;
}
