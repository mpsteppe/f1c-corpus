int __thiscall sub_69FF6D(int this)
{
  int v1; // eax

  v1 = *(_DWORD *)(this + 200);
  *(_DWORD *)(this + 264) = v1;
  if ( v1 == -130304 )
  {
    *(_DWORD *)(this + 108) |= 0x40200100u;
    *(_WORD *)(this + 112) |= 0xFE4u;
    *(_DWORD *)(this + 48) = 1;
    *(_DWORD *)(this + 76) = 4;
LABEL_9:
    *(_DWORD *)(this + 96) = 16;
    *(_DWORD *)(this + 64) = 16;
    *(_DWORD *)(this + 84) = 8;
    *(_DWORD *)(this + 92) = 4;
    goto LABEL_10;
  }
  if ( v1 != -130049 )
  {
    if ( v1 != -64768 && v1 != -64513 )
    {
      sub_686791(this, 0, 0, "internal error: no profile exists for this shader version");
      return -2147467259;
    }
    *(_DWORD *)(this + 48) = 0;
    *(_DWORD *)(this + 108) |= 0x402001A0u;
    *(_WORD *)(this + 112) |= 0x534u;
    *(_DWORD *)(this + 72) = 4;
    *(_DWORD *)(this + 76) = 16;
    goto LABEL_9;
  }
  *(_DWORD *)(this + 108) |= 0x40200100u;
  *(_WORD *)(this + 112) |= 0xFE4u;
  *(_DWORD *)(this + 48) = 1;
  *(_DWORD *)(this + 96) = 2048;
  *(_DWORD *)(this + 64) = 2048;
  *(_DWORD *)(this + 84) = 16;
  *(_DWORD *)(this + 92) = 4;
  *(_DWORD *)(this + 76) = 16;
LABEL_10:
  *(_BYTE *)(this + 113) |= 0x10u;
  *(_DWORD *)(this + 40) = 16;
  *(_DWORD *)(this + 68) = 16;
  *(_DWORD *)(this + 44) = 32;
  *(_DWORD *)(this + 56) = 0x2000;
  *(_DWORD *)(this + 104) = 255;
  *(_DWORD *)(this + 100) = 1;
  *(_DWORD *)(this + 88) = 24;
  *(_DWORD *)(this + 464) = 32;
  *(_DWORD *)(this + 340) = 1;
  return 0;
}
