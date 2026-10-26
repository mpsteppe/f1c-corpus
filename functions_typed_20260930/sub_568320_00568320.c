char __thiscall sub_568320(_DWORD *this, _DWORD *a2)
{
  int v4; // eax
  int v5; // edx
  bool v6; // bl
  char *v7; // eax
  int v8; // eax
  char v10; // [esp+11h] [ebp-3h]
  bool v11; // [esp+12h] [ebp-2h]
  bool v12; // [esp+13h] [ebp-1h]
  bool v13; // [esp+18h] [ebp+4h]

  if ( a2 )
  {
    v4 = sub_563E70(a2);
    v5 = a2[9];
    v12 = v4 == 0;
    v6 = a2[1] != 0;
    v13 = a2[3] != 0;
    v11 = v5 != 0;
    if ( v5 || (v10 = 1, a2[10]) )
      v10 = 0;
    v7 = StringPointerAccessor(a2);
    v8 = StringHash(v7);
    if ( v12 )
    {
      if ( v10 )
      {
        if ( v13 )
        {
          this[v8] = a2[3];
          *(_DWORD *)(a2[3] + 40) = 0;
          *(_DWORD *)(a2[3] + 4) = a2[1];
          RecursiveTreeTraversalFree(a2);
          return 0;
        }
        this[v8] = a2[1];
        goto LABEL_14;
      }
    }
    else if ( v10 )
    {
      if ( v13 )
      {
        *(_DWORD *)(*a2 + 8) = a2[3];
        *(_DWORD *)(a2[3] + 40) = 0;
        *(_DWORD *)(a2[3] + 4) = a2[1];
        *(_DWORD *)a2[3] = *a2;
        RecursiveTreeTraversalFree(a2);
        return 0;
      }
      *(_DWORD *)(*a2 + 8) = a2[1];
LABEL_14:
      if ( v6 )
      {
        *(_DWORD *)(a2[1] + 36) = 0;
        RecursiveTreeTraversalFree(a2);
        return 0;
      }
      goto LABEL_21;
    }
    if ( v11 )
    {
      *(_DWORD *)(a2[9] + 4) = a2[1];
      if ( v6 )
      {
        *(_DWORD *)(a2[1] + 36) = a2[9];
        RecursiveTreeTraversalFree(a2);
        return 0;
      }
    }
    else
    {
      *(_DWORD *)(a2[10] + 12) = a2[3];
      if ( v13 )
        *(_DWORD *)(a2[3] + 40) = a2[10];
    }
  }
LABEL_21:
  RecursiveTreeTraversalFree(a2);
  return 0;
}

