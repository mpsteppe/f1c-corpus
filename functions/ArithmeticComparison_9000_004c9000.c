char __thiscall sub_4C9000(_DWORD *this)
{
  int v2; // eax
  bool v3; // zf
  char result; // al

  v2 = ShortComputation_c910(&dword_5EA510);
  if ( !this[1] )
    return 0;
  if ( !v2 )
    return 0;
  v3 = sub_54C0E0(v2) == 0;
  result = 1;
  if ( v3 )
    return 0;
  return result;
}
