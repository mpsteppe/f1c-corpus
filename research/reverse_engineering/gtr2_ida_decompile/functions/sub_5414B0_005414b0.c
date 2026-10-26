int __thiscall sub_5414B0(float *this, int a2)
{
  int result; // eax
  float v4; // eax

  result = 1;
  if ( a2 )
  {
    *((_DWORD *)this + 1) = a2;
    sub_5DA840(this + 2, this + 3, this + 4, 0);
    v4 = *this;
    this[3] = -this[3];
    return (*(int (__thiscall **)(float *))(LODWORD(v4) + 4))(this);
  }
  return result;
}
