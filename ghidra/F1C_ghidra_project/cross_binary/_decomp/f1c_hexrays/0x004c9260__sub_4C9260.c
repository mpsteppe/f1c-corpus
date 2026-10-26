// f1c  0x004c9260  size=27
int __thiscall sub_4C9260(_DWORD *this)
{
  int v1; // edx
  int result; // eax
  int v3; // edx

  v1 = this[7];
  result = 0;
  if ( !v1 )
    return this[8];
  v3 = v1 - 1;
  if ( !v3 )
    return this[9];
  if ( v3 == 1 )
    return this[10];
  return result;
}
