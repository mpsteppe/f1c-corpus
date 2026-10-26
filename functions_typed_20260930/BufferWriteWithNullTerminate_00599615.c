_DWORD *__thiscall sub_599615(_DWORD *this, _BYTE *a2, unsigned int a3)
{
  int v4; // eax

  if ( sub_599560(this, a3, 1) )
  {
    MemoryCopy_cc00(this[1], a2, a3);
    v4 = this[1];
    this[2] = a3;
    *(_BYTE *)(v4 + a3) = 0;
  }
  return this;
}

