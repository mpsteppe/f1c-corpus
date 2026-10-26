int __thiscall sub_4BF790(int *this, int a2, int a3, const char *a4)
{
  int v6; // esi
  int v7; // ecx
  int v8; // ebx
  int v9; // edi
  char *v10; // eax
  float *v11; // eax
  float *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // edi
  _DWORD *v21; // esi
  _DWORD *v22; // eax
  _DWORD *v23; // ecx
  _DWORD *v24; // edx
  _DWORD *v25; // edi
  _DWORD *v26; // eax
  int v27; // edx
  int i; // eax
  int v29; // [esp-Ch] [ebp-21Ch]
  int v30; // [esp+8h] [ebp-208h]
  int v31; // [esp+Ch] [ebp-204h]
  _BYTE v32[512]; // [esp+10h] [ebp-200h] BYREF

  v30 = 0;
  sub_4BF730(this);
  StringFormatWithBufferOverflowCheck(v32, "%s NOT: NotAI", a4);
  sub_4C4D50(v32);
  if ( a2 <= 10 )
  {
    if ( AIPathPerformanceFunction(a2, a3) == a2 )
      return a2;
    sub_4BF730(this);
  }
  v6 = ReadFieldAtOffset0x14(&dword_8AC36C);
  v31 = v6;
  v8 = 2 * RandLCGRandomNumberGenerator(v7) % v6;
  if ( v6 > 0 )
  {
    if ( a2 > 0 )
    {
      do
      {
        v9 = RandomVehicleSelector(v8);
        v10 = *(char **)v9;
        if ( !*(_DWORD *)v9 )
          v10 = byte_5EA438;
        if ( sub_588410(v10, a3) || v6 < 2 )
        {
          v11 = (float *)OperatorNewNhMallocWrapper(8);
          v12 = 0;
          if ( v11 )
          {
            v11[1] = 0.0;
            *v11 = NAN;
            v12 = v11;
          }
          *(_DWORD *)v12 = GuardedListAccessor(v8);
          v12[1] = sub_4BF6A0((const char *)(v9 + 188));
          v13 = OperatorNewNhMallocWrapper(12);
          if ( v13 )
          {
            *(_DWORD *)v13 = v12;
            *(_DWORD *)(v13 + 4) = 0;
            *(_BYTE *)(v13 + 8) = 1;
          }
          else
          {
            v13 = 0;
          }
          if ( *this )
          {
            *(_DWORD *)(this[1] + 4) = v13;
          }
          else
          {
            *this = v13;
            this[2] = v13;
          }
          v14 = this[3];
          v6 = v31;
          this[1] = v13;
          this[3] = v14 + 1;
          ++v30;
        }
        v8 = (v8 + 1) % v6;
      }
      while ( v30 < a2 );
    }
    v15 = *this;
    v16 = 0;
    v17 = *this;
    if ( *this )
    {
      do
      {
        v17 = *(_DWORD *)(v17 + 4);
        ++v16;
      }
      while ( v17 );
      if ( v16 >= 2 )
      {
        v18 = v16 / 2 - 1;
        v19 = *this;
        if ( v18 > 0 )
        {
          do
          {
            --v18;
            v19 = *(_DWORD *)(v19 + 4);
          }
          while ( v18 );
        }
        v20 = *(_DWORD *)(v19 + 4);
        v29 = *this;
        *(_DWORD *)(v19 + 4) = 0;
        v21 = (_DWORD *)MergeSortLinkedListByFloat(v29);
        v22 = (_DWORD *)MergeSortLinkedListByFloat(v20);
        v23 = v22;
        v24 = v21;
        if ( v21 )
        {
          if ( v22 )
          {
            if ( *(float *)(*v22 + 4) <= (double)*(float *)(*v21 + 4) )
            {
              v21 = v22;
              v25 = v22;
              v23 = (_DWORD *)v22[1];
            }
            else
            {
              v24 = (_DWORD *)v21[1];
              v25 = v21;
            }
            if ( v24 )
            {
              while ( v23 )
              {
                if ( *(float *)(*v23 + 4) <= (double)*(float *)(*v24 + 4) )
                {
                  v26 = v23;
                  v23 = (_DWORD *)v23[1];
                }
                else
                {
                  v26 = v24;
                  v24 = (_DWORD *)v24[1];
                }
                v25[1] = v26;
                v25 = v26;
                if ( !v24 )
                  goto LABEL_37;
              }
              v25[1] = v24;
            }
            else
            {
LABEL_37:
              if ( v23 )
                v25[1] = v23;
              else
                v25[1] = 0;
            }
          }
        }
        else
        {
          v21 = v22;
        }
        v15 = (int)v21;
      }
    }
    *this = v15;
    v27 = v15;
    if ( v15 )
    {
      for ( i = *(_DWORD *)(v15 + 4); i; i = *(_DWORD *)(i + 4) )
        v27 = i;
    }
    this[1] = v27;
    this[2] = v15;
  }
  return v30;
}

