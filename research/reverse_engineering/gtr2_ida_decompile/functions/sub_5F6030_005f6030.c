int __stdcall sub_5F6030(char *SubStr, int a2, int *a3, int a4)
{
  int result; // eax
  int v5; // edx
  int v6; // esi
  int v8; // ecx
  int *v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  int v13; // eax
  char *v14; // eax
  int v15; // [esp+0h] [ebp-8h]
  int v16; // [esp+4h] [ebp-4h]
  int v17; // [esp+14h] [ebp+Ch]

  result = a4;
  v5 = 0;
  v16 = 0;
  if ( a4 )
  {
    v6 = a2;
    v15 = 0;
    if ( *(int *)(a2 + 544) > 0 )
    {
      do
      {
        *a3 = 0;
        v8 = v5;
        if ( v5 >= 0 && v5 < *(_DWORD *)(v6 + 544) )
        {
          v9 = *(int **)(v6 + 532);
          if ( v5 <= 0 )
          {
LABEL_8:
            if ( v9 )
            {
              v10 = *v9;
              if ( *v9 )
              {
                v11 = 0;
                if ( *(int *)(v10 + 360) > 0 )
                {
                  v17 = 0;
                  do
                  {
                    *a3 = 0;
                    if ( v11 < *(_DWORD *)(v10 + 360) )
                    {
                      v12 = v17 + *(_DWORD *)(v10 + 364);
                      if ( v12 )
                      {
                        v13 = *(_DWORD *)(v12 + 4);
                        if ( v13 )
                        {
                          if ( !SubStr || (v14 = strstr((const char *)(v13 + 4), SubStr), v5 = v15, v14) )
                          {
                            *a3++ = v12;
                            result = v16 + 1;
                            v16 = result;
                            if ( result >= a4 )
                              return result;
                            *a3 = 0;
                          }
                        }
                      }
                    }
                    ++v11;
                    v17 += 108;
                  }
                  while ( v11 < *(_DWORD *)(v10 + 360) );
                  v6 = a2;
                }
              }
            }
          }
          else
          {
            while ( v9 )
            {
              v9 = (int *)v9[1];
              if ( --v8 <= 0 )
                goto LABEL_8;
            }
          }
        }
        result = *(_DWORD *)(v6 + 544);
        v15 = ++v5;
      }
      while ( v5 < result );
    }
  }
  return result;
}
