// Address: 0x004d7960
// Size: 149 bytes
// Name: sub_4D7960
// Type: int __thiscall(int *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4D7960(int *this)
{
  int result; // eax
  const CHAR *v3; // eax
  const char *v4; // eax
  _BYTE v5[256]; // [esp+4h] [ebp-100h] BYREF

  result = *this;
  if ( *this > 0 )
  {
    if ( result > 2 )
      *this = 2;
    if ( this[1] )
      return sub_5887B1(this[1], "\nTRACE LEVEL = %d", *this);
    v3 = dword_5EC438;
    if ( !dword_5EC438 )
      v3 = &byte_5EA438;
    sub_589671(v3);
    v4 = dword_5EC438;
    if ( !dword_5EC438 )
      v4 = &byte_5EA438;
    sub_58815F(v5, "%strace.txt", v4);
    result = sub_587DB0(v5, aW);
    this[1] = result;
    if ( result )
      return sub_5887B1(this[1], "\nTRACE LEVEL = %d", *this);
    else
      *this = 0;
  }
  return result;
}
