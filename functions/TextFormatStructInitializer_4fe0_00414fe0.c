int __thiscall sub_414FE0(int this)
{
  int v2; // edi
  int result; // eax

  StringCopyWithBufferRealloc(&byte_5EA438);
  *(_DWORD *)(this + 8) = -1;
  StringCopyWithBufferRealloc(&byte_5EA438);
  *(_DWORD *)(this + 20) = -1;
  *(_DWORD *)(this + 24) = -1;
  *(_BYTE *)(this + 28) = 0;
  StringCopyWithBufferRealloc(&byte_5EA438);
  *(_DWORD *)(this + 40) = -1;
  *(_DWORD *)(this + 44) = -1;
  *(_BYTE *)(this + 48) = 0;
  v2 = this + 52;
  StringCopyWithBufferRealloc(&byte_5EA438);
  this += 72;
  *(_DWORD *)(v2 + 8) = -1;
  *(_DWORD *)(v2 + 12) = -1;
  *(_BYTE *)(v2 + 16) = 0;
  result = StringCopyWithBufferRealloc(&byte_5EA438);
  *(_DWORD *)(this + 8) = -1;
  *(_DWORD *)(this + 12) = -1;
  *(_BYTE *)(this + 16) = 0;
  return result;
}
