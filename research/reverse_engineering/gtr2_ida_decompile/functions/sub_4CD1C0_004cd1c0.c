_DWORD *__thiscall sub_4CD1C0(_DWORD *this, const char *a2, const char *a3)
{
  _DWORD *result; // eax

  result = (_DWORD *)this[2];
  this[608] = 0;
  this[609] = 0;
  if ( result )
  {
    result = (_DWORD *)this[2];
    if ( (int)result[160] > 0 )
    {
      result = (_DWORD *)result[157];
      if ( result )
      {
        if ( *result )
          return (_DWORD *)_stricmp(a2, a3);
      }
    }
  }
  return result;
}
