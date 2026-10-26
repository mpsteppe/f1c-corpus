int __thiscall sub_4DED20(_DWORD *this)
{
  int v2; // ecx
  int result; // eax
  int v4; // eax
  void *v5; // ebp
  int v6; // edx
  int v7; // eax
  LPVOID *v8; // edi
  int v9; // ebx
  int v10; // ecx
  int v11; // eax
  void *v12; // ebp
  int v13; // edx
  int v14; // eax
  LPVOID *v15; // edi
  int v16; // ebx

  v2 = this[3];
  result = 0;
  this[1] = 0;
  this[2] = 0;
  if ( v2 )
  {
    v4 = *(_DWORD *)(v2 - 4);
    v5 = (void *)(v2 - 4);
    v6 = 3 * v4;
    v7 = v4 - 1;
    v8 = (LPVOID *)(v2 + 4 * v6);
    if ( v7 >= 0 )
    {
      v9 = v7 + 1;
      do
      {
        v8 -= 3;
        sub_4DD4C0(v8);
        --v9;
      }
      while ( v9 );
    }
    FreeWrapper_7bcf(v5);
    result = 0;
  }
  v10 = this[5];
  this[3] = 0;
  this[4] = 0;
  if ( v10 )
  {
    v11 = *(_DWORD *)(v10 - 4);
    v12 = (void *)(v10 - 4);
    v13 = 3 * v11;
    v14 = v11 - 1;
    v15 = (LPVOID *)(v10 + 8 * v13);
    if ( v14 >= 0 )
    {
      v16 = v14 + 1;
      do
      {
        v15 -= 6;
        ShortComputation_d4d0(v15);
        --v16;
      }
      while ( v16 );
    }
    FreeWrapper_7bcf(v12);
    result = 0;
  }
  this[5] = 0;
  this[6] = 0;
  return result;
}
