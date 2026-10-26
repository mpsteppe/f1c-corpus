int __thiscall sub_69056E(_DWORD *this, int a2)
{
  int v3; // esi
  _DWORD *v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edi
  _DWORD *v7; // eax
  unsigned int v8; // edx
  int v9; // edx
  unsigned int j; // eax
  unsigned int *v11; // ebx
  unsigned int v12; // edi
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // edx
  unsigned int v18; // eax
  bool v19; // zf
  int v20; // ecx
  int v21; // eax
  unsigned int v22; // edi
  _DWORD *v23; // eax
  unsigned int v24; // edx
  unsigned int v26; // [esp+8h] [ebp-24h]
  unsigned int v27; // [esp+Ch] [ebp-20h]
  unsigned int v28; // [esp+Ch] [ebp-20h]
  unsigned int v29; // [esp+10h] [ebp-1Ch]
  unsigned int v30; // [esp+14h] [ebp-18h]
  int v31; // [esp+18h] [ebp-14h]
  unsigned int v32; // [esp+1Ch] [ebp-10h]
  unsigned int *v33; // [esp+1Ch] [ebp-10h]
  unsigned int i; // [esp+20h] [ebp-Ch]
  int v35; // [esp+20h] [ebp-Ch]
  int *Block; // [esp+24h] [ebp-8h]
  unsigned int v37; // [esp+28h] [ebp-4h]
  int v38; // [esp+34h] [ebp+8h]
  unsigned int v39; // [esp+34h] [ebp+8h]
  unsigned int v40; // [esp+34h] [ebp+8h]

  v37 = 0;
  Block = (int *)operator new(4 * this[3]);
  if ( Block )
  {
    for ( i = 0; i < this[3]; ++i )
    {
      v4 = *(_DWORD **)(this[6] + 4 * i);
      v5 = *v4 & 0xFFF00000;
      if ( v5
        && (!a2 || !v4[9])
        && v5 != 284164096
        && v5 != 544210944
        && v5 != 286261248
        && v5 != 287309824
        && v5 != 288358400
        && v5 != 289406976
        && v5 != 545259520
        && v5 != 546308096
        && v5 != 290455552 )
      {
        v6 = v4[3];
        v32 = 0;
        if ( v6 )
        {
          v7 = (_DWORD *)v4[4];
          do
          {
            if ( (*(_WORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v7) + 4)) + 4) & 0x1020) != 0 )
              break;
            ++v32;
            ++v7;
          }
          while ( v32 < v6 );
        }
        if ( v32 >= v6 )
        {
          v8 = v37++;
          Block[v8] = i;
        }
      }
    }
    v31 = 0;
    while ( 1 )
    {
      v38 = 0;
      sub_686606(this);
      sub_682274((int (__stdcall *)(int, int, int))sub_686A2E, Block, v37, (int)this);
      if ( !v37 )
        break;
      v35 = 1;
      v33 = (unsigned int *)Block;
      v27 = v37;
      do
      {
        v30 = *v33;
        if ( *v33 != -1 )
        {
          for ( j = v35; ; ++j )
          {
            v29 = j;
            if ( j >= v37 )
              break;
            v11 = (unsigned int *)&Block[j];
            v12 = *v11;
            if ( *v11 != -1 )
            {
              if ( v30 >= v12 || sub_68688F(v30, v9, v12, (int)this) )
                break;
              v13 = this[6];
              v14 = *(_DWORD *)(v13 + 4 * v30);
              v15 = *(_DWORD **)(v13 + 4 * v12);
              v9 = 0;
              v39 = 0;
              if ( *(_DWORD *)(v14 + 12) )
              {
                do
                {
                  v16 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v15[4] + 4 * v39));
                  v17 = *(_DWORD *)(*(_DWORD *)(v14 + 16) + 4 * v39++);
                  *(_DWORD *)(v16 + 48) = v17;
                }
                while ( v39 < *(_DWORD *)(v14 + 12) );
                v9 = 0;
              }
              *v11 = -1;
              *v15 = 0;
              v15[1] = 0;
              v15[3] = 0;
              v31 = 1;
              v38 = 1;
              j = v29;
            }
          }
        }
        ++v33;
        ++v35;
        --v27;
      }
      while ( v27 );
      v18 = 0;
      if ( !v38 )
        break;
      v19 = v37 == 0;
      v26 = v37;
      v37 = 0;
      v28 = 0;
      if ( !v19 )
      {
        do
        {
          v20 = Block[v18];
          if ( v20 != -1 )
          {
            v21 = *(_DWORD *)(this[6] + 4 * v20);
            v22 = *(_DWORD *)(v21 + 4);
            v40 = 0;
            if ( v22 )
            {
              v23 = *(_DWORD **)(v21 + 8);
              do
              {
                if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v23) + 48) != *v23 )
                  break;
                ++v40;
                ++v23;
              }
              while ( v40 < v22 );
            }
            if ( v40 != v22 )
            {
              v24 = v37++;
              Block[v24] = v20;
            }
          }
          v18 = ++v28;
        }
        while ( v28 < v26 );
      }
      sub_68661F(this);
    }
    if ( v31 )
      sub_68FECA(this);
    v3 = v31 == 0;
  }
  else
  {
    v3 = -2147024882;
  }
  j__free(Block);
  return v3;
}
