int __thiscall sub_688CD8(_DWORD *this)
{
  unsigned int i; // ebx
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // edx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  unsigned int n; // ebx
  int v9; // eax
  _DWORD *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  int *v13; // ebx
  _DWORD *v14; // eax
  int *v15; // ebx
  unsigned int ii; // ecx
  _DWORD *v17; // eax
  unsigned int m; // ecx
  _DWORD *v19; // eax
  unsigned int k; // ecx
  _DWORD *v21; // eax
  unsigned int jj; // ecx
  _DWORD *v23; // eax
  int v25; // [esp+Ch] [ebp-14h]
  unsigned int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  unsigned int v28; // [esp+14h] [ebp-Ch]
  unsigned int j; // [esp+18h] [ebp-8h]
  unsigned int v30; // [esp+1Ch] [ebp-4h]

  sub_686074((int)this);
  for ( i = 0; i < this[2]; ++i )
  {
    v3 = *(_DWORD **)(this[5] + 4 * i);
    v4 = *(_DWORD *)(this[4] + 4 * v3[1]);
    *v3 &= ~0x20u;
    v5 = *(_DWORD *)(v4 + 4);
    if ( (v5 & 0x10) != 0 && (v5 & 0x200) == 0 )
      *v3 |= 0x20u;
    if ( (*(_BYTE *)(v4 + 5) & 8) != 0 )
      *v3 |= 0x20u;
  }
  for ( j = 0; j < this[3]; ++j )
  {
    v6 = *(_DWORD **)(this[6] + 4 * j);
    v7 = *v6 & 0xFFF00000;
    if ( v7 )
    {
      if ( v7 == 1343225856 || v7 == 285212672 || v7 == 287309824 || (*v6 & 0xF0000000) == 0x60000000 )
      {
        for ( k = 0; k < v6[3]; ++k )
        {
          v21 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * k));
          *v21 |= 0x20u;
        }
      }
      else if ( v7 == 284164096 || v7 == 286261248 || v7 == 289406976 )
      {
        for ( m = 0; m < v6[3]; ++m )
        {
          v19 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * m));
          *v19 |= 0x20u;
        }
      }
      else
      {
        for ( n = 0; n < v6[3]; ++n )
        {
          v9 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * n));
          if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v9 + 4)) + 5) & 0x10) != 0
            && sub_682608(this, *(_DWORD *)(v9 + 20)) )
          {
            v10 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * n));
            *v10 |= 0x20u;
          }
        }
        v11 = *v6 & 0xF0000000;
        if ( v11 < 0x10000000 || v11 > 0x40000000 )
        {
          v28 = 0;
          if ( v6[1] )
          {
            v15 = (int *)v6[2];
            while ( !sub_682608(this, *v15) )
            {
              ++v28;
              ++v15;
              if ( v28 >= v6[1] )
                goto LABEL_46;
            }
            for ( ii = 0; ii < v6[3]; ++ii )
            {
              v17 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * ii));
              *v17 |= 0x20u;
            }
          }
        }
        else
        {
          v30 = 0;
          v26 = v6[1] / (*v6 & 0xFFFFFu);
          v12 = v6[3];
          if ( v12 )
          {
            do
            {
              v27 = 0;
              if ( v26 )
              {
                v25 = 4 * v12;
                v13 = (int *)(4 * v30 + v6[2]);
                while ( !sub_682608(this, *v13) )
                {
                  ++v27;
                  v13 = (int *)((char *)v13 + v25);
                  if ( v27 >= v26 )
                    goto LABEL_31;
                }
                v14 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(4 * v30 + v6[4]));
                *v14 |= 0x20u;
              }
LABEL_31:
              ++v30;
              v12 = v6[3];
            }
            while ( v30 < v12 );
          }
        }
      }
    }
LABEL_46:
    ;
  }
  for ( jj = 0; jj < this[2]; ++jj )
  {
    v23 = *(_DWORD **)(this[5] + 4 * jj);
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v23[1]) + 4) & 0x20) != 0 )
      *v23 |= 0x20u;
  }
  return 0;
}
