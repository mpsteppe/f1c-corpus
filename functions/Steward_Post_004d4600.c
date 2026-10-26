_DWORD *__thiscall sub_4D4600(int this)
{
  _DWORD *v2; // ecx
  void *v3; // edi
  void *v4; // eax
  int i; // edi
  int v6; // eax
  int v7; // ecx
  void *v8; // ebp
  int v9; // edi
  int v10; // ecx
  void *v11; // eax
  _DWORD *result; // eax
  int v13; // ecx
  int v14; // [esp+Ch] [ebp-4h]

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_3, 2855) )
    DebugLogWrite(&dword_8AD25C, aEnteredSteward_2);
  v2 = *(_DWORD **)(this + 168);
  if ( v2 )
  {
    D3DStateInit(v2);
    v3 = *(void **)(this + 168);
    if ( v3 )
    {
      D3DStateInit(*(_DWORD **)(this + 168));
      FreeWrapper_7bcf(v3);
    }
    *(_DWORD *)(this + 168) = 0;
  }
  ArithmeticComparison_2e20((int **)this);
  sub_4D24D0();
  CameraDirectorResetInit((char *)this);
  v4 = *(void **)(this + 272);
  *(_DWORD *)(this + 268) = 0;
  if ( v4 )
  {
    FreeWrapper_7bcf(v4);
    *(_DWORD *)(this + 272) = 0;
  }
  if ( *(_DWORD *)(this + 276) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 276));
    *(_DWORD *)(this + 276) = 0;
  }
  if ( dword_7D0410 != 4 )
    SeasonScoringInfoUpdater(dword_7D2DB0);
  for ( i = 0; i < dword_5C329C; ++i )
    StructResetReinitializer(dword_7C54F0[i] + 16436);
  if ( *(_DWORD *)(this + 272) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 272));
    *(_DWORD *)(this + 272) = 0;
  }
  v6 = *(_DWORD *)(this + 428);
  *(_DWORD *)(this + 424) = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 - 4);
    v8 = (void *)(v6 - 4);
    v9 = v6 + 8 * v7;
    v10 = v7 - 1;
    if ( v10 >= 0 )
    {
      v14 = v10 + 1;
      do
      {
        v11 = *(void **)(v9 - 8);
        v9 -= 8;
        if ( v11 )
          FreeWrapper_7bcf(v11);
        --v14;
      }
      while ( v14 );
    }
    FreeWrapper_7bcf(v8);
    *(_DWORD *)(this + 428) = 0;
  }
  result = (_DWORD *)(this + 640);
  v13 = 52;
  do
  {
    *(result - 52) = 0;
    *result++ = 0;
    --v13;
  }
  while ( v13 );
  return result;
}
