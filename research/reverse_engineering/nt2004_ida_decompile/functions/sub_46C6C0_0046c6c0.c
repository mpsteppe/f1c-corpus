char __thiscall sub_46C6C0(_BYTE *this, char a2)
{
  char result; // al

  result = a2;
  if ( a2 )
    *this = 0x80;
  else
    *this &= ~0x80u;
  return result;
}
