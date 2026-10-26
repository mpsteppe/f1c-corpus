__int16 **__stdcall sub_490D00(int a1, int a2)
{
  int v2; // edi
  __int16 **result; // eax
  bool v4; // zf
  __int16 *v5; // ebx
  void **v6; // eax
  void *v7; // ebp
  void **v8; // edi
  void **v9; // eax
  int v10; // eax
  void **v11; // ecx
  int v12; // edi
  void **v13; // eax
  void *v14; // edx
  int v15; // eax
  int v16; // eax
  void **v17; // eax

  v2 = a2;
  result = *(__int16 ***)a2;
  v4 = *(_DWORD *)a2 == 0;
  *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
  if ( !v4 )
  {
    v5 = *result;
    if ( *result )
    {
      while ( 1 )
      {
        v6 = *(void ***)a1;
        v4 = *(_DWORD *)a1 == 0;
        *(_DWORD *)(a1 + 8) = *(_DWORD *)a1;
        if ( !v4 )
        {
          v7 = *v6;
          if ( *v6 )
            break;
        }
LABEL_46:
        result = (__int16 **)LinkedListNodeAdvance(v2);
        v5 = (__int16 *)result;
        if ( !result )
          return result;
      }
      while ( !(unsigned __int8)AABBOverlapTest(*v5, v5[1], v5[2], v5[3]) )
      {
        if ( (unsigned __int8)sub_491680(*v5, v5[1], v5[2], v5[3]) )
        {
          v10 = RectangleClipping(*v5, v5[1], v5[2], v5[3]);
          v11 = *(void ***)a1;
          v12 = v10;
          v13 = 0;
          if ( *(_DWORD *)a1 )
          {
            while ( *v11 != v7 )
            {
              v13 = v11;
              v11 = (void **)v11[1];
              if ( !v11 )
                goto LABEL_31;
            }
            if ( v11 == *(void ***)(a1 + 8) )
              *(_DWORD *)(a1 + 8) = v11[1];
            v14 = v11[1];
            if ( v13 )
              v13[1] = v14;
            else
              *(_DWORD *)a1 = v14;
            if ( *(void ***)(a1 + 4) == v11 )
              *(_DWORD *)(a1 + 4) = v13;
            --*(_DWORD *)(a1 + 12);
            ConditionalResourceCleanup(1);
          }
LABEL_31:
          while ( v12 )
          {
            if ( OperatorNewNhMallocWrapper(12) )
              v15 = ShortComputation_ac20(v12, 0);
            else
              v15 = 0;
            if ( *(_DWORD *)a1 )
            {
              *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) = v15;
            }
            else
            {
              *(_DWORD *)a1 = v15;
              *(_DWORD *)(a1 + 8) = v15;
            }
            *(_DWORD *)(a1 + 4) = v15;
            v16 = *(_DWORD *)(a1 + 12) + 1;
            *(_DWORD *)(a1 + 12) = v16;
            if ( v16 == 1 )
              ShortComputation_a780(a1);
            v12 = *(_DWORD *)(v12 + 12);
          }
          goto LABEL_41;
        }
        v7 = (void *)LinkedListNodeAdvance(a1);
LABEL_44:
        if ( !v7 )
        {
LABEL_45:
          v2 = a2;
          goto LABEL_46;
        }
      }
      v8 = *(void ***)a1;
      v9 = 0;
      if ( *(_DWORD *)a1 )
      {
        while ( *v8 != v7 )
        {
          v9 = v8;
          v8 = (void **)v8[1];
          if ( !v8 )
            goto LABEL_41;
        }
        if ( v8 == *(void ***)(a1 + 8) )
          *(_DWORD *)(a1 + 8) = v8[1];
        if ( v9 )
          v9[1] = v8[1];
        else
          *(_DWORD *)a1 = v8[1];
        if ( *(void ***)(a1 + 4) == v8 )
          *(_DWORD *)(a1 + 4) = v9;
        --*(_DWORD *)(a1 + 12);
        sub_491E40(v8);
        FreeWrapper_7bcf(v8);
      }
LABEL_41:
      LinkedListNodePrepend(v7);
      v17 = *(void ***)(a1 + 8);
      if ( !v17 )
        goto LABEL_45;
      v7 = *v17;
      goto LABEL_44;
    }
  }
  return result;
}
