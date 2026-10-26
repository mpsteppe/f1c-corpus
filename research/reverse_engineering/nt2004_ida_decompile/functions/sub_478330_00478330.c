char __thiscall sub_478330(_DWORD *this, int a2, char *a3, char *a4)
{
  int v5; // esi
  int v6; // eax
  int v7; // eax
  char v8; // cl
  int v9; // eax
  double v10; // st7
  __int64 v11; // rax
  char *v12; // eax
  double v13; // st7
  double v14; // st7
  __int64 v15; // rax
  double v16; // st7
  int v17; // eax
  char *v18; // ebx
  int v19; // ebp
  char *v20; // edx
  char *v21; // edi
  void *v22; // eax
  float v24; // [esp+18h] [ebp-294h]
  unsigned int v25; // [esp+18h] [ebp-294h]
  float v26; // [esp+1Ch] [ebp-290h]
  float v27; // [esp+1Ch] [ebp-290h]
  int v28; // [esp+20h] [ebp-28Ch]
  int v29; // [esp+24h] [ebp-288h]
  char v31[45]; // [esp+2Ch] [ebp-280h] BYREF
  __int16 v32; // [esp+59h] [ebp-253h]
  char v33; // [esp+5Bh] [ebp-251h]
  char v34[32]; // [esp+5Ch] [ebp-250h] BYREF
  char Buffer[432]; // [esp+7Ch] [ebp-230h] BYREF
  char String[128]; // [esp+22Ch] [ebp-80h] BYREF

  if ( a4 )
    *a4 = 0;
  v5 = dword_75AAD0[a2];
  memset(Buffer, 0, sizeof(Buffer));
  v6 = *(_DWORD *)(v5 + 20884);
  v29 = v5;
  if ( v6 >= 1 )
  {
    sprintf(Buffer, "%d", v6);
  }
  else
  {
    v7 = 0;
    do
    {
      v8 = word_5FBEB8[v7];
      Buffer[v7++] = v8;
    }
    while ( v8 );
  }
  v31[0] = byte_629120;
  memset(&v31[1], 0, 0x2Cu);
  v32 = 0;
  v33 = 0;
  sub_4EDE00(v31, 48);
  sprintf(&Buffer[48], off_601510, v31);
  strncpy(&Buffer[96], (const char *)(v5 + 24772), 0x2Fu);
  Buffer[143] = 0;
  v9 = sub_42DD90(a2, &Buffer[144]);
  v26 = *(float *)(v5 + 20960) * 0.0002777777777777778;
  v28 = v9;
  v10 = *(float *)(v5 + 20960);
  if ( v10 <= 0.0 )
  {
    sprintf(&Buffer[144], asc_601504);
  }
  else
  {
    v11 = (__int64)(0.01666666666666667 * v10);
    if ( (int)v11 > 0 )
      v10 = v10 - (double)(int)v11 * 60.0;
    sprintf(&Buffer[144], "%i:%06.3f", (_DWORD)v11, v10);
  }
  if ( this[157] == 1 )
  {
    sub_4E8E50(String, 127, aLength, 0);
    v12 = strtok(String, word_5FBEBC);
    v13 = atof(v12);
    if ( v26 <= 0.0 )
      sprintf(&Buffer[192], asc_6014F4);
    else
      sprintf(&Buffer[192], "%03.3f", v13 / v26);
    v14 = *(float *)(v5 + 20960);
    if ( v14 <= 0.0 )
    {
      sprintf(&Buffer[144], asc_601504);
    }
    else
    {
      v15 = (__int64)(0.01666666666666667 * v14);
      if ( (int)v15 > 0 )
        v14 = v14 - (double)(int)v15 * 60.0;
      sprintf(&Buffer[144], "%i:%06.3f", (_DWORD)v15, v14);
    }
    v27 = flt_6290D0 * 0.0006213712;
    if ( !sub_4E8E50(v34, 32, aLength, 0) )
      v27 = atof(v34);
    v16 = *(float *)(v5 + 20988) * 0.0002777777777777778;
    if ( v16 > 0.0 && dword_75CBB0 == 7 )
    {
      v24 = v16;
      sprintf(&Buffer[240], "%03.3f", (double)*(int *)(v5 + 20848) * v27 / v24);
    }
    else
    {
      sprintf(&Buffer[240], asc_6014F4);
    }
    if ( this[157] == 1 )
    {
      v17 = sub_4DEBD0(v5 + 20836);
      sprintf(&Buffer[288], "%d", v17);
      sprintf(&Buffer[336], "%d", *(_DWORD *)(v5 + 20848));
      sprintf(&Buffer[384], "%d", *(_DWORD *)dword_768B70);
    }
    else
    {
      sprintf(&Buffer[288], &byte_629120);
      sprintf(&Buffer[336], &byte_629120);
      sprintf(&Buffer[384], &byte_629120);
    }
  }
  v18 = a3;
  *a3 = 0;
  v19 = 0;
  v20 = Buffer;
  do
  {
    if ( strlen(v20) )
    {
      if ( v19 )
        *(_WORD *)&v18[strlen(v18)] = *(_WORD *)word_6014F0;
      v25 = strlen(v20) + 1;
      v21 = &v18[strlen(v18) + 1];
      v18 = a3;
      qmemcpy(v21 - 1, v20, v25);
      v5 = v29;
    }
    ++v19;
    v20 += 48;
  }
  while ( v19 < 9 );
  if ( sub_463490(dword_764D70) && this[157] != 1 )
  {
    *(_WORD *)&v18[strlen(v18)] = *(_WORD *)word_6014F0;
    if ( a2 == dword_75AAC8 )
    {
      *(_WORD *)&v18[strlen(v18)] = *(_WORD *)word_5FBEB8;
    }
    else
    {
      v22 = (void *)sub_4EED90(v5);
      strcat(v18, sub_42F640(v22));
    }
  }
  switch ( v28 )
  {
    case 1:
      strcpy(a4, aFtch14redBmp);
      break;
    case 2:
      strcpy(a4, aFtch14grnBmp);
      return 1;
    case 3:
      strcpy(a4, aFtch14gryBmp);
      return 1;
  }
  return 1;
}
