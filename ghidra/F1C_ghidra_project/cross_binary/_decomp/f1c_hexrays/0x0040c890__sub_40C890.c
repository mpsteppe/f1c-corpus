// f1c  0x0040c890  size=54
int __thiscall sub_40C890(_DWORD **this, int a2)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    result = (*(int (__thiscall **)(_DWORD *, int))(*this[6] + 28))(this[6], a2);
    if ( !result )
    {
      result = (*(int (__thiscall **)(_DWORD *, int))(*this[7] + 28))(this[7], a2);
      if ( !result )
        return (*(int (__thiscall **)(_DWORD *, int))(*this[8] + 28))(this[8], a2);
    }
  }
  return result;
}
