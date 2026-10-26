int __stdcall sub_67377F(int a1, _DWORD *a2)
{
  unsigned int v3; // eax
  _DWORD *v4; // ecx
  int v5; // edi
  int v6; // eax

  if ( !a2 )
    return -2005530516;
  v3 = *(_DWORD *)(a1 + 12);
  if ( v3 < 0x1C )
    return -2005529767;
  v4 = *(_DWORD **)(a1 + 8);
  if ( *v4 < 0x1Cu || v4[1] >= v3 )
    return -2005529767;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  v5 = v4[1];
  if ( v5 )
    v6 = v5 + *(_DWORD *)(a1 + 8);
  else
    v6 = 0;
  *a2 = v6;
  a2[1] = v4[2];
  a2[2] = v4[3];
  return 0;
}
