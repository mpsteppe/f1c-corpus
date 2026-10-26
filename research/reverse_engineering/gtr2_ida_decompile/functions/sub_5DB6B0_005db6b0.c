int __thiscall sub_5DB6B0(float *this, float *a2)
{
  int result; // eax

  result = (int)a2;
  if ( a2 )
    return sub_5DB3C0(this, *a2, a2[1], a2[2], a2[3]);
  return result;
}
