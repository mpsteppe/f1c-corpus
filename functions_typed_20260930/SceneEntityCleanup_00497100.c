char __thiscall sub_497100(_DWORD *this, char a2)
{
  int *v3; // eax
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  int v7; // edi
  _DWORD *v8; // ebp
  bool v9; // zf
  int *v10; // eax
  int v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  _DWORD *v15; // ebp
  int *v16; // eax

  if ( a2 )
  {
    RenderFrameWrapper();
    v3 = (int *)this[1583];
    this[1585] = v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        do
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 68))(v4);
          v5 = this[1585];
          if ( !v5 )
            break;
          v6 = *(int **)(v5 + 4);
          this[1585] = v6;
          if ( !v6 )
            break;
          v4 = *v6;
        }
        while ( *v6 );
      }
    }
    v7 = this[1583];
    while ( v7 )
    {
      v8 = (_DWORD *)v7;
      v9 = *(_BYTE *)(v7 + 12) == 0;
      v7 = *(_DWORD *)(v7 + 4);
      if ( !v9 && *v8 )
        (**(void (__thiscall ***)(_DWORD, int))*v8)(*v8, 1);
      FreeWrapper_7bcf(v8);
    }
    this[1583] = 0;
    this[1584] = 0;
    this[1585] = 0;
    this[1586] = 0;
    v10 = (int *)this[1587];
    this[1589] = v10;
    if ( v10 )
    {
      v11 = *v10;
      if ( *v10 )
      {
        do
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 68))(v11);
          v12 = this[1589];
          if ( !v12 )
            break;
          v13 = *(int **)(v12 + 4);
          this[1589] = v13;
          if ( !v13 )
            break;
          v11 = *v13;
        }
        while ( *v13 );
      }
    }
    v14 = this[1587];
    while ( v14 )
    {
      v15 = (_DWORD *)v14;
      v9 = *(_BYTE *)(v14 + 12) == 0;
      v14 = *(_DWORD *)(v14 + 4);
      if ( !v9 && *v15 )
        (**(void (__thiscall ***)(_DWORD, int))*v15)(*v15, 1);
      FreeWrapper_7bcf(v15);
    }
    this[1587] = 0;
    this[1588] = 0;
    this[1589] = 0;
    this[1590] = 0;
    StateFlagComputation(0);
  }
  v16 = (int *)Accessor();
  return CircularBufferRingAdvance(v16);
}

