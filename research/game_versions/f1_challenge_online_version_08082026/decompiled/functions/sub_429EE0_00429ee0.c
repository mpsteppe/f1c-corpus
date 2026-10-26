int __thiscall sub_429EE0(_DWORD *this)
{
  int result; // eax

  if ( dword_7C56A8 == 3 )
  {
    sub_42ADB0(this);
    this[4433] = 0;
    sub_42AC90(this);
  }
  if ( dword_7C56A4 != 7 && sub_424E30(this, 0) )
  {
    this[4433] = 0;
    sub_42ACD0(18);
    this[4420] = 5;
    sub_42ACA0(1);
  }
  if ( sub_424E30(this, 5) )
  {
    sub_42ACD0(99999);
    this[4433] = 1;
  }
  if ( sub_424E30(this, 4) )
  {
    this[4367] = 1;
    sub_42ACD0(18);
  }
  result = sub_424E30(this, 14);
  if ( result )
  {
    this[4433] = 0;
    this[4367] = 1;
  }
  if ( dword_7C56A8 == 4 )
  {
    sub_42ACA0(0);
    result = sub_42ACD0(99999);
    this[4433] = 1;
  }
  return result;
}
