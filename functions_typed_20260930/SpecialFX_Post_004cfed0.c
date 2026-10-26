int __thiscall sub_4CFED0(_DWORD *this)
{
  int v2; // eax
  int v3; // ebx
  void *v4; // ebp
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // eax
  void *v8; // ebp
  LPVOID *v9; // edi
  int v10; // ebx
  int result; // eax
  int v12; // edi
  int v13; // ecx
  void *v14; // ebp
  _DWORD *v15; // edi
  int v16; // ebx

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_25, 3371) )
    DebugLogWrite(&dword_8AD25C, aEnteredSpecial_3);
  v2 = this[1];
  v3 = 0;
  *this = 0;
  if ( v2 )
  {
    v4 = (void *)(v2 - 4);
    v5 = (_DWORD *)(v2 + 60 * *(_DWORD *)(v2 - 4));
    if ( *(_DWORD *)(v2 - 4) - 1 >= 0 )
    {
      v6 = *(_DWORD *)(v2 - 4);
      do
      {
        v5 -= 15;
        sub_4CA280(v5);
        --v6;
      }
      while ( v6 );
      v3 = 0;
    }
    FreeWrapper_7bcf(v4);
    this[1] = 0;
  }
  CollisionTreeNodeCleanup((int)dbl_7C9360);
  v7 = this[3];
  if ( v7 )
  {
    v8 = (void *)(v7 - 4);
    v9 = (LPVOID *)(v7 + 108 * *(_DWORD *)(v7 - 4));
    if ( *(_DWORD *)(v7 - 4) - 1 >= 0 )
    {
      v10 = *(_DWORD *)(v7 - 4);
      do
      {
        v9 -= 27;
        FreeIfNonNull(v9);
        --v10;
      }
      while ( v10 );
      v3 = 0;
    }
    FreeWrapper_7bcf(v8);
  }
  result = this[4];
  v12 = 0;
  this[3] = 0;
  for ( this[2] = 0; v12 < result; v3 += 108 )
  {
    MultiFieldFree((_DWORD *)(v3 + this[5]));
    result = this[4];
    ++v12;
  }
  v13 = this[5];
  if ( v13 )
  {
    v14 = (void *)(v13 - 4);
    v15 = (_DWORD *)(v13 + 108 * *(_DWORD *)(v13 - 4));
    if ( *(_DWORD *)(v13 - 4) - 1 >= 0 )
    {
      v16 = *(_DWORD *)(v13 - 4);
      do
      {
        v15 -= 27;
        sub_4CA410(v15);
        --v16;
      }
      while ( v16 );
    }
    result = FreeWrapper_7bcf(v14);
  }
  this[5] = 0;
  this[4] = 0;
  this[7] = 0;
  this[6] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  return result;
}

