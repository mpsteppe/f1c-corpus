int __thiscall sub_423A00(_DWORD *this, const char *a2, char *a3)
{
  int v3; // ebp
  int v4; // edx
  int v5; // edi
  const char *v6; // eax
  int v7; // eax
  char *v9; // eax
  int v10; // edx
  char v11; // cl
  int v12; // [esp+10h] [ebp-4h]

  v3 = this[1];
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_10:
    strcpy(a3, a2);
    return -1;
  }
  else
  {
    v12 = this[2];
    while ( 1 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = *(const char **)(v12 + 16 * v5);
      if ( !v6 )
        v6 = &byte_5EA438;
      v7 = strcmp(a2, v6);
      if ( !v7 )
        break;
      if ( v7 >= 0 )
        v4 = v5 + 1;
      else
        v3 = (v4 + v3) >> 1;
      if ( v4 >= v3 )
        goto LABEL_10;
    }
    v9 = *(char **)(16 * v5 + v12 + 8);
    if ( !v9 )
      v9 = &byte_5EA438;
    v10 = a3 - v9;
    do
    {
      v11 = *v9;
      v9[v10] = *v9;
      ++v9;
    }
    while ( v11 );
    return 0;
  }
}

