int __thiscall sub_479880(int this, char a2)
{
  double v2; // st7
  unsigned int i; // esi
  int result; // eax

  *(_DWORD *)(this + 4) = 0;
  if ( a2 )
  {
    *(_DWORD *)(this + 8) = 0;
    *(_DWORD *)(this + 12) = 0;
    *(_DWORD *)(this + 16) = 0;
    *(_DWORD *)(this + 20) = 0;
  }
  if ( *(float *)(this + 24) >= 0.0 )
  {
    if ( flt_B735A0 <= (double)flt_B735C4 )
      v2 = flt_B735C4;
    else
      v2 = flt_B735A0;
    *(float *)(this + 24) = v2;
  }
  else
  {
    *(_DWORD *)(this + 24) = 1051931443;
  }
  for ( i = 0; i < 0xD0; ++i )
    result = sub_4797E0();
  return result;
}
