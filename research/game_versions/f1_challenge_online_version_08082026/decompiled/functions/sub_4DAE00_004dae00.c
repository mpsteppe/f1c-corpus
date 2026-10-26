char __thiscall sub_4DAE00(int this)
{
  bool v2; // bl
  char result; // al

  v2 = 0;
  if ( *(float *)(this + 20) <= 0.0 )
    return 1;
  if ( *(float *)(this + 28) > 0.0 )
    return v2;
  if ( dword_5F073C[4656 * sub_4D1B50((unsigned __int8 *)dword_8ACEE0, 0)] == 1
    && *(_DWORD *)(this + 32) >= *(_DWORD *)(dword_7C54E8 + 16480) )
  {
    v2 = *(_DWORD *)(dword_7C54E8 + 16484) != 0;
  }
  result = 1;
  if ( *(_DWORD *)(this + 32) != dword_5C329C )
    return v2;
  return result;
}
