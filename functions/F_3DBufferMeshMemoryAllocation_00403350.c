int __thiscall sub_403350(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // edx
  _DWORD *v11; // eax
  __int64 v12; // rax
  int i; // ecx
  _DWORD *v14; // eax
  int v16; // [esp-8h] [ebp-10h]

  if ( *(_DWORD *)(this + 336) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 336));
  if ( *(_DWORD *)(this + 340) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 340));
  if ( *(_DWORD *)(this + 344) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 344));
  v2 = *(_DWORD *)(this + 348) + 1;
  v3 = v2 + *(_DWORD *)(this + 352);
  *(_DWORD *)(this + 12) = v2;
  v4 = *(_DWORD *)(this + 356);
  *(_DWORD *)(this + 16) = v3;
  *(_DWORD *)(this + 8) = 1;
  *(_DWORD *)(this + 20) = v4 + v3;
  v5 = OperatorNewNhMallocWrapper(28 * v4);
  v16 = 28 * *(_DWORD *)(this + 352);
  *(_DWORD *)(this + 340) = v5;
  *(_DWORD *)(this + 336) = OperatorNewNhMallocWrapper(v16);
  *(_DWORD *)(this + 344) = OperatorNewNhMallocWrapper(28 * *(_DWORD *)(this + 356) * *(_DWORD *)(this + 360));
  v6 = 0;
  if ( *(int *)(this + 356) > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (_DWORD *)(v7 + *(_DWORD *)(this + 340));
      *v8 = 0;
      v8[1] = 0;
      v8[2] = 0;
      v8[3] = 0;
      v8[4] = 0;
      v8[5] = 0;
      v8[6] = 0;
      ++v6;
      v7 += 28;
    }
    while ( v6 < *(_DWORD *)(this + 356) );
  }
  v9 = 0;
  if ( *(int *)(this + 352) > 0 )
  {
    v10 = 0;
    do
    {
      v11 = (_DWORD *)(v10 + *(_DWORD *)(this + 336));
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
      v11[3] = 0;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      ++v9;
      v10 += 28;
    }
    while ( v9 < *(_DWORD *)(this + 352) );
  }
  v12 = *(unsigned int *)(this + 356);
  if ( (int)v12 > 0 )
  {
    LODWORD(v12) = *(_DWORD *)(this + 360);
    do
    {
      for ( i = 0; i < (int)v12; ++i )
      {
        v14 = (_DWORD *)(*(_DWORD *)(this + 344) + 28 * (HIDWORD(v12) + i * *(_DWORD *)(this + 356)));
        *v14 = 0;
        v14[1] = 0;
        v14[2] = 0;
        v14[3] = 0;
        v14[4] = 0;
        v14[5] = 0;
        v14[6] = 0;
        LODWORD(v12) = *(_DWORD *)(this + 360);
      }
      ++HIDWORD(v12);
    }
    while ( SHIDWORD(v12) < *(_DWORD *)(this + 356) );
  }
  return v12;
}
