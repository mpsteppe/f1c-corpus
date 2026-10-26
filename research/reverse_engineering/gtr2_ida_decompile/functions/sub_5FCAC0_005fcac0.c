void __thiscall sub_5FCAC0(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // esi
  _DWORD *v4; // eax

  v2 = this[11];
  v3 = this[12];
  if ( v3 < v2 && a2 < v2 )
  {
    v4 = (_DWORD *)(this[13] + 132 * a2);
    if ( (*v4 & 0x100) == 0 )
    {
      v4[1] = v3;
      v4[32] = this[24] + ((this[12] * this[9]) << 6);
      *(_DWORD *)(this[14] + 4 * this[12]) = v4;
      *v4 |= 0x100u;
      ++this[12];
    }
  }
}
