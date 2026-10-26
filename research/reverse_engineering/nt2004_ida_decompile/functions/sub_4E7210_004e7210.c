char __thiscall sub_4E7210(const char **this, int a2, char *Destination, int a4)
{
  char v4; // bl
  char *v5; // ecx
  char v7[28]; // [esp+8h] [ebp-334h] BYREF
  char String[384]; // [esp+24h] [ebp-318h] BYREF
  int v9; // [esp+1A4h] [ebp-198h]
  char v10; // [esp+1A8h] [ebp-194h]
  int v11; // [esp+1B0h] [ebp-18Ch]
  int v12; // [esp+1B4h] [ebp-188h]
  int v13; // [esp+1B8h] [ebp-184h]
  char Buffer[384]; // [esp+1BCh] [ebp-180h] BYREF

  v4 = 0;
  if ( sub_4E7140(this, a2, Destination, a4) )
  {
    sub_57A080(v7);
    v5 = &Destination[strlen(Destination)];
    if ( v5 > Destination )
    {
      while ( *v5 != 46 )
      {
        if ( --v5 <= Destination )
          goto LABEL_7;
      }
      *v5 = 0;
    }
LABEL_7:
    strcat(Destination, ".txt");
    if ( (unsigned __int8)sub_57A2F0(Destination, 1) )
    {
      memset(Buffer, 0, sizeof(Buffer));
      v9 = 0;
      v13 = 0;
      v11 = 0;
      v12 = 0;
      v10 = 1;
      if ( sub_57A490(Buffer, 384) )
      {
        while ( sub_577B60(String) || !sub_577E50(String, aDescription_0, (int)Destination) )
        {
          if ( !sub_57A490(Buffer, 384) )
            goto LABEL_14;
        }
        v4 = 1;
      }
LABEL_14:
      sub_57A360(v7);
    }
    sub_57A0A0(v7);
  }
  return v4;
}
