// f1c  0x004998c0  size=22
bool __thiscall sub_4998C0(_DWORD *this)
{
  int v1; // eax

  v1 = this[5];
  if ( v1 )
    this[5] = *(_DWORD *)(v1 + 72);
  return this[5] != 0;
}
