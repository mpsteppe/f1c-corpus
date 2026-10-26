_DWORD *__thiscall NetworkThreadConnectionCleanup(_DWORD *this)
{
  _DWORD *result; // eax
  void *v3; // esi
  int v4; // [esp+4h] [ebp-10h] BYREF
  u_long v5; // [esp+8h] [ebp-Ch]

  result = (_DWORD *)this[708];
  if ( result )
  {
    result = (_DWORD *)WaitForSingleObject(result, this[709]);
    if ( !result || result == (_DWORD *)128 )
    {
      v5 = htonl(0);
      htons(0);
      Copy4DwordsStructToStruct(this + 673, &v4);
      result = (_DWORD *)this[704];
      if ( result )
      {
        while ( !*result || *(_DWORD *)*result != v5 )
        {
          result = (_DWORD *)result[1];
          if ( !result )
            goto LABEL_11;
        }
        result = (_DWORD *)*result;
        if ( result )
        {
          result[1] = 0;
          result[2] = 0;
          result[3] = 0;
        }
      }
LABEL_11:
      v3 = (void *)this[708];
      if ( v3 )
        return (_DWORD *)ReleaseMutex(v3);
    }
  }
  return result;
}

