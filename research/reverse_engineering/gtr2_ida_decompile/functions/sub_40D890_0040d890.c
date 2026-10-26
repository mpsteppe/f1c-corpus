int __thiscall sub_40D890(_DWORD *this)
{
  int v1; // edx
  int result; // eax

  v1 = this[5];
  result = 0;
  if ( v1 >= 0 && v1 < this[4] )
    return this[3] + 164 * v1;
  return result;
}
