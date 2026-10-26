double *__thiscall sub_5C23D0(double *this, int a2, int a3)
{
  void *v4; // eax
  _DWORD *v5; // eax

  *this = 0.0;
  this[1] = 0.0;
  *((_DWORD *)this + 6) = 1065353216;
  *((_DWORD *)this + 7) = 1065353216;
  this[2] = 0.3;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 15) = a2;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 19) = 6;
  *((_DWORD *)this + 18) = 0;
  *((_BYTE *)this + 82) = 0;
  *((_BYTE *)this + 83) = 0;
  *((_BYTE *)this + 81) = 0;
  *((_BYTE *)this + 80) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 16) = a3;
  *((_BYTE *)this + 84) = 0;
  v4 = operator new(8u);
  if ( v4 )
    v5 = (_DWORD *)sub_5D19D0(v4);
  else
    v5 = 0;
  *((_DWORD *)this + 17) = v5;
  sub_40A7C0(v5, (int)this);
  return this;
}
