char __fastcall sub_617A70(char *a1, char *a2, signed int a3)
{
  char *v3; // ebp
  char v4; // al
  char v5; // al
  char v6; // cl
  char v7; // dl
  char v9; // [esp+Bh] [ebp-19h]
  int v10; // [esp+Ch] [ebp-18h] BYREF
  char *v11; // [esp+10h] [ebp-14h]
  char v12; // [esp+14h] [ebp-10h]
  char v13; // [esp+15h] [ebp-Fh]
  char Buffer; // [esp+16h] [ebp-Eh] BYREF
  char v15; // [esp+17h] [ebp-Dh]
  char v16; // [esp+18h] [ebp-Ch]
  char v17[8]; // [esp+1Ch] [ebp-8h] BYREF

  v3 = a1;
  v11 = a2;
  if ( !a1 || !a2 )
    return 0;
  *a2 = 0;
  v4 = *a1;
  v9 = 1;
  if ( *a1 )
  {
    while ( 1 )
    {
      if ( v4 != 43 )
        goto LABEL_10;
      if ( strlen(v3) < 4 )
        goto LABEL_10;
      v5 = v3[1];
      v6 = v3[2];
      v7 = v3[3];
      v12 = 43;
      v13 = v5;
      Buffer = v6;
      v15 = v7;
      v16 = 0;
      if ( v5 != 126 )
        goto LABEL_10;
      if ( isxdigit(v6) && isxdigit(v15) )
      {
        v10 = 0;
        sscanf(&Buffer, "%x", &v10);
        v17[0] = v10;
        v3 += 4;
      }
      else
      {
LABEL_10:
        v17[0] = *v3++;
      }
      v17[1] = 0;
      if ( (int)(strlen(v11) + strlen(v17)) >= a3 )
        return 0;
      strcat(v11, v17);
      v4 = *v3;
      if ( !*v3 )
        return 1;
    }
  }
  return v9;
}
