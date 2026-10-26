int __thiscall sub_4197B0(_DWORD *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  int v6; // ebx
  int v7; // edi
  int v8; // ebx
  int v9; // edi
  int v10; // ebx
  int v11; // edi
  int v12; // ebx
  int v13; // edi
  int v14; // ebx
  int result; // eax
  int v16; // edi
  int v17; // ebx

  v2 = this[9];
  v3 = 0;
  this[31] = 0;
  if ( v2 > 0 )
  {
    v4 = 0;
    do
    {
      sub_418460((int *)(v4 + this[10]));
      ++v3;
      v4 += 40;
    }
    while ( v3 < this[9] );
  }
  v5 = 0;
  if ( (int)this[12] > 0 )
  {
    v6 = 0;
    do
    {
      sub_418460((int *)(v6 + this[13]));
      ++v5;
      v6 += 40;
    }
    while ( v5 < this[12] );
  }
  v7 = 0;
  if ( (int)this[15] > 0 )
  {
    v8 = 0;
    do
    {
      sub_418460((int *)(v8 + this[16]));
      ++v7;
      v8 += 40;
    }
    while ( v7 < this[15] );
  }
  v9 = 0;
  if ( (int)this[27] > 0 )
  {
    v10 = 0;
    do
    {
      sub_418460((int *)(v10 + this[28]));
      ++v9;
      v10 += 40;
    }
    while ( v9 < this[27] );
  }
  v11 = 420;
  if ( (int)this[18] > 420 )
  {
    v12 = 16800;
    do
    {
      sub_418460((int *)(v12 + this[19]));
      ++v11;
      v12 += 40;
    }
    while ( v11 < this[18] );
  }
  v13 = 210;
  if ( (int)this[21] > 210 )
  {
    v14 = 8400;
    do
    {
      sub_418460((int *)(v14 + this[22]));
      ++v13;
      v14 += 40;
    }
    while ( v13 < this[21] );
  }
  result = this[24];
  v16 = 840;
  if ( result > 840 )
  {
    v17 = 33600;
    do
    {
      sub_418460((int *)(v17 + this[25]));
      result = this[24];
      ++v16;
      v17 += 40;
    }
    while ( v16 < result );
  }
  return result;
}
