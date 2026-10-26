char __fastcall sub_568910(const char *a1, char *a2, signed int a3)
{
  const char *v3; // ebp
  char v5; // al
  char v6; // al
  char v7; // cl
  char v8; // dl
  char v9; // dl
  char v11; // [esp+Bh] [ebp-15h]
  int v12; // [esp+Ch] [ebp-14h] BYREF
  char v13; // [esp+10h] [ebp-10h]
  char v14; // [esp+11h] [ebp-Fh]
  char v15; // [esp+12h] [ebp-Eh] BYREF
  char v16; // [esp+13h] [ebp-Dh]
  char v17; // [esp+14h] [ebp-Ch]
  char v18[8]; // [esp+18h] [ebp-8h] BYREF

  v3 = a1;
  if ( !a1 || !a2 )
    return 0;
  *a2 = 0;
  v5 = *a1;
  v11 = 1;
  if ( *a1 )
  {
    while ( 1 )
    {
      if ( v5 != 43 )
        goto LABEL_10;
      if ( strlen(v3) < 4 )
        goto LABEL_10;
      v6 = v3[1];
      v7 = v3[2];
      v8 = v3[3];
      v13 = 43;
      v14 = v6;
      v15 = v7;
      v16 = v8;
      v17 = 0;
      if ( v6 != 126 )
        goto LABEL_10;
      if ( sub_589BC6(v7) && sub_589BC6(v16) )
      {
        v12 = 0;
        sub_5887ED(&v15, "%x", &v12);
        v18[0] = v12;
        v3 += 4;
      }
      else
      {
LABEL_10:
        v9 = *v3++;
        v18[0] = v9;
      }
      v18[1] = 0;
      if ( (int)(strlen(v18) + strlen(a2)) >= a3 )
        return 0;
      strcat(a2, v18);
      v5 = *v3;
      if ( !*v3 )
        return 1;
    }
  }
  return v11;
}
