int __thiscall sub_4A8410(_BYTE *this)
{
  int v2; // edi

  v2 = 1;
  if ( (unsigned __int8)sub_57A2F0(this + 84, 1) )
  {
    v2 = 0;
    if ( this[482] && !(unsigned __int8)sub_57A110(this + 212, 0, 1, 1) )
      this[482] = 0;
    if ( *(_DWORD *)this )
      sub_57A5B0(0);
    if ( this[482] )
      sub_57A5B0(0);
  }
  return v2;
}
