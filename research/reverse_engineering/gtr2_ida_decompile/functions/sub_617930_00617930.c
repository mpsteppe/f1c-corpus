char __fastcall sub_617930(char *a1, char *a2, signed int a3)
{
  char *v3; // ebp
  char *v4; // edi
  char v5; // cl
  char v6; // dl
  char *v7; // ebp
  char v8; // al
  char v9; // cl
  char Buffer; // [esp+Ch] [ebp-8h] BYREF
  char v14; // [esp+Dh] [ebp-7h]
  char v15; // [esp+Eh] [ebp-6h]
  char v16; // [esp+Fh] [ebp-5h]
  char v17; // [esp+10h] [ebp-4h]

  v3 = a1;
  v4 = a2;
  if ( !a1 || !a2 )
    return 0;
  *a2 = 0;
  if ( *a1 )
  {
    while ( !sub_6177C0() )
    {
      if ( sub_6176A0(*v3) )
      {
        Buffer = *v3;
        v14 = 0;
      }
      else
      {
        if ( *v3 != 43 )
          break;
        if ( sub_617750((int)v3) )
        {
          v5 = *v3;
          v6 = v3[1];
          v7 = v3 + 1;
          v8 = v7[1];
          v3 = v7 + 2;
          Buffer = v5;
          v9 = *v3;
          v14 = v6;
          v15 = v8;
          v16 = v9;
          v17 = 0;
        }
        else
        {
          Buffer = *v3;
          v14 = 0;
        }
      }
LABEL_12:
      if ( (int)(strlen(v4) + strlen(&Buffer)) < a3 )
      {
        strcat(v4, &Buffer);
        v4 = a2;
      }
      if ( !*++v3 )
        return 1;
    }
    sprintf(&Buffer, "%c%c%x%x", 43, 126, (unsigned __int8)*v3 >> 4, *v3 & 0xF);
    goto LABEL_12;
  }
  return 1;
}
