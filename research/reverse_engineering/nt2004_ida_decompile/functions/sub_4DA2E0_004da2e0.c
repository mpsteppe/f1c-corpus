void __thiscall sub_4DA2E0(_BYTE *this)
{
  int v2; // eax
  char v3; // cl
  char *v4; // eax
  const char *v5; // esi
  char v6[77]; // [esp+8h] [ebp-50h] BYREF
  __int16 v7; // [esp+55h] [ebp-3h]
  char v8; // [esp+57h] [ebp-1h]

  if ( !this[4] && *(_DWORD *)this == 1 )
  {
    if ( sub_41F230(dword_62A170, aRecordingOn, Destination) )
    {
      strncpy(Destination, aRecordingOn, 0x1FFu);
      byte_62A37B = 0;
    }
    sub_45D100(&byte_764D68, (int)Destination, 2, 16909060, 0);
    if ( !sub_463490(dword_764D70) )
    {
      v6[0] = byte_629120;
      memset(&v6[1], 0, 0x4Cu);
      v7 = 0;
      v8 = 0;
      if ( sub_41F230(dword_62A170, aReplayActivati, Destination) )
      {
        strncpy(Destination, aReplayActivati, 0x1FFu);
        byte_62A37B = 0;
      }
      v2 = 0;
      do
      {
        v3 = Destination[v2];
        v6[v2++] = v3;
      }
      while ( v3 );
      *(_WORD *)&v6[strlen(v6)] = *(_WORD *)word_5FBEBC;
      v4 = sub_457840(dword_76A820);
      v5 = v4;
      if ( v4 )
      {
        if ( sub_41F230(dword_62A170, v4, Destination) )
        {
          strncpy(Destination, v5, 0x1FFu);
          byte_62A37B = 0;
        }
        strcat(v6, Destination);
      }
      sub_45D100(&byte_764D68, (int)v6, 3, 16909060, 0);
    }
    this[4] = 1;
  }
}
