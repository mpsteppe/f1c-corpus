_DWORD *__thiscall sub_5DA960(_DWORD *this, _DWORD *a2, __int16 a3)
{
  _DWORD *result; // eax

  result = (_DWORD *)*this;
  if ( (*this & 0x800) != 0 && (a3 & 0x800) != 0 )
  {
    result = (_DWORD *)this[161];
    *a2 = result;
  }
  else if ( (BYTE1(result) & 0x10) != 0 && (a3 & 0x1000) != 0 )
  {
    result = a2;
    *a2 = this[162];
  }
  return result;
}
