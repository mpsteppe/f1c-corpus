int __thiscall sub_557670(int this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // edi
  _DWORD *v12; // ebp
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // edi
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // edi
  char *v19; // ebp
  int v20; // edi
  void *v21; // edi
  unsigned int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // ebp
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // edi
  int v34; // edx
  _DWORD *v35; // ecx
  int v36; // edi
  _DWORD *v37; // eax
  bool v38; // cc
  _DWORD *v39; // ecx
  int v40; // eax
  int v41; // edx
  int v42; // eax
  int v43; // edi
  int v44; // eax
  int v45; // eax
  int v46; // edx
  _DWORD *v47; // eax
  int v48; // ecx
  int v49; // edx
  int v50; // ecx
  int v51; // edi
  int v52; // edx
  _WORD *v53; // eax
  int v54; // ecx
  __int16 v55; // dx
  int v56; // ecx
  void *v57; // edi
  int v58; // edi
  int v59; // ebp
  int v60; // [esp-8h] [ebp-34h]
  int v61; // [esp+10h] [ebp-1Ch]
  int v62; // [esp+10h] [ebp-1Ch]
  int v63; // [esp+10h] [ebp-1Ch]
  int v64; // [esp+10h] [ebp-1Ch]
  int v65; // [esp+14h] [ebp-18h]
  int v66; // [esp+14h] [ebp-18h]
  int v67; // [esp+14h] [ebp-18h]
  int v68; // [esp+18h] [ebp-14h]
  __int16 v69; // [esp+18h] [ebp-14h]
  _DWORD *v70; // [esp+1Ch] [ebp-10h]
  void *v71; // [esp+1Ch] [ebp-10h]
  int v72; // [esp+1Ch] [ebp-10h]
  void *v73; // [esp+20h] [ebp-Ch]
  int v74; // [esp+24h] [ebp-8h]
  _DWORD *v75; // [esp+28h] [ebp-4h]

  if ( (*(_BYTE *)(a2 + 32) & 8) == 0 )
    return 0;
  v3 = (_DWORD *)OperatorNewNhMallocWrapper(572);
  if ( v3 )
    v4 = sub_54A600(v3);
  else
    v4 = 0;
  v73 = v4;
  if ( SelfCopyStringWithValidation((char *)v4, aPtemp, a2 + 56) )
  {
    if ( v4 )
    {
      TwoFunctionCallChain();
      FreeWrapper_7bcf(v4);
    }
    sub_53C590(-1, aSomeMtsInitErr);
    return -1;
  }
  v6 = (_DWORD *)LinkedListIndexedAccessor_c230(v4, 0);
  v75 = v6;
  if ( (BYTE1(v6[5]) & 0x80u) != 0 )
  {
    VertexBufferTransform((int)v6, 0);
    v7 = (_DWORD *)ValueGetter((_DWORD *)dword_8B8F28);
    if ( v7 && LinkedListWalkInterlockedDec(v7) )
    {
      SceneGraph(v4);
      if ( v4 )
      {
        TwoFunctionCallChain();
        FreeWrapper_7bcf(v4);
      }
      return -1;
    }
    strcpy((char *)this, (const char *)a2);
    v8 = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(this + 44) = v8;
    v9 = OperatorNewNhMallocWrapper((v8 << 7) + 4);
    if ( v9 )
    {
      v10 = (_DWORD *)(v9 + 4);
      *(v10 - 1) = v8;
      v11 = v8 - 1;
      v70 = v10;
      v12 = v10;
      if ( v11 >= 0 )
      {
        v13 = v11 + 1;
        do
        {
          StructInitWithVTableColor(v12);
          v12 += 32;
          --v13;
        }
        while ( v13 );
      }
      v14 = v70;
    }
    else
    {
      v14 = 0;
    }
    *(_DWORD *)(this + 52) = v14;
    v15 = v6[70];
    *(_DWORD *)(this + 76) = v15;
    v16 = OperatorNewNhMallocWrapper((v15 << 6) + 4);
    if ( v16 )
    {
      v17 = (_DWORD *)(v16 + 4);
      *(v17 - 1) = v15;
      v18 = v15 - 1;
      v71 = v17;
      v19 = (char *)v17;
      if ( v18 >= 0 )
      {
        v20 = v18 + 1;
        do
        {
          GlobalZeroInit_c2a0(v19);
          v19 += 64;
          --v20;
        }
        while ( v20 );
      }
      v21 = v71;
    }
    else
    {
      v21 = 0;
    }
    v22 = *(_DWORD *)(this + 76) << 6;
    *(_DWORD *)(this + 80) = v21;
    memset(v21, 0, v22);
    if ( (*(_BYTE *)(a2 + 32) & 0x10) != 0 )
      *(_DWORD *)(this + 32) = 16;
    if ( (*(_BYTE *)(a2 + 32) & 0x20) != 0 )
      *(_DWORD *)(this + 32) = 32;
    v23 = OperatorNewNhMallocWrapper(4 * *(_DWORD *)(this + 44));
    v60 = 4 * *(_DWORD *)(this + 44);
    *(_DWORD *)(this + 64) = v23;
    v24 = OperatorNewNhMallocWrapper(v60);
    v25 = *(_DWORD *)(this + 32);
    v26 = *(_DWORD *)(this + 76);
    *(_DWORD *)(this + 60) = v24;
    *(_DWORD *)(this + 32) = v25 | 8;
    *(_DWORD *)(this + 36) = 0;
    *(_DWORD *)(this + 40) = 0;
    v72 = 0;
    if ( v26 > 0 )
    {
      v27 = 0;
      do
      {
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27) &= ~0x10u;
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 4) = *(_DWORD *)(v6[71] + v27 + 4);
        TwoCounterIncrements(*(_DWORD **)(*(_DWORD *)(this + 80) + v27 + 4));
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 8) = *(_DWORD *)(this + 44) * *(_DWORD *)(v6[71] + v27 + 8);
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 16) = *(_DWORD *)(this + 44) * *(_DWORD *)(v6[71] + v27 + 16);
        v28 = *(_DWORD *)(this + 80) + v27;
        v29 = *(_DWORD *)(this + 40);
        *(_DWORD *)(this + 36) += *(_DWORD *)(v28 + 8);
        *(_DWORD *)(this + 40) = *(_DWORD *)(v28 + 16) + v29;
        v30 = *(char *)(a2 + 32) >= 0
            ? OperatorNewNhMallocWrapper(36 * *(_DWORD *)(v6[71] + v27 + 8))
            : OperatorNewNhMallocWrapper(36 * *(_DWORD *)(v28 + 8));
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 12) = v30;
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 20) = OperatorNewNhMallocWrapper(2 * *(_DWORD *)(*(_DWORD *)(this + 80)
                                                                                                  + v27
                                                                                                  + 16));
        if ( *(char *)(a2 + 32) >= 0 )
        {
          v39 = *(_DWORD **)(*(_DWORD *)(this + 80) + v27 + 12);
          v40 = v6[71] + v27;
          v62 = 0;
          if ( *(int *)(v40 + 8) > 0 )
          {
            v41 = 0;
            do
            {
              v42 = *(_DWORD *)(v40 + 12);
              v43 = *(_DWORD *)(v42 + v41);
              v44 = v41 + v42;
              *v39 = v43;
              v39[1] = *(_DWORD *)(v44 + 4);
              v39[2] = *(_DWORD *)(v44 + 8);
              v39[6] = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v41 + 24) | 0xFF000000;
              v39 += 9;
              v40 = v27 + v6[71];
              v41 += 48;
              ++v62;
            }
            while ( v62 < *(_DWORD *)(v40 + 8) );
          }
        }
        else
        {
          v31 = *(_DWORD *)(this + 44);
          *(_DWORD *)(this + 32) |= 0x80u;
          v65 = 0;
          if ( v31 > 0 )
          {
            do
            {
              v32 = v6[71];
              v33 = *(_DWORD *)(v32 + v27 + 8);
              v34 = v27 + v32;
              v35 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 12) + 36 * v65 * v33);
              v61 = 0;
              if ( v33 > 0 )
              {
                v36 = 0;
                v68 = 0;
                do
                {
                  v37 = (_DWORD *)(v36 + *(_DWORD *)(v34 + 12));
                  *v35 = *v37;
                  v35[1] = v37[1];
                  v35[2] = v37[2];
                  v35[6] = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v68 + 24) | 0xFF000000;
                  v35 += 9;
                  v36 = v68 + 48;
                  v38 = ++v61 < *(_DWORD *)(v34 + 8);
                  v68 += 48;
                }
                while ( v38 );
              }
              ++v65;
            }
            while ( v65 < *(_DWORD *)(this + 44) );
          }
        }
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 56) = *(char *)(a2 + 32) < 0 ? 32 : 34;
        if ( sub_540940(dword_8B78A0, (_DWORD *)(v27 + *(_DWORD *)(this + 80))) )
          return -1;
        if ( *(char *)(a2 + 32) >= 0 )
        {
          *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 8) = *(_DWORD *)(v6[71] + v27 + 8);
          *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 16) = *(_DWORD *)(v6[71] + v27 + 16);
        }
        ConditionalFieldSetter_0d40((_DWORD *)(v27 + *(_DWORD *)(this + 80)), 12);
        v45 = 0;
        v63 = 0;
        if ( *(int *)(this + 44) > 0 )
        {
          v66 = 0;
          do
          {
            *(_DWORD *)(v66 + *(_DWORD *)(this + 52) + 4) = v45;
            v46 = *(_DWORD *)(v6[71] + v27 + 8);
            if ( v46 > 0 )
            {
              v47 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 32)
                             + ((v63 * *(_DWORD *)(v6[71] + v27 + 8)) << 6)
                             + 36);
              v48 = 0;
              do
              {
                *(v47 - 1) = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v48 + 32);
                *v47 = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v48 + 36);
                v47 += 16;
                v48 += 48;
                --v46;
              }
              while ( v46 );
            }
            v45 = v63 + 1;
            v38 = ++v63 < *(_DWORD *)(this + 44);
            v66 += 128;
          }
          while ( v38 );
        }
        v49 = v6[71];
        v50 = *(_DWORD *)(v49 + v27 + 8);
        v51 = *(_DWORD *)(v49 + v27 + 16);
        v52 = 0;
        v69 = v50;
        v74 = v51;
        v64 = 0;
        if ( *(int *)(this + 44) > 0 )
        {
          v67 = 0;
          do
          {
            v53 = (_WORD *)(v67 + *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 20));
            v54 = 0;
            if ( v51 > 0 )
            {
              v55 = v69 * v52;
              do
              {
                *v53 = v55 + *(_WORD *)(*(_DWORD *)(v6[71] + v27 + 20) + 2 * v54);
                v51 = v74;
                ++v53;
                ++v54;
              }
              while ( v54 < v74 );
              v52 = v64;
            }
            v64 = ++v52;
            v67 += 2 * v51;
          }
          while ( v52 < *(_DWORD *)(this + 44) );
        }
        v56 = *(_DWORD *)(this + 80);
        v57 = *(void **)(v56 + v27 + 40);
        if ( v57 )
        {
          qmemcpy(v57, *(const void **)(v56 + v27 + 20), 2 * *(_DWORD *)(this + 44) * *(_DWORD *)(v56 + v27 + 16));
          v6 = v75;
        }
        ConditionalBitmaskCleanup((_DWORD *)(v27 + *(_DWORD *)(this + 80)), 12);
        v27 += 64;
      }
      while ( ++v72 < *(_DWORD *)(this + 76) );
    }
    v58 = 0;
    if ( (int)v6[70] > 0 )
    {
      v59 = 0;
      do
      {
        AudioResourceFree(dword_8B78A0, v59 + v6[71]);
        ++v58;
        v59 += 64;
      }
      while ( v58 < v6[70] );
    }
    FreeWrapper_7bcf(v6);
    if ( v73 )
    {
      TwoFunctionCallChain();
      FreeWrapper_7bcf(v73);
    }
    *(_DWORD *)(this + 68) = OperatorNewNhMallocWrapper(4 * *(_DWORD *)(this + 76));
    *(_DWORD *)(this + 72) = OperatorNewNhMallocWrapper(4 * *(_DWORD *)(this + 76));
    return 0;
  }
  SceneGraph(v4);
  if ( v4 )
  {
    TwoFunctionCallChain();
    FreeWrapper_7bcf(v4);
  }
  sub_53C590(-1, aParticleMustBe);
  return -1;
}

