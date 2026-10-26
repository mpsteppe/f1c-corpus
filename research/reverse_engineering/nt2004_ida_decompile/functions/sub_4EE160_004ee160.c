int __thiscall sub_4EE160(_DWORD *this, float a2)
{
  int result; // eax
  _BYTE v4[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v5[12]; // [esp+18h] [ebp-Ch] BYREF

  sub_50A950(SLOBYTE(a2));
  sub_50F940(this + 21);
  sub_417C50(dword_6291D0, (int)(this + 21));
  if ( LOBYTE(a2) )
    sub_4DC0C0((int)(this + 5209));
  if ( !this[6325] )
  {
    sub_4F8EF0(this, v5, v4);
    sub_4F8F50(this, v5, v4);
  }
  sub_4F8F10(this, v5, v4);
  if ( LOBYTE(a2) )
  {
    sub_4F8F90(this, v5, v4);
    sub_51BE20(v5, v4);
  }
  sub_420DA0((int)this, a2);
  sub_4EDFE0((int)this, 1);
  this[6320] = -8388609;
  if ( flt_6290DC <= 0.0 )
    sub_50FD00(this + 21);
  result = sub_4EED40(this);
  if ( (_BYTE)result )
  {
    sub_4EEC50(1);
    return sub_4EEC20(byte_76617C == 0);
  }
  return result;
}
