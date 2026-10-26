char *__thiscall sub_432930(void *this, int a2)
{
  int v2; // edx
  int v3; // eax
  char **v4; // eax
  char *result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= *(_DWORD *)(*(_DWORD *)this + 60) )
    return 0;
  v3 = *(_DWORD *)(*(_DWORD *)this + 48);
  if ( a2 > 0 )
  {
    while ( v3 )
    {
      v3 = *(_DWORD *)(v3 + 4);
      if ( --v2 <= 0 )
        goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  if ( !v3 )
    return 0;
  v4 = *(char ***)v3;
  if ( !v4 )
    return 0;
  result = *v4;
  if ( !result )
    return &byte_5EA438;
  return result;
}
