int __thiscall sub_56ECF0(int *this)
{
  int v2; // ecx
  int v3; // ebp
  int v4; // edi
  int i; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // ebx
  int v11; // ebx
  int v12; // eax
  char v13; // cl
  int v14; // eax
  int v15; // edi
  int v16; // ebp
  int v17; // ebx
  int v18; // edx
  int v19; // edi
  int v20; // ebx
  int v21; // edi
  int v22; // ecx
  int v23; // ecx
  int v25; // [esp-4h] [ebp-14h]

  v2 = this[12];
  v3 = 0;
  if ( v2 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 28))(v2);
  }
  else
  {
    v4 = this[8];
    for ( i = 0; i < v4; ++i )
    {
      v6 = *(_DWORD *)(this[10] + 4 * i);
      v7 = 0;
      if ( v4 > 0 )
      {
        do
        {
          *(_DWORD *)(v6 + 8 * v7) = 0;
          *(_DWORD *)(v6 + 8 * v7++ + 4) = 0;
        }
        while ( v7 < this[8] );
      }
      v8 = this[11];
      *(_DWORD *)(v8 + 8 * i) = 0;
      *(_DWORD *)(v8 + 8 * i + 4) = 0;
      v4 = this[8];
    }
  }
  BatchProcessingLoop3Passes(this);
  v9 = 0;
  if ( *this > 0 )
  {
    v10 = 0;
    do
    {
      InertialTensorVectorTransform(v10 + this[1]);
      ++v9;
      v10 += 580;
    }
    while ( v9 < *this );
  }
  if ( this[2] > 0 )
  {
    v11 = 0;
    do
    {
      v12 = this[3];
      v13 = *(_BYTE *)(v12 + v11 + 44);
      v14 = v11 + v12;
      if ( (v13 & 1) != 0 )
      {
        v25 = *(_DWORD *)(*(_DWORD *)(v14 + 8) + 48);
        v15 = v25 + 1;
        MatrixIdentityInitialization(this, v25);
        MatrixIdentityInitialization(this, v15);
        MatrixIdentityInitialization(this, v15 + 1);
      }
      ++v3;
      v11 += 48;
    }
    while ( v3 < this[2] );
  }
  v16 = 0;
  if ( this[4] > 0 )
  {
    v17 = 0;
    do
    {
      v18 = this[5];
      if ( (*(_BYTE *)(v17 + v18 + 44) & 1) != 0 )
      {
        v19 = *(_DWORD *)(*(_DWORD *)(v17 + v18 + 8) + 124);
        MatrixIdentityInitialization(this, v19);
        MatrixIdentityInitialization(this, v19 + 1);
      }
      ++v16;
      v17 += 48;
    }
    while ( v16 < this[4] );
  }
  v20 = 0;
  if ( this[6] > 0 )
  {
    v21 = 0;
    do
    {
      v22 = this[7];
      if ( (*(_BYTE *)(v22 + v21 + 68) & 1) != 0 )
        MatrixIdentityInitialization(this, *(_DWORD *)(*(_DWORD *)(v22 + v21 + 8) + 48));
      ++v20;
      v21 += 72;
    }
    while ( v20 < this[6] );
  }
  v23 = this[12];
  if ( v23 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 20))(v23);
  else
    return sub_56CD70(this + 13, this[10], this[11], this[8]);
}
