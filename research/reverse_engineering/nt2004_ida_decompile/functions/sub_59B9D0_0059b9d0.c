int __thiscall sub_59B9D0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx

  if ( (this[5] & 0x8000000) != 0 )
  {
    v2 = 0;
    if ( (int)this[70] > 0 )
    {
      v3 = 0;
      do
      {
        sub_5A7DD0(v3 + this[71]);
        ++v2;
        v3 += 64;
      }
      while ( v2 < this[70] );
    }
    this[5] &= ~0x8000000u;
  }
  return 0;
}
