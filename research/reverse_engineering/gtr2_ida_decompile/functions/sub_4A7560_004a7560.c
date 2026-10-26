int __thiscall sub_4A7560(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx

  if ( this[70] && !(unsigned __int8)sub_4CD650(this) )
  {
    v2 = (_DWORD *)this[70];
    if ( v2 )
    {
      v3 = this[69];
      if ( v3 != 276 && v3 != 636 )
      {
        *v2 = *v2 == 0;
        sub_494640();
        return 0;
      }
      *v2 = *v2 == 3 ? 0 : 3;
    }
    sub_494640();
  }
  return 0;
}
