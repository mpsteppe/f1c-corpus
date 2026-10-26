int __stdcall sub_53D3A0(int a1)
{
  int result; // eax
  int v2; // ecx
  int v3; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 2156);
  if ( v2 )
    *(_DWORD *)(v2 + 2160) = *(_DWORD *)(a1 + 2160);
  v3 = *(_DWORD *)(a1 + 2160);
  if ( v3 )
    *(_DWORD *)(v3 + 2156) = *(_DWORD *)(a1 + 2156);
  if ( dword_8B8E20 == a1 )
    dword_8B8E20 = *(_DWORD *)(a1 + 2160);
  *(_DWORD *)(a1 + 2156) = 0;
  *(_DWORD *)(a1 + 2160) = 0;
  return result;
}

