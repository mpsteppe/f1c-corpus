int __thiscall sub_68FECA(_DWORD *this)
{
  unsigned int v1; // edi
  int *v3; // ebx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edi
  int v11; // ecx
  int v12; // ecx
  int v13; // edi
  int v14; // [esp+Ch] [ebp-14h]
  int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-Ch]
  unsigned int v18; // [esp+18h] [ebp-8h]
  unsigned int v19; // [esp+18h] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-4h]
  unsigned int v21; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  v14 = 0;
  sub_686074((int)this);
  v3 = (int *)operator new(4 * this[2]);
  v15 = (int)v3;
  if ( !v3 )
    return -2147024882;
  v5 = 0;
  v18 = 0;
  v16 = 0;
  if ( this[2] )
  {
    do
    {
      v6 = *(_DWORD *)(this[5] + 4 * v5);
      *(_DWORD *)(v6 + 48) = v5;
      v7 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v6 + 4)) + 4);
      if ( (v7 & 0x100) != 0 && (v7 & 0xC00) == 0 )
        v3[v1++] = v5;
      ++v5;
    }
    while ( v5 < this[2] );
    v18 = v1;
  }
  sub_682274(sub_681E57, v3, v1, (int)this);
  v20 = 1;
  if ( v1 > 1 )
  {
    while ( 1 )
    {
      v8 = &v3[v20];
      if ( !sub_681E57(*(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(v8 - 1)) + 48), *v8, (int)this) )
      {
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v8) + 4) = this[29];
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v8) + 48) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(v8 - 1)) + 48);
        v16 = 1;
      }
      if ( ++v20 >= v18 )
        break;
      v3 = (int *)v15;
    }
    if ( v16 )
    {
      sub_68661F(this);
      v14 = 1;
    }
    v3 = (int *)v15;
  }
  v9 = 0;
  v10 = 0;
  v19 = 0;
  v17 = 0;
  if ( this[2] )
  {
    do
    {
      v11 = *(_DWORD *)(this[5] + 4 * v9);
      *(_DWORD *)(v11 + 48) = v9;
      v12 = *(_DWORD *)(v11 + 4);
      if ( this[29] != v12 && ((*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v12) + 4) & 0x40) != 0 || this[55]) )
        v3[v10++] = v9;
      ++v9;
    }
    while ( v9 < this[2] );
    v19 = v10;
  }
  sub_682274(sub_681EA6, v3, v10, (int)this);
  if ( v10 )
    v15 = *v3;
  v21 = 1;
  if ( v10 > 1 )
  {
    do
    {
      v13 = v3[v21];
      if ( sub_681EA6(v15, v13, (int)this) )
      {
        v15 = v13;
      }
      else
      {
        sub_688FBF(this, v15, v13);
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v3[v21]) + 4) = this[29];
        v17 = 1;
      }
      ++v21;
    }
    while ( v21 < v19 );
    if ( v17 )
    {
      sub_68661F(this);
      v14 = 1;
    }
  }
  j__free(v3);
  return v14 == 0;
}
