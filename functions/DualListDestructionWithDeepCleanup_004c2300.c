void __thiscall sub_4C2300(_DWORD *this)
{
  int v2; // edi
  LPVOID **v3; // ebp
  bool v4; // zf
  int v5; // ebp
  LPVOID **v6; // eax
  LPVOID *v7; // edi
  int v8; // ecx
  LPVOID *v9; // [esp+10h] [ebp-4h]
  LPVOID **v10; // [esp+10h] [ebp-4h]

  v2 = *this;
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 )
    {
      v9 = *v3;
      if ( *v3 )
      {
        PitStopMemoryCleanup(*v3);
        FreeWrapper_7bcf(v9);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v5 = this[4];
  while ( v5 )
  {
    v6 = (LPVOID **)v5;
    v4 = *(_BYTE *)(v5 + 8) == 0;
    v5 = *(_DWORD *)(v5 + 4);
    v10 = v6;
    if ( !v4 )
    {
      v7 = *v6;
      if ( *v6 )
      {
        if ( v7[2] )
          FreeWrapper_7bcf(v7[2]);
        if ( *v7 )
          FreeWrapper_7bcf(*v7);
        FreeWrapper_7bcf(v7);
        v6 = v10;
      }
    }
    FreeWrapper_7bcf(v6);
  }
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  this[25] = 0;
  this[26] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  *((_BYTE *)this + 108) = 1;
  v8 = dword_7D0A24;
  this[33] = 0;
  this[34] = 0;
  this[35] = 0;
  this[32] = v8;
}
