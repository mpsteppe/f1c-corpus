char __thiscall sub_4CB120(char *this, char a2)
{
  int v2; // eax
  double v4; // st7
  char v5; // cl
  int v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // ebp
  _DWORD *v9; // edx
  int v10; // edx
  double v11; // st7
  double v12; // st7
  int v13; // edx
  int v14; // edi
  int v15; // ebp
  float *v16; // esi
  double v17; // st7
  double v18; // st7
  int v19; // edx
  float *v20; // ecx
  double v21; // st7
  double v22; // st6
  int v23; // edx
  int v24; // edx
  long double v25; // st6
  long double v26; // st6
  double v27; // st7
  float v29; // [esp+8h] [ebp-108h]
  float v30; // [esp+8h] [ebp-108h]
  float v31; // [esp+Ch] [ebp-104h]
  _BYTE v32[256]; // [esp+10h] [ebp-100h] BYREF

  dword_5D3488 = dword_7CF998;
  LOBYTE(v2) = a2;
  flt_5D348C = flt_7CF974 * flt_7CF974;
  v4 = flt_7CF974 + *(float *)&dword_7CF998;
  flt_5D3490 = v4;
  flt_5D3494 = v4 * 1.4142135;
  if ( a2 )
  {
    v5 = 4 - dword_7CF8A8;
    *((_DWORD *)this + 2) = 4 - dword_7CF8A8;
    if ( dword_7CF8A8 )
    {
      *((int *)this + 22) >>= v5;
    }
    else
    {
      *((_DWORD *)this + 22) = 0;
      *((_DWORD *)this + 25) = 0;
    }
  }
  if ( *((int *)this + 22) > 0 )
  {
    StringFormatWithBufferOverflowCheck(*((_DWORD *)this + 20), "Reaction%02d", *(_DWORD *)this);
    *(_DWORD *)(*((_DWORD *)this + 20) + 36) = *((_DWORD *)this + 22);
    *(_DWORD *)(*((_DWORD *)this + 20) + 40) = *((_DWORD *)this + 3);
    *(_DWORD *)(*((_DWORD *)this + 20) + 44) = *((_DWORD *)this + 4);
    *(_DWORD *)(*((_DWORD *)this + 20) + 48) = *((_DWORD *)this + 5);
    if ( sub_559200(this + 84, *((_DWORD *)this + 20)) )
    {
      StringRelocationCopy(0, v32);
      if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_25, 873) )
        DebugLogWrite(&dword_8AD25C, aCouldNotCreate_1);
      LOBYTE(v2) = StringSplitLoop(1, aDDevF119992002_25, 876);
      if ( (_BYTE)v2 )
        LOBYTE(v2) = DebugLogWrite(&dword_8AD25C, aCubeErrorS);
    }
    else
    {
      v6 = *((_DWORD *)this + 22);
      v7 = (_DWORD *)OperatorNewNhMallocWrapper(108 * v6 + 4);
      if ( v7 )
      {
        v8 = v7 + 1;
        *v7 = v6;
        v9 = v7 + 1;
        if ( v6 - 1 >= 0 )
        {
          do
          {
            SentinelFieldInit(v9);
            v9 = (_DWORD *)(v10 + 108);
            --v6;
          }
          while ( v6 );
        }
      }
      else
      {
        v8 = 0;
      }
      v11 = *((float *)this + 12);
      *((_DWORD *)this + 23) = v8;
      *((_DWORD *)this + 24) = 0;
      if ( v11 <= 0.0 )
        v12 = 0.0;
      else
        v12 = 1.0 / *((float *)this + 12);
      v13 = *((_DWORD *)this + 22);
      *((float *)this + 16) = v12;
      *((_DWORD *)this + 25) = 0;
      *((_DWORD *)this + 26) = OperatorNewNhMallocWrapper(4 * v13);
      v2 = *((_DWORD *)this + 22);
      v14 = 0;
      if ( v2 > 0 )
      {
        v15 = 0;
        do
        {
          *(_DWORD *)(*((_DWORD *)this + 23) + v15) = v14;
          *(_DWORD *)(*((_DWORD *)this + 23) + v15 + 4) = -1;
          ParticlePositionSetup(
            v15 + *((_DWORD *)this + 23),
            *((float *)this + 12),
            *((float *)this + 13),
            *((float *)this + 14),
            *((float *)this + 15));
          *(_DWORD *)(*((_DWORD *)this + 26) + 4 * v14) = 0;
          v2 = *((_DWORD *)this + 22);
          ++v14;
          v15 += 108;
        }
        while ( v14 < v2 );
      }
      if ( *((_DWORD *)this + 1) == 13 )
      {
        dword_8ACEDC = 0;
        v16 = &flt_8ACAA4;
        do
        {
          do
          {
            v17 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 20.0;
            v29 = v17;
            v18 = ((double)(DeterministicHashPseudoRandomGenerator(&dword_8AAE70) & 0x1FFFF) * 0.000015258789 - 1.0)
                * 20.0;
          }
          while ( v18 * v18 + v29 * v29 >= 400.0 );
          *v16 = v18;
          *(v16 - 1) = v29;
          v16 += 2;
        }
        while ( (int)v16 < (int)&flt_8ACEA4 );
        v19 = dword_8AAE70;
        v20 = (float *)&unk_8AC828;
        do
        {
          v21 = flt_8AB274[(unsigned __int8)v19];
          dword_8AAE70 = v19 + 1;
          v22 = flt_8AB274[(unsigned __int8)(v19 + 1)];
          v23 = v19 + 2;
          dword_8AAE70 = v23;
          v30 = v22;
          v31 = flt_8AB274[(unsigned __int8)v23];
          *v20 = v21;
          *(v20 - 2) = v31;
          *(v20 - 1) = v30;
          v24 = v23 + 1;
          dword_8AAE70 = v24;
          v25 = v31 * v31 + v30 * v30 + v21 * v21;
          if ( v25 == 0.0 )
          {
            *(v20 - 2) = 0.0;
            *(v20 - 1) = 1.0;
            *v20 = 0.0;
          }
          else
          {
            v26 = 1.0 / sqrt(v25);
            *(v20 - 2) = v31 * v26;
            *(v20 - 1) = v30 * v26;
            *v20 = v26 * v21;
          }
          LOBYTE(v2) = v24;
          v27 = flt_8AAE74[(unsigned __int8)v24];
          v19 = v24 + 1;
          v20 += 10;
          dword_8AAE70 = v19;
          *(v20 - 9) = -24.0 - v27 * 3.0;
        }
        while ( (int)v20 < (int)flt_8ACAA8 );
      }
    }
  }
  return v2;
}

