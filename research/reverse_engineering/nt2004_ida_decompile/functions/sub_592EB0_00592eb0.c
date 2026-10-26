int __stdcall sub_592EB0(int a1)
{
  int result; // eax
  int v2; // ecx
  int v3; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 28);
  if ( v2 )
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a1 + 32);
  v3 = *(_DWORD *)(a1 + 32);
  if ( v3 )
    *(_DWORD *)(v3 + 28) = *(_DWORD *)(a1 + 28);
  if ( dword_7E8D34 == a1 )
    dword_7E8D34 = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  return result;
}
