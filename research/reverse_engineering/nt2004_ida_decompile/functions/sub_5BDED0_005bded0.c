unsigned int __fastcall sub_5BDED0(unsigned int a1)
{
  unsigned int v1; // edx
  unsigned int v2; // eax
  unsigned int result; // eax

  v1 = 16807 * HIWORD(a1);
  v2 = ((v1 & 0x7FFF) << 16) + 16807 * (unsigned __int16)a1;
  if ( v2 > 0x7FFFFFFF )
    v2 = (v2 & 0x7FFFFFFF) + 1;
  result = (v1 >> 15) + v2;
  if ( result > 0x7FFFFFFF )
    return (result & 0x7FFFFFFF) + 1;
  return result;
}
