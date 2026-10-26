int *__thiscall sub_5F79C0(_DWORD *this, const char *a2, int *a3)
{
  int *result; // eax
  int v4; // edi
  int v5; // eax

  result = a3;
  if ( a3 )
  {
    result = (int *)this[51];
    this[53] = result;
    if ( result && (v4 = *result) != 0 )
    {
      while ( 1 )
      {
        result = (int *)strcmp(a2, (const char *)(v4 + 204));
        if ( !result )
          break;
        v5 = this[53];
        if ( v5 )
          this[53] = *(_DWORD *)(v5 + 4);
        result = (int *)this[53];
        if ( result )
        {
          v4 = *result;
          if ( *result )
            continue;
        }
        goto LABEL_9;
      }
      *a3 = v4;
    }
    else
    {
LABEL_9:
      *a3 = 0;
    }
  }
  return result;
}
