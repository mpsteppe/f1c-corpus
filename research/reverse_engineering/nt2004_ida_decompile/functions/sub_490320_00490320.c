int __thiscall sub_490320(_DWORD *this)
{
  const char *v2; // eax
  char *v3; // edi
  const char *v4; // edx
  CHAR *v5; // eax
  const char *v6; // eax
  int v7; // esi
  const char *v8; // eax
  int v9; // edi
  LPVOID **v10; // esi
  char v11; // al
  LPVOID *v12; // ebx
  int v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  char *v21; // eax
  int result; // eax
  const char *v23; // eax
  int v24; // eax
  const char *v25; // eax
  int v26; // eax
  const char *v27; // eax
  int v28; // eax
  const char *v29; // eax
  int v30; // eax
  const char *v31; // eax
  int v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35[7]; // [esp-1Ch] [ebp-134h] BYREF
  CHAR v36; // [esp+10h] [ebp-108h] BYREF
  __int16 v37; // [esp+11h] [ebp-107h]
  char v38; // [esp+13h] [ebp-105h]
  int v39; // [esp+14h] [ebp-104h]
  char Buffer[256]; // [esp+18h] [ebp-100h] BYREF

  v37 = 0;
  v38 = 0;
  v36 = byte_629120;
  sub_49FEC0(this);
  v2 = (const char *)this[105];
  v3 = dword_76662C;
  if ( !v2 )
    v2 = &byte_629120;
  v4 = dword_76662C;
  if ( !dword_76662C )
    v4 = &byte_629120;
  if ( strcmp(v4, v2) )
  {
    v5 = dword_76662C;
    if ( !dword_76662C )
      v5 = &byte_629120;
    sub_578600(v5);
    v3 = dword_76662C;
  }
  v6 = v3;
  if ( !v3 )
    v6 = &byte_629120;
  if ( _strcmpi(aBrad, v6) )
  {
    v39 = 0;
    if ( dword_7D6A58 > 0 )
    {
      v7 = 0;
      do
      {
        v8 = dword_76662C;
        if ( !dword_76662C )
          v8 = &byte_629120;
        if ( !_strcmpi(v8, (const char *)(v7 + dword_7D6A5C + 246)) )
          break;
        v7 += 1232;
        ++v39;
      }
      while ( v39 < dword_7D6A58 );
    }
  }
  else
  {
    v39 = dword_7D6A54;
  }
  v9 = this[13];
  while ( v9 )
  {
    v10 = (LPVOID **)v9;
    v11 = *(_BYTE *)(v9 + 8);
    v9 = *(_DWORD *)(v9 + 4);
    if ( v11 )
    {
      v12 = *v10;
      if ( *v10 )
      {
        sub_40D5B0(*v10);
        sub_5BE8AE(v12);
      }
    }
    sub_5BE8AE(v10);
  }
  v35[6] = (const char *)-1;
  v35[5] = aTeam_1;
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  sub_49D5B0(v35[5], v35[6]);
  sub_49D5B0(aFounded, -1);
  sub_49D5B0(aHeadquarters, -1);
  sub_49D5B0(aStarts, -1);
  sub_49D5B0(aPolePositions, -1);
  sub_49D5B0(aWins, -1);
  sub_49D5B0(aConstructorCha, -1);
  sub_49D5B0(aDriver_2, -1);
  sub_49D5B0(aNationality, -1);
  sub_49D5B0(aDateOfBirth, -1);
  sub_49D5B0(aStarts, -1);
  sub_49D5B0(aPolePositions, -1);
  sub_49D5B0(aWins, -1);
  sub_49D5B0(aDriversChampio, -1);
  sub_49F640(&v36);
  v13 = 1232 * v39;
  v35[6] = (const char *)(1232 * v39 + dword_7D6A5C + 886);
  v14 = (const char *)sub_49D690(0);
  sprintf(Buffer, "%s%s%s", v14, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v35[6] = (const char *)(v13 + dword_7D6A5C + 1014);
  v15 = (const char *)sub_49D690(1);
  sprintf(Buffer, "%s%s%s", v15, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v35[6] = (const char *)(v13 + dword_7D6A5C + 1030);
  v16 = (const char *)sub_49D690(2);
  sprintf(Buffer, "%s%s%s", v16, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v35[6] = (const char *)(v13 + dword_7D6A5C + 1094);
  v17 = (const char *)sub_49D690(3);
  sprintf(Buffer, "%s%s%s", v17, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v35[6] = (const char *)(v13 + dword_7D6A5C + 1110);
  v18 = (const char *)sub_49D690(4);
  sprintf(Buffer, "%s%s%s", v18, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v35[6] = (const char *)(v13 + dword_7D6A5C + 1126);
  v19 = (const char *)sub_49D690(5);
  sprintf(Buffer, "%s%s%s", v19, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v35[6] = (const char *)(v13 + dword_7D6A5C + 1142);
  v20 = (const char *)sub_49D690(6);
  sprintf(Buffer, "%s%s%s", v20, &v36, v35[6]);
  sub_49F730(Buffer, 0, 0, 0, 0);
  sprintf(Buffer, "%s", &v36);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v21 = dword_76662C;
  if ( !dword_76662C )
    v21 = &byte_629120;
  result = sub_57AE50(v21);
  if ( result )
  {
    qmemcpy(v35, &unk_766618, sizeof(v35));
    v23 = (const char *)sub_49D690(7);
    sprintf(Buffer, "%s%s%s", v23, &v36, v35[0]);
    sub_49F730(Buffer, 0, 0, 0, 0);
    if ( sub_41F230(dword_62A170, aNationality_0, Destination) )
    {
      strncpy(Destination, aNationality_0, 0x1FFu);
      byte_62A37B = 0;
    }
    v24 = sub_57A720(Destination);
    if ( v24 )
    {
      v35[6] = (const char *)sub_57A6D0(v24);
      v35[5] = &v36;
      v25 = (const char *)sub_49D690(8);
      sprintf(Buffer, "%s%s%s", v25, v35[5], v35[6]);
      sub_49F730(Buffer, 0, 0, 0, 0);
    }
    v26 = sub_57A720(aDateofbirth);
    if ( v26 )
    {
      v35[6] = (const char *)sub_57A6D0(v26);
      v35[5] = &v36;
      v27 = (const char *)sub_49D690(9);
      sprintf(Buffer, "%s%s%s", v27, v35[5], v35[6]);
      sub_49F730(Buffer, 0, 0, 0, 0);
    }
    v28 = sub_57A720(aStarts_0);
    if ( v28 )
    {
      v35[6] = (const char *)sub_57A6D0(v28);
      v35[5] = &v36;
      v29 = (const char *)sub_49D690(10);
      sprintf(Buffer, "%s%s%s", v29, v35[5], v35[6]);
      sub_49F730(Buffer, 0, 0, 0, 0);
    }
    v30 = sub_57A720(aPoles_0);
    if ( v30 )
    {
      v35[6] = (const char *)sub_57A6D0(v30);
      v35[5] = &v36;
      v31 = (const char *)sub_49D690(11);
      sprintf(Buffer, "%s%s%s", v31, v35[5], v35[6]);
      sub_49F730(Buffer, 0, 0, 0, 0);
    }
    v32 = sub_57A720(aWins_0);
    if ( v32 )
    {
      v35[6] = (const char *)sub_57A6D0(v32);
      v35[5] = &v36;
      v33 = (const char *)sub_49D690(12);
      sprintf(Buffer, "%s%s%s", v33, v35[5], v35[6]);
      sub_49F730(Buffer, 0, 0, 0, 0);
    }
    result = sub_57A720(aDriverschampio);
    if ( result )
    {
      v35[6] = (const char *)sub_57A6D0(result);
      v35[5] = &v36;
      v34 = (const char *)sub_49D690(13);
      sprintf(Buffer, "%s%s%s", v34, v35[5], v35[6]);
      return sub_49F730(Buffer, 0, 0, 0, 0);
    }
  }
  return result;
}
