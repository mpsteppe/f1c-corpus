// f1c  0x004c8900  size=26
int __stdcall sub_4C8900(int a1)
{
  int result; // eax

  if ( dword_8AC4C8 )
    return (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_8AC4C8 + 28))(dword_8AC4C8, a1);
  return result;
}
