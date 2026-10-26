_DWORD *__thiscall sub_4F0980(_DWORD *this)
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
        v4 = (_DWORD *)result[33];
        j__free(result);
        result = v4;
      }
      while ( v4 );
    }
  }
  return result;
}
