// Address: 0x004b1e20
// Size: 149 bytes
// Name: sub_4B1E20
// Type: char __thiscall(_DWORD *this, int)
// Source: IDA Hex-Rays decompilation

char __thiscall sub_4B1E20(_DWORD *this, int a2)
{
  const char *v3; // eax
  const char *v4; // eax
  char v6[256]; // [esp+Ch] [ebp-100h] BYREF

  v6[0] = 0;
  sub_4A1A00(v6, this + 5);
  v3 = (const char *)this[1];
  if ( !v3 )
    v3 = &byte_5EA438;
  sub_566C30(a2, "%s=\"%s\"", v3, v6);
  v4 = (const char *)this[3];
  if ( !v4 )
    v4 = &byte_5EA438;
  if ( strlen(v4) )
    sub_566C30(a2, " // %s", (const char *)this[3]);
  sub_566C30(a2, &word_5C30B4);
  return 0;
}
