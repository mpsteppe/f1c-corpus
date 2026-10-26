void __thiscall sub_58E480(float *this, float a2, float a3)
{
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2

  if ( v5 | v6 )
  {
    if ( v8 | v9 || a2 < (double)this[55] )
    {
      sub_58C630(this, 15);
      return;
    }
    sub_58C630(this, 15);
LABEL_9:
    sub_58C630(this, 16);
    return;
  }
  if ( a2 < (double)this[58] )
  {
    sub_58C630(this, 16);
    return;
  }
  if ( a2 < (double)this[59] )
    goto LABEL_9;
}
