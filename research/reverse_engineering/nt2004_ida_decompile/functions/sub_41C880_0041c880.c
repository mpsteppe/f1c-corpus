int __thiscall sub_41C880(_DWORD **this)
{
  _DWORD *v2; // ecx
  int result; // eax
  _DWORD *v4; // edi

  v2 = *this;
  if ( v2 )
  {
    result = sub_41C050(v2);
    v4 = *this;
    if ( *this )
    {
      sub_41C050(*this);
      result = sub_5BE8AE(v4);
    }
    *this = 0;
  }
  return result;
}
