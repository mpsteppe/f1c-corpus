char __userpurge sub_4E4100@<al>(int *a1@<ecx>, char a2@<sil>, _DWORD *ArgList, char *a4)
{
  int v5; // eax
  int i; // esi
  int v7; // ecx
  int v8; // eax
  CHAR **v9; // eax
  CHAR *v10; // eax
  int v11; // esi
  char *v12; // edi
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  if ( *ArgList )
  {
    if ( a4 )
    {
      sub_57A4C0(a4);
      sub_57A4C0(asc_5FB9D8);
    }
    sub_57A400((int)ArgList, aSeasonstatusD, a1[7741]);
    sub_57A400((int)ArgList, aRacesessionD, a1[7743]);
    sub_57A400((int)ArgList, aRaceoverD, *((_BYTE *)a1 + 30976) != 0);
    sub_57A400((int)ArgList, aCurrentraceD, a1[7742]);
    v5 = a1[3];
    for ( i = 0; i < v5; ++i )
    {
      v7 = i;
      if ( i >= 0 && i < v5 )
      {
        v8 = *a1;
        if ( i <= 0 )
        {
LABEL_10:
          if ( v8 )
          {
            v9 = *(CHAR ***)v8;
            if ( v9 )
            {
              v10 = *v9;
              if ( !v10 )
                v10 = &byte_629120;
              sub_57A400((int)ArgList, aEventS, (char)v10);
            }
          }
        }
        else
        {
          while ( v8 )
          {
            v8 = *(_DWORD *)(v8 + 4);
            if ( --v7 <= 0 )
              goto LABEL_10;
          }
        }
      }
      v5 = a1[3];
    }
    sub_4E38E0((char *)a1 + 30284, ArgList, aPlayer_0);
    v11 = 0;
    v12 = (char *)(a1 + 4);
    do
    {
      if ( v12[640] )
      {
        sprintf(Buffer, "%s%2.2d]", aOpponent, v11);
        sub_4E38E0(v12, ArgList, Buffer);
      }
      ++v11;
      v12 += 644;
    }
    while ( v11 < 47 );
    sub_57A400((int)ArgList, asc_5FB9D8, a2);
  }
  return 0;
}
