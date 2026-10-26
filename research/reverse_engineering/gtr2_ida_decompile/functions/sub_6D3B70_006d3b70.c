int __stdcall sub_6D3B70(int *a1, int a2, int a3, int Offset, int a5)
{
  int v5; // eax
  int result; // eax
  int v7; // eax

  if ( fseek(*(FILE **)(a2 + 12), Offset, 0) )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 65;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  result = sub_6318A2(a3, 1, a5, *(_DWORD *)(a2 + 12));
  if ( result != a5 )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 64;
    return (*(int (__stdcall **)(int *))v7)(a1);
  }
  return result;
}
