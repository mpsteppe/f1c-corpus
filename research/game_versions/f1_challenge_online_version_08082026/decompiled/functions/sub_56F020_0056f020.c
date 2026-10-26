int __thiscall sub_56F020(int *this, double a2)
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
      sub_569C10(v5 + this[1], a2);
      result = *this;
      ++v4;
      v5 += 580;
    }
    while ( v4 < *this );
  }
  return result;
}
