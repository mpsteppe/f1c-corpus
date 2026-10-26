void __cdecl sub_557446(int a1)
{
  int v1; // edi

  v1 = *(_DWORD *)(a1 + 388);
  if ( *(_DWORD *)(v1 + 16) )
  {
    if ( *(_BYTE *)(a1 + 73) && sub_556E46(a1) )
      *(_DWORD *)(v1 + 12) = sub_556F29;
    else
      *(_DWORD *)(v1 + 12) = sub_556CE0;
  }
  *(_DWORD *)(a1 + 136) = 0;
}
