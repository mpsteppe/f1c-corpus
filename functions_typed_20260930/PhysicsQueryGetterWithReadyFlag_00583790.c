char __thiscall sub_583790(int this, double *a2, _DWORD *a3, _DWORD *a4, double a5)
{
  double v5; // st7
  char result; // al

  if ( !*(_BYTE *)(this + 12) )
    return 0;
  v5 = a5 - *(double *)(this + 16);
  *(_BYTE *)(this + 12) = 0;
  *a2 = v5 + *(double *)(this + 24);
  *a4 = *(_DWORD *)(this + 288);
  if ( *(int *)(this + 288) <= 0 )
  {
    *a3 = 0;
    return 1;
  }
  else
  {
    result = 1;
    *a3 = this + 32;
  }
  return result;
}

