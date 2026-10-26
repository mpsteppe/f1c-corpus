int __thiscall sub_4D18F0(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // eax

  v3 = (_DWORD *)this[53251];
  if ( v3 == (_DWORD *)this[53249] )
  {
    this[53251] = this[53250];
    return 0;
  }
  else
  {
    sub_4D1850(a2, v3);
    this[53251] += 208;
    return 1;
  }
}
