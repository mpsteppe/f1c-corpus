int __thiscall sub_410890(_DWORD *this)
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
  int result; // eax
  int v14; // edi
  int v15; // ebx

  v2 = this[9];
  v3 = 0;
  this[27] = 0;
  if ( v2 > 0 )
  {
    v4 = 0;
    do
    {
      sub_40F130((_DWORD *)(v4 + this[10]));
      ++v3;
      v4 += 36;
    }
    while ( v3 < this[9] );
  }
  v5 = 0;
  if ( (int)this[12] > 0 )
  {
    v6 = 0;
    do
    {
      sub_40F130((_DWORD *)(v6 + this[13]));
      ++v5;
      v6 += 36;
    }
    while ( v5 < this[12] );
  }
  v7 = 0;
  if ( (int)this[15] > 0 )
  {
    v8 = 0;
    do
    {
      sub_40F130((_DWORD *)(v8 + this[16]));
      ++v7;
      v8 += 36;
    }
    while ( v7 < this[15] );
  }
  v9 = 416;
  if ( (int)this[18] > 416 )
  {
    v10 = 14976;
    do
    {
      sub_40F130((_DWORD *)(v10 + this[19]));
      ++v9;
      v10 += 36;
    }
    while ( v9 < this[18] );
  }
  v11 = 208;
  if ( (int)this[21] > 208 )
  {
    v12 = 7488;
    do
    {
      sub_40F130((_DWORD *)(v12 + this[22]));
      ++v11;
      v12 += 36;
    }
    while ( v11 < this[21] );
  }
  result = this[24];
  v14 = 832;
  if ( result > 832 )
  {
    v15 = 29952;
    do
    {
      sub_40F130((_DWORD *)(v15 + this[25]));
      result = this[24];
      ++v14;
      v15 += 36;
    }
    while ( v14 < result );
  }
  return result;
}
