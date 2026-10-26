_DWORD *__thiscall sub_477BA0(_DWORD *this)
{
  int v1; // esi
  int i; // ebp
  int v3; // edx
  int *v4; // eax
  int v5; // edi
  int v6; // edx
  const char *v7; // esi
  _DWORD *result; // eax
  char *v9; // eax

  v1 = this[63];
  for ( i = 0; i < v1; ++i )
  {
    v3 = i;
    if ( i >= 0 && i < this[63] )
    {
      v4 = (int *)this[60];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v4 )
        {
          v5 = *v4;
          if ( *v4 )
          {
            v6 = *(_DWORD *)(v5 + 60);
            if ( v6 )
            {
              v7 = (const char *)dword_7CE5EC;
              if ( !dword_7CE5EC )
                v7 = byte_5EA438;
              if ( !strcmp((const char *)(v6 + 260), v7) )
              {
                this[93] = i;
                v9 = *(char **)(v5 + 4);
LABEL_19:
                if ( !v9 )
                  v9 = byte_5EA438;
                TrackSceneLoader(v9);
                return (_DWORD *)AIW(0);
              }
              v1 = this[63];
            }
          }
        }
      }
      else
      {
        while ( v4 )
        {
          v4 = (int *)v4[1];
          if ( --v3 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  result = (_DWORD *)this[63];
  if ( (int)result > 0 )
  {
    result = (_DWORD *)this[60];
    if ( result )
    {
      result = (_DWORD *)*result;
      if ( result )
      {
        this[93] = 0;
        v9 = (char *)result[1];
        goto LABEL_19;
      }
    }
  }
  return result;
}
