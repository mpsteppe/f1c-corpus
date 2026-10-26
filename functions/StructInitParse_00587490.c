_DWORD *__thiscall sub_587490(_DWORD *this, int a2)
{
  int v4; // [esp+4h] [ebp-4h] BYREF

  this[2] = 0;
  this[1] = 0;
  *this = 0;
  if ( (unsigned __int8)BufferQueryReturnPtrSizeIfValid(&v4, &a2) )
    MemcpyLikeWithRealloc(v4, a2);
  return this;
}
