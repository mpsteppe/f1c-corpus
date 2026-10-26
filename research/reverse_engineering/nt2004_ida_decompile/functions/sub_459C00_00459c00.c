_DWORD *__thiscall sub_459C00(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax
  int v4; // ecx

  v4 = *this;
  if ( a2 )
    *a2 = *(_DWORD *)(v4 + 72);
  result = a3;
  if ( a3 )
    *a3 = *(_DWORD *)(v4 + 76);
  return result;
}
