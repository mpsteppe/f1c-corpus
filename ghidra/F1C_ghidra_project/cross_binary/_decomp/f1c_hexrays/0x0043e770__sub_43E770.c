// f1c  0x0043e770  size=273
int __thiscall sub_43E770(_DWORD *this, int a2)
{
  int v2; // esi
  int result; // eax
  int v4; // edi
  int v5; // edx
  int v6; // eax
  int v7; // ebp
  int v8; // eax
  int v9; // edi
  int v10; // ebp
  int v11; // esi
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // ebp
  int v16; // esi
  int v17; // eax
  int v18; // edx
  int v19; // eax

  v2 = this[281 * a2 + 251];
  LOBYTE(this[281 * a2 + 276]) = 1;
  if ( v2 )
  {
    LOBYTE(this[281 * a2 + 291]) = 1;
    result = this[1393];
    v4 = 0;
    if ( result > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this[1394];
        v7 = *(_DWORD *)(v6 + v5 + 4);
        v8 = v5 + v6;
        if ( v7 == v2 || *(_DWORD *)(v8 + 12) == v2 )
          *(_DWORD *)(v8 + 68) |= 1u;
        result = this[1393];
        ++v4;
        v5 += 72;
      }
      while ( v4 < result );
    }
  }
  else
  {
    v9 = this[281 * a2 + 250];
    v10 = 0;
    if ( (int)this[1389] > 0 )
    {
      v11 = 0;
      do
      {
        v12 = this[1390];
        v13 = *(_DWORD *)(v12 + v11 + 4);
        v14 = v11 + v12;
        if ( v13 == v9 && *(_DWORD *)(v14 + 12) == this[1287] || *(_DWORD *)(v14 + 12) == v9 && v13 == this[1287] )
          *(_DWORD *)(v14 + 44) |= 1u;
        ++v10;
        v11 += 48;
      }
      while ( v10 < this[1389] );
    }
    result = this[1391];
    v15 = 0;
    if ( result > 0 )
    {
      v16 = 0;
      do
      {
        v17 = this[1392];
        v18 = *(_DWORD *)(v17 + v16 + 4);
        v19 = v16 + v17;
        if ( v18 == v9 && *(_DWORD *)(v19 + 12) == this[1287] || *(_DWORD *)(v19 + 12) == v9 && v18 == this[1287] )
          *(_DWORD *)(v19 + 44) |= 1u;
        result = this[1391];
        ++v15;
        v16 += 48;
      }
      while ( v15 < result );
    }
  }
  return result;
}
