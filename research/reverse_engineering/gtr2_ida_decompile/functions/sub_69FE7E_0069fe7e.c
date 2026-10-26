int __thiscall sub_69FE7E(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  if ( !a4 )
    return -2005530516;
  *a4 = 0;
  *this = a3;
  this[1] = a2;
  this[2] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[16] = 0;
  this[17] = 0;
  this[18] = 1;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  dword_FBAA30 = (int)this;
  result = sub_65A004((_DWORD *)this[1], 1);
  if ( result >= 0 )
  {
    sub_694CC7(this, 0, 0);
    if ( sub_69EB7F() )
      this[16] = 1;
    result = sub_65D529((_DWORD *)this[1]);
    if ( result >= 0 )
    {
      if ( !this[16] )
      {
        *a4 = *(_DWORD *)(this[2] + 8);
        *(_DWORD *)(this[2] + 8) = 0;
      }
      return this[16] != 0 ? 0x80004005 : 0;
    }
  }
  return result;
}
