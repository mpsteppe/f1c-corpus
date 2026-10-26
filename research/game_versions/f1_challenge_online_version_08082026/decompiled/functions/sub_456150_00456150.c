_DWORD *__thiscall sub_456150(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx

  result = a2;
  if ( a2 )
  {
    v3 = this + 9;
    *v3 = *a2;
    v3[1] = a2[1];
    result = (_DWORD *)a2[2];
    v3[2] = result;
  }
  return result;
}
