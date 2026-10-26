int __thiscall sub_4D05F0(_BYTE *this)
{
  if ( this[280] )
  {
    sub_4D0510(this);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 64))(this);
  }
  return 0;
}
