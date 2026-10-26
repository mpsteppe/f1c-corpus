int __thiscall sub_68AD21(_DWORD *this)
{
  unsigned int i; // edx
  _DWORD *v3; // eax
  int v4; // ecx
  unsigned int j; // eax
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // ecx
  int result; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ecx
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // ebx
  unsigned int v18; // edx
  int v19; // ecx
  int v20; // eax
  int *v21; // ecx
  int v22; // edi
  int v23; // eax
  unsigned int k; // eax
  _DWORD *v25; // ecx
  unsigned int m; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // edi
  unsigned int v30; // ecx
  int v31; // edx
  int v32; // ebx
  int v33; // [esp+Ch] [ebp-Ch]
  int v34; // [esp+Ch] [ebp-Ch]
  unsigned int v35; // [esp+10h] [ebp-8h]
  unsigned int v36; // [esp+14h] [ebp-4h]
  unsigned int v37; // [esp+14h] [ebp-4h]
  unsigned int v38; // [esp+14h] [ebp-4h]
  unsigned int n; // [esp+14h] [ebp-4h]

  sub_686074((int)this);
  for ( i = 0; i < this[2]; ++i )
  {
    v3 = *(_DWORD **)(this[5] + 4 * i);
    v4 = *(_DWORD *)(this[4] + 4 * v3[1]);
    v3[16] = 0;
    if ( (*(_BYTE *)(v4 + 4) & 0x40) == 0 )
    {
      v3[3] = -1;
      v3[4] = -1;
    }
  }
  for ( j = 0; j < this[3]; *(_DWORD *)(v6 + 40) = 0 )
  {
    *(_DWORD *)(*(_DWORD *)(this[6] + 4 * j) + 36) = 0;
    v6 = *(_DWORD *)(this[6] + 4 * j++);
  }
  sub_686074((int)this);
  v7 = this[3];
  v35 = v7;
  if ( !v7 )
  {
LABEL_24:
    v18 = (unsigned int)(this[3] - v7) >> 1;
    v38 = 0;
    if ( v18 )
    {
      v19 = 4 * v7;
      v34 = 4 * v7;
      do
      {
        v20 = this[6];
        v21 = (int *)(v20 + v19);
        v22 = *v21;
        *v21 = *(_DWORD *)(v20 + 4 * (this[3] - v38) - 4);
        v23 = this[3] - v38++;
        *(_DWORD *)(this[6] + 4 * v23 - 4) = v22;
        v19 = v34 + 4;
        v34 += 4;
      }
      while ( v38 < v18 );
    }
    for ( k = 0; k < v35; *v25 = 0 )
      v25 = *(_DWORD **)(this[6] + 4 * k++);
    result = sub_6825A9(this);
    if ( result >= 0 )
    {
      for ( m = 0; m < this[1]; ++m )
      {
        v27 = *(_DWORD *)(this[4] + 4 * m);
        if ( (*(_BYTE *)(v27 + 4) & 0x40) == 0 )
          *(_DWORD *)(v27 + 16) = 0;
      }
      for ( n = 0; n < this[3]; ++n )
      {
        v28 = *(_DWORD *)(this[6] + 4 * n);
        if ( (*(_WORD *)(v28 + 2) & 0xFFF0) != 0 )
        {
          if ( *(_DWORD *)(v28 + 12) )
          {
            v29 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v28 + 16)) + 4));
            if ( (*(_BYTE *)(v29 + 4) & 0x40) == 0 )
            {
              v30 = 0;
              do
              {
                v31 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v28 + 16) + 4 * v30));
                v32 = *(_DWORD *)(v29 + 16);
                *(_DWORD *)(v31 + 16) = v30++;
                *(_DWORD *)(v31 + 12) = v32;
              }
              while ( v30 < *(_DWORD *)(v28 + 12) );
              ++*(_DWORD *)(v29 + 16);
            }
          }
        }
      }
      return 0;
    }
    return result;
  }
  while ( 1 )
  {
    v33 = v7 - 1;
    v8 = *(_DWORD **)(this[6] + 4 * (v7 - 1));
    if ( (*v8 & 0xFFF00000) != 0 )
      break;
LABEL_22:
    v7 = v33;
    if ( !v33 )
    {
      v7 = v35;
      goto LABEL_24;
    }
  }
  v9 = this[3];
  v10 = *v8 & 0xF0000000;
  if ( v10 < 0x10000000 || v10 > 0x40000000 )
  {
    if ( (*v8 & 0xFFF00000) == 0x50000000 )
      result = sub_684000(this, (int)v8);
    else
      result = sub_6844C5(this, (int)v8);
  }
  else
  {
    result = sub_683C12(this, v8);
  }
  if ( result < 0 )
    return result;
  v12 = this[3];
  v36 = v9;
  if ( v9 >= v12 )
  {
LABEL_19:
    v13 = (v12 - v9) >> 1;
    if ( v13 )
    {
      v14 = 4 * v9;
      v15 = 4 * v12;
      v37 = v13;
      do
      {
        v16 = this[6];
        v17 = *(_DWORD *)(v14 + v16);
        *(_DWORD *)(v14 + v16) = *(_DWORD *)(v15 + v16 - 4);
        *(_DWORD *)(v15 + this[6] - 4) = v17;
        v14 += 4;
        v15 -= 4;
        --v37;
      }
      while ( v37 );
    }
    goto LABEL_22;
  }
  while ( 1 )
  {
    result = sub_68466B(this, *(_DWORD **)(this[6] + 4 * v36));
    if ( result < 0 )
      return result;
    if ( ++v36 >= v12 )
      goto LABEL_19;
  }
}
