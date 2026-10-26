int *__stdcall sub_493160(int a1)
{
  int v1; // eax
  int v2; // ecx
  int *result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int *v7; // edi
  int *v8; // esi
  int *v9; // ebp
  int *v10; // ebx
  int *v11; // eax

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return (int *)a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return (int *)a1;
  v4 = v1 / 2 - 1;
  v5 = a1;
  if ( v4 > 0 )
  {
    do
    {
      --v4;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v4 );
  }
  v6 = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(v5 + 4) = 0;
  v7 = (int *)sub_493160(a1);
  result = (int *)sub_493160(v6);
  v8 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( sub_475A80((_DWORD *)*v7, *result) )
      {
        v9 = v7;
        v10 = v7;
        v7 = (int *)v7[1];
      }
      else
      {
        v9 = v8;
        v10 = v8;
        v8 = (int *)v8[1];
      }
      if ( v7 )
      {
        while ( v8 )
        {
          if ( sub_475A80((_DWORD *)*v7, *v8) )
          {
            v11 = v7;
            v7 = (int *)v7[1];
          }
          else
          {
            v11 = v8;
            v8 = (int *)v8[1];
          }
          v10[1] = (int)v11;
          v10 = v11;
          if ( !v7 )
            goto LABEL_18;
        }
        v10[1] = (int)v7;
        return v9;
      }
      else
      {
LABEL_18:
        if ( v8 )
          v10[1] = (int)v8;
        else
          v10[1] = 0;
        return v9;
      }
    }
    else
    {
      return v7;
    }
  }
  return result;
}
