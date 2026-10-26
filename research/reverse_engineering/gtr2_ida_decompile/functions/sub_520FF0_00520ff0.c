int __thiscall sub_520FF0(_DWORD *this, int a2)
{
  int result; // eax

  if ( this[723237] )
    this[723239] = this[723238];
  else
    this[723239] = this[723214];
  this[723238] = a2;
  result = this[723239];
  this[723213] = a2;
  this[723214] = result;
  this[723237] = 2;
  return result;
}
