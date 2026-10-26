int __thiscall sub_4F04C0(float *this, int a2)
{
  int result; // eax
  float v4; // eax

  result = 1;
  if ( a2 )
  {
    *((_DWORD *)this + 1) = a2;
    sub_59E5E0(this + 2, this + 3, this + 4);
    v4 = *this;
    this[3] = -this[3];
    return (*(int (__thiscall **)(float *))(LODWORD(v4) + 4))(this);
  }
  return result;
}
