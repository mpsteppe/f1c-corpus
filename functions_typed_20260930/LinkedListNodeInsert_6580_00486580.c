int __thiscall sub_486580(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi

  result = OperatorNewNhMallocWrapper(8);
  v4 = result;
  if ( result )
  {
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 4) = -1;
    result = StringCopyWithBufferRealloc(a2);
  }
  else
  {
    v4 = 0;
  }
  if ( v4 )
  {
    result = OperatorNewNhMallocWrapper(12);
    if ( result )
    {
      *(_DWORD *)result = v4;
      *(_DWORD *)(result + 4) = 0;
      *(_BYTE *)(result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( this[21] )
    {
      *(_DWORD *)(this[22] + 4) = result;
    }
    else
    {
      this[21] = result;
      this[23] = result;
    }
    this[22] = result;
    ++this[24];
  }
  return result;
}

