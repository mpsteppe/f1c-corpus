char __thiscall sub_4ECEA0(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  int *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int **v9; // eax
  int v10; // edx
  int *v11; // eax
  int v12; // eax

  v3 = this[24];
  if ( !v3 )
    return 0;
  v4 = a2;
  if ( a2 < 0 || a2 >= *(_DWORD *)(v3 + 96) )
    return 0;
  v5 = *(int **)(v3 + 84);
  if ( a2 > 0 )
  {
    while ( v5 )
    {
      v5 = (int *)v5[1];
      if ( --v4 <= 0 )
        goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( !v5 )
    return 0;
  v6 = *v5;
  if ( !v6 )
    return 0;
  *(_DWORD *)(v6 + 28) = a3;
  if ( !a2 )
  {
    v7 = this[24];
    v8 = *(_DWORD *)(v7 + 96);
    v9 = (int **)(v7 + 84);
    v10 = 1;
    if ( v8 > 1 )
    {
      v11 = *v9;
      while ( v11 )
      {
        v11 = (int *)v11[1];
        if ( --v10 <= 0 )
        {
          if ( v11 )
          {
            v12 = *v11;
            if ( v12 )
              *(_DWORD *)(v12 + 28) = a3;
          }
          return 1;
        }
      }
    }
  }
  return 1;
}
