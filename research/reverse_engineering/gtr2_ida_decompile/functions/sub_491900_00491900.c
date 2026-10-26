char __thiscall sub_491900(_BYTE *this)
{
  char result; // al

  result = sub_4735E0(&dword_B6CBA8);
  if ( result )
  {
    result = this[844];
    if ( result )
      result = sub_478CF0();
  }
  this[844] = 0;
  return result;
}
