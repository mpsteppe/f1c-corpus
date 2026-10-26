_DWORD *__thiscall sub_459CC0(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax
  int v4; // ecx

  v4 = *this;
  if ( a2 )
    *(_DWORD *)(v4 + 72) = *a2;
  result = a3;
  if ( a3 )
    *(_DWORD *)(v4 + 76) = *a3;
  return result;
}
