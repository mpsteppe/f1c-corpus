int __thiscall sub_4E3C80(_DWORD *this)
{
  int v1; // edx
  int result; // eax

  v1 = this[5];
  result = -1;
  if ( v1 != -1 || this[6] != -1 || this[7] != -1 || this[8] != -1 )
    return v1 + this[3];
  return result;
}
