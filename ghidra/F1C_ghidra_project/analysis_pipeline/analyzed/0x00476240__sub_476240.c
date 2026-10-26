// Address: 0x00476240
// Size: 13 bytes
// Name: sub_476240
// Type: char *__thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

char *__thiscall sub_476240(_DWORD *this)
{
  char *result; // eax

  result = (char *)this[16];
  if ( !result )
    return &byte_5EA438;
  return result;
}
