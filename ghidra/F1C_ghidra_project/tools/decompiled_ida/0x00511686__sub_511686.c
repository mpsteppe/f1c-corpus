// Address: 0x00511686
// Size: 29 bytes
// Name: sub_511686
// Type: int __cdecl(int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_511686(int a1)
{
  _BYTE v2[200]; // [esp+0h] [ebp-C8h] BYREF

  return (*(int (__cdecl **)(int, _BYTE *))(*(_DWORD *)a1 + 12))(a1, v2);
}
