int __thiscall sub_4AD7B0(float *this)
{
  double v2; // st7
  int v3; // eax

  v2 = sub_4DE460(*((_DWORD *)this + 12)) + this[149];
  this[149] = v2;
  if ( v2 > 2.0 )
  {
    v3 = *((_DWORD *)this + 150) + 2;
    this[149] = 0.0;
    *((_DWORD *)this + 150) = v3;
    if ( v3 >= dword_B7628C )
      this[150] = 0.0;
    (*(void (__thiscall **)(float *))(*(_DWORD *)this + 152))(this);
  }
  return 0;
}
