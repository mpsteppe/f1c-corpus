// f1c  0x004c8d80  size=16
int sub_4C8D80()
{
  int result; // eax

  if ( dword_8AC4C4 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C4 + 16))(dword_8AC4C4);
  return result;
}
