char __thiscall sub_404D50(void *this, char a2)
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
  *(_BYTE *)(*(_DWORD *)this + 36) = a2;
  if ( !v3 )
  {
    v4 = (int *)(*(_DWORD *)this + 64);
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
            sub_587BCF(*v8);
          sub_587BCF(v8);
        }
      }
      sub_587BCF(v6);
    }
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    v4[3] = 0;
    sub_565DC0(&a2);
    v9 = (char *)lpPathName;
    if ( !lpPathName )
      v9 = &byte_5EA438;
    sub_565F80(aVcr, 1, (int)v9, 0);
    sub_565F50(&a2);
    for ( i = (const char *)sub_5662D0(&a2); i; i = (const char *)sub_5662D0(&a2) )
    {
      if ( strlen(i) )
        sub_404E60(i);
      if ( !(unsigned __int8)sub_565F20(&a2) )
        break;
    }
    return sub_565E20(&a2);
  }
  return result;
}
