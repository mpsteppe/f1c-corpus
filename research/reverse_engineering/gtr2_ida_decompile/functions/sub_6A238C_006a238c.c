int __thiscall sub_6A238C(int this)
{
  int v1; // edx
  int v2; // eax
  unsigned int v3; // eax

  v1 = *(_DWORD *)(this + 200);
  v2 = *(_DWORD *)(this + 108);
  *(_DWORD *)(this + 48) = 0;
  *(_BYTE *)(this + 205) |= 1u;
  *(_DWORD *)(this + 112) |= 8u;
  *(_DWORD *)(this + 264) = v1;
  v3 = v2 & 0xE98ED354 | 0x16712C8A;
  *(_DWORD *)(this + 40) = 2;
  *(_DWORD *)(this + 44) = 24;
  *(_DWORD *)(this + 56) = 8;
  *(_DWORD *)(this + 72) = 1;
  *(_DWORD *)(this + 100) = 64;
  *(_DWORD *)(this + 108) = v3;
  if ( (unsigned __int16)v1 == 260 )
  {
    *(_DWORD *)(this + 80) = 0;
    *(_DWORD *)(this + 60) = 6;
    *(_DWORD *)(this + 68) = 8;
    *(_DWORD *)(this + 76) = 6;
    *(_DWORD *)(this + 108) = v3 & 0xFF712FCB | 0xD010;
  }
  else
  {
    *(_DWORD *)(this + 60) = 4;
    *(_DWORD *)(this + 68) = 6;
    *(_DWORD *)(this + 76) = 4;
    *(_DWORD *)(this + 108) = v3 & 0xFFFD2FFF | (((unsigned __int16)v1 == 257) << 17) | 0x208C0014;
    *(_DWORD *)(this + 80) = 2;
  }
  return 0;
}
