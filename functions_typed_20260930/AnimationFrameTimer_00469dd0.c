int __thiscall AnimationFrameTimer(float *this)
{
  double v2; // st7
  int v3; // eax

  v2 = FloatFieldAccessor((float *)*((_DWORD *)this + 16)) + this[93];
  this[93] = v2;
  if ( v2 > 2.0 )
  {
    v3 = *((_DWORD *)this + 94) + 2;
    this[93] = 0.0;
    *((_DWORD *)this + 94) = v3;
    if ( v3 >= dword_7D2DCC )
      this[94] = 0.0;
    (*(void (__thiscall **)(float *))(*(_DWORD *)this + 160))(this);
  }
  return 0;
}

