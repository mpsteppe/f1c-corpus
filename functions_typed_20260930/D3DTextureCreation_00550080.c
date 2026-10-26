int __thiscall sub_550080(int this, const char *a2, int a3, int a4)
{
  int v5; // ebp
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // ebp
  int v18; // edi
  int v19; // eax
  int v20; // eax
  int v21; // [esp+Ch] [ebp-8h] BYREF
  int v22; // [esp+10h] [ebp-4h] BYREF

  v5 = 0;
  sub_54FE50((const CHAR *)this, a2);
  if ( sub_5427D0((int)a2, (int)&v22, (int)&v21, 0) == -1 )
  {
LABEL_2:
    DestructorWithConditionalFreeFlagClear(this);
    return -1;
  }
  v7 = CRTFtol(__FYL2X__((double)v22, 0.6931471805599453094) * 1.442695036924675 + 0.5);
  v8 = CRTFtol(__FYL2X__((double)v21, 0.6931471805599453094) * 1.442695036924675 + 0.5);
  v9 = *(_DWORD *)(this + 80);
  if ( !v9 || v9 > v7 || v9 > v8 )
  {
    if ( v7 < v8 )
      v8 = v7;
    *(_DWORD *)(this + 80) = v8;
  }
  if ( (*(_BYTE *)(this + 68) & 1) == 0 )
  {
    v10 = SimpleFieldGetter_bfc0(dword_8B78A0);
    v11 = IndexedArrayAccess_d890(dword_8B78A0, v10);
    v12 = v22;
    v13 = v21;
    if ( !v11 )
      goto LABEL_16;
    while ( v12 > *(_DWORD *)(v11 + 284) || v13 > *(_DWORD *)(v11 + 288) )
    {
      v14 = *(_DWORD *)(this + 80);
      v12 >>= 1;
      v13 >>= 1;
      ++v5;
      v22 = v12;
      v21 = v13;
      if ( v14 > 1 )
        *(_DWORD *)(this + 80) = v14 - 1;
    }
    if ( !v5 )
    {
LABEL_16:
      if ( (*(_BYTE *)(this + 68) & 1) == 0 )
      {
        v15 = dword_8B8E4C;
        if ( dword_8B8E4C )
        {
          v16 = *(_DWORD *)(this + 80);
          do
          {
            v12 >>= 1;
            v13 >>= 1;
            if ( v16 > 1 )
              --v16;
            --v15;
          }
          while ( v15 );
          v21 = v13;
          v22 = v12;
          *(_DWORD *)(this + 80) = v16;
        }
      }
    }
  }
  v17 = a4;
  if ( ((unsigned int)&unk_800000 & a4) != 0 )
  {
    v18 = 8;
    goto LABEL_41;
  }
  if ( !dword_8B8E2C || !MaskedFieldGetter(dword_8B78A0) )
  {
    if ( (a4 & 0x800) != 0 )
    {
      v18 = 5;
      goto LABEL_41;
    }
    if ( (a4 & 0x40000) != 0 )
      goto LABEL_34;
LABEL_39:
    v19 = GetVTableParamBasedOnFlagBits(dword_8B8DC8);
    goto LABEL_40;
  }
  if ( (*(_BYTE *)(this + 68) & 1) == 0 && v22 >= 8 && v21 >= 8 )
  {
    v18 = 9;
    goto LABEL_41;
  }
  if ( (a4 & 0x800) != 0 )
  {
    v18 = 5;
    goto LABEL_41;
  }
  if ( (a4 & 0x40000) == 0 )
    goto LABEL_39;
LABEL_34:
  v19 = KeyEventDispatchToSubHandlers(0x200000);
LABEL_40:
  v18 = v19;
LABEL_41:
  if ( (a4 & 0x800) != 0 )
  {
    v20 = a3;
    if ( !a3 )
      v20 = 16711935;
    sub_5435C0(*(_DWORD **)(this + 84), v20);
  }
  *(_DWORD *)(*(_DWORD *)(this + 84) + 44) = *(_DWORD *)(this + 80);
  if ( !dword_8B8E28 )
    v17 = a4 | 0x1000000;
  if ( sub_5429B0(*(_DWORD **)(this + 84), a2, v22, v21, v18, v17) )
    goto LABEL_2;
  *(_DWORD *)(this + 80) = *(_DWORD *)(*(_DWORD *)(this + 84) + 44);
  return 0;
}

