char __thiscall sub_4A1BB0(_BYTE *this, char a2)
{
  char result; // al

  result = a2;
  this[268] = a2;
  if ( !a2 )
    return (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 168))(this);
  return result;
}
