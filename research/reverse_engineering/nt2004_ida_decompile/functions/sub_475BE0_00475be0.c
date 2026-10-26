int __thiscall sub_475BE0(void *this)
{
  int v1; // edi
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi
  CHAR v7; // [esp+14h] [ebp-18Ch] BYREF
  int v8; // [esp+15h] [ebp-18Bh]
  __int16 v9; // [esp+19h] [ebp-187h]
  char v10; // [esp+1Bh] [ebp-185h]
  int v11; // [esp+1Ch] [ebp-184h]
  char Buffer[256]; // [esp+20h] [ebp-180h] BYREF
  char Destination[125]; // [esp+120h] [ebp-80h] BYREF
  __int16 v14; // [esp+19Dh] [ebp-3h]
  char v15; // [esp+19Fh] [ebp-1h]

  v8 = 0;
  v9 = 0;
  v10 = 0;
  v7 = byte_629120;
  sub_49FEC0(this);
  sub_49F640(&v7);
  *(_WORD *)(&v7 + strlen(&v7)) = *(_WORD *)word_5FBEBC;
  sub_49F640(&v7);
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x7Cu);
  v14 = 0;
  v15 = 0;
  sub_4CE010(Destination, 127);
  if ( sub_41F230(dword_62A170, aName_3, ::Destination) )
  {
    strncpy(::Destination, aName_3, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%s", ::Destination, &v7, Destination);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v1 = dword_76BB4C;
  if ( sub_41F230(dword_62A170, aExperienceLaps, ::Destination) )
  {
    strncpy(::Destination, aExperienceLaps, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%i", ::Destination, &v7, v1);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v11 = dword_76BB74;
  if ( sub_41F230(dword_62A170, aAverageRaceLen, ::Destination) )
  {
    strncpy(::Destination, aAverageRaceLen, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%.1f", ::Destination, &v7, *(float *)&v11);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v2 = dword_76BB50;
  if ( sub_41F230(dword_62A170, aStarts, ::Destination) )
  {
    strncpy(::Destination, aStarts, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%i", ::Destination, &v7, v2);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v11 = dword_76BB6C;
  if ( sub_41F230(dword_62A170, aAverageStart, ::Destination) )
  {
    strncpy(::Destination, aAverageStart, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%.1f", ::Destination, &v7, *(float *)&v11);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v11 = dword_76BB70;
  if ( sub_41F230(dword_62A170, aAverageFinish, ::Destination) )
  {
    strncpy(::Destination, aAverageFinish, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%.1f", ::Destination, &v7, *(float *)&v11);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v3 = dword_76BB64;
  if ( sub_41F230(dword_62A170, aPoles, ::Destination) )
  {
    strncpy(::Destination, aPoles, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%i", ::Destination, &v7, v3);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v4 = dword_76BB60;
  if ( sub_41F230(dword_62A170, aWins, ::Destination) )
  {
    strncpy(::Destination, aWins, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%i", ::Destination, &v7, v4);
  sub_49F730(Buffer, 0, 0, 0, 0);
  v5 = dword_76BB58;
  if ( sub_41F230(dword_62A170, aPoints_0, ::Destination) )
  {
    strncpy(::Destination, aPoints_0, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s%s%i", ::Destination, &v7, v5);
  return sub_49F730(Buffer, 0, 0, 0, 0);
}
