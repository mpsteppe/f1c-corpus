int __thiscall sub_415550(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  char **v8; // eax
  char *v9; // eax

  result = -1;
  if ( a2 )
  {
    v4 = this[7];
    v5 = 0;
    if ( v4 > 0 )
    {
      while ( 1 )
      {
        v6 = v5;
        if ( v5 < 0 || v5 >= this[7] )
          goto LABEL_9;
        v7 = this[4];
        if ( v5 > 0 )
          break;
LABEL_8:
        if ( !v7 )
          goto LABEL_9;
        v8 = *(char ***)v7;
LABEL_11:
        v9 = *v8;
        if ( !v9 )
          v9 = &byte_5EA438;
        if ( sub_566810(v9, a2) )
          return v5;
        if ( ++v5 >= v4 )
          return -1;
      }
      while ( v7 )
      {
        v7 = *(_DWORD *)(v7 + 4);
        if ( --v6 <= 0 )
          goto LABEL_8;
      }
LABEL_9:
      v8 = 0;
      goto LABEL_11;
    }
  }
  return result;
}

