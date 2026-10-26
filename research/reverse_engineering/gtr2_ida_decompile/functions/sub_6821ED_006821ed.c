int __stdcall sub_6821ED(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(a3 + 188) + 88);
  v4 = *(_DWORD *)(v3 + 12 * a1);
  v5 = *(_DWORD *)(v3 + 12 * a2);
  if ( v4 <= v5 )
    return v4 < v5;
  else
    return -1;
}
