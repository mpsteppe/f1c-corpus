BOOL __thiscall sub_439CB0(int this, double a2)
{
  double v2; // st7

  if ( *(_DWORD *)(this + 9104) == 1 )
  {
    if ( *(double *)(this + 1040) <= a2 || *(double *)(this + 2320) <= a2 )
      return 0;
    goto LABEL_7;
  }
  if ( *(_DWORD *)(this + 9104) != 2 )
  {
LABEL_7:
    if ( *(double *)(this + 3600) <= a2 )
      return 0;
    v2 = *(double *)(this + 4880);
    return v2 > a2;
  }
  if ( *(double *)(this + 1040) <= a2 )
    return 0;
  v2 = *(double *)(this + 2320);
  return v2 > a2;
}
