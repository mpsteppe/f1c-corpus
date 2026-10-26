int __thiscall sub_5F11A0(_DWORD *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  char *v7; // esi
  bool v8; // cc
  char *v9; // ebp
  char *v10; // esi
  int v11; // ebx
  int v12; // edi
  char *v13; // eax
  char *v14; // esi
  char *v15; // ebp
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]

  if ( (*this & 2) != 0 )
  {
    v18 = 0;
    if ( (int)this[9] > 0 )
    {
      v17 = 0;
      do
      {
        v2 = this[10];
        v3 = *(_DWORD *)(v2 + v17 + 4);
        v4 = v17 + v2;
        v5 = 0;
        if ( v3 > 0 )
        {
          v6 = 0;
          do
          {
            j__free(*(void **)(v6 + *(_DWORD *)(v4 + 8) + 4));
            ++v5;
            v6 += 12;
          }
          while ( v5 < *(_DWORD *)(v4 + 4) );
        }
        v7 = *(char **)(v4 + 8);
        if ( v7 )
        {
          `eh vector destructor iterator'(v7, 0xCu, *((_DWORD *)v7 - 1), nullsub_7);
          j__free(v7 - 4);
        }
        v8 = ++v18 < this[9];
        v17 += 12;
      }
      while ( v8 );
    }
    v9 = (char *)this[10];
    if ( v9 )
    {
      v10 = v9 - 4;
      `eh vector destructor iterator'(v9, 0xCu, *((_DWORD *)v9 - 1), j_nullsub_7);
LABEL_20:
      j__free(v10);
    }
  }
  else if ( (*this & 1) != 0 )
  {
    v11 = 0;
    if ( (int)this[7] > 0 )
    {
      v12 = 0;
      do
      {
        v13 = *(char **)(v12 + this[8] + 40);
        if ( v13 )
        {
          v14 = v13 - 4;
          `eh vector destructor iterator'(v13, 0x20u, *((_DWORD *)v13 - 1), nullsub_7);
          j__free(v14);
        }
        ++v11;
        v12 += 44;
      }
      while ( v11 < this[7] );
    }
    v15 = (char *)this[8];
    if ( v15 )
    {
      v10 = v15 - 4;
      `eh vector destructor iterator'(v15, 0x2Cu, *((_DWORD *)v15 - 1), j_nullsub_7);
      goto LABEL_20;
    }
  }
  return 0;
}
