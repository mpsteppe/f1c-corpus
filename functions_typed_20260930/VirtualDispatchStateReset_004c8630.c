int __thiscall sub_4C8630(_BYTE *this)
{
  int result; // eax

  if ( dword_8AC4C8 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C8 + 12))(dword_8AC4C8);
  this[16] = 0;
  return result;
}

