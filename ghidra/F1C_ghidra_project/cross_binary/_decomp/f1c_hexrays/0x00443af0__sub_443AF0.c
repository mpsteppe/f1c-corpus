// f1c  0x00443af0  size=118
BOOL __thiscall sub_443AF0(int this, double a2)
{
  double v2; // st7

  if ( *(_DWORD *)(this + 7700) == 1 )
  {
    if ( *(double *)(this + 976) <= a2 || *(double *)(this + 2100) <= a2 )
      return 0;
    goto LABEL_7;
  }
  if ( *(_DWORD *)(this + 7700) != 2 )
  {
LABEL_7:
    if ( *(double *)(this + 3224) <= a2 )
      return 0;
    v2 = *(double *)(this + 4348);
    return v2 > a2;
  }
  if ( *(double *)(this + 976) <= a2 )
    return 0;
  v2 = *(double *)(this + 2100);
  return v2 > a2;
}
