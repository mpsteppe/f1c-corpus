int __thiscall sub_4C1700(int *this)
{
  int v2; // esi
  int result; // eax
  LPVOID **v4; // edi
  char v5; // cl
  LPVOID *v6; // ebx
  int v7; // esi
  LPVOID **v8; // edi
  char v9; // al
  LPVOID *v10; // ebx
  int i; // esi
  _DWORD *v12; // edi
  char v13; // cl

  v2 = *this;
  for ( result = 0; v2; result = 0 )
  {
    v4 = (LPVOID **)v2;
    v5 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        PitStopMemoryCleanup(*v4);
        FreeWrapper_7bcf(v6);
      }
    }
    FreeWrapper_7bcf(v4);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v7 = this[4];
  if ( v7 )
  {
    do
    {
      v8 = (LPVOID **)v7;
      v9 = *(_BYTE *)(v7 + 8);
      v7 = *(_DWORD *)(v7 + 4);
      if ( v9 )
      {
        v10 = *v8;
        if ( *v8 )
        {
          ShortComputation_4370(v10 + 2);
          ShortComputation_4370(v10);
          FreeWrapper_7bcf(v10);
        }
      }
      FreeWrapper_7bcf(v8);
    }
    while ( v7 );
    result = 0;
  }
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  for ( i = *this; i; result = 0 )
  {
    v12 = (_DWORD *)i;
    v13 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v13 && *v12 )
      sub_4C1E20(1);
    FreeWrapper_7bcf(v12);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
