int __thiscall sub_4DEDB0(float *this, float *a2)
{
  float *v2; // ebx
  int v4; // edx
  int v5; // esi
  float *v6; // ecx
  int v7; // edx
  int v8; // ecx
  float *v9; // esi
  float v10; // eax
  double v11; // st7
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  float *v17; // esi
  float *v18; // edi
  int v19; // eax
  float v20; // [esp+10h] [ebp-4h]

  v2 = a2;
  v4 = *((_DWORD *)this + 6);
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = this + 8;
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
        return sub_4DF110(a2[1], -1);
      }
      ++v5;
      v6 += 9;
    }
    while ( v5 < v4 );
  }
  if ( v4 != 20 )
    goto LABEL_34;
  v7 = -1;
  v20 = 3.4028235e38;
  v8 = 0;
  v9 = this + 7;
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
  while ( v8 < 20 );
  v14 = (int)&this[9 * v7 + 7];
  do
  {
    qmemcpy((void *)v14, (const void *)(v14 + 36), 0x24u);
    ++v7;
    v14 += 36;
  }
  while ( v7 < *((_DWORD *)this + 6) );
  --*((_DWORD *)this + 6);
LABEL_34:
  v15 = *((_DWORD *)this + 6);
  v16 = 0;
  if ( v15 > 0 )
  {
    v17 = this + 8;
    do
    {
      if ( a2[1] < (double)*v17 )
        break;
      ++v16;
      v17 += 9;
    }
    while ( v16 < v15 );
  }
  if ( v15 - 1 >= v16 )
  {
    v18 = &this[9 * v15 + 7];
    v19 = v15 - v16;
    do
    {
      --v19;
      qmemcpy(v18, v18 - 9, 0x24u);
      v18 -= 9;
    }
    while ( v19 );
    v2 = a2;
  }
  qmemcpy(&this[9 * v16 + 7], v2, 0x24u);
  ++*((_DWORD *)this + 6);
  return sub_4DF110(v2[1], v16);
}
