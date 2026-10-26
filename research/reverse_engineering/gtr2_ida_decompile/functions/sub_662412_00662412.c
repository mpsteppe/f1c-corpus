_DWORD *__thiscall sub_662412(_DWORD *this, int a2)
{
  unsigned int v3; // ebx
  int v4; // edi
  _DWORD *result; // eax

  v3 = a2 + 2;
  if ( this[35] >= (unsigned int)(a2 + 2) )
  {
    result = (_DWORD *)this[34];
    *result = result;
    result[1] = this[35];
    goto LABEL_7;
  }
  v4 = a2 + 2;
  if ( v3 < 0x2000 )
    v4 = 0x2000;
  result = operator new(4 * v4);
  if ( result )
  {
    *result = this[34];
    result[1] = -this[35];
    this[34] = result;
    this[35] = v4;
LABEL_7:
    this[35] -= v3;
    this[34] += 4 * v3;
    result += 2;
  }
  return result;
}
