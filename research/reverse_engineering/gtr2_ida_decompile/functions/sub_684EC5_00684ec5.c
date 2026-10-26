int __fastcall sub_684EC5(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // ebx
  int v6; // esi
  unsigned int v7; // edi
  bool v8; // zf
  int v9; // eax
  int v10; // edx
  int *v11; // eax
  _DWORD *v12; // ebx
  int v13; // edi
  int result; // eax
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  unsigned int v21; // edi
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  _DWORD *v23; // [esp+10h] [ebp-8h] BYREF
  unsigned int v24; // [esp+14h] [ebp-4h]
  unsigned int v25; // [esp+20h] [ebp+8h]
  unsigned int v26; // [esp+20h] [ebp+8h]

  v5 = a1;
  v6 = *(_DWORD *)(a1[6] + 4 * a3);
  v7 = 0;
  v8 = *(_DWORD *)(v6 + 36) == 0;
  v24 = (unsigned int)a1;
  if ( !v8 )
    return 0;
  if ( *(_DWORD *)(v6 + 20) )
  {
    do
    {
      v9 = *(_DWORD *)(v6 + 24);
      v10 = v5[6];
      v22 = 0;
      v11 = (int *)(v9 + 4 * v7);
      v12 = *(_DWORD **)(v10 + 4 * *v11);
      v23 = 0;
      sub_684E45((_DWORD *)v24, v12, &v23, &v22, *v11);
      ++v7;
      v12[12] = v22 / ((int)v23 + 1);
      v5 = (_DWORD *)v24;
    }
    while ( v7 < *(_DWORD *)(v6 + 20) );
  }
  sub_682274((int (__stdcall *)(int, int, int))sub_681F34, *(int **)(v6 + 24), *(_DWORD *)(v6 + 20), (int)v5);
  v13 = 0;
  if ( !*(_DWORD *)(v6 + 20) )
  {
LABEL_7:
    if ( !*(_DWORD *)(v6 + 36) )
    {
      v24 = 0;
      *(_DWORD *)(v6 + 36) = 1;
      *(_DWORD *)(a4 + 4 * (*a5)++) = a3;
      if ( *(_DWORD *)(v6 + 20) )
      {
        while ( 1 )
        {
          v15 = v5[6];
          v16 = *(_DWORD *)(v15 + 4 * *(_DWORD *)(*(_DWORD *)(v6 + 24) + 4 * v24));
          v17 = *(_DWORD *)(v16 + 28);
          v25 = 0;
          v18 = -1;
          if ( v17 )
          {
            v22 = *(_DWORD *)(v16 + 32);
            v23 = (_DWORD *)v22;
            do
            {
              if ( !*(_DWORD *)(*(_DWORD *)(v15 + 4 * *v23) + 36) )
              {
                if ( v18 != -1 )
                  goto LABEL_16;
                v18 = v25;
              }
              ++v25;
              ++v23;
            }
            while ( v25 < v17 );
            if ( v18 == -1 )
              goto LABEL_23;
LABEL_16:
            if ( v25 == v17 )
            {
              v19 = *(_DWORD *)(v22 + 4 * v18);
              v20 = *(_DWORD *)(v15 + 4 * v19);
              v21 = *(_DWORD *)(v20 + 20);
              v26 = 0;
              if ( v21 )
              {
                v23 = *(_DWORD **)(v20 + 24);
                do
                {
                  if ( !*(_DWORD *)(*(_DWORD *)(v15 + 4 * *v23) + 36) )
                    break;
                  ++v26;
                  ++v23;
                }
                while ( v26 < v21 );
              }
              if ( v26 >= v21 )
              {
                result = sub_684EC5(v19, a4, a5);
                if ( result < 0 )
                  return result;
              }
            }
          }
LABEL_23:
          if ( ++v24 >= *(_DWORD *)(v6 + 20) )
            return 0;
        }
      }
    }
    return 0;
  }
  while ( 1 )
  {
    result = sub_684EC5(*(_DWORD *)(*(_DWORD *)(v6 + 24) + 4 * v13), a4, a5);
    if ( result < 0 )
      return result;
    if ( (unsigned int)++v13 >= *(_DWORD *)(v6 + 20) )
      goto LABEL_7;
  }
}
