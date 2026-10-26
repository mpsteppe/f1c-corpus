double __thiscall sub_4420C0(int this)
{
  double v1; // st7
  double v2; // st6

  if ( *(double *)(this + 2404) >= *(double *)(this + 1148) )
    v1 = *(double *)(this + 2404);
  else
    v1 = *(double *)(this + 1148);
  if ( *(double *)(this + 4916) >= *(double *)(this + 3660) )
    v2 = *(double *)(this + 4916);
  else
    v2 = *(double *)(this + 3660);
  if ( v1 <= v2 )
  {
    if ( *(double *)(this + 4916) >= *(double *)(this + 3660) )
      return *(double *)(this + 4916);
    else
      return *(double *)(this + 3660);
  }
  else if ( *(double *)(this + 2404) >= *(double *)(this + 1148) )
  {
    return *(double *)(this + 2404);
  }
  else
  {
    return *(double *)(this + 1148);
  }
}
