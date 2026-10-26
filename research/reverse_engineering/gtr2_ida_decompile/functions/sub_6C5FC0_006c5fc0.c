int __thiscall sub_6C5FC0(_DWORD *this)
{
  unsigned int v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax

  v1 = 0;
  v2 = 0;
  if ( !this[3] )
    return 0;
  do
  {
    v3 = this[6];
    this[63] = v1;
    v4 = *(_DWORD *)(v3 + 4 * v1);
    this[64] = v4;
    v5 = *(_DWORD *)v4 & 0xFFF00000;
    if ( v5 )
    {
      v6 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v4 + 8));
      switch ( v5 )
      {
        case 0x60500000u:
        case 0x60700000u:
        case 0x60800000u:
        case 0x60900000u:
        case 0x60600000u:
        case 0x60000000u:
        case 0x60200000u:
        case 0x60300000u:
        case 0x60400000u:
        case 0x60100000u:
          if ( (*(_BYTE *)(v6 + 62) & 0xC0) != 0 )
            v2 = 1;
          *(_DWORD *)(v6 + 60) = 0x200000;
          break;
        case 0x60A00000u:
        case 0x60C00000u:
        case 0x60D00000u:
        case 0x60E00000u:
        case 0x60B00000u:
          if ( (*(_BYTE *)(v6 + 62) & 0xA0) != 0 )
            v2 = 1;
          *(_DWORD *)(v6 + 60) = 0x400000;
          break;
        case 0x60F00000u:
        case 0x61100000u:
        case 0x61200000u:
        case 0x61300000u:
        case 0x61000000u:
          if ( (*(_BYTE *)(v6 + 62) & 0x60) != 0 )
            v2 = 1;
          *(_DWORD *)(v6 + 60) = &byte_800000;
          break;
      }
    }
    ++v1;
  }
  while ( v1 < this[3] );
  if ( !v2 )
    return 0;
  sub_686791((int)this, 0, 4539, "sampler mismatch: sampler used inconsistently");
  return -2147467259;
}
