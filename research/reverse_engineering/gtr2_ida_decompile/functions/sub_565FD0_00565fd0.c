char __thiscall sub_565FD0(int this)
{
  bool v2; // bl
  char result; // al

  v2 = 0;
  if ( *(float *)(this + 20) <= 0.0 )
    return 1;
  if ( *(float *)(this + 28) > 0.0 )
    return v2;
  if ( dword_925054[5654 * sub_5511F0(dword_FADD40, 0)] == 1
    && *(_DWORD *)(this + 32) >= *(_DWORD *)(dword_91E084 + 19324) )
  {
    v2 = *(_DWORD *)(dword_91E084 + 19380) != 0;
  }
  result = 1;
  if ( *(_DWORD *)(this + 32) != dword_757C10 )
    return v2;
  return result;
}
