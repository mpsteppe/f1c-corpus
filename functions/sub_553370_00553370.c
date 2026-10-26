int __thiscall sub_553370(unsigned int *this, int a2)
{
  _DWORD *v3; // eax
  int v5; // eax
  signed int v6; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  unsigned int v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  signed int v12; // edx
  int v13; // ecx
  int v14; // eax
  double v15; // st7
  float v16; // [esp+8h] [ebp-4h]
  float v17; // [esp+10h] [ebp+4h]

  if ( a2 != 1 )
  {
    if ( a2 == 2 )
    {
      v9 = this[6];
      *this = *this & 0xFFFFFFFC | 2;
      if ( !v9 )
        this[6] = OperatorNewNhMallocWrapper(448);
      if ( this[5] )
      {
        ObjectResetWithVirtualRelease(dword_8B78A0, this[5]);
      }
      else
      {
        v10 = (_DWORD *)OperatorNewNhMallocWrapper(36);
        if ( v10 )
        {
          v10[5] = 0;
          v10[4] = 0;
          v10[3] = 0;
          v10[2] = 0;
          v10[1] = 0;
          *v10 = 0;
          v10[7] = 0;
          v10[6] = 0;
          v10[8] = 0;
        }
        else
        {
          v10 = 0;
        }
        this[5] = (unsigned int)v10;
      }
      *(_DWORD *)this[5] = 34;
      *(_DWORD *)(this[5] + 12) = 16;
      *(_DWORD *)(this[5] + 4) = 324;
      *(_DWORD *)(this[5] + 8) = 28;
      if ( sub_540DF0(dword_8B78A0, (int *)this[5]) )
        return -1;
      if ( (int)this[1] > 0 )
      {
        v11 = BufferLockAllocate(dword_8B78A0, (_DWORD *)this[5], 96, 0, 0);
        v12 = 0;
        v16 = flt_8B8CF0 * (double)dword_8B8DD4;
        v17 = flt_8B8CF4;
        if ( (int)this[1] > 0 )
        {
          v13 = 0;
          v14 = v11 + 8;
          do
          {
            v15 = v17 * *(float *)(v13 + this[6]);
            ++v12;
            v13 += 28;
            v14 += 28;
            *(float *)(v14 - 36) = v15 + v16;
            *(_DWORD *)(v14 - 32) = *(_DWORD *)(v13 + this[6] - 24);
            *(_DWORD *)(v14 - 28) = *(_DWORD *)(v13 + this[6] - 20);
            *(_DWORD *)(v14 - 24) = *(_DWORD *)(v13 + this[6] - 16);
            *(_DWORD *)(v14 - 16) = *(_DWORD *)(v13 + this[6] - 8);
            *(_DWORD *)(v14 - 12) = *(_DWORD *)(v13 + this[6] - 4);
            *(_DWORD *)(v14 - 20) = *(_DWORD *)(v13 + this[6] - 12);
          }
          while ( v12 < (int)this[1] );
        }
        ArithmeticComparison_0f90(dword_8B78A0, this[5]);
      }
    }
    return 0;
  }
  *this = *this & 0xFFFFFFFC | 1;
  if ( !this[6] )
    this[6] = OperatorNewNhMallocWrapper(384);
  if ( this[5] )
  {
    ObjectResetWithVirtualRelease(dword_8B78A0, this[5]);
  }
  else
  {
    v3 = (_DWORD *)OperatorNewNhMallocWrapper(36);
    if ( v3 )
    {
      v3[5] = 0;
      v3[4] = 0;
      v3[3] = 0;
      v3[2] = 0;
      v3[1] = 0;
      *v3 = 0;
      v3[7] = 0;
      v3[6] = 0;
      v3[8] = 0;
    }
    else
    {
      v3 = 0;
    }
    this[5] = (unsigned int)v3;
  }
  *(_DWORD *)this[5] = 34;
  *(_DWORD *)(this[5] + 12) = 16;
  *(_DWORD *)(this[5] + 4) = 322;
  *(_DWORD *)(this[5] + 8) = 24;
  if ( sub_540DF0(dword_8B78A0, (int *)this[5]) )
    return -1;
  if ( (int)this[1] <= 0 )
    return 0;
  v5 = BufferLockAllocate(dword_8B78A0, (_DWORD *)this[5], 96, 0, 0);
  v6 = 0;
  if ( (int)this[1] > 0 )
  {
    v7 = 0;
    v8 = (_DWORD *)(v5 + 8);
    do
    {
      *(v8 - 2) = *(_DWORD *)(v7 + this[6]);
      *(v8 - 1) = *(_DWORD *)(v7 + this[6] + 4);
      *v8 = *(_DWORD *)(v7 + this[6] + 8);
      v8[2] = *(_DWORD *)(v7 + this[6] + 16);
      v8[3] = *(_DWORD *)(v7 + this[6] + 20);
      v8[1] = *(_DWORD *)(v7 + this[6] + 12);
      ++v6;
      v7 += 24;
      v8 += 6;
    }
    while ( v6 < (int)this[1] );
  }
  ArithmeticComparison_0f90(dword_8B78A0, this[5]);
  return 0;
}
