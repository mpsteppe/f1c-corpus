char __thiscall sub_4A8120(_BYTE *this)
{
  char result; // al
  LPVOID *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(LPVOID **)this;
    if ( *(_DWORD *)this )
    {
      sub_4AFEE0(*(_DWORD *)this);
      if ( v2[5] )
        sub_5BE8AE(v2[5]);
      if ( v2[1] )
        sub_5BE8AE(v2[1]);
      return sub_5BE8AE(v2);
    }
  }
  return result;
}
