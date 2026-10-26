LPVOID __thiscall sub_49A270(LPVOID *this)
{
  LPVOID result; // eax
  void *v3; // esi

  if ( this[4] )
    sub_587BCF(this[4]);
  result = this[2];
  if ( result )
    result = (LPVOID)sub_587BCF(this[2]);
  v3 = *this;
  if ( v3 )
    return (LPVOID)sub_587BCF(v3);
  return result;
}
