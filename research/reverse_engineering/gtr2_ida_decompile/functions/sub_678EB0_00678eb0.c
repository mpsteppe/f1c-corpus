int __stdcall sub_678EB0(int *a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // eax

  if ( a1[105] || sub_6789F0(a1) )
  {
    v1 = a1[111];
    v2 = *(_DWORD *)(v1 + 20);
    if ( a1[105] == v2 + 208 )
    {
      v3 = *a1;
      *(_DWORD *)(v3 + 20) = 98;
      *(_DWORD *)(v3 + 24) = *(_DWORD *)(v1 + 20);
      (*(void (__stdcall **)(int *, int))(v3 + 4))(a1, 3);
      a1[105] = 0;
LABEL_5:
      *(_DWORD *)(a1[111] + 20) = ((unsigned __int8)*(_DWORD *)(a1[111] + 20) + 1) & 7;
      return 1;
    }
    if ( (*(int (__stdcall **)(int *, int))(a1[6] + 20))(a1, v2) )
      goto LABEL_5;
  }
  return 0;
}
