int __stdcall sub_53C630(int a1)
{
  int result; // eax
  int v2; // ecx
  int v3; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 484);
  if ( v2 )
    *(_DWORD *)(v2 + 488) = *(_DWORD *)(a1 + 488);
  v3 = *(_DWORD *)(a1 + 488);
  if ( v3 )
    *(_DWORD *)(v3 + 484) = *(_DWORD *)(a1 + 484);
  if ( dword_8B8F28 == a1 )
  {
    result = *(_DWORD *)(a1 + 488);
    dword_8B8F28 = result;
  }
  return result;
}

