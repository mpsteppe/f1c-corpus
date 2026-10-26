char __thiscall sub_56DC50(int this, float *a2)
{
  float *v2; // ebp
  int v4; // esi
  int v5; // edx
  float *v6; // ecx
  int v7; // edx
  int v8; // ecx
  float *v9; // esi
  float v10; // eax
  double v11; // st7
  int v13; // eax
  int v14; // eax
  int v15; // esi
  int v16; // edx
  float *v17; // ecx
  char *v18; // edi
  int v19; // ebp
  float v20; // [esp+10h] [ebp-4h]

  v2 = a2;
  v4 = *(_DWORD *)(this + 24);
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = (float *)(this + 32);
    do
    {
      if ( *(_DWORD *)a2 == *((_DWORD *)v6 - 1)
        && a2[1] == *v6
        && a2[2] == v6[1]
        && a2[3] == v6[2]
        && a2[4] == v6[3]
        && a2[5] == v6[4]
        && a2[6] == v6[5]
        && a2[7] == v6[6]
        && a2[8] == v6[7] )
      {
        return sub_56A0D0((float *)this, a2[1], -1);
      }
      ++v5;
      v6 += 9;
    }
    while ( v5 < *(_DWORD *)(this + 24) );
  }
  if ( v4 != 20 )
    goto LABEL_35;
  v7 = -1;
  v20 = 3.4028235e38;
  v8 = 0;
  v9 = (float *)(this + 28);
  do
  {
    v10 = *v9;
    v11 = 1.7014117e38;
    if ( !*(_DWORD *)v9 )
    {
      v11 = v9[8];
      goto LABEL_28;
    }
    if ( LODWORD(v10) == 1 )
    {
      if ( v8 <= 0 )
        goto LABEL_28;
      v13 = *((_DWORD *)v9 - 9);
      if ( v13 != 1 )
        goto LABEL_26;
    }
    else
    {
      if ( LODWORD(v10) != 2 )
        goto LABEL_28;
      if ( v8 )
      {
        if ( v8 <= 0 )
          goto LABEL_28;
        v13 = *((_DWORD *)v9 - 9);
LABEL_26:
        if ( v13 != 2 )
          goto LABEL_28;
      }
    }
    v11 = -1.0;
LABEL_28:
    if ( v11 < v20 )
    {
      v20 = v11;
      v7 = v8;
    }
    ++v8;
    v9 += 9;
  }
  while ( v8 < *(_DWORD *)(this + 24) );
  if ( v7 < 20 )
  {
    v14 = this + 36 * v7 + 28;
    do
    {
      qmemcpy((void *)v14, (const void *)(v14 + 36), 0x24u);
      ++v7;
      v14 += 36;
    }
    while ( v7 < *(_DWORD *)(this + 24) );
  }
  --*(_DWORD *)(this + 24);
LABEL_35:
  v15 = *(_DWORD *)(this + 24);
  v16 = 0;
  if ( v15 > 0 )
  {
    v17 = (float *)(this + 32);
    do
    {
      if ( a2[1] < (double)*v17 )
        break;
      ++v16;
      v17 += 9;
    }
    while ( v16 < *(_DWORD *)(this + 24) );
  }
  if ( v15 - 1 >= v16 )
  {
    v18 = (char *)(this + 36 * (v15 - 1) + 64);
    v19 = v15 - v16;
    do
    {
      --v19;
      qmemcpy(v18, v18 - 36, 0x24u);
      v18 -= 36;
    }
    while ( v19 );
    v2 = a2;
  }
  qmemcpy((void *)(this + 36 * v16 + 28), v2, 0x24u);
  ++*(_DWORD *)(this + 24);
  return sub_56A0D0((float *)this, v2[1], v16);
}
