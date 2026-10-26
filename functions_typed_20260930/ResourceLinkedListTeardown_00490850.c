int sub_490850()
{
  void *v0; // esi
  int result; // eax
  int *v2; // ecx
  int v3; // esi
  _DWORD *v4; // ebp
  _DWORD *v5; // edi
  bool v6; // zf
  int v7; // esi
  _DWORD *v8; // edi
  void *v9; // ebp
  int v10; // [esp+0h] [ebp-4h]

  v0 = (void *)dword_7CD9D0;
  if ( dword_7CD9D0 )
  {
    ConditionalDestructor_1740();
    FreeWrapper_7bcf(v0);
  }
  result = dword_7CD9CC;
  v2 = (int *)dword_7CD9CC;
  v10 = dword_7CD9CC;
  if ( dword_7CD9CC )
  {
    v3 = *(_DWORD *)(dword_7CD9CC + 16);
    v4 = (_DWORD *)(dword_7CD9CC + 16);
    if ( v3 )
    {
      do
      {
        v5 = (_DWORD *)v3;
        v6 = *(_BYTE *)(v3 + 8) == 0;
        v3 = *(_DWORD *)(v3 + 4);
        if ( !v6 && *v5 )
          ShortComputation_1e60(1);
        FreeWrapper_7bcf(v5);
      }
      while ( v3 );
      v2 = (int *)v10;
    }
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    v4[3] = 0;
    v7 = *v2;
    if ( *v2 )
    {
      do
      {
        v8 = (_DWORD *)v7;
        v6 = *(_BYTE *)(v7 + 8) == 0;
        v7 = *(_DWORD *)(v7 + 4);
        if ( !v6 )
        {
          v9 = (void *)*v8;
          if ( *v8 )
          {
            UtilityFunction_1e80(*v8);
            FreeWrapper_7bcf(v9);
          }
        }
        FreeWrapper_7bcf(v8);
      }
      while ( v7 );
      v2 = (int *)v10;
    }
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    return FreeWrapper_7bcf(v2);
  }
  return result;
}

