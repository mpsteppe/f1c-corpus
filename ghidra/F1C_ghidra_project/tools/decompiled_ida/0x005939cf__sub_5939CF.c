// Address: 0x005939cf
// Size: 42 bytes
// Name: sub_5939CF
// Type: BOOL __cdecl(_DWORD *)
// Source: IDA Hex-Rays decompilation

BOOL __cdecl sub_5939CF(_DWORD *a1)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)*a1;
  return *(_DWORD *)*a1 == -529697949 && v1[4] == 3 && v1[5] == 429065504 && !v1[7];
}
