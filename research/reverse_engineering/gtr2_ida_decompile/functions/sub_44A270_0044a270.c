double __thiscall sub_44A270(int this)
{
  double result; // st7
  double v2; // [esp+0h] [ebp-10h]
  double v3; // [esp+8h] [ebp-8h]

  if ( !*(_BYTE *)(this + 8650) )
    return 0.0;
  if ( *(double *)(this + 456) >= 0.9 )
    return 1.0;
  if ( *(double *)(this + 456) <= 0.0 )
    return 0.0;
  v2 = *(double *)(this + 456) + 0.1;
  v3 = *(double *)(this + 456) + 1.6;
  result = sub_44A210((double *)this) * (v3 - v2) + v2;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
