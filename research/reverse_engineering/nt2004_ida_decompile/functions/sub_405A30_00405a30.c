char __thiscall sub_405A30(void *this, char a2)
{
  char result; // al
  bool v3; // zf
  int *v4; // ebx
  int v5; // esi
  LPVOID **v6; // ebp
  char v7; // al
  LPVOID *v8; // edi
  char *v9; // eax
  const char *i; // edx

  result = a2;
  v3 = a2 == 0;
  *(_BYTE *)(*(_DWORD *)this + 40) = a2;
  if ( !v3 )
  {
    v4 = (int *)(*(_DWORD *)this + 68);
    v5 = *v4;
    while ( v5 )
    {
      v6 = (LPVOID **)v5;
      v7 = *(_BYTE *)(v5 + 8);
      v5 = *(_DWORD *)(v5 + 4);
      if ( v7 )
      {
        v8 = *v6;
        if ( *v6 )
        {
          if ( *v8 )
            sub_5BE8AE(*v8);
          sub_5BE8AE(v8);
        }
      }
      sub_5BE8AE(v6);
    }
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    v4[3] = 0;
    sub_578870(&a2);
    v9 = ArgList;
    if ( !ArgList )
      v9 = &byte_629120;
    sub_578A30(aVcr, 1, v9, 0);
    sub_578A00(&a2);
    for ( i = (const char *)sub_578D80(&a2); i; i = (const char *)sub_578D80(&a2) )
    {
      if ( strlen(i) )
        sub_405B40(i);
      if ( !(unsigned __int8)sub_5789D0(&a2) )
        break;
    }
    return sub_5788D0(&a2);
  }
  return result;
}
