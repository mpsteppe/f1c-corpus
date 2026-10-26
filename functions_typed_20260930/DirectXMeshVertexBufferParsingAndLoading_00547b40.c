int __thiscall sub_547B40(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  int v3; // esi
  _DWORD *v4; // eax
  char *v5; // ebp
  bool v6; // zf
  int *v7; // eax
  const CHAR *v8; // ebx
  _DWORD *v9; // edi
  const CHAR *v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // esi
  int v14; // esi
  int v15; // eax
  int v17; // [esp+10h] [ebp-F8h]
  int v18; // [esp+18h] [ebp-F0h]
  unsigned __int16 v19; // [esp+20h] [ebp-E8h]
  unsigned __int16 v20; // [esp+22h] [ebp-E6h]
  int v21; // [esp+24h] [ebp-E4h]
  int v22; // [esp+28h] [ebp-E0h]
  unsigned int v23; // [esp+2Ch] [ebp-DCh]
  int v24; // [esp+30h] [ebp-D8h]
  int v25; // [esp+38h] [ebp-D0h]
  int v26; // [esp+3Ch] [ebp-CCh]
  int v28; // [esp+44h] [ebp-C4h]
  int v29; // [esp+4Ch] [ebp-BCh]
  int v30; // [esp+50h] [ebp-B8h]
  int v31; // [esp+54h] [ebp-B4h]
  int v32; // [esp+58h] [ebp-B0h]
  char v33; // [esp+5Ch] [ebp-ACh]
  char v34; // [esp+5Dh] [ebp-ABh]
  char v35[8]; // [esp+60h] [ebp-A8h] BYREF
  _BYTE v36[32]; // [esp+68h] [ebp-A0h] BYREF
  _BYTE v37[32]; // [esp+88h] [ebp-80h] BYREF
  char v38[32]; // [esp+A8h] [ebp-60h] BYREF
  _BYTE v39[32]; // [esp+C8h] [ebp-40h] BYREF

  v2 = this;
  ArithmeticComparison_a5c0(4);
  v22 = 0;
  if ( v24 <= 0 )
    return 0;
  while ( 1 )
  {
    v38[0] = 0;
    v36[0] = 0;
    v37[0] = 0;
    v39[0] = 0;
    v3 = 0;
    v4 = (_DWORD *)OperatorNewNhMallocWrapper(196);
    if ( v4 )
      v5 = (char *)ConstructorInputControlInit(v4);
    else
      v5 = 0;
    SelfCopyStringToBuffer(v5, v38, (int)v2);
    ArithmeticComparison_a5c0(32);
    ArithmeticComparison_a5c0(4);
    if ( v17 > 0 )
    {
      ArithmeticComparison_a5c0(32);
      v6 = v17 == 1;
      v3 = 1;
      --v17;
      if ( !v6 )
      {
        do
        {
          ArithmeticComparison_a5c0(32);
          --v17;
        }
        while ( v17 );
      }
    }
    ArithmeticComparison_a5c0(4);
    if ( v31 > 0 )
    {
      ArithmeticComparison_a5c0(32);
      ArithmeticComparison_a5c0(32);
      ArithmeticComparison_a5c0(4);
      ArithmeticComparison_a5c0(4);
      OperatorNewNhMallocWrapper(4 * v18);
      ArithmeticComparison_a5c0(4 * v18);
      ArithmeticComparison_a5c0(4);
      ArithmeticComparison_a5c0(4);
      ++v3;
    }
    ArithmeticComparison_a5c0(4);
    if ( v29 > 0 )
    {
      ArithmeticComparison_a5c0(32);
      ++v3;
    }
    SelfCopyStringToBuffer(v5, v38, (int)v2);
    *((_DWORD *)v5 + 41) = v3;
    v7 = (int *)OperatorNewNhMallocWrapper(148 * v3 + 4);
    if ( v7 )
    {
      v8 = (const CHAR *)(v7 + 1);
      *v7 = v3;
      v9 = v7 + 1;
      if ( v3 - 1 >= 0 )
      {
        do
        {
          StructInitWithDefaults_fb90(v9);
          v9 += 37;
          --v3;
        }
        while ( v3 );
      }
      v10 = v8;
      v2 = this;
    }
    else
    {
      v10 = 0;
    }
    *((_DWORD *)v5 + 42) = v10;
    if ( v39[0] )
    {
      SelfRelativeCopyNormalize(v10, v39);
      FieldSetterAt0x48(1);
      v11 = GuardedRenderStateSet(v5, 0);
    }
    else
    {
      SelfRelativeCopyNormalize(v10, v36);
      FieldSetterAt0x48(1);
      v11 = sub_546F30(v5, 0);
    }
    if ( v11 )
      break;
    if ( v37[0] )
    {
      SelfRelativeCopyNormalize((LPCSTR)(*((_DWORD *)v5 + 42) + 148), v37);
      FieldSetterAt0x48(1);
      sub_54FC70(1);
      if ( sub_546F70(v5, 1) )
        break;
    }
    ArithmeticComparison_a5c0(4);
    v12 = 0;
    if ( (v33 & 8) != 0 )
      v12 = 32;
    if ( (v33 & 0x10) != 0 )
      v12 |= 0x40u;
    if ( (v33 & 0x20) != 0 )
      v12 |= 0x80u;
    if ( (v34 & 8) != 0 )
      v12 |= 0x100u;
    v13 = (v34 & 0x10) != 0;
    if ( (v34 & 0x40) != 0 )
      v13 |= 2u;
    if ( v33 < 0 )
      v13 |= 4u;
    if ( (v34 & 1) != 0 )
      v13 |= 8u;
    if ( (v34 & 4) != 0 )
      v13 |= 0x80u;
    if ( (v34 & 0x20) != 0 )
      v13 |= 0x100u;
    if ( v34 < 0 )
      v13 |= 0x200u;
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(16);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    ArithmeticComparison_a5c0(4);
    *((_DWORD *)v5 + 39) = v12;
    SimpleSetter_71c0(v5, v30);
    sub_547240((int)v5, v19, v20);
    *(_DWORD *)(*((_DWORD *)v5 + 42) + 64) = v13;
    DualFieldSetter(v25, v32);
    ShortComputation_fd30(v28, v26);
    FieldSetterAt0x80(v23 & 0xFFFFFF);
    sub_54FCC0(HIBYTE(v23));
    v14 = v13 & 0xC;
    PlaybackRateConfigSetter(v14, v21);
    *((_DWORD *)v5 + 39) |= 2u;
    if ( v37[0] )
      PlaybackRateConfigSetter(v14, v21);
    *(_DWORD *)(*((_DWORD *)v5 + 42) + 64) &= ~0x100u;
    if ( (*(_DWORD *)(*((_DWORD *)v5 + 42) + 64) & 0x100) != 0 )
    {
      RandomPasswordKeyGenerator(a2, v35);
      strcat(v5, v35);
    }
    if ( (*(_DWORD *)(*((_DWORD *)v5 + 42) + 64) & 0x100) != 0 || !ArithmeticComparisonBinarySearch(v2, v5) )
    {
      sub_547670(v2, v5);
      v15 = *((_DWORD *)v5 + 39);
      if ( (v15 & 0x8000) == 0 )
        *((_DWORD *)v5 + 39) = v15 | 1;
    }
    else
    {
      ArrayCleanupWithDualFree(v5);
      EmptyStub_7470(v5);
      FreeWrapper_7bcf(v5);
    }
    if ( ++v22 >= v24 )
      return 0;
  }
  return -1;
}

