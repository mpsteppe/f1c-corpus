_DWORD *__thiscall sub_5D1CB0(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx

  result = this;
  while ( 1 )
  {
    v2 = result[2];
    if ( v2 )
    {
      if ( !*(_BYTE *)(v2 + 83) )
        break;
    }
    result = (_DWORD *)result[4];
    if ( !result )
      return result;
  }
  return (_DWORD *)result[2];
}
