int __thiscall sub_4186F0(int this)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // eax
  char *v6; // esi
  int v7; // ebp
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  _UNKNOWN **v11; // esi
  int v12; // ebp
  void *v13; // eax
  _BYTE v15[8]; // [esp+8h] [ebp-3Ch] BYREF
  char v16; // [esp+10h] [ebp-34h] BYREF
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h] BYREF

  if ( !dword_7D0308 || flt_7CF3C8 <= 0.0 || !*(_BYTE *)(this + 2800) )
    return 0;
  v2 = *(_DWORD *)(this + 2804);
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 24))(v2);
  v3 = *(_DWORD *)(this + 2804);
  if ( v3 && !(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(v3) && *(_BYTE *)(this + 2788) )
  {
    *(_BYTE *)(this + 2788) = 0;
    *(float *)(this + 2792) = dbl_8AFEA8;
    *(_DWORD *)(this + 2796) = -1;
  }
  ArraySlotCompactionWithGapFilling(this);
  v4 = *(_DWORD *)(this + 2804);
  if ( *(_DWORD *)(this + 2148) == -1 )
  {
    if ( v4 && !(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4) )
      *(_DWORD *)(this + 2796) = -1;
    return 0;
  }
  if ( !v4 || (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4) )
    return 0;
  v5 = *(_DWORD *)(this + 4956);
  if ( (double)dword_7CF278 < dbl_8AFEA8 - *(float *)(this + 2792) )
  {
    if ( v5 <= 0 )
      goto LABEL_18;
    goto LABEL_17;
  }
  if ( v5 <= 0 )
    return 0;
LABEL_17:
  *(_DWORD *)(this + 4956) = v5 - 1;
LABEL_18:
  if ( dbl_8AFEA8 < *(float *)(this + 2156) )
  {
    *(_DWORD *)(this + 2796) = -1;
    return 0;
  }
  else
  {
    if ( dbl_8AFEA8 - *(float *)(this + 4 * *(_DWORD *)(this + 2148) + 2808) >= flt_5BF9AC[5 * *(_DWORD *)(this + 2148)] )
    {
      v6 = &v16;
      v7 = 3;
      do
      {
        *((_DWORD *)v6 - 2) = 0;
        *((_DWORD *)v6 - 1) = -1;
        StringCopyWithBufferRealloc(&byte_5EA438);
        *(_DWORD *)v6 = -1;
        *((_DWORD *)v6 + 1) = -1;
        v6[8] = 0;
        v6 += 20;
        --v7;
      }
      while ( v7 );
      v8 = FontRenderingPrep((_DWORD *)(this + 2148), (int)v15);
      if ( v8 > 0 )
      {
        v9 = *(_DWORD *)(this + 2804);
        if ( v9 )
        {
          (*(void (__thiscall **)(int, _BYTE *, int, _DWORD))(*(_DWORD *)v9 + 4))(v9, v15, v8, 0);
          v10 = *(_DWORD *)(this + 2148);
          *(_BYTE *)(this + 2788) = 1;
          *(_DWORD *)(this + 2796) = v10;
          *(float *)(this + 4 * v10 + 2808) = dbl_8AFEA8;
        }
      }
      v11 = &retaddr;
      v12 = 3;
      do
      {
        v13 = *(v11 - 5);
        v11 -= 5;
        if ( v13 )
          FreeWrapper_7bcf(v13);
        --v12;
      }
      while ( v12 );
    }
    StructInitWithSentinelValues((_DWORD *)(this + 2148));
    ArraySlotCompactionWithGapFilling(this);
    return 0;
  }
}

