int __thiscall sub_527E30(int *this, float a2)
{
  int v3; // eax
  char *v4; // ecx
  int v5; // edx
  int v6; // eax
  int result; // eax

  sub_527120(this, 0);
  v3 = this[722649];
  if ( v3 >= 0 && this[722650] >= 0 )
  {
    v5 = (v3 + 1) % this[722648];
    v6 = this[722647];
    this[722649] = v5;
    v4 = (char *)(v6 + 184 * v5);
  }
  else
  {
    v4 = (char *)this[722647];
    this[722650] = 0;
    this[722649] = 0;
  }
  sub_5252B0(v4);
  result = 184 * this[722649];
  *(float *)(result + this[722647] + 116) = a2;
  return result;
}
