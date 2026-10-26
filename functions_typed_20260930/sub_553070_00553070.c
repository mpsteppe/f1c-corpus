void __thiscall sub_553070(_DWORD *this, const char *a2, int a3, int a4, _DWORD *a5)
{
  int v7; // eax
  int v8; // ecx
  const char *v9; // edi
  bool v10; // zf
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // eax
  int v14; // eax
  unsigned int v15; // ebp
  unsigned int v16; // ebp
  int v17; // [esp-4h] [ebp-18h]
  int i; // [esp+10h] [ebp-4h]
  int v19; // [esp+18h] [ebp+4h]

  if ( *a2 )
  {
    v7 = this[9];
    v8 = -1;
    v9 = a2;
    if ( (v7 & 0x20000) != 0 )
    {
      do
      {
        if ( !v8 )
          break;
        v10 = *v9++ == 0;
        --v8;
      }
      while ( !v10 );
      v11 = 3 * (-v8 - 2);
      v12 = this[2];
      v19 = 2 * v11;
      v17 = 2 * v11;
      if ( 2 * v11 <= 768 - v12 )
      {
        v14 = BufferLockAllocate(dword_8B78A0, (_DWORD *)this[3], 32, v12, v17);
      }
      else
      {
        v13 = (_DWORD *)this[3];
        this[2] = 0;
        v14 = BufferLockAllocate(dword_8B78A0, v13, 96, 0, v17);
      }
      this[4] = v14;
      if ( v14 )
      {
        v15 = 0;
        for ( i = this[2]; v15 < strlen(a2); ++v15 )
          a3 += sub_552910((int)this, a2[v15], a3, a4, a5);
        ArithmeticComparison_0f90(dword_8B78A0, this[3]);
        if ( !dword_8B8DF0 )
          VTableGetterWrapper(dword_8B78A0);
        AudioBufferFormatSetup(dword_8B78A0, dword_8B8F28, this[3], i, v19, this[538], this[19], this[20], this[22], 0);
        if ( !dword_8B8DF0 )
          VTableDispatchGetter(dword_8B78A0);
      }
    }
    else
    {
      v16 = 0;
      do
      {
        if ( !v8 )
          break;
        v10 = *v9++ == 0;
        --v8;
      }
      while ( !v10 );
      if ( -v8 != 2 )
      {
        do
          a3 += sub_552910((int)this, a2[v16++], a3, a4, a5);
        while ( v16 < strlen(a2) );
      }
    }
  }
}

