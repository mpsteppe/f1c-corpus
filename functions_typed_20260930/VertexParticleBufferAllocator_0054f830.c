int __thiscall sub_54F830(int this, int a2, int a3)
{
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // ebx
  unsigned int v8; // esi
  _DWORD *v9; // edi
  bool v10; // zf
  _DWORD *v11; // edx
  _DWORD *v12; // esi
  int v13; // edi
  float *v14; // ebp
  float *v15; // ecx
  int v16; // esi
  int i; // edx
  double v18; // st5
  double v19; // st3
  double v20; // st4
  double v21; // st3
  double v22; // st4
  int result; // eax
  int v24; // [esp+10h] [ebp-4h]
  _DWORD *v25; // [esp+1Ch] [ebp+8h]
  int v26; // [esp+1Ch] [ebp+8h]
  float v27; // [esp+1Ch] [ebp+8h]

  v4 = *(_DWORD *)(this + 480);
  if ( v4 && *(_DWORD *)(v4 + 8) )
  {
    LinkedNodeDestruction(this);
    FreeWrapper_7bcf(*(LPVOID *)(this + 480));
    *(_DWORD *)(this + 480) = 0;
  }
  v5 = (_DWORD *)OperatorNewNhMallocWrapper(20);
  if ( v5 )
    v6 = sub_54EB20(v5);
  else
    v6 = 0;
  v7 = a3;
  v8 = 116 * a3;
  *(_DWORD *)(this + 480) = v6;
  v6[1] = a3;
  v9 = (_DWORD *)OperatorNewNhMallocWrapper(116 * a3);
  if ( v9 )
  {
    v25 = v9;
    if ( v7 - 1 >= 0 )
    {
      v24 = v7;
      do
      {
        ShortComputation_eaf0(v25);
        v10 = v24 == 1;
        v25 += 29;
        --v24;
      }
      while ( !v10 );
    }
  }
  else
  {
    v9 = 0;
  }
  *(_DWORD *)(*(_DWORD *)(this + 480) + 8) = v9;
  memset(*(void **)(*(_DWORD *)(this + 480) + 8), 0, v8);
  v11 = *(_DWORD **)(*(_DWORD *)(this + 480) + 8);
  if ( v7 > 0 )
  {
    v12 = (_DWORD *)(a2 + 8);
    v26 = v7;
    do
    {
      v11[1] = *(v12 - 2);
      v11[2] = *(v12 - 1);
      v11[3] = *v12;
      v11[7] = v12[1];
      v11[8] = v12[2];
      v11[9] = v12[3];
      *v11 = 0;
      memset(v11 + 13, 0, 0x40u);
      v11 += 29;
      v12 += 8;
      --v26;
    }
    while ( v26 );
  }
  v13 = *(_DWORD *)(this + 480);
  v27 = 0.0;
  if ( v7 > 0 )
  {
    v14 = *(float **)(this + 516);
    v15 = 0;
    v16 = *(_DWORD *)(v13 + 8) + 4;
    do
    {
      for ( i = 0; i < 2; ++i )
      {
        if ( i )
        {
          if ( i == 1 )
            v15 = (float *)(v16 + 24);
        }
        else
        {
          v15 = (float *)v16;
        }
        v18 = v14[57] - v15[2];
        v19 = v14[56] - v15[1];
        v20 = v18 * v18 + v19 * v19;
        v21 = v14[55] - *v15;
        v22 = v20 + v21 * v21;
        if ( v27 <= v22 )
          v27 = v22;
      }
      v16 += 116;
      --v7;
    }
    while ( v7 );
  }
  result = 0;
  *(float *)v13 = sqrt(v27);
  return result;
}

