int __thiscall sub_55D2F0(unsigned int *this, int a2)
{
  unsigned int v2; // eax
  unsigned int v3; // eax

  v2 = *this;
  if ( a2 )
    v3 = v2 | 0x80;
  else
    v3 = v2 & 0xFFFFFF7F;
  *this = v3;
  return DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, (int)this, this[1], 1);
}

