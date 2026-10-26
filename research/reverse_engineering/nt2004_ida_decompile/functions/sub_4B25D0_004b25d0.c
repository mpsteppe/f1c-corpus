void __thiscall sub_4B25D0(float *this, float a2, char a3)
{
  if ( *(_BYTE *)this )
  {
    if ( !a3 )
      return;
  }
  else if ( !a3 && this[1] > 0.0 )
  {
    goto LABEL_7;
  }
  this[2] = a2 * 0.5;
LABEL_7:
  *(_BYTE *)this = 1;
  this[1] = 0.0;
}
