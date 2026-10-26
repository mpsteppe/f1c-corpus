int __thiscall sub_48AB00(_DWORD *this)
{
  int v2; // eax
  char *v3; // edx
  char v4; // cl
  int v5; // edi
  int v6; // esi
  unsigned int v7; // edx
  int v8; // eax
  CHAR *v9; // eax
  char v11; // [esp+21h] [ebp-1E9h] BYREF
  int v12; // [esp+22h] [ebp-1E8h]
  int v13; // [esp+26h] [ebp-1E4h]
  int v14; // [esp+2Ah] [ebp-1E0h]
  char v15[16]; // [esp+2Eh] [ebp-1DCh] BYREF
  char v16[16]; // [esp+3Eh] [ebp-1CCh] BYREF
  char v17[80]; // [esp+4Eh] [ebp-1BCh] BYREF
  __int16 v18; // [esp+9Eh] [ebp-16Ch]
  char Buffer[32]; // [esp+AAh] [ebp-160h] BYREF
  char v20[64]; // [esp+CAh] [ebp-140h] BYREF
  char v21[128]; // [esp+10Ah] [ebp-100h] BYREF
  char String2[128]; // [esp+18Ah] [ebp-80h] BYREF

  String2[0] = 0;
  v2 = sub_49FB30(this);
  if ( v2 )
  {
    v3 = &String2[-v2];
    do
    {
      v4 = *(_BYTE *)v2;
      v3[v2] = *(_BYTE *)v2;
      ++v2;
    }
    while ( v4 );
  }
  sub_49FEC0(this);
  v5 = sub_4637F0(dword_764D70);
  v14 = v5;
  v12 = 0;
  if ( v5 > 0 && !sub_4637C0(dword_764D70) )
  {
    ((void (__thiscall *)(_DWORD *, int, _DWORD, _DWORD))dword_463960[0])(dword_764D70, dword_7699F4, 0, 0);
    v6 = 0;
    v13 = 0;
    do
    {
      sub_462C80(v17);
      v20[0] = 0;
      if ( (unsigned __int8)((int (__thiscall *)(_DWORD *, int, char *, char *, int, char *))loc_463800)(
                              dword_764D70,
                              v6,
                              v17,
                              v20,
                              64,
                              &v11)
        && v18 < 9999
        && strlen(v17) )
      {
        v21[0] = 0;
        strcat(v21, v17);
        sub_49F640(v21);
        if ( !strlen(v20) )
          strcpy(v20, word_5FBEB8);
        strcat(v21, v20);
        sub_49F640(v21);
        Buffer[0] = 0;
        sprintf(Buffer, "%d/%d", v17[69], v17[70]);
        strcat(v21, Buffer);
        sub_49F640(v21);
        v15[0] = 0;
        sprintf(v15, "%d", v18);
        v7 = strlen(v15) + 1;
        v8 = v13;
        qmemcpy(&v21[strlen(v21)], v15, v7);
        sprintf(v16, "%d", v8);
        v9 = (CHAR *)this[42];
        if ( !v9 )
          v9 = &byte_629120;
        sub_49F730(v21, v9, &byte_629120, v16, 0);
        if ( v11 )
        {
          sub_49FE20(this[37] - 1, aFtch14gryBmp);
        }
        else if ( sub_462D10(v17, 2) )
        {
          sub_49FE20(this[37] - 1, aFtch14redBmp);
        }
        else
        {
          sub_49FE20(this[37] - 1, aFtch14blkBmp);
        }
        v6 = v13;
        ++v12;
      }
      nullsub_6(v17);
      v13 = ++v6;
    }
    while ( v6 < v14 );
    if ( strlen(String2) )
      sub_49FDB0(String2, 0);
    if ( v12 )
      return sub_4A0640(1);
  }
  sub_4A0640(0);
  if ( sub_4637C0(dword_764D70) )
  {
    if ( sub_41F230(dword_62A170, aSearching, Destination) )
    {
      strncpy(Destination, aSearching, 0x1FFu);
      byte_62A37B = 0;
    }
  }
  else if ( sub_41F230(dword_62A170, aNoRacesAvailab, Destination) )
  {
    strncpy(Destination, aNoRacesAvailab, 0x1FFu);
    byte_62A37B = 0;
  }
  return sub_49F730(Destination, 0, 0, 0, 0);
}
