// f1c  0x004e39d0  size=64
int __thiscall sub_4E39D0(_DWORD *this, float a2)
{
  int result; // eax
  int v4; // esi
  int v5; // edi

  result = this[746];
  v4 = 0;
  if ( result > 0 )
  {
    v5 = (int)(this + 747);
    do
    {
      sub_4DF030(v5, a2);
      result = this[746];
      ++v4;
      v5 += 748;
    }
    while ( v4 < result );
  }
  return result;
}
