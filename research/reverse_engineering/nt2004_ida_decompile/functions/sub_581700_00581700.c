int __thiscall sub_581700(_DWORD *this)
{
  int v2; // eax
  char *v3; // esi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // ebp
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // ebp
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // esi
  int v22; // ebp
  int v23; // eax

  v2 = this[1];
  *this = 0;
  if ( v2 )
  {
    v3 = (char *)(v2 + 580 * *(_DWORD *)(v2 - 4));
    if ( *(_DWORD *)(v2 - 4) - 1 >= 0 )
    {
      v4 = *(_DWORD *)(v2 - 4);
      do
      {
        v3 -= 580;
        sub_57BBF0(v3);
        --v4;
      }
      while ( v4 );
    }
    sub_5BE8AE();
    this[1] = 0;
  }
  v5 = this[3];
  this[2] = 0;
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 - 4);
    v7 = v5 + 48 * v6;
    v8 = v6 - 1;
    if ( v8 >= 0 )
    {
      v9 = v8 + 1;
      do
      {
        v10 = *(_DWORD *)(v7 - 48);
        v7 -= 48;
        if ( v10 )
          sub_5BE8AE();
        --v9;
      }
      while ( v9 );
    }
    sub_5BE8AE();
    this[3] = 0;
  }
  v11 = this[5];
  this[4] = 0;
  if ( v11 )
  {
    v12 = *(_DWORD *)(v11 - 4);
    v13 = v11 + 48 * v12;
    v14 = v12 - 1;
    if ( v14 >= 0 )
    {
      v15 = v14 + 1;
      do
      {
        v16 = *(_DWORD *)(v13 - 48);
        v13 -= 48;
        if ( v16 )
          sub_5BE8AE();
        --v15;
      }
      while ( v15 );
    }
    sub_5BE8AE();
    this[5] = 0;
  }
  v17 = this[7];
  this[6] = 0;
  if ( v17 )
  {
    v18 = *(_DWORD *)(v17 - 4);
    v19 = 9 * v18;
    v20 = v18 - 1;
    v21 = v17 + 8 * v19;
    if ( v20 >= 0 )
    {
      v22 = v20 + 1;
      do
      {
        v23 = *(_DWORD *)(v21 - 72);
        v21 -= 72;
        if ( v23 )
          sub_5BE8AE();
        --v22;
      }
      while ( v22 );
    }
    sub_5BE8AE();
    this[7] = 0;
  }
  if ( this[9] )
  {
    sub_5BE8AE();
    if ( this[10] )
      sub_5BE8AE();
    if ( this[11] )
      sub_5BE8AE();
  }
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  return sub_57FCA0(this + 13);
}
