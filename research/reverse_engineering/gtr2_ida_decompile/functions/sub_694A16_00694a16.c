int __thiscall sub_694A16(_DWORD *this, _DWORD *a2)
{
  int result; // eax

  this[54] = 0;
  this[55] = 0;
  if ( a2 )
    *a2 = 0;
  result = sub_69468D((int)this);
  if ( result >= 0 )
  {
    result = sub_69490B(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
