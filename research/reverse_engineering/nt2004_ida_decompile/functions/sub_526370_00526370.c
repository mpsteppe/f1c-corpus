float *__thiscall sub_526370(_BYTE *this)
{
  int v2; // eax
  int v3; // eax

  v2 = rand();
  if ( v2 >= 10922 )
    v3 = (v2 < 21844) + 18;
  else
    v3 = 20;
  return sub_526050(this, v3, 2, 1.0, 1065353216);
}
