int __thiscall sub_548190(_DWORD *this, int a2)
{
  _DWORD *v2; // ebp
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // ecx
  int v6; // esi
  int *v7; // eax
  _DWORD *v8; // ebp
  _DWORD *v9; // edi
  _DWORD *v10; // esi
  int v11; // eax
  unsigned int *v12; // ebp
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  _DWORD *v18; // esi
  float v20; // [esp+0h] [ebp-3Ch]
  int v21; // [esp+14h] [ebp-28h]
  unsigned __int16 v22; // [esp+18h] [ebp-24h]
  unsigned __int16 v23; // [esp+1Ah] [ebp-22h]
  unsigned int v24; // [esp+1Ch] [ebp-20h]
  int v26; // [esp+24h] [ebp-18h]
  int v27; // [esp+28h] [ebp-14h]
  int v28; // [esp+2Ch] [ebp-10h]
  int v29; // [esp+30h] [ebp-Ch]
  char v30[8]; // [esp+34h] [ebp-8h] BYREF

  v2 = this;
  ArithmeticComparison_a5c0(4);
  v26 = 0;
  if ( v27 <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = (_DWORD *)OperatorNewNhMallocWrapper(196);
    v4 = v3 ? ConstructorInputControlInit(v3) : 0;
    v4[46] = v2;
    ArithmeticComparison_a5c0(32);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    v4[39] |= 2u;
    sub_547240((int)v4, v22, v23);
    SimpleSetter_71c0(v5, v28);
    ArithmeticComparison_a5c0(4);
    v6 = v4[41];
    if ( v6 > 0 )
    {
      v7 = (int *)OperatorNewNhMallocWrapper(148 * v6 + 4);
      if ( v7 )
      {
        v8 = v7 + 1;
        *v7 = v6;
        v9 = v7 + 1;
        if ( v6 - 1 >= 0 )
        {
          do
          {
            StructInitWithDefaults_fb90(v9);
            v9 += 37;
            --v6;
          }
          while ( v6 );
        }
        v10 = v8;
        v2 = this;
      }
      else
      {
        v10 = 0;
      }
      v11 = v4[41];
      v4[42] = v10;
      v21 = 0;
      if ( v11 > 0 )
        break;
    }
LABEL_32:
    v18 = v4 + 39;
    if ( (v4[39] & 0x200) != 0 )
    {
      RandomPasswordKeyGenerator(a2, v30);
      sub_587DD0(v4 + 16, v30, 4);
      strcat((char *)v4, v30);
      v18 = v4 + 39;
    }
    if ( ArithmeticComparisonBinarySearch(v2, (const char *)v4) )
    {
      ArrayCleanupWithDualFree(v4);
      EmptyStub_7470(v4);
      FreeWrapper_7bcf(v4);
    }
    else
    {
      sub_547670(v2, v4);
      if ( (BYTE1(*v18) & 0x80u) == 0 )
        *v18 |= 1u;
    }
    if ( ++v26 >= v27 )
      return 0;
  }
  while ( 1 )
  {
    ArithmeticComparison_a5c0(32);
    v12 = v10 + 16;
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    if ( (int)v10[18] > 1 )
    {
      ArithmeticComparison_a5c0(4);
      v13 = OperatorNewNhMallocWrapper(4 * v10[20]);
      v14 = 4 * v10[20];
      v10[19] = v13;
      ArithmeticComparison_a5c0(v14);
      ArithmeticComparison_a5c0(4);
      ArithmeticComparison_a5c0(4);
    }
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    v20 = (float)v29;
    FloatToIntMultiply(v20);
    FieldSetterAt0x80(v24 & 0xFFFFFF);
    sub_54FCC0(HIBYTE(v24));
    PlaybackRateConfigSetter(*v12 & 0xC, v10[17]);
    v15 = v10[24];
    if ( v15 <= (int)&unk_800000 )
    {
      if ( (_UNKNOWN *)v10[24] == &unk_800000 )
      {
        v16 = sub_546F70(v4, v21);
        goto LABEL_25;
      }
      if ( v15 == 0x100000 )
      {
        sub_546F30(v4, v21);
      }
      else if ( v15 == 0x400000 )
      {
        v16 = sub_546FE0(v4, v21);
        goto LABEL_25;
      }
      goto LABEL_26;
    }
    if ( v15 == 0x1000000 )
      break;
    if ( v15 == 0x8000000 )
    {
      v16 = GuardedRenderStateSet(v4, v21);
      goto LABEL_25;
    }
LABEL_26:
    v17 = *v12 & 0xFFFFFEFF;
    *v12 = v17;
    if ( (v17 & 0x100) != 0 )
      v4[39] |= 0x200u;
    if ( (*v12 & 0x200) != 0 )
      v4[39] |= 0x4000u;
    v10 += 37;
    if ( ++v21 >= v4[41] )
    {
      v2 = this;
      goto LABEL_32;
    }
  }
  v16 = ConditionalRenderStateSetup(v4, v21);
LABEL_25:
  if ( !v16 )
    goto LABEL_26;
  return -1;
}

