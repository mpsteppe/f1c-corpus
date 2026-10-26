int __thiscall sub_4E3A10(_DWORD *this, float a2)
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
      ConditionalRenderCall(v5, a2);
      result = this[746];
      ++v4;
      v5 += 748;
    }
    while ( v4 < result );
  }
  return result;
}

