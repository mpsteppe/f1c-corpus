int __thiscall sub_5DA9A0(_DWORD *this, const char *a2, int a3)
{
  char *v3; // ebp
  int *v4; // eax
  bool v5; // zf
  int v6; // edi
  _DWORD *v7; // eax
  int result; // eax
  int v9; // eax
  int *v10; // eax
  int **v11; // ebp
  int *v12; // eax
  _DWORD *v13; // eax
  int *v14; // eax
  int *v15; // eax

  v3 = (char *)(a3 + 628);
  if ( !a3 )
    v3 = (char *)(this + 109);
  v4 = *(int **)v3;
  v5 = *(_DWORD *)v3 == 0;
  *((_DWORD *)v3 + 2) = *(_DWORD *)v3;
  if ( v5 || (v6 = *v4) == 0 )
  {
LABEL_12:
    if ( a3 )
      v11 = (int **)(a3 + 628);
    else
      v11 = (int **)(this + 113);
    v12 = *v11;
    v5 = *v11 == 0;
    v11[2] = *v11;
    if ( v5 )
      return 0;
    v6 = *v12;
    if ( !*v12 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v13 = *(_DWORD **)(v6 + 628);
        *(_DWORD *)(v6 + 636) = v13;
        if ( v13 )
        {
          if ( *v13 )
          {
            result = sub_5DA9A0(a2, v6);
            if ( result )
              break;
          }
        }
        if ( !strcmp((const char *)(v6 + 468), a2) )
          return v6;
        v14 = v11[2];
        if ( v14 )
        {
          v15 = (int *)v14[1];
          v11[2] = v15;
          if ( v15 )
          {
            v6 = *v15;
            if ( *v15 )
              continue;
          }
        }
        return 0;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = *(_DWORD **)(v6 + 628);
      *(_DWORD *)(v6 + 636) = v7;
      if ( v7 )
      {
        if ( *v7 )
        {
          result = sub_5DA9A0(a2, v6);
          if ( result )
            break;
        }
      }
      if ( !strcmp((const char *)(v6 + 468), a2) )
        return v6;
      v9 = *((_DWORD *)v3 + 2);
      if ( v9 )
      {
        v10 = *(int **)(v9 + 4);
        *((_DWORD *)v3 + 2) = v10;
        if ( v10 )
        {
          v6 = *v10;
          if ( *v10 )
            continue;
        }
      }
      goto LABEL_12;
    }
  }
  return result;
}
