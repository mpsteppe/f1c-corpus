unsigned __int8 __thiscall sub_4A4900(_DWORD *this, int a2)
{
  unsigned __int8 result; // al
  char *v4; // esi
  unsigned int v5; // kr04_4
  char *i; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  char *v20; // ecx
  bool v21; // zf
  char *v22; // eax
  char *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  char *v26; // ecx
  int v27; // eax
  _BYTE *v28; // esi
  int v29; // ecx
  char *v30; // eax
  char *v31; // eax
  int v32; // [esp-Ch] [ebp-6Ch]
  unsigned __int8 v33; // [esp+7h] [ebp-59h]
  int v34; // [esp+8h] [ebp-58h] BYREF
  int v35; // [esp+Ch] [ebp-54h] BYREF
  int v36; // [esp+10h] [ebp-50h] BYREF
  int v37; // [esp+14h] [ebp-4Ch] BYREF
  char *v38; // [esp+18h] [ebp-48h]
  int v39; // [esp+1Ch] [ebp-44h]
  char *v40; // [esp+20h] [ebp-40h]
  int v41; // [esp+24h] [ebp-3Ch]
  char *v42; // [esp+28h] [ebp-38h]
  int v43; // [esp+2Ch] [ebp-34h]
  _DWORD v44[4]; // [esp+30h] [ebp-30h] BYREF
  char v45[32]; // [esp+40h] [ebp-20h] BYREF

  result = UIComponentCleanup();
  if ( dword_8AB6E4 != 2 )
  {
    result = *this == dword_7C54E8;
    v33 = result;
    if ( *this == dword_7C54E8 || dword_7CF884 >= 3 )
    {
      sub_4A1F60(v44);
      sub_4A51C0(a2, v44);
      v38 = (char *)OperatorNewNhMallocWrapper(256);
      *v38 = 0;
      v32 = *this + 18196;
      v39 = 256;
      v42 = 0;
      v43 = -1;
      StringCopyWithBufferRealloc(v32);
      v4 = 0;
      v5 = strlen(byte_5EA438) + 1;
      if ( (int)(v5 - 1) > 0 )
      {
        for ( i = &byte_5EA438[v5 - 2]; i > byte_5EA438; --i )
        {
          if ( *i == 92 )
            break;
        }
        *i = 0;
        v4 = v42;
      }
      if ( !v4 )
        v4 = byte_5EA438;
      StringRegistry(v4);
      v40 = (char *)OperatorNewNhMallocWrapper(256);
      *v40 = 0;
      v7 = (char *)dword_5EC3D8;
      v41 = 256;
      if ( !dword_5EC3D8 )
        v7 = byte_5EA438;
      StringCopyWithBufferRealloc(v7);
      v8 = (char *)dword_5EC420;
      if ( !dword_5EC420 )
        v8 = byte_5EA438;
      sub_5665B0(v8);
      sub_5665B0(aPits);
      v9 = v40;
      if ( !v40 )
        v9 = byte_5EA438;
      StringRegistry(v9);
      v37 = 0;
      sub_53CBC0(&v37, aTeamMas);
      v36 = 0;
      sub_53CBC0(&v36, aPitsMas);
      v10 = (char *)dword_5EC3D8;
      v34 = 0;
      if ( !dword_5EC3D8 )
        v10 = byte_5EA438;
      StringCopyWithBufferRealloc(v10);
      v11 = (char *)dword_5EC428;
      if ( !dword_5EC428 )
        v11 = byte_5EA438;
      sub_5665B0(v11);
      sub_5665B0(aCdbMas);
      v12 = v38;
      if ( !v38 )
        v12 = byte_5EA438;
      sub_53CBC0(&v34, v12);
      v13 = (char *)dword_5EC3D8;
      v35 = 0;
      if ( !dword_5EC3D8 )
        v13 = byte_5EA438;
      StringCopyWithBufferRealloc(v13);
      v14 = (char *)dword_5EC428;
      if ( !dword_5EC428 )
        v14 = byte_5EA438;
      sub_5665B0(v14);
      sub_5665B0(aCmapsMas);
      v15 = v38;
      if ( !v38 )
        v15 = byte_5EA438;
      sub_53CBC0(&v35, v15);
      v16 = (char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v16 = byte_5EA438;
      StringCopyWithBufferRealloc(v16);
      v17 = (char *)dword_5EC420;
      if ( !dword_5EC420 )
        v17 = byte_5EA438;
      sub_5665B0(v17);
      sub_5665B0(aPits10secPitcr);
      StringFormatWithBufferOverflowCheck(v45, "PITCREW10SEC%02d", *(_DWORD *)(*this + 18580));
      v18 = (_DWORD *)OperatorNewNhMallocWrapper(24);
      if ( v18 )
        v19 = StructInitCall(v18);
      else
        v19 = 0;
      v20 = v38;
      v21 = v38 == 0;
      this[4] = v19;
      if ( v21 )
        v20 = byte_5EA438;
      PITANIMSMASAnimationFileLoader(v19, (int)v20, (int)v44, (int)v45);
      v22 = (char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v22 = byte_5EA438;
      StringCopyWithBufferRealloc(v22);
      v23 = (char *)dword_5EC420;
      if ( !dword_5EC420 )
        v23 = byte_5EA438;
      sub_5665B0(v23);
      if ( byte_5EA3EC )
        sub_5665B0(aPitsLeftPitcre);
      else
        sub_5665B0(aPitsNormalPitc);
      StringFormatWithBufferOverflowCheck(v45, "PITCREWNORMAL%02d", *(_DWORD *)(*this + 18580));
      v24 = (_DWORD *)OperatorNewNhMallocWrapper(24);
      if ( v24 )
        v25 = StructInitCall(v24);
      else
        v25 = 0;
      v26 = v38;
      v21 = v38 == 0;
      this[3] = v25;
      if ( v21 )
        v26 = byte_5EA438;
      PITANIMSMASAnimationFileLoader(v25, (int)v26, (int)v44, (int)v45);
      if ( v33 )
      {
        StringFormatWithBufferOverflowCheck(v45, "PITDIRECTOR%02d", *(_DWORD *)(*this + 18580));
        v27 = OperatorNewNhMallocWrapper(136);
        v28 = (_BYTE *)v27;
        if ( v27 )
        {
          *(_DWORD *)(v27 + 100) = 0;
          *(_DWORD *)(v27 + 108) = 0;
          *(_DWORD *)(v27 + 116) = 0;
          sub_4A2220((_BYTE *)v27);
          sub_4A3B30(v28);
          v29 = (int)v28;
        }
        else
        {
          v29 = 0;
        }
        this[5] = v29;
        PitCrewAnimationMASSetup(v29, v45);
      }
      if ( v34 )
        PhysicsObjectLinkedListRemoval(v34);
      if ( v35 )
        PhysicsObjectLinkedListRemoval(v35);
      if ( v36 )
        PhysicsObjectLinkedListRemoval(v36);
      if ( v37 )
        PhysicsObjectLinkedListRemoval(v37);
      v30 = v40;
      if ( !v40 )
        v30 = byte_5EA438;
      StringMatchWithFlagSet(v30);
      v31 = v42;
      if ( !v42 )
        v31 = byte_5EA438;
      StringMatchWithFlagSet(v31);
      if ( v40 )
        FreeWrapper_7bcf(v40);
      if ( v42 )
        FreeWrapper_7bcf(v42);
      if ( v38 )
        FreeWrapper_7bcf(v38);
      return (unsigned __int8)ArithmeticComparison_1f80(v44);
    }
  }
  return result;
}
