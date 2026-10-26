int __fastcall sub_42D810(int a1, int *a2, int a3, char *Source)
{
  int v6; // eax
  char v7; // cl
  int v9; // eax
  int v10; // esi
  int v11; // esi
  const char *v12; // esi
  int v13; // esi
  int v14; // eax
  char v15; // cl
  char v16[128]; // [esp+10h] [ebp-80h] BYREF

  if ( !(unsigned __int8)sub_4CE6E0(a1) )
  {
    if ( sub_41F230(dword_62A170, Source, Destination) )
    {
      if ( Source )
      {
        strncpy(Destination, Source, 0x1FFu);
        byte_62A37B = 0;
      }
      else
      {
        Destination[0] = 0;
      }
    }
    v6 = 0;
    do
    {
      v7 = Destination[v6];
      v16[v6++] = v7;
    }
    while ( v7 );
    *(_WORD *)&v16[strlen(v16)] = *(_WORD *)word_5FBEBC;
    if ( sub_41F230(dword_62A170, aDisallowed, Destination) )
    {
      strncpy(Destination, aDisallowed, 0x1FFu);
      byte_62A37B = 0;
    }
    strcat(v16, Destination);
    return sub_45D100(v16, 3, 16909060, 0);
  }
  v9 = *a2 + 1;
  *a2 = v9;
  if ( v9 > a3 )
    *a2 = 0;
  if ( a1 == 3 )
  {
    if ( *a2 != 3 && *a2 != 0 )
      *a2 = 3;
    v10 = *a2;
    if ( v10 )
    {
      v11 = v10 - 1;
      if ( v11 )
      {
        if ( v11 == 1 )
          v12 = aDownshifts;
        else
          v12 = aOn;
      }
      else
      {
        v12 = aUpshifts;
      }
      goto LABEL_29;
    }
  }
  else
  {
    v13 = *a2;
    if ( v13 )
    {
      if ( v13 == 1 )
      {
        if ( a3 == 1 )
          v12 = aOn;
        else
          v12 = (const char *)&off_5FD350;
      }
      else
      {
        v12 = aHigh;
      }
      goto LABEL_29;
    }
  }
  v12 = (const char *)&off_5FB7E4;
LABEL_29:
  if ( sub_41F230(dword_62A170, Source, Destination) )
  {
    if ( Source )
    {
      strncpy(Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  v14 = 0;
  do
  {
    v15 = Destination[v14];
    v16[v14++] = v15;
  }
  while ( v15 );
  *(_WORD *)&v16[strlen(v16)] = *(_WORD *)word_5FBEBC;
  sub_45D270(v16, 1);
  if ( sub_41F230(dword_62A170, v12, Destination) )
  {
    if ( v12 )
    {
      strncpy(Destination, v12, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  strcat(v16, Destination);
  sub_45D100(v16, 3, 16909060, 0);
  return sub_43B590(&dbl_75E930);
}
