int __thiscall sub_48E120(_DWORD *this, int a2)
{
  int v3; // esi
  LPVOID **v4; // edi
  char v5; // al
  int result; // eax
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  const char **v11; // esi
  int v12; // eax
  const char *v13; // eax
  char *p_Buffer; // esi
  unsigned int v15; // edx
  int v16; // eax
  char v17; // cl
  int v18; // eax
  char v19; // cl
  int v20; // eax
  char v21; // cl
  int v22; // [esp+14h] [ebp-218h]
  char Buffer; // [esp+18h] [ebp-214h] BYREF
  int v24; // [esp+19h] [ebp-213h]
  __int16 v25; // [esp+1Dh] [ebp-20Fh]
  char v26; // [esp+1Fh] [ebp-20Dh]
  char v27; // [esp+20h] [ebp-20Ch] BYREF
  int v28; // [esp+21h] [ebp-20Bh]
  __int16 v29; // [esp+25h] [ebp-207h]
  char v30; // [esp+27h] [ebp-205h]
  int v31; // [esp+28h] [ebp-204h]
  char String2[253]; // [esp+2Ch] [ebp-200h] BYREF
  __int16 v33; // [esp+129h] [ebp-103h]
  char v34; // [esp+12Bh] [ebp-101h]
  char v35[125]; // [esp+12Ch] [ebp-100h] BYREF
  __int16 v36; // [esp+1A9h] [ebp-83h]
  char v37; // [esp+1ABh] [ebp-81h]
  _BYTE v38[125]; // [esp+1ACh] [ebp-80h] BYREF
  __int16 v39; // [esp+229h] [ebp-3h]
  char v40; // [esp+22Bh] [ebp-1h]

  v3 = this[13];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    if ( v5 && *v4 )
      sub_4115A0(*v4, 1);
    sub_5BE8AE(v4);
  }
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  sub_49D5B0(aTeam_0, -1);
  sub_49D5B0(aDriver_1, -1);
  sub_49D5B0(aPoints_1, -1);
  String2[0] = byte_629120;
  memset(&String2[1], 0, 0xFCu);
  v33 = 0;
  v34 = 0;
  sub_49FEC0(this);
  this[104] = a2;
  result = sub_4E5DA0(&unk_76BB28);
  v7 = result;
  if ( result )
  {
    v8 = sub_4E4C30(result);
    v38[0] = byte_629120;
    memset(&v38[1], 0, 0x7Cu);
    v39 = 0;
    v40 = 0;
    v31 = v8 + 1;
    sub_4E4C50(v7);
    sub_4E3D70(v38);
    v9 = 0;
    v22 = 0;
    if ( v8 + 1 > 0 )
    {
      while ( 1 )
      {
        if ( v9 )
          v10 = sub_4E4C60(v9 - 1);
        else
          v10 = sub_4E4C50(v7);
        v35[0] = byte_629120;
        v11 = (const char **)v10;
        memset(&v35[1], 0, 0x7Cu);
        Buffer = byte_629120;
        v27 = byte_629120;
        v24 = 0;
        v36 = 0;
        v28 = 0;
        v25 = 0;
        v29 = 0;
        v26 = 0;
        v37 = 0;
        v30 = 0;
        String2[0] = 0;
        sprintf(&Buffer, "%d", *(_DWORD *)(v10 + 608));
        sub_4E3D70(v35);
        v12 = sub_4E4CD0(v35);
        sprintf(&v27, "%d", v12);
        if ( a2 )
        {
          if ( a2 != 1 )
            goto LABEL_22;
          v13 = *v11;
          if ( !*v11 )
            v13 = &byte_629120;
          sprintf(String2, "%s", v13);
          sub_49F640(String2);
          strcat(String2, v35);
          sub_49F640(String2);
          p_Buffer = &Buffer;
          v15 = strlen(&Buffer) + 1;
        }
        else
        {
          v16 = 0;
          do
          {
            v17 = v35[v16];
            String2[v16++] = v17;
          }
          while ( v17 );
          sub_49F640(String2);
          p_Buffer = &v27;
          v15 = strlen(&v27) + 1;
        }
        qmemcpy(&String2[strlen(String2)], p_Buffer, v15);
LABEL_22:
        if ( !(unsigned __int8)sub_49FC60(String2, 0) )
          sub_49F730(String2, 0, 0, 0, 0);
        if ( ++v22 >= v31 )
          break;
        v9 = v22;
      }
    }
    sub_49FE20(0, aFtch14redBmp);
    if ( a2 )
    {
      if ( a2 == 1 )
        sub_4A0650(1, 2);
    }
    else
    {
      sub_4A0650(1, 1);
    }
    String2[0] = 0;
    if ( a2 )
    {
      if ( a2 != 1 )
      {
LABEL_45:
        sub_49F730(String2, 0, 0, 0, 1);
        return sub_49FE20(0, aFtch14blkBmp);
      }
      if ( sub_41F230(dword_62A170, aDriver_1, Destination) )
      {
        strncpy(Destination, aDriver_1, 0x1FFu);
        byte_62A37B = 0;
      }
      v18 = 0;
      do
      {
        v19 = Destination[v18];
        String2[v18++] = v19;
      }
      while ( v19 );
      sub_49F640(String2);
      if ( sub_41F230(dword_62A170, aTeam_0, Destination) )
      {
        strncpy(Destination, aTeam_0, 0x1FFu);
        byte_62A37B = 0;
      }
      strcat(String2, Destination);
    }
    else
    {
      if ( sub_41F230(dword_62A170, aTeam_0, Destination) )
      {
        strncpy(Destination, aTeam_0, 0x1FFu);
        byte_62A37B = 0;
      }
      v20 = 0;
      do
      {
        v21 = Destination[v20];
        String2[v20++] = v21;
      }
      while ( v21 );
    }
    sub_49F640(String2);
    if ( sub_41F230(dword_62A170, aPoints_1, Destination) )
    {
      strncpy(Destination, aPoints_1, 0x1FFu);
      byte_62A37B = 0;
    }
    strcat(String2, Destination);
    goto LABEL_45;
  }
  return result;
}
