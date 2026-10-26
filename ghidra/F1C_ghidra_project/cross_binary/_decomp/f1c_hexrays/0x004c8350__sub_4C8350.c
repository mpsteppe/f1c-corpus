// f1c  0x004c8350  size=92
int sub_4C8350()
{
  int result; // eax

  if ( dword_8AC4C8 )
  {
    result = (**(int (__thiscall ***)(int, int))dword_8AC4C8)(dword_8AC4C8, 1);
    dword_8AC4C8 = 0;
  }
  if ( dword_8AC4CC )
  {
    result = (**(int (__thiscall ***)(int, int))dword_8AC4CC)(dword_8AC4CC, 1);
    dword_8AC4CC = 0;
  }
  if ( dword_8AC4D0 )
  {
    result = (**(int (__thiscall ***)(int, int))dword_8AC4D0)(dword_8AC4D0, 1);
    dword_8AC4D0 = 0;
  }
  if ( dword_8AC4C4 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C4 + 12))(dword_8AC4C4);
  dword_8AC4C4 = 0;
  return result;
}
