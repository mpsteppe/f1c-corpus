// Address: 0x00515ebc
// Size: 17 bytes
// Name: sub_515EBC
// Type: _DWORD *__cdecl(int)
// Source: IDA Hex-Rays decompilation

_DWORD *__cdecl sub_515EBC(int a1)
{
  _DWORD *result; // eax

  result = *(_DWORD **)(a1 + 396);
  *result = sub_515DF2;
  return result;
}
