void __thiscall sub_46DCD0(float *this, char a2, int a3, float a4)
{
  double v4; // st7
  int v5; // [esp+0h] [ebp-4h]

  v4 = 0.40000001;
  if ( a3 == 1 )
    v4 = 6.0;
  if ( !a2 )
    v4 = v4 * -1.0;
  *(float *)&v5 = v4 * a4 + this[44];
  sub_46B750((int)this, v5);
}
