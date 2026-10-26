char sub_58F2C0()
{
  char result; // al

  result = byte_FB1CED;
  if ( byte_FB1CED )
  {
    byte_FB1CED = 0;
    return (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 464))(dword_FB27A4, 0);
  }
  return result;
}
