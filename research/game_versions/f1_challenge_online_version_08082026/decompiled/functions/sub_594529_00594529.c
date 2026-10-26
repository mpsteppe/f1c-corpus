int __cdecl sub_594529(_DWORD *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // edi
  _DWORD *v8; // eax

  v1 = a1[4];
  v2 = a1[2];
  v3 = 0;
  while ( v2 >= 0 )
  {
    v2 *= 2;
    ++v3;
  }
  v4 = 63;
  v5 = 516 * v3 + v1 + 324;
  do
  {
    *(_DWORD *)(v5 + 8) = v5;
    *(_DWORD *)(v5 + 4) = v5;
    v5 += 8;
    --v4;
  }
  while ( v4 );
  v6 = (_DWORD *)(a1[3] + (v3 << 15));
  if ( !VirtualAlloc(v6, 0x8000u, 0x1000u, 4u) )
    return -1;
  if ( v6 < v6 + 7168 )
  {
    v8 = v6 + 4;
    do
    {
      *(v8 - 2) = -1;
      v8[1019] = -1;
      *(v8 - 1) = 4080;
      *v8 = v8 + 1023;
      v8[1] = v8 - 1025;
      v8[1018] = 4080;
      v8 += 1024;
    }
    while ( v8 - 4 <= v6 + 7168 );
  }
  *(_DWORD *)(516 * v3 + v1 + 832) = v6 + 3;
  v6[5] = 516 * v3 + v1 + 828;
  *(_DWORD *)(516 * v3 + v1 + 836) = v6 + 7171;
  v6[7172] = 516 * v3 + v1 + 828;
  *(_DWORD *)(v1 + 4 * v3 + 68) = 0;
  *(_DWORD *)(v1 + 4 * v3 + 196) = 1;
  if ( (*(_BYTE *)(v1 + 67))++ == 0 )
    a1[1] |= 1u;
  a1[2] &= ~(0x80000000 >> v3);
  return v3;
}
