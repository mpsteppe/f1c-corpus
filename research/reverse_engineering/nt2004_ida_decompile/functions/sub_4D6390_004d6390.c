int __thiscall sub_4D6390(_DWORD *this)
{
  int result; // eax
  int v2; // et2

  result = this[333];
  if ( result != this[332] )
  {
    v2 = (result + 1) % this[331];
    result = (result + 1) / this[331];
    this[333] = v2;
  }
  return result;
}
