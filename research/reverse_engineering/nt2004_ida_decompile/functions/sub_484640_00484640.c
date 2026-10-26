_DWORD *__thiscall sub_484640(_DWORD *this)
{
  _DWORD *result; // eax

  result = (_DWORD *)this[218];
  if ( result )
  {
    result = (_DWORD *)*result;
    if ( result )
    {
      result = (_DWORD *)result[21];
      if ( result )
      {
        sub_4E8C80(result + 65);
        return (_DWORD *)sub_4E8A30(&byte_7D6A30);
      }
    }
  }
  return result;
}
