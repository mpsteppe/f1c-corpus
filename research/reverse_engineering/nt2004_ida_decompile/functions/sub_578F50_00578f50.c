int *__stdcall sub_578F50(int a1)
{
  int v1; // eax
  int v2; // ecx
  int *result; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ebx
  int *v7; // edi
  int *v8; // esi
  int *v9; // ebx
  int *v10; // eax
  int *v11; // [esp+Ch] [ebp+4h]

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
  v4 = a1;
  v5 = v1 / 2 - 1;
  if ( v5 > 0 )
  {
    do
    {
      v4 = *(_DWORD *)(v4 + 4);
      --v5;
    }
    while ( v5 );
  }
  v6 = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v4 + 4) = 0;
  v7 = (int *)sub_578F50(a1);
  result = (int *)sub_578F50(v6);
  v8 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( sub_578660((void *)*v7, *result) )
      {
        v11 = v7;
        v9 = v7;
        v7 = (int *)v7[1];
      }
      else
      {
        v11 = v8;
        v9 = v8;
        v8 = (int *)v8[1];
      }
      if ( v7 )
      {
        while ( v8 )
        {
          if ( sub_578660((void *)*v7, *v8) )
          {
            v10 = v7;
            v7 = (int *)v7[1];
          }
          else
          {
            v10 = v8;
            v8 = (int *)v8[1];
          }
          v9[1] = (int)v10;
          v9 = v10;
          if ( !v7 )
            goto LABEL_18;
        }
        result = v11;
        v9[1] = (int)v7;
      }
      else
      {
LABEL_18:
        result = v11;
        if ( v8 )
          v9[1] = (int)v8;
        else
          v9[1] = 0;
      }
    }
    else
    {
      return v7;
    }
  }
  return result;
}
