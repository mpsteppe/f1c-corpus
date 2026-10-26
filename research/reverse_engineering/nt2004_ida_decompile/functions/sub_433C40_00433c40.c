int __thiscall sub_433C40(char *this)
{
  int v2; // eax
  char v3; // cl
  char *v4; // esi
  int v5; // edi
  int v6; // esi
  int v7; // eax
  char v8; // cl
  int v9; // eax
  char v10; // cl
  int v11; // eax
  char v12; // cl
  int v13; // eax
  char v14; // cl
  double v15; // st7
  double v16; // st7
  int v17; // eax
  char v18; // cl
  int v19; // eax
  char v20; // cl
  int v21; // eax
  char v22; // cl
  double v24; // [esp+1Ch] [ebp-120h]
  double j; // [esp+1Ch] [ebp-120h]
  double v26; // [esp+24h] [ebp-118h]
  double v27; // [esp+24h] [ebp-118h]
  double v28; // [esp+24h] [ebp-118h]
  double v29; // [esp+2Ch] [ebp-110h]
  double i; // [esp+34h] [ebp-108h]
  char v31[64]; // [esp+3Ch] [ebp-100h] BYREF
  char v32[64]; // [esp+7Ch] [ebp-C0h] BYREF
  char v33[64]; // [esp+BCh] [ebp-80h] BYREF
  char v34[64]; // [esp+FCh] [ebp-40h] BYREF

  if ( sub_41F230(dword_62A170, asc_5FE040, Destination) )
  {
    strncpy(Destination, asc_5FE040, 0x1FFu);
    byte_62A37B = 0;
  }
  v2 = 0;
  do
  {
    v3 = Destination[v2];
    v33[v2++] = v3;
  }
  while ( v3 );
  v4 = this + 6950;
  v5 = 3;
  do
  {
    sprintf(v4, off_5FD8E4);
    v4 += 128;
    --v5;
  }
  while ( v5 );
  if ( byte_768A14 )
  {
    v6 = 150;
    v29 = 41.66666666666667;
    if ( sub_41F230(dword_62A170, off_5FE03C, Destination) )
    {
      strncpy(Destination, off_5FE03C, 0x1FFu);
      byte_62A37B = 0;
    }
    v7 = 0;
    do
    {
      v8 = Destination[v7];
      v32[v7++] = v8;
    }
    while ( v8 );
  }
  else
  {
    v6 = 100;
    v29 = 44.704;
    if ( sub_41F230(dword_62A170, off_5FE038, Destination) )
    {
      strncpy(Destination, off_5FE038, 0x1FFu);
      byte_62A37B = 0;
    }
    v9 = 0;
    do
    {
      v10 = Destination[v9];
      v32[v9++] = v10;
    }
    while ( v10 );
  }
  if ( sub_41F230(dword_62A170, aEstAccel, Destination) )
  {
    strncpy(Destination, aEstAccel, 0x1FFu);
    byte_62A37B = 0;
  }
  v11 = 0;
  do
  {
    v12 = Destination[v11];
    v31[v11++] = v12;
  }
  while ( v12 );
  if ( sub_41F230(dword_62A170, aS_1, Destination) )
  {
    strncpy(Destination, aS_1, 0x1FFu);
    byte_62A37B = 0;
  }
  v13 = 0;
  do
  {
    v14 = Destination[v13];
    v34[v13++] = v14;
  }
  while ( v14 );
  sprintf(this + 6566, "%s (0-%d %s)%s", v31, v6, v32, v33);
  v24 = 0.0;
  for ( i = 0.0; ; i = i + 0.04 )
  {
    v15 = sub_433740((int)this, v24);
    if ( v15 <= 0.0 )
      break;
    v16 = sub_433740((int)this, v15 * 0.02 + v24);
    if ( v16 <= 0.0 )
      break;
    v26 = v16 * 0.04;
    if ( v26 + v24 > v29 )
    {
      sprintf(this + 6950, "%.2f %s", (v29 - v24) / v26 * 0.04 + i, v34);
      break;
    }
    v24 = v26 + v24;
  }
  if ( sub_41F230(dword_62A170, aEstTopSpeed, Destination) )
  {
    strncpy(Destination, aEstTopSpeed, 0x1FFu);
    byte_62A37B = 0;
  }
  v17 = 0;
  do
  {
    v18 = Destination[v17];
    v31[v17++] = v18;
  }
  while ( v18 );
  sprintf(this + 6694, "%s%s", v31, v33);
  for ( j = 0.0; sub_433740((int)this, j) > 0.0; j = j + 0.135 )
    ;
  if ( byte_768A14 )
    v27 = j * 3.6;
  else
    v27 = j * 2.236936292054402;
  sprintf(this + 7078, "%d %s", (int)v27, v32);
  v28 = sub_433420((int)this, 75.0);
  if ( sub_41F230(dword_62A170, aEstCornering, Destination) )
  {
    strncpy(Destination, aEstCornering, 0x1FFu);
    byte_62A37B = 0;
  }
  v19 = 0;
  do
  {
    v20 = Destination[v19];
    v31[v19++] = v20;
  }
  while ( v20 );
  if ( sub_41F230(dword_62A170, aG, Destination) )
  {
    strncpy(Destination, aG, 0x1FFu);
    byte_62A37B = 0;
  }
  v21 = 0;
  do
  {
    v22 = Destination[v21];
    v34[v21++] = v22;
  }
  while ( v22 );
  sprintf(this + 6822, "%s%s", v31, v33);
  return sprintf(this + 7206, "%.2f %s", v28 * 0.1019367991845056, v34);
}
