char __thiscall sub_5A3BD0(int this, double *a2, _DWORD *a3, _DWORD *a4, double a5)
{
  double v5; // st7

  if ( !*(_BYTE *)(this + 16) )
    return 0;
  v5 = a5 - *(double *)(this + 24);
  *(_BYTE *)(this + 16) = 0;
  *a2 = v5 + *(double *)(this + 32);
  *a4 = *(_DWORD *)(this + 296);
  if ( *(int *)(this + 296) <= 0 )
    *a3 = 0;
  else
    *a3 = this + 40;
  return 1;
}
