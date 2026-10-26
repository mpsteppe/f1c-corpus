// Address: 0x0059bfb6
// Size: 13 bytes
// Name: sub_59BFB6
// Type: const char *__thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

const char *__thiscall sub_59BFB6(_DWORD *this)
{
  const char *result; // eax

  result = (const char *)this[1];
  if ( !result )
    return "Unknown exception";
  return result;
}
