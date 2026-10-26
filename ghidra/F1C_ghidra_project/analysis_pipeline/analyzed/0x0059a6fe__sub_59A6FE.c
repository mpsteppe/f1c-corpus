// Address: 0x0059a6fe
// Size: 13 bytes
// Name: sub_59A6FE
// Type: void *__thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

void *__thiscall sub_59A6FE(_DWORD *this)
{
  void *result; // eax

  result = (void *)this[4];
  if ( !result )
    return &unk_5B9D34;
  return result;
}
