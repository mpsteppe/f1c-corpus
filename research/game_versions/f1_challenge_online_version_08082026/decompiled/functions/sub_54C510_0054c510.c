int __thiscall sub_54C510(int this, int *a2, int a3)
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
  int v15; // ecx
  int v16; // edx
  int v18; // [esp+18h] [ebp+8h]

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
  v18 = 0;
  if ( v9 <= 0 )
  {
LABEL_13:
    if ( *(int *)(this + 304) > 0 )
      *(_DWORD *)(this + 20) |= (unsigned int)&unk_800000;
    v15 = 0;
    if ( *(int *)(this + 288) > 0 )
    {
      v16 = 0;
      do
      {
        *(_DWORD *)(v16 + *(_DWORD *)(this + 292) + 8) = *(_DWORD *)(this + 284)
                                                       + (*(_DWORD *)(v16 + *(_DWORD *)(this + 292) + 8) << 6);
        ++v15;
        v16 += 36;
      }
      while ( v15 < *(_DWORD *)(this + 288) );
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
      v11 = (const char *)sub_548850(a2, *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 4));
      v12 = sub_5477F0(*(_DWORD **)(dword_8B8F28 + 272), v11);
      if ( !v12 )
        break;
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 4) = v12;
      v13 = 0;
      if ( *(int *)(v12 + 164) > 0 )
      {
        v14 = *(_DWORD *)(v12 + 168) + 96;
        do
        {
          if ( *(int *)(v14 - 24) > 1 )
            *(_BYTE *)(this + 22) |= 8u;
          if ( (*(_BYTE *)(v12 + 156) & 0x40) != 0 )
            *(_BYTE *)(this + 22) |= 0x10u;
          if ( (*(_BYTE *)(v14 + 2) & 0x20) != 0 )
            *(_BYTE *)(this + 22) |= 0x10u;
          v14 += 148;
          ++v13;
        }
        while ( v13 < *(_DWORD *)(v12 + 164) );
      }
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 28) = 0;
      *(_DWORD *)(v10 + *(_DWORD *)(this + 284) + 36) = 0;
      v10 += 64;
      if ( ++v18 >= *(_DWORD *)(this + 280) )
        goto LABEL_13;
    }
    sub_53C590(-1, aSurfaceMatLibM);
    return -1;
  }
}
