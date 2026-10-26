// Address: 0x0051eb5a
// Size: 20 bytes
// Name: sub_51EB5A
// Type: int __cdecl(int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_51EB5A(int a1)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 45;
  return (**(int (__cdecl ***)(int))a1)(a1);
}
