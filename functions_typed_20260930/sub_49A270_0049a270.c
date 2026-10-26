LPVOID __thiscall sub_49A270(LPVOID *this)
{
  LPVOID result; // eax
  void *v3; // esi

  if ( this[4] )
    FreeWrapper_7bcf(this[4]);
  result = this[2];
  if ( result )
    result = (LPVOID)FreeWrapper_7bcf(this[2]);
  v3 = *this;
  if ( v3 )
    return (LPVOID)FreeWrapper_7bcf(v3);
  return result;
}

