// Address: 0x0057ef80
// Size: 23 bytes
// Name: sub_57EF80
// Type: int __stdcall(int (__thiscall ***)(_DWORD, int))
// Source: IDA Hex-Rays decompilation

int __stdcall sub_57EF80(int (__thiscall ***a1)(_DWORD, int))
{
  int result; // eax

  if ( a1 )
    return (**a1)(a1, 1);
  return result;
}
