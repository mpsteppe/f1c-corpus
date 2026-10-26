int __thiscall sub_405440(_DWORD *this)
{
  int result; // eax

  *this = -1;
  StringCopyWithBufferRealloc(&byte_5EA438);
  this[3] = 0;
  this[4] = -1;
  this[5] = 0;
  this[6] = 0;
  this[7] = -1;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  VirtualCleanup(this + 12);
  this[14] = 0;
  result = 0;
  memset(this + 17, 0, 0x2Cu);
  *((_BYTE *)this + 112) = 0;
  return result;
}

