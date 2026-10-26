int __thiscall sub_455760(int this)
{
  _DWORD *v2; // edi
  int v3; // ebp
  _DWORD *v4; // eax
  int v5; // ecx

  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 636) = 17;
  memset((void *)(this + 4), 0, 0xCBCu);
  memset((void *)(this + 3264), 0, 0xC4u);
  *(_DWORD *)(this + 3600) = 0;
  *(_DWORD *)(this + 4228) = 17;
  memset((void *)(this + 3472), 0, 0x3FCu);
  *(_DWORD *)(this + 4620) = 0;
  *(_DWORD *)(this + 5248) = 17;
  memset((void *)(this + 4492), 0, 0x3FCu);
  memset((void *)(this + 5512), 0, 0x590u);
  v2 = (_DWORD *)(this + 6952);
  v3 = 61;
  do
  {
    sub_454D30(v2);
    v2 += 11;
    --v3;
  }
  while ( v3 );
  v4 = (_DWORD *)(this + 9636);
  v5 = 61;
  do
  {
    *v4 = 0;
    v4[1] = -1;
    v4 += 2;
    --v5;
  }
  while ( v5 );
  *(_DWORD *)(this + 3464) = 0;
  *(_DWORD *)(this + 10124) = 0;
  *(_DWORD *)(this + 10128) = 0;
  *(_DWORD *)(this + 10132) = 0;
  *(_DWORD *)(this + 10136) = 0;
  *(_DWORD *)(this + 10140) = 0;
  *(_BYTE *)(this + 10148) = 0;
  *(_BYTE *)(this + 3460) = 1;
  *(_DWORD *)(this + 10144) = -2;
  *(_DWORD *)(this + 5512) = this;
  return this;
}
