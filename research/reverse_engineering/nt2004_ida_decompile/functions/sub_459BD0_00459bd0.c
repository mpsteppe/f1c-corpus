_DWORD *__thiscall sub_459BD0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // ecx

  v5 = (_DWORD *)*this;
  if ( a2 )
  {
    *a2 = v5[5];
    a2[1] = v5[6];
    a2[2] = v5[7];
  }
  result = a3;
  if ( a3 )
  {
    v4 = v5 + 8;
    *a3 = *v4;
    a3[1] = v4[1];
    a3[2] = v4[2];
  }
  return result;
}
