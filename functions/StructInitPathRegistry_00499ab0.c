_DWORD *__thiscall sub_499AB0(_DWORD *this, int a2, int a3)
{
  *this = 0;
  this[1] = -1;
  StringCopyWithBufferRealloc(a2);
  this[2] = a3;
  return this;
}
