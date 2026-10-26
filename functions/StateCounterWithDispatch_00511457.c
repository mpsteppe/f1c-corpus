char __cdecl sub_511457(_DWORD *a1)
{
  if ( a1[94] || BitstreamTokenReader(a1) )
  {
    if ( a1[94] == *(_DWORD *)(a1[100] + 84) + 208 )
    {
      *(_DWORD *)(*a1 + 20) = 97;
      *(_DWORD *)(*a1 + 24) = *(_DWORD *)(a1[100] + 84);
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 3);
      a1[94] = 0;
LABEL_5:
      *(_DWORD *)(a1[100] + 84) = ((unsigned __int8)*(_DWORD *)(a1[100] + 84) + 1) & 7;
      return 1;
    }
    if ( (*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD))(a1[5] + 20))(a1, *(_DWORD *)(a1[100] + 84)) )
      goto LABEL_5;
  }
  return 0;
}
