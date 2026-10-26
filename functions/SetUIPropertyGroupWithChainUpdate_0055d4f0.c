int __thiscall sub_55D4F0(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // edx
  int result; // eax

  this[15] = a3;
  v4 = this[1];
  this[14] = a2;
  this[16] = a4;
  DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, (int)this, v4, 6);
  result = dword_8B8F28;
  *(_DWORD *)(dword_8B8F28 + 236) |= 0x800u;
  return result;
}
