int __thiscall sub_6B0DA4(int this)
{
  int v1; // edx
  int v2; // eax
  int v4; // eax
  int v5; // eax

  v1 = *(_DWORD *)(this + 200);
  *(_DWORD *)(this + 112) |= 0x40u;
  v2 = *(_DWORD *)(this + 112);
  *(_DWORD *)(this + 264) = v1;
  switch ( v1 )
  {
    case -130815:
      *(_BYTE *)(this + 111) |= 1u;
      *(_DWORD *)(this + 100) = 10;
      v4 = v2 | 0x2002;
      goto LABEL_10;
    case -130560:
      v4 = v2 | 2;
      *(_DWORD *)(this + 108) |= 0x200100u;
      *(_DWORD *)(this + 48) = 1;
      *(_DWORD *)(this + 96) = 16;
      *(_DWORD *)(this + 64) = 16;
      *(_DWORD *)(this + 104) = 255;
      *(_DWORD *)(this + 100) = 1;
      *(_DWORD *)(this + 84) = 8;
      *(_DWORD *)(this + 92) = 1;
LABEL_10:
      *(_DWORD *)(this + 44) = 12;
      break;
    case -130558:
      v4 = v2 | 4;
      *(_DWORD *)(this + 108) |= 0x40200100u;
      *(_DWORD *)(this + 44) = 13;
      *(_DWORD *)(this + 48) = 1;
      *(_DWORD *)(this + 96) = 16;
      *(_DWORD *)(this + 64) = 16;
      *(_DWORD *)(this + 104) = 255;
      *(_DWORD *)(this + 100) = 1;
      *(_DWORD *)(this + 84) = 8;
      *(_DWORD *)(this + 88) = 24;
      *(_DWORD *)(this + 92) = 1;
      *(_DWORD *)(this + 200) = -130559;
      break;
    case -130305:
      v4 = v2 | 4;
      *(_DWORD *)(this + 108) |= 0x40200100u;
      *(_DWORD *)(this + 44) = 32;
      *(_DWORD *)(this + 48) = 1;
      *(_DWORD *)(this + 96) = 2048;
      *(_DWORD *)(this + 64) = 2048;
      *(_DWORD *)(this + 104) = 255;
      *(_DWORD *)(this + 100) = 1;
      *(_DWORD *)(this + 84) = 16;
      *(_DWORD *)(this + 88) = 24;
      *(_DWORD *)(this + 92) = 4;
      break;
    default:
      sub_686791(this, 0, 0, "internal error: no profile exists for this vertex shader version");
      return -2147467259;
  }
  *(_DWORD *)(this + 108) |= 0x40u;
  *(_DWORD *)(this + 112) = v4;
  v5 = *(_DWORD *)(this + 44);
  *(_BYTE *)(this + 113) |= 3u;
  *(_DWORD *)(this + 464) = v5;
  *(_DWORD *)(this + 40) = 16;
  *(_DWORD *)(this + 56) = 0x2000;
  *(_DWORD *)(this + 68) = 16;
  return 0;
}
