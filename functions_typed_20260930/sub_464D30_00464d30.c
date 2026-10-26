int __thiscall sub_464D30(_DWORD *this, int a2)
{
  int v3; // edi
  LPVOID *v4; // ebp
  bool v5; // zf
  int v6; // edi
  LPVOID *v7; // ebp
  int v8; // ecx
  int result; // eax
  int v10; // ecx
  int v11; // edx
  int i; // edi
  LPVOID *v13; // ebp
  int j; // edi
  LPVOID *v15; // ebp

  *this = a2;
  TimerResetUsingQueryPerformanceCounter(this + 1);
  this[25] = 1065353216;
  this[26] = 0;
  this[24] = 0;
  v3 = this[27];
  while ( v3 )
  {
    v4 = (LPVOID *)v3;
    v5 = *(_BYTE *)(v3 + 8) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 )
      FreeWrapper_7bcf(*v4);
    FreeWrapper_7bcf(v4);
  }
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  v6 = this[31];
  while ( v6 )
  {
    v7 = (LPVOID *)v6;
    v5 = *(_BYTE *)(v6 + 8) == 0;
    v6 = *(_DWORD *)(v6 + 4);
    if ( !v5 )
      FreeWrapper_7bcf(*v7);
    FreeWrapper_7bcf(v7);
  }
  this[31] = 0;
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  v8 = (int)(this + 35);
  do
  {
    result = CollisionSensorInit(v8);
    v8 = v10 + 560;
  }
  while ( v11 != 1 );
  this[14595] = 0;
  for ( i = this[14700]; i; result = FreeWrapper_7bcf(v13) )
  {
    v13 = (LPVOID *)i;
    v5 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v5 )
      FreeWrapper_7bcf(*v13);
  }
  this[14700] = 0;
  this[14701] = 0;
  this[14702] = 0;
  this[14703] = 0;
  for ( j = this[14704]; j; result = FreeWrapper_7bcf(v15) )
  {
    v15 = (LPVOID *)j;
    v5 = *(_BYTE *)(j + 8) == 0;
    j = *(_DWORD *)(j + 4);
    if ( !v5 )
      FreeWrapper_7bcf(*v15);
  }
  this[14704] = 0;
  this[14705] = 0;
  this[14706] = 0;
  this[14707] = 0;
  return result;
}

