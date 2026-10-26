// Address: 0x00405a30
// Size: 22 bytes
// Name: sub_405A30
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_405A30(_DWORD *this)
{
  int result; // eax

  result = this[22];
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    if ( result )
      return AIL_stop_sample(result);
  }
  return result;
}
