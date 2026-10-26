int __thiscall sub_59AE80(int this, int *a2, int a3)
{
  int v5; // ebx
  int v6; // ebx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  const char *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int *v15; // edx
  int v16; // edx
  int *v17; // ecx
  int v18; // ecx
  int v19; // edx
  int v21; // [esp+18h] [ebp+8h]

  v5 = *(_DWORD *)(this + 292);
  *(_DWORD *)(this + 284) += this + a3;
  v6 = this + a3 + v5;
  v7 = this + a3 + *(_DWORD *)(this + 300);
  v8 = this + a3 + *(_DWORD *)(this + 308);
  v9 = *(_DWORD *)(this + 280);
  *(_DWORD *)(this + 300) = v7;
  v10 = 0;
  *(_DWORD *)(this + 292) = v6;
  *(_DWORD *)(this + 308) = v8;
  v21 = 0;
  if ( v9 <= 0 )
  {
LABEL_16:
    if ( *(int *)(this + 304) > 0 )
      *(_DWORD *)(this + 20) |= (unsigned int)&unk_800000;
    v18 = 0;
    if ( *(int *)(this + 288) > 0 )
    {
      v19 = 0;
      do
      {
        *(_DWORD *)(v19 + *(_DWORD *)(this + 292) + 8) = *(_DWORD *)(this + 284)
                                                       + (*(_DWORD *)(v19 + *(_DWORD *)(this + 292) + 8) << 6);
        ++v18;
        v19 += 36;
      }
      while ( v18 < *(_DWORD *)(this + 288) );
    }
    return 0;
  }
  else
  {
    while ( 1 )
    {
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 12) += this + a3;
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 24) = this;
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 20) += this + a3;
      v11 = (const char *)sub_59A620(a2, *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 4));
      v12 = sub_599BF0(*(_DWORD **)(dword_7E8E5C + 276), v11);
      if ( !v12 )
        break;
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 4) = v12;
      v13 = *(_DWORD *)(this + 284);
      v14 = *(_DWORD *)(v13 + v10);
      v15 = (int *)(v10 + v13);
      if ( (v14 & 3) == 0 )
        *v15 = v14 | 4;
      v16 = 0;
      if ( *(int *)(v12 + 172) > 0 )
      {
        v17 = (int *)(*(_DWORD *)(v12 + 176) + 84);
        do
        {
          if ( *(v17 - 3) > 1 && (*(_BYTE *)v17 & 6) == 0 )
            *(_BYTE *)(this + 22) |= 8u;
          if ( (*(_BYTE *)(v12 + 156) & 0x40) != 0 )
            *(_BYTE *)(this + 22) |= 0x10u;
          if ( (*((_BYTE *)v17 + 14) & 0x20) != 0 )
            *(_BYTE *)(this + 22) |= 0x10u;
          v17 += 37;
          ++v16;
        }
        while ( v16 < *(_DWORD *)(v12 + 172) );
      }
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 28) = 0;
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 36) = 0;
      v10 += 64;
      if ( ++v21 >= *(_DWORD *)(this + 280) )
        goto LABEL_16;
    }
    sub_591C60(this, -1, aSurfaceMatLibM);
    return -1;
  }
}
