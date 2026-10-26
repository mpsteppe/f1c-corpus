_DWORD *__thiscall sub_51F0F0(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // esi

  this[4386] = 0;
  this[4387] = 0;
  this[4388] = 0;
  this[4389] = 0;
  this[4390] = 0;
  this[4391] = 0;
  this[4392] = 0;
  this[4393] = 0;
  this[4394] = 0;
  result = this + 4435;
  v2 = 4;
  do
  {
    *result = 0;
    result += 62;
    --v2;
  }
  while ( v2 );
  if ( !this[4125] )
    return sub_441680(&dbl_75E930);
  return result;
}
