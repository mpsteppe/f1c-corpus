int __thiscall sub_4DCA20(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx
  _DWORD *v5; // eax

  result = this[16];
  if ( result > 0 )
  {
    v4 = 0;
    v5 = this + 19;
    do
    {
      *(v5 - 2) = 0;
      *(v5 - 1) = 0;
      *v5 = 0;
      ++v4;
      v5 += 3;
    }
    while ( v4 < this[16] );
    result = sub_4C0AD0((_DWORD *)(*this + 16588), 0);
    this[16] = 0;
  }
  return result;
}
