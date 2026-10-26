int __thiscall sub_61E060(int *this, double a2)
{
  int result; // eax
  int v4; // edi
  int v5; // ebx

  result = *this;
  v4 = 0;
  if ( *this > 0 )
  {
    v5 = 0;
    do
    {
      sub_619590(v5 + this[1], a2);
      result = *this;
      ++v4;
      v5 += 584;
    }
    while ( v4 < *this );
  }
  return result;
}
