int __thiscall sub_4072E0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ebp
  int v5; // edi
  int v6; // ecx
  int *v7; // eax
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // ebp
  int v12; // edi
  int v13; // eax
  int v14; // edx

  result = this[18];
  if ( result )
  {
    v4 = 0;
    if ( (int)this[19] > 0 )
    {
      v5 = 0;
      do
      {
        v6 = *(_DWORD *)(v5 + this[18]);
        if ( v6 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6);
        if ( *(_DWORD *)(v5 + this[18] + 16) )
        {
          AIL_release_sample_handle(*(_DWORD *)(v5 + this[18] + 16));
          *(_DWORD *)(v5 + this[18] + 16) = 0;
        }
        ++v4;
        v5 += 20;
      }
      while ( v4 < this[19] );
    }
    result = this[18];
    if ( result )
      result = FreeWrapper_7bcf((LPVOID)(result - 4));
    this[18] = 0;
  }
  this[19] = a2;
  if ( a2 > 0 )
  {
    v7 = (int *)OperatorNewNhMallocWrapper(20 * a2 + 4);
    if ( v7 )
    {
      v8 = v7 + 1;
      *v7 = a2;
      v9 = v7 + 1;
      if ( a2 - 1 >= 0 )
      {
        v10 = a2;
        do
        {
          *v9 = 0;
          v9[1] = 0;
          v9[2] = 0;
          *((_BYTE *)v9 + 12) = 0;
          v9[4] = 0;
          v9 += 5;
          --v10;
        }
        while ( v10 );
      }
      result = (int)v8;
    }
    else
    {
      result = 0;
    }
    this[18] = result;
    if ( result )
    {
      result = this[19];
      v11 = 0;
      if ( result > 0 )
      {
        v12 = 0;
        do
        {
          v13 = v12 + this[18];
          *(_DWORD *)v13 = 0;
          *(_DWORD *)(v13 + 4) = 0;
          *(_DWORD *)(v13 + 8) = 0;
          *(_BYTE *)(v13 + 12) = 0;
          *(_DWORD *)(v13 + 16) = 0;
          if ( this[36] )
          {
            *(_DWORD *)(v12 + this[18] + 16) = AIL_allocate_sample_handle(this[36]);
            v14 = this[18];
            if ( *(_DWORD *)(v12 + v14 + 16) )
              AIL_init_sample(*(_DWORD *)(v12 + v14 + 16));
          }
          result = this[19];
          ++v11;
          v12 += 20;
        }
        while ( v11 < result );
      }
    }
    else
    {
      this[19] = 0;
    }
  }
  return result;
}
