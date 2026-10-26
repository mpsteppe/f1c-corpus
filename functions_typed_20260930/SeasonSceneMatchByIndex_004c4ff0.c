_DWORD *__thiscall sub_4C4FF0(_DWORD *this, int a2)
{
  _DWORD **v3; // eax
  _DWORD *result; // eax
  int v5; // edi
  char **v6; // eax
  char *v7; // eax
  int v8; // eax

  v3 = (_DWORD **)this[2];
  this[4] = v3;
  if ( v3 )
    result = *v3;
  else
    result = 0;
  v5 = 0;
  if ( result )
  {
    while ( 1 )
    {
      v6 = (char **)(dword_8AC394 + 1060 * *result);
      if ( v6 )
      {
        v7 = *v6;
        if ( !v7 )
          v7 = byte_5EA438;
        result = (_DWORD *)sub_588410(a2, v7);
        if ( !result )
          break;
      }
      v8 = this[4];
      ++v5;
      if ( v8 )
        this[4] = *(_DWORD *)(v8 + 4);
      result = (_DWORD *)this[4];
      if ( result )
      {
        result = (_DWORD *)*result;
        if ( result )
          continue;
      }
      goto LABEL_13;
    }
    this[6] = v5;
  }
  else
  {
LABEL_13:
    this[6] = 0;
  }
  return result;
}

