int __thiscall sub_5BC0A0(int *this)
{
  int result; // eax
  int v3; // eax

  result = this[4];
  if ( result < this[1] )
  {
    do
    {
      result = this[7];
      if ( result <= 0 )
        break;
      v3 = sub_5BC080(this + 5);
      sub_5BBC20(this, v3);
      result = this[1];
    }
    while ( this[4] < result );
  }
  return result;
}
