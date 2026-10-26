int __thiscall sub_666ADA(_DWORD *this, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  char *v6; // edx
  unsigned int i; // eax
  int v8; // edx
  unsigned int j; // eax
  unsigned int v10; // edx
  unsigned int k; // edx
  int v12; // ecx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v17; // [esp+8h] [ebp-10h]
  _DWORD *v18; // [esp+Ch] [ebp-Ch]
  void *v19; // [esp+10h] [ebp-8h]
  void *Block; // [esp+14h] [ebp-4h]
  int v21; // [esp+28h] [ebp+10h]

  v6 = (char *)operator new(12 * a4);
  Block = v6;
  if ( v6 )
  {
    for ( i = 0; i < 3; ++i )
    {
      *(&v17 + i) = (int)v6;
      v6 += 4 * a4;
    }
    v8 = v17;
    for ( j = 0; j < a4; ++j )
      *(_DWORD *)(v8 + 4 * j) = this[11];
    v21 = sub_6624CC(v18, a4);
    if ( v21 >= 0 )
    {
      v21 = sub_6624CC(v19, a4);
      if ( v21 >= 0 )
      {
        v21 = sub_6641F3(this, a2, a4 & 0xFFFFF | 0x20500000, (int)v18, a3, v10);
        if ( v21 >= 0 )
        {
          v21 = sub_6641F3(this, a2, a4 & 0xFFFFF | 0x11000000, (int)v19, v18, 0);
          if ( v21 >= 0 )
          {
            for ( k = 0; k < a4; v13[3] = v14 )
            {
              v12 = this[2];
              v13 = *(_DWORD **)(*(_DWORD *)(v12 + 20) + 4 * *((_DWORD *)v19 + k));
              v13[1] = *(_DWORD *)(v12 + 168);
              v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[2] + 16) + 4 * *(_DWORD *)(this[2] + 168)) + 8);
              v13[4] = k++;
            }
            v15 = *(_DWORD *)(*(_DWORD *)(this[2] + 16) + 4 * *(_DWORD *)(this[2] + 168));
            ++*(_DWORD *)(v15 + 8);
            v21 = 0;
          }
        }
      }
    }
  }
  else
  {
    v21 = -2147024882;
  }
  j__free(Block);
  return v21;
}
