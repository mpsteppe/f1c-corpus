int __thiscall sub_44A700(int this, _DWORD *a2)
{
  _DWORD *v2; // esi
  __int16 v5; // ax
  bool v6; // cc
  int v7; // ebx
  int v8; // ebp
  unsigned __int8 v9; // [esp+13h] [ebp-5h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  v2 = a2;
  if ( FileWriteWithBackendDispatch(this, 4) != 4 )
    return -1;
  if ( FileWriteWithBackendDispatch(this + 4, 4) != 4 )
    return -1;
  if ( FileWriteWithBackendDispatch(&a2, 1) != 1 )
    return -1;
  v5 = (char)a2;
  v6 = (char)a2 <= -3;
  *(_WORD *)(this + 8) = (char)a2;
  if ( v6 )
    return -1;
  v7 = 2;
  if ( v5 >= 2 )
    return -1;
  v8 = 0;
  if ( v5 < 0 )
  {
    if ( v5 == -1 )
    {
      v7 = 1;
    }
    else if ( v5 != -2 )
    {
      v7 = (int)a2;
    }
    *(_DWORD *)(this + 12) = v2[9] + 92 * v2[7];
    v2[7] += v7;
    if ( v7 > 0 )
    {
      v10 = 0;
      while ( !IndexedVertexLookupFromStream((_DWORD *)(v10 + *(_DWORD *)(this + 12)), (int)v2) )
      {
        ++v8;
        v10 += 92;
        if ( v8 >= v7 )
          return 0;
      }
      return -1;
    }
    return 0;
  }
  if ( FileWriteWithBackendDispatch(&v9, 1) != 1 )
    return -1;
  *(_WORD *)(this + 10) = v9;
  *(_DWORD *)(this + 12) = v2[12] + 16 * v2[10];
  v2[10] += 2;
  if ( CollisionTreeNodeDeserializer(v2) )
    return -1;
  if ( !CollisionTreeNodeDeserializer(v2) )
    return 0;
  return -1;
}

