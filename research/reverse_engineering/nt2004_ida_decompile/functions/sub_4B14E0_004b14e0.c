int __thiscall sub_4B14E0(_DWORD *this)
{
  int result; // eax

  result = -1;
  if ( this[5] != -1 || this[6] != -1 || this[7] != -1 || this[8] != -1 )
    return this[1] + this[6];
  return result;
}
