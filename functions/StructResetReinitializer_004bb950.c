int __thiscall sub_4BB950(int this)
{
  _BYTE *v2; // ecx
  int v3; // edx
  int i; // eax
  int result; // eax

  if ( *(_DWORD *)(this + 140) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 140));
    *(_DWORD *)(this + 140) = 0;
  }
  if ( *(_DWORD *)(this + 144) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 144));
    *(_DWORD *)(this + 144) = 0;
  }
  v2 = *(_BYTE **)(this + 148);
  *(_DWORD *)(this + 152) = 0;
  if ( v2 )
  {
    v3 = *(_DWORD *)(this + 8);
    for ( i = 0; i < v3; ++i )
    {
      if ( v2[i] == 1 )
        ++*(_DWORD *)(this + 152);
    }
    FreeWrapper_7bcf(v2);
    *(_DWORD *)(this + 148) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 12) = 2;
  *(_DWORD *)(this + 20) = -1082130432;
  *(_DWORD *)(this + 24) = -1082130432;
  *(_DWORD *)(this + 28) = -1082130432;
  *(_DWORD *)(this + 32) = -1082130432;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_DWORD *)(this + 104) = -1082130432;
  *(_DWORD *)(this + 108) = -1082130432;
  *(_DWORD *)(this + 112) = -1082130432;
  *(_DWORD *)(this + 116) = -1082130432;
  *(_DWORD *)(this + 120) = -1082130432;
  *(_DWORD *)(this + 124) = -1082130432;
  *(_DWORD *)(this + 128) = -1082130432;
  result = -1;
  *(_DWORD *)(this + 132) = 0;
  *(_DWORD *)(this + 136) = 0;
  *(_DWORD *)(this + 156) = 0;
  *(_DWORD *)(this + 160) = 0;
  *(_BYTE *)(this + 168) = 0;
  *(_DWORD *)(this + 172) = 0;
  *(_DWORD *)(this + 176) = 0;
  *(_BYTE *)(this + 180) = 0;
  *(_DWORD *)(this + 184) = 0;
  *(_DWORD *)(this + 196) = 0;
  *(_DWORD *)(this + 200) = 0;
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 208) = 0;
  *(_BYTE *)(this + 212) = 0;
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 188) = -1;
  *(_DWORD *)(this + 192) = -1;
  *(_DWORD *)(this + 216) = -1;
  memset((void *)(this + 224), 0xFFu, 0x28u);
  return result;
}
