int __thiscall sub_6768C8(_DWORD *this, int a2, _DWORD *a3)
{
  char *v3; // edi
  _DWORD *v4; // ebx
  int v6; // eax
  unsigned int v7; // esi
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  const char *v11; // ecx
  _DWORD *v12; // eax
  const char *v13; // eax
  _DWORD *v14; // eax
  unsigned int j; // edi
  _DWORD *v16; // edi
  const char *v17; // eax
  const char *v18; // [esp+8h] [ebp-18h]
  _DWORD *v19; // [esp+Ch] [ebp-14h]
  char *v20; // [esp+10h] [ebp-10h]
  unsigned int v22; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]
  unsigned int v24; // [esp+28h] [ebp+8h]
  _DWORD *v25; // [esp+28h] [ebp+8h]

  v3 = (char *)a2;
  v4 = this;
  if ( a2 >= 0 )
  {
    v20 = (char *)a2;
    if ( isspace(*(char *)a2) )
    {
      do
        ++v3;
      while ( isspace(*v3) );
      v20 = v3;
    }
    if ( isalnum(*v3) || *v3 == 95 || *v3 == 36 )
    {
      for ( i = 1; isalnum(v3[i]) || v3[i] == 95; ++i )
        ;
      v6 = v4[4];
      v7 = 0;
      v22 = 0;
      v8 = v4[2] + *(_DWORD *)(v6 + 16);
      v24 = *(_DWORD *)(v6 + 12);
      if ( v24 )
      {
        do
        {
          v7 = (v24 + v22) >> 1;
          v9 = sub_67347A(v20, this[2] + *(_DWORD *)(v8 + 20 * v7), i);
          if ( !v9 )
            break;
          if ( v9 >= 0 )
            v24 = (v24 + v22) >> 1;
          else
            v22 = v7 + 1;
        }
        while ( v22 < v24 );
        v4 = this;
      }
      if ( v22 == v24 )
        return -2005530516;
      v10 = (_DWORD *)(v8 + 20 * v7);
      v11 = (const char *)(v4[2] + *v10);
      v18 = v11;
      if ( v7 )
      {
        v12 = v10 - 5;
        v19 = v12;
        do
        {
          v13 = (const char *)(v4[2] + *v12);
          if ( v11 != v13 && strcmp(v11, v13) )
            break;
          --v7;
          v12 = v19 - 5;
          v19 -= 5;
        }
        while ( v7 );
      }
      v14 = sub_67677A(*(_DWORD **)(v4[5] + 4 * v7), &v20[i], 0);
      if ( !v14 )
      {
        return -2005530516;
      }
      else
      {
        for ( j = v8 + 20 * v7; ; j = (unsigned int)v25 )
        {
          *a3 = v14;
          a3 = v14 + 9;
          ++v7;
          v16 = (_DWORD *)(j + 20);
          v25 = v16;
          if ( v7 >= *(_DWORD *)(v4[4] + 12) )
            break;
          v17 = (const char *)(v4[2] + *v16);
          if ( v18 != v17 )
          {
            if ( strcmp(v18, v17) )
              break;
          }
          v14 = sub_67677A(*(_DWORD **)(v4[5] + 4 * v7), &v20[i], 0);
          if ( !v14 )
            return -2005530516;
        }
        return 0;
      }
    }
    else
    {
      return -2005530516;
    }
  }
  else
  {
    *a3 = -a2;
    return 0;
  }
}
