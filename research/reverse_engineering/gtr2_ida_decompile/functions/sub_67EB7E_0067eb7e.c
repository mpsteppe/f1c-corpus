int __thiscall sub_67EB7E(_DWORD *this, int a2, SIZE_T dwSize)
{
  int v4; // edx
  SIZE_T v5; // ecx
  unsigned int v6; // edi
  bool v7; // cc
  SIZE_T v8; // ebx
  int v9; // eax
  unsigned int v11; // ecx
  _DWORD *lpAddress; // [esp+Ch] [ebp-4h]
  SIZE_T dwSizea; // [esp+1Ch] [ebp+Ch]

  v4 = this[2];
  v5 = ~(dwSize - 1);
  v6 = a2 + (v5 & (dwSize + v4 - 1));
  if ( v6 <= this[4] )
  {
    v11 = this[3];
    if ( v6 <= v11 )
      goto LABEL_9;
    v8 = ~(this[1] - 1) & (this[1] + v6 - 1);
    if ( !VirtualAlloc((LPVOID)(v11 + *this), v8 - v11, 0x1000u, 4u) )
      return 0;
LABEL_8:
    this[3] = v8;
LABEL_9:
    v9 = *this - a2;
    this[2] = v6;
    return v6 + v9;
  }
  v6 = a2 + (v5 & (dwSize + 3));
  dwSizea = this[5];
  if ( v6 > dwSizea )
  {
    do
    {
      v7 = v6 <= 2 * dwSizea;
      dwSizea *= 2;
    }
    while ( !v7 );
  }
  lpAddress = VirtualAlloc(0, dwSizea, 0x2000u, 4u);
  if ( !lpAddress )
    return 0;
  v8 = ~(this[1] - 1) & (this[1] + v6 - 1);
  if ( VirtualAlloc(lpAddress, v8, 0x1000u, 4u) )
  {
    *lpAddress = *this;
    *this = lpAddress;
    this[4] = dwSizea;
    goto LABEL_8;
  }
  VirtualFree(lpAddress, 0, 0x8000u);
  return 0;
}
