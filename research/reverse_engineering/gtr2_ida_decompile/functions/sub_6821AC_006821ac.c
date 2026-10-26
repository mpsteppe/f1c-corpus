int __usercall sub_6821AC@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // esi
  int v9; // ecx
  int v10; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 188) + 88);
  v4 = v3 + 12 * a3;
  v5 = v3 + 12 * a2;
  v6 = *(_DWORD *)(v4 + 4);
  v7 = *(_DWORD *)(v5 + 4);
  if ( v6 < v7 )
    return -1;
  if ( v6 > v7 )
    return 1;
  v9 = *(_DWORD *)(v4 + 8);
  v10 = *(_DWORD *)(v5 + 8);
  if ( v9 < v10 )
    return -1;
  return v9 > v10;
}
