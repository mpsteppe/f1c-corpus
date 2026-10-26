int __thiscall sub_50ED80(_DWORD *this, float a2)
{
  int result; // eax
  int v4; // esi
  int v5; // edi

  result = this[867];
  v4 = 0;
  if ( result > 0 )
  {
    v5 = (int)(this + 868);
    do
    {
      sub_508CB0(v5, a2);
      result = this[867];
      ++v4;
      v5 += 748;
    }
    while ( v4 < result );
  }
  return result;
}
