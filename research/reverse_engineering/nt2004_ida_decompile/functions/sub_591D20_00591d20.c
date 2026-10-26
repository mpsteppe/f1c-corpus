int __stdcall sub_591D20(int a1)
{
  int result; // eax
  int v2; // ecx
  int v3; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 500);
  if ( v2 )
    *(_DWORD *)(v2 + 504) = *(_DWORD *)(a1 + 504);
  v3 = *(_DWORD *)(a1 + 504);
  if ( v3 )
    *(_DWORD *)(v3 + 500) = *(_DWORD *)(a1 + 500);
  if ( dword_7E8E5C == a1 )
  {
    result = *(_DWORD *)(a1 + 504);
    dword_7E8E5C = result;
  }
  return result;
}
