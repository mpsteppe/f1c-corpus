// Address: 0x004a7040
// Size: 57 bytes
// Name: sub_4A7040
// Type: char __thiscall(_DWORD *this, int)
// Source: IDA Hex-Rays decompilation

char __thiscall sub_4A7040(_DWORD *this, int a2)
{
  const char *v2; // eax

  v2 = (const char *)this[1];
  if ( !v2 )
    v2 = &byte_5EA438;
  sub_566C30(a2, "%s=\"(%d, %d)\"", v2, this[5], this[6]);
  sub_566C30(a2, &word_5C30B4);
  return 0;
}
