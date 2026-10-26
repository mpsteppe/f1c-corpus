int __thiscall std::string::assign(int this, void *Src, size_t Size)
{
  int v4; // eax

  if ( std::string::_Grow((_DWORD *)this, Size, 1) )
  {
    memcpy_0(*(void **)(this + 4), Src, Size);
    v4 = *(_DWORD *)(this + 4);
    *(_DWORD *)(this + 8) = Size;
    *(_BYTE *)(v4 + Size) = 0;
  }
  return this;
}
