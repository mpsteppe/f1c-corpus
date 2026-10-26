char __fastcall sub_57B040(char *Source, char *a2, int a3)
{
  char *v3; // ebp
  int v5; // ecx
  char v6; // dl
  char *v7; // ebp
  char v8; // al
  char v9; // cl
  char v10; // dl
  char Buffer; // [esp+8h] [ebp-8h] BYREF
  char v14; // [esp+9h] [ebp-7h]
  char v15; // [esp+Ah] [ebp-6h]
  char v16; // [esp+Bh] [ebp-5h]
  char v17; // [esp+Ch] [ebp-4h]

  v3 = Source;
  if ( !Source || !a2 )
    return 0;
  *a2 = 0;
  if ( *Source )
  {
    while ( !(unsigned __int8)sub_57B220(v3) )
    {
      LOBYTE(v5) = *v3;
      if ( (unsigned __int8)sub_57B170(v5) )
      {
        Buffer = *v3;
        v14 = 0;
      }
      else
      {
        if ( *v3 != 43 )
          break;
        if ( sub_57AFD0((int)v3) )
        {
          v6 = v3[1];
          Buffer = *v3;
          v7 = v3 + 2;
          v14 = v6;
          v17 = 0;
          v8 = *v7;
          v9 = v7[1];
          v3 = v7 + 1;
          v15 = v8;
          v16 = v9;
        }
        else
        {
          v10 = *v3;
          v14 = 0;
          Buffer = v10;
        }
      }
LABEL_12:
      if ( (int)(strlen(&Buffer) + strlen(a2)) < a3 )
        strcat(a2, &Buffer);
      if ( !*++v3 )
        return 1;
    }
    sprintf(&Buffer, "%c%c%x%x", 43, 126, (unsigned __int8)*v3 >> 4, *v3 & 0xF);
    goto LABEL_12;
  }
  return 1;
}
