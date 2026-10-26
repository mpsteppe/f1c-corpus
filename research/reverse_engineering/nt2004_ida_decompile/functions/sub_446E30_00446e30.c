BOOL __thiscall sub_446E30(int this, double a2)
{
  double v2; // st7

  if ( *(_DWORD *)(this + 8376) == 1 )
  {
    if ( *(double *)(this + 992) <= a2 || *(double *)(this + 2248) <= a2 )
      return 0;
    goto LABEL_7;
  }
  if ( *(_DWORD *)(this + 8376) != 2 )
  {
LABEL_7:
    if ( *(double *)(this + 3504) <= a2 )
      return 0;
    v2 = *(double *)(this + 4760);
    return v2 > a2;
  }
  if ( *(double *)(this + 992) <= a2 )
    return 0;
  v2 = *(double *)(this + 2248);
  return v2 > a2;
}
