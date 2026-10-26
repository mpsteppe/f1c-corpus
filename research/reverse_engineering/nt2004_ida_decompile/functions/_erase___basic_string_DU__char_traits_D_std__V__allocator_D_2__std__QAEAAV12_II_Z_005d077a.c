_DWORD *__thiscall std::string::erase(_DWORD *this, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // esi
  int v7; // eax

  if ( this[2] < a2 )
    std::_Xran();
  std::string::_Split(this);
  v4 = a3;
  v5 = this[2] - a2;
  if ( v5 < a3 )
    v4 = this[2] - a2;
  if ( v4 )
  {
    memcpy((void *)(a2 + this[1]), (const void *)(a2 + this[1] + v4), v5 - v4);
    v6 = this[2] - v4;
    if ( (unsigned __int8)std::string::_Grow(v6, 0) )
    {
      v7 = this[1];
      this[2] = v6;
      *(_BYTE *)(v6 + v7) = 0;
    }
  }
  return this;
}
