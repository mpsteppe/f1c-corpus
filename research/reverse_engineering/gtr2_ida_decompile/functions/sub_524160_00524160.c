char __thiscall sub_524160(_DWORD *this, char a2)
{
  char result; // al

  result = a2;
  *(_BYTE *)(this[7] + 2892940) = a2;
  if ( !a2 )
    return sub_521650(this[7] + 2892996, dword_91E084);
  return result;
}
