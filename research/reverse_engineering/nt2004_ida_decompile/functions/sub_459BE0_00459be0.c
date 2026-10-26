_DWORD *__thiscall sub_459BE0(int *this, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  int v4; // ecx

  v4 = *this;
  result = a2;
  if ( a2 )
  {
    v3 = (_DWORD *)(v4 + 44);
    *a2 = *v3;
    a2[1] = v3[1];
    a2[2] = v3[2];
  }
  return result;
}
