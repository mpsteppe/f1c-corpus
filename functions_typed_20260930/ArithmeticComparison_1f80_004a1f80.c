_DWORD *__thiscall sub_4A1F80(_DWORD *this)
{
  int i; // edi
  _DWORD *result; // eax
  _DWORD *v4; // esi

  for ( i = 0; i < 4; ++i )
  {
    result = (_DWORD *)this[i];
    if ( result )
    {
      do
      {
        v4 = (_DWORD *)result[17];
        FreeWrapper_7bcf(result);
        result = v4;
      }
      while ( v4 );
    }
  }
  return result;
}

