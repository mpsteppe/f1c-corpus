int __thiscall sub_430F00(char *this)
{
  int v2; // eax
  char v3; // cl
  int v4; // eax
  char v5; // cl
  char *v6; // esi
  int v7; // edi
  int v8; // esi
  int v9; // eax
  char v10; // cl
  int v11; // eax
  char v12; // cl
  int v13; // eax
  char v14; // cl
  int v15; // eax
  char v16; // cl
  int v17; // eax
  char v18; // cl
  int v19; // eax
  char v20; // cl
  int v21; // eax
  char v22; // cl
  int v23; // eax
  char v24; // cl
  double v25; // st7
  double v26; // st7
  int v27; // eax
  char v28; // cl
  int v29; // eax
  char v30; // cl
  int v31; // eax
  char v32; // cl
  int v33; // eax
  char v34; // cl
  int v35; // eax
  char v36; // cl
  int v37; // eax
  char v38; // cl
  double v40; // [esp+1Ch] [ebp-120h]
  double j; // [esp+1Ch] [ebp-120h]
  double v42; // [esp+24h] [ebp-118h]
  double v43; // [esp+24h] [ebp-118h]
  double v44; // [esp+24h] [ebp-118h]
  double v45; // [esp+2Ch] [ebp-110h]
  double i; // [esp+34h] [ebp-108h]
  char v47[64]; // [esp+3Ch] [ebp-100h] BYREF
  char v48[64]; // [esp+7Ch] [ebp-C0h] BYREF
  char v49[64]; // [esp+BCh] [ebp-80h] BYREF
  char v50[64]; // [esp+FCh] [ebp-40h] BYREF

  if ( BinarySearchInStringTable(byte_5EC4C0, byte_5C3F6C, byte_5EC4CC) )
  {
    v2 = 0;
    do
    {
      v3 = byte_5C3F6C[v2];
      byte_5EC4CC[v2++] = v3;
    }
    while ( v3 );
  }
  v4 = 0;
  do
  {
    v5 = byte_5EC4CC[v4];
    v49[v4++] = v5;
  }
  while ( v5 );
  v6 = this + 6950;
  v7 = 3;
  do
  {
    StringFormatWithBufferOverflowCheck(v6, &off_5C3810);
    v6 += 128;
    --v7;
  }
  while ( v7 );
  if ( byte_7D0474 )
  {
    v8 = 150;
    v45 = 41.66666666666667;
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3F68, byte_5EC4CC) )
    {
      v9 = 0;
      do
      {
        v10 = *((_BYTE *)&off_5C3F68 + v9);
        byte_5EC4CC[v9++] = v10;
      }
      while ( v10 );
    }
    v11 = 0;
    do
    {
      v12 = byte_5EC4CC[v11];
      v48[v11++] = v12;
    }
    while ( v12 );
  }
  else
  {
    v8 = 100;
    v45 = 44.704;
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3F64, byte_5EC4CC) )
    {
      v13 = 0;
      do
      {
        v14 = *((_BYTE *)&off_5C3F64 + v13);
        byte_5EC4CC[v13++] = v14;
      }
      while ( v14 );
    }
    v15 = 0;
    do
    {
      v16 = byte_5EC4CC[v15];
      v48[v15++] = v16;
    }
    while ( v16 );
  }
  if ( BinarySearchInStringTable(byte_5EC4C0, aEstAccel, byte_5EC4CC) )
  {
    v17 = 0;
    do
    {
      v18 = aEstAccel[v17];
      byte_5EC4CC[v17++] = v18;
    }
    while ( v18 );
  }
  v19 = 0;
  do
  {
    v20 = byte_5EC4CC[v19];
    v47[v19++] = v20;
  }
  while ( v20 );
  if ( BinarySearchInStringTable(byte_5EC4C0, aS_2, byte_5EC4CC) )
  {
    v21 = 0;
    do
    {
      v22 = aS_2[v21];
      byte_5EC4CC[v21++] = v22;
    }
    while ( v22 );
  }
  v23 = 0;
  do
  {
    v24 = byte_5EC4CC[v23];
    v50[v23++] = v24;
  }
  while ( v24 );
  StringFormatWithBufferOverflowCheck(this + 6566, "%s (0-%d %s)%s", v47, v8, v48, v49);
  v40 = 0.0;
  for ( i = 0.0; ; i = i + 0.04 )
  {
    v25 = BrakeTemperatureFadeModel((int)this, v40);
    if ( v25 <= 0.0 )
      break;
    v26 = BrakeTemperatureFadeModel((int)this, v25 * 0.02 + v40);
    if ( v26 <= 0.0 )
      break;
    v42 = v26 * 0.04;
    if ( v42 + v40 > v45 )
    {
      StringFormatWithBufferOverflowCheck(this + 6950, "%.2f %s", (v45 - v40) / v42 * 0.04 + i, v50);
      break;
    }
    v40 = v42 + v40;
  }
  if ( BinarySearchInStringTable(byte_5EC4C0, aEstTopSpeed, byte_5EC4CC) )
  {
    v27 = 0;
    do
    {
      v28 = aEstTopSpeed[v27];
      byte_5EC4CC[v27++] = v28;
    }
    while ( v28 );
  }
  v29 = 0;
  do
  {
    v30 = byte_5EC4CC[v29];
    v47[v29++] = v30;
  }
  while ( v30 );
  StringFormatWithBufferOverflowCheck(this + 6694, "%s%s", v47, v49);
  for ( j = 0.0; BrakeTemperatureFadeModel((int)this, j) > 0.0; j = j + 0.135 )
    ;
  if ( byte_7D0474 )
    v43 = j * 3.6;
  else
    v43 = j * 2.236936292054402;
  StringFormatWithBufferOverflowCheck(this + 7078, "%d %s", (int)v43, v48);
  v44 = sub_430750((int)this, 75.0);
  if ( BinarySearchInStringTable(byte_5EC4C0, aEstCornering, byte_5EC4CC) )
  {
    v31 = 0;
    do
    {
      v32 = aEstCornering[v31];
      byte_5EC4CC[v31++] = v32;
    }
    while ( v32 );
  }
  v33 = 0;
  do
  {
    v34 = byte_5EC4CC[v33];
    v47[v33++] = v34;
  }
  while ( v34 );
  if ( BinarySearchInStringTable(byte_5EC4C0, aG, byte_5EC4CC) )
  {
    v35 = 0;
    do
    {
      v36 = aG[v35];
      byte_5EC4CC[v35++] = v36;
    }
    while ( v36 );
  }
  v37 = 0;
  do
  {
    v38 = byte_5EC4CC[v37];
    v50[v37++] = v38;
  }
  while ( v38 );
  StringFormatWithBufferOverflowCheck(this + 6822, "%s%s", v47, v49);
  return StringFormatWithBufferOverflowCheck(this + 7206, "%.2f %s", v44 * 0.1019367991845056, v50);
}
