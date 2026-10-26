char sub_437DEF()
{
  char result; // al

  result = byte_FB1CED;
  if ( !byte_FB1CED )
  {
    byte_FB1CED = 1;
    return (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 460))(dword_FB27A4, 0);
  }
  return result;
}
