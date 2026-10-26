int __thiscall sub_4EFA70(_BYTE *this)
{
  int result; // eax

  if ( dword_7D6BB4 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_7D6BB4 + 12))(dword_7D6BB4);
  this[20] = 0;
  return result;
}
