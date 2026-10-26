int __thiscall sub_4226C0(float *this, int a2)
{
  int result; // eax

  if ( a2 == 18 )
  {
    result = dword_FADE50;
    *((_DWORD *)this + 5207) = dword_FADE50;
  }
  else
  {
    this[5207] = (float)a2;
  }
  return result;
}
