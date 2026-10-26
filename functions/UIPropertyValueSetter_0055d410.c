int __thiscall sub_55D410(int *this, int a2, int a3)
{
  int result; // eax

  switch ( a2 )
  {
    case 1:
      this[5] = a3;
      DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, (int)this, this[1], 2);
      break;
    case 2:
      this[9] = a3;
      DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, (int)this, this[1], 3);
      break;
    case 3:
      this[13] = a3;
      DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, (int)this, this[1], 4);
      break;
  }
  result = dword_8B8F28;
  *(_DWORD *)(dword_8B8F28 + 236) |= 0x800u;
  return result;
}
