_DWORD *__thiscall sub_54C150(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = a3;
  if ( (BYTE1(a3) & 8) != 0 && (this[15] & 0x800) != 0 )
  {
    result = (_DWORD *)this[141];
    *a2 = result;
  }
  else if ( (BYTE1(a3) & 0x10) != 0 )
  {
    result = (_DWORD *)this[15];
    if ( (BYTE1(result) & 0x10) != 0 )
    {
      result = a2;
      *a2 = this[142];
    }
  }
  return result;
}

