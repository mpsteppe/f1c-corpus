// f1c  0x004b69d0  size=29
int __thiscall sub_4B69D0(_DWORD *this)
{
  int result; // eax
  int v2; // et2

  result = this[623];
  if ( result != this[622] )
  {
    v2 = (result + 1) % this[621];
    result = (result + 1) / this[621];
    this[623] = v2;
  }
  return result;
}
