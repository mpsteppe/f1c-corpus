int __thiscall sub_534E70(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edx

  if ( this[15] )
    return -1;
  if ( this[1] )
    goto LABEL_8;
  *(_DWORD *)TLSOffsetGetter() = 0;
  v3 = ThreadSafeReadWrapper_803f(this[17], 1, 0x4000, this[16]);
  this[1] = v3;
  if ( v3 )
  {
    *this = this[17];
LABEL_8:
    --this[1];
    return *(unsigned __int8 *)(*this)++;
  }
  v4 = this[16];
  this[15] = 1;
  result = -1;
  if ( (*(_BYTE *)(v4 + 12) & 0x20) != 0 )
    this[14] = -1;
  return result;
}
