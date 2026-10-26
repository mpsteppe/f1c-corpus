unsigned int __thiscall sub_4EEC20(_DWORD *this, char a2)
{
  int v2; // eax
  unsigned int result; // eax

  v2 = this[6324];
  if ( a2 )
    result = v2 | 1;
  else
    result = v2 & 0xFFFFFFFE;
  this[6324] = result;
  return result;
}
