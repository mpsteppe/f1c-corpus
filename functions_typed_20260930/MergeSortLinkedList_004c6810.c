_DWORD **__stdcall sub_4C6810(int a1)
{
  int v1; // eax
  int v2; // ecx
  _DWORD **result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  _DWORD **v7; // edi
  _DWORD **v8; // esi
  _DWORD **v9; // ebx
  _DWORD **v10; // eax
  _DWORD **v11; // [esp+Ch] [ebp+4h]

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return (_DWORD **)a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return (_DWORD **)a1;
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
  v7 = (_DWORD **)MergeSortLinkedList(a1);
  result = (_DWORD **)MergeSortLinkedList(v6);
  v8 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( SceneSortComparator(*v7, *result) )
      {
        v11 = v7;
        v9 = v7;
        v7 = (_DWORD **)v7[1];
      }
      else
      {
        v11 = v8;
        v9 = v8;
        v8 = (_DWORD **)v8[1];
      }
      if ( v7 )
      {
        while ( v8 )
        {
          if ( SceneSortComparator(*v7, *v8) )
          {
            v10 = v7;
            v7 = (_DWORD **)v7[1];
          }
          else
          {
            v10 = v8;
            v8 = (_DWORD **)v8[1];
          }
          v9[1] = v10;
          v9 = v10;
          if ( !v7 )
            goto LABEL_18;
        }
        result = v11;
        v9[1] = v7;
      }
      else
      {
LABEL_18:
        result = v11;
        if ( v8 )
          v9[1] = v8;
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

