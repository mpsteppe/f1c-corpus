// f1c  0x004f8a70  size=59
float *__thiscall sub_4F8A70(float *this)
{
  int v2; // eax
  int v3; // eax

  v2 = sub_5884ED(this);
  if ( v2 >= 10922 )
    v3 = (v2 < 21844) + 18;
  else
    v3 = 20;
  return sub_4F87C0(this, v3, 2, 1.0, 1.0);
}
