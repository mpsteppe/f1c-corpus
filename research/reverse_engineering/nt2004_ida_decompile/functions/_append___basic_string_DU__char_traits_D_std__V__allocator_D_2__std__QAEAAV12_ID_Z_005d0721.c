_DWORD *__thiscall std::string::append(_DWORD *this, size_t Size, char a3)
{
  size_t v4; // edi
  int v5; // eax

  if ( -1 - this[2] <= Size )
    std::_Xlen();
  if ( Size )
  {
    v4 = this[2] + Size;
    if ( (unsigned __int8)std::string::_Grow(v4, 0) )
    {
      memset((void *)(this[2] + this[1]), a3, Size);
      v5 = this[1];
      this[2] = v4;
      *(_BYTE *)(v5 + v4) = 0;
    }
  }
  return this;
}
