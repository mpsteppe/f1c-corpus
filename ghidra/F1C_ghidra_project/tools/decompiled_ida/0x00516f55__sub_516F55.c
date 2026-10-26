// Address: 0x00516f55
// Size: 33 bytes
// Name: sub_516F55
// Type: int __cdecl(int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_516F55(int a1)
{
  int result; // eax
  int v2; // esi

  result = a1;
  v2 = *(_DWORD *)(a1 + 380);
  if ( *(_BYTE *)(a1 + 74) )
    result = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 420) + 8))(a1);
  ++*(_DWORD *)(v2 + 12);
  return result;
}
