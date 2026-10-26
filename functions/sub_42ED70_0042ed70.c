char *__thiscall sub_42ED70(int this)
{
  int v2; // eax
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  int v6; // eax
  char v7; // cl
  char *v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  char *v12; // eax
  char v13; // cl
  int v14; // eax
  char v15; // cl
  int v16; // eax
  char v17; // cl
  int v18; // eax
  char v19; // cl
  int v20; // eax
  char v21; // cl
  int v22; // eax
  char v23; // cl
  int v24; // eax
  char v25; // cl
  int v26; // eax
  char v27; // cl
  int v28; // eax
  char v29; // cl
  int v30; // eax
  char v31; // cl
  char *result; // eax
  char v33; // cl
  int v34; // eax
  char v35; // cl
  char *v36; // eax
  char v37; // cl
  int v38; // eax
  char v39; // cl
  char *v40; // eax
  char v41; // cl
  int v42; // eax
  char v43; // cl
  int v44; // eax
  char v45; // cl
  char v46[64]; // [esp+4h] [ebp-C0h] BYREF
  char v47[64]; // [esp+44h] [ebp-80h] BYREF
  char v48[64]; // [esp+84h] [ebp-40h] BYREF

  if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3774, byte_5EC4CC) )
  {
    v2 = 0;
    do
    {
      v3 = *((_BYTE *)&off_5C3774 + v2);
      byte_5EC4CC[v2++] = v3;
    }
    while ( v3 );
  }
  v4 = byte_5EC4CC;
  do
  {
    v5 = *v4;
    v4[this - (_DWORD)byte_5EC4CC + 40] = *v4;
    ++v4;
  }
  while ( v5 );
  if ( *(_DWORD *)(this + 4) )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3744, byte_5EC4CC) )
    {
      v34 = 0;
      do
      {
        v35 = *((_BYTE *)&off_5C3744 + v34);
        byte_5EC4CC[v34++] = v35;
      }
      while ( v35 );
    }
    v36 = byte_5EC4CC;
    do
    {
      v37 = *v36;
      v36[this - (_DWORD)byte_5EC4CC + 8] = *v36;
      ++v36;
    }
    while ( v37 );
    if ( BinarySearchInStringTable(byte_5EC4C0, byte_5C3740, byte_5EC4CC) )
    {
      v38 = 0;
      do
      {
        v39 = byte_5C3740[v38];
        byte_5EC4CC[v38++] = v39;
      }
      while ( v39 );
    }
    v40 = byte_5EC4CC;
    do
    {
      v41 = *v40;
      v40[this - (_DWORD)byte_5EC4CC + 24] = *v40;
      ++v40;
    }
    while ( v41 );
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3700, byte_5EC4CC) )
    {
      v42 = 0;
      do
      {
        v43 = *((_BYTE *)&off_5C3700 + v42);
        byte_5EC4CC[v42++] = v43;
      }
      while ( v43 );
    }
    v44 = 0;
    do
    {
      v45 = byte_5EC4CC[v44];
      v47[v44++] = v45;
    }
    while ( v45 );
    strcpy(v46, (const char *)StringCopyWithReturn(byte_5C3740));
    StringFormatWithBufferOverflowCheck(this + 56, "%s/%s", v47, v46);
    strcpy(v48, (const char *)StringCopyWithReturn(aS_2));
    StringFormatWithBufferOverflowCheck(this + 72, "%s/%s/%s", v47, v46, v48);
    strcpy((char *)(this + 88), (const char *)StringCopyWithReturn(&off_5C373C));
  }
  else
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3770, byte_5EC4CC) )
    {
      v6 = 0;
      do
      {
        v7 = *((_BYTE *)&off_5C3770 + v6);
        byte_5EC4CC[v6++] = v7;
      }
      while ( v7 );
    }
    v8 = byte_5EC4CC;
    do
    {
      v9 = *v8;
      v8[this - (_DWORD)byte_5EC4CC + 8] = *v8;
      ++v8;
    }
    while ( v9 );
    if ( BinarySearchInStringTable(byte_5EC4C0, byte_5C376C, byte_5EC4CC) )
    {
      v10 = 0;
      do
      {
        v11 = byte_5C376C[v10];
        byte_5EC4CC[v10++] = v11;
      }
      while ( v11 );
    }
    v12 = byte_5EC4CC;
    do
    {
      v13 = *v12;
      v12[this - (_DWORD)byte_5EC4CC + 24] = *v12;
      ++v12;
    }
    while ( v13 );
    if ( BinarySearchInStringTable(byte_5EC4C0, aN, byte_5EC4CC) )
    {
      v14 = 0;
      do
      {
        v15 = aN[v14];
        byte_5EC4CC[v14++] = v15;
      }
      while ( v15 );
    }
    v16 = 0;
    do
    {
      v17 = byte_5EC4CC[v16];
      v47[v16++] = v17;
    }
    while ( v17 );
    if ( BinarySearchInStringTable(byte_5EC4C0, aMm, byte_5EC4CC) )
    {
      v18 = 0;
      do
      {
        v19 = aMm[v18];
        byte_5EC4CC[v18++] = v19;
      }
      while ( v19 );
    }
    v20 = 0;
    do
    {
      v21 = byte_5EC4CC[v20];
      v46[v20++] = v21;
    }
    while ( v21 );
    StringFormatWithBufferOverflowCheck(this + 56, "%s/%s", v47, v46);
    if ( BinarySearchInStringTable(byte_5EC4C0, aM, byte_5EC4CC) )
    {
      v22 = 0;
      do
      {
        v23 = aM[v22];
        byte_5EC4CC[v22++] = v23;
      }
      while ( v23 );
    }
    v24 = 0;
    do
    {
      v25 = byte_5EC4CC[v24];
      v46[v24++] = v25;
    }
    while ( v25 );
    if ( BinarySearchInStringTable(byte_5EC4C0, aS_2, byte_5EC4CC) )
    {
      v26 = 0;
      do
      {
        v27 = aS_2[v26];
        byte_5EC4CC[v26++] = v27;
      }
      while ( v27 );
    }
    v28 = 0;
    do
    {
      v29 = byte_5EC4CC[v28];
      v48[v28++] = v29;
    }
    while ( v29 );
    StringFormatWithBufferOverflowCheck(this + 72, "%s/%s/%s", v47, v46, v48);
    if ( BinarySearchInStringTable(byte_5EC4C0, byte_5C3748, byte_5EC4CC) )
    {
      v30 = 0;
      do
      {
        v31 = byte_5C3748[v30];
        byte_5EC4CC[v30++] = v31;
      }
      while ( v31 );
    }
    result = byte_5EC4CC;
    do
    {
      v33 = *result;
      result[this - (_DWORD)byte_5EC4CC + 88] = *result;
      ++result;
    }
    while ( v33 );
  }
  return result;
}
