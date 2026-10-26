// Address: 0x00409f40
// Size: 17 bytes
// Name: sub_409F40
// Type: int __thiscall(void *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_409F40(void *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 24))(this);
  if ( result )
    return (*(int (__thiscall **)(int))(*(_DWORD *)result + 28))(result);
  return result;
}
