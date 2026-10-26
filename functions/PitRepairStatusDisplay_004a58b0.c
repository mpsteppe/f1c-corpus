int __thiscall sub_4A58B0(int this)
{
  int v2; // eax
  int v3; // eax
  const char **v4; // eax
  int v5; // eax
  char v6; // cl
  const char *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  char v11; // cl
  const char *v12; // esi
  int v13; // eax
  char v14; // cl
  int v16; // ebp
  const char *v17; // esi
  double v18; // [esp+1Ch] [ebp-48h]
  char v19[64]; // [esp+24h] [ebp-40h] BYREF

  v18 = (double)*(int *)(this + 108) * *(double *)(this + 96) + *(double *)(this + 88);
  if ( *(float *)(this + 380) == 0.0 )
  {
    v19[0] = 0;
  }
  else
  {
    v2 = CRTFtol(*(float *)(this + 380) * v18);
    StringFormatWithBufferOverflowCheck(v19, &off_5CCEA4, v2);
  }
  if ( dword_7D0450 == 1 )
  {
    StringFormatWithBufferOverflowCheck(this + 118, "%4.1f%s", v18 * 0.2641720372841846, v19);
  }
  else
  {
    v3 = CRTFtol(v18 + 0.5);
    StringFormatWithBufferOverflowCheck(this + 118, "%d%s", v3, v19);
  }
  v4 = (const char **)NthValidPartLookup((_DWORD *)this, *(_DWORD *)(this + 172));
  if ( v4 )
  {
    v7 = *v4;
    if ( !*v4 )
      v7 = byte_5EA438;
    if ( BinarySearchInStringTable(byte_5EC4C0, v7, byte_5EC4CC) )
    {
      if ( v7 )
        strcpy(byte_5EC4CC, v7);
      else
        byte_5EC4CC[0] = 0;
    }
  }
  else if ( BinarySearchInStringTable(byte_5EC4C0, aNoChange, byte_5EC4CC) )
  {
    v5 = 0;
    do
    {
      v6 = aNoChange[v5];
      byte_5EC4CC[v5++] = v6;
    }
    while ( v6 );
  }
  StringFormatWithBufferOverflowCheck(this + 182, "%s", byte_5EC4CC);
  v8 = *(_DWORD *)(this + 236);
  v9 = *(_DWORD *)(this + 240);
  if ( v8 == v9 )
  {
    StringFormatWithBufferOverflowCheck(this + 246, "%d", v8 + 1);
  }
  else if ( v8 <= v9 )
  {
    StringFormatWithBufferOverflowCheck(this + 246, "%d (-%d)", v8 + 1, v9 - v8);
  }
  else
  {
    StringFormatWithBufferOverflowCheck(this + 246, "%d (+%d)", v8 + 1, v8 - v9);
  }
  if ( *(_DWORD *)(this + 296) == 1 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3810, byte_5EC4CC) )
    {
      v10 = 0;
      do
      {
        v11 = *((_BYTE *)&off_5C3810 + v10);
        byte_5EC4CC[v10++] = v11;
      }
      while ( v11 );
    }
  }
  else
  {
    v12 = aRepair;
    if ( !*(_DWORD *)(this + 300) )
      v12 = aDoNotRepair;
    if ( BinarySearchInStringTable(byte_5EC4C0, v12, byte_5EC4CC) )
    {
      if ( v12 )
        strcpy(byte_5EC4CC, v12);
      else
        byte_5EC4CC[0] = 0;
    }
  }
  StringFormatWithBufferOverflowCheck(this + 310, "%s", byte_5EC4CC);
  if ( *(_DWORD *)(this + 40) == 1 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3810, byte_5EC4CC) )
    {
      v13 = 0;
      do
      {
        v14 = *((_BYTE *)&off_5C3810 + v13);
        byte_5EC4CC[v13++] = v14;
      }
      while ( v14 );
    }
    return StringFormatWithBufferOverflowCheck(this + 54, "%s", byte_5EC4CC);
  }
  else
  {
    v16 = *(_DWORD *)(*(_DWORD *)this + 16500);
    v17 = (const char *)&off_5C6E14;
    if ( !*(_DWORD *)(this + 44) )
      v17 = (const char *)&unk_5C6E18;
    if ( BinarySearchInStringTable(byte_5EC4C0, v17, byte_5EC4CC) )
    {
      if ( v17 )
        strcpy(byte_5EC4CC, v17);
      else
        byte_5EC4CC[0] = 0;
    }
    return StringFormatWithBufferOverflowCheck(this + 54, "%s/%d", byte_5EC4CC, v16);
  }
}
