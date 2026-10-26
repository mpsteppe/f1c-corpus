int __thiscall sub_4531A0(int this)
{
  int *v2; // edi
  int v3; // ebp
  _DWORD *v4; // eax
  int v5; // ecx

  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 636) = 17;
  memset((void *)(this + 4), 0, 0xCB8u);
  memset((void *)(this + 3260), 0, 0xC0u);
  *(_DWORD *)(this + 3592) = 0;
  *(_DWORD *)(this + 4220) = 17;
  memset((void *)(this + 3464), 0, 0x3FCu);
  *(_DWORD *)(this + 4612) = 0;
  *(_DWORD *)(this + 5240) = 17;
  memset((void *)(this + 4484), 0, 0x3FCu);
  memset((void *)(this + 5504), 0, 0x590u);
  v2 = (int *)(this + 6944);
  v3 = 44;
  do
  {
    StructInitWithFixedValues(v2);
    v2 += 11;
    --v3;
  }
  while ( v3 );
  v4 = (_DWORD *)(this + 8880);
  v5 = 44;
  do
  {
    *v4 = 0;
    v4[1] = -1;
    v4 += 2;
    --v5;
  }
  while ( v5 );
  *(_DWORD *)(this + 3456) = 0;
  *(_DWORD *)(this + 9232) = 0;
  *(_DWORD *)(this + 9236) = 0;
  *(_DWORD *)(this + 9240) = 0;
  *(_DWORD *)(this + 9244) = 0;
  *(_DWORD *)(this + 9248) = 0;
  *(_BYTE *)(this + 9256) = 0;
  *(_BYTE *)(this + 3452) = 1;
  *(_DWORD *)(this + 9252) = -2;
  *(_DWORD *)(this + 5504) = this;
  return this;
}

