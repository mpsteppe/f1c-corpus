int __thiscall sub_40DAC0(_DWORD *this)
{
  int result; // eax

  result = this[3];
  if ( result )
    return (*(int (__thiscall **)(int))(*(_DWORD *)(this[3] + 272 * this[5]) + 28))(272 * this[5] + this[3]);
  return result;
}
