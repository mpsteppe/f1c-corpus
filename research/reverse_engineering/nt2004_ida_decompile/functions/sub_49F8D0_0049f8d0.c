int __thiscall sub_49F8D0(_DWORD *this, char *Source, int a3)
{
  int v4; // eax
  char *v5; // eax
  char *v6; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // esi
  char v11; // dl
  unsigned int v12; // kr0C_4
  char v13; // al
  char v14; // al
  char v16; // [esp+Bh] [ebp-3C9h]
  int v17; // [esp+Ch] [ebp-3C8h] BYREF
  int v18; // [esp+10h] [ebp-3C4h] BYREF
  int v19; // [esp+14h] [ebp-3C0h]
  char v20[253]; // [esp+18h] [ebp-3BCh] BYREF
  __int16 v21; // [esp+115h] [ebp-2BFh]
  char v22; // [esp+117h] [ebp-2BDh]
  char Destination[700]; // [esp+118h] [ebp-2BCh] BYREF

  if ( !Source )
    return -1;
  v4 = this[61];
  if ( v4 )
  {
    v5 = *(char **)(v4 + 64);
    if ( !v5 )
      v5 = &byte_629120;
    sub_4AE350(v5);
  }
  strncpy(Destination, Source, 0x2BCu);
  Destination[699] = 0;
  v6 = Destination;
  v7 = sub_49D770(this, 2);
  if ( v7 <= 0 )
    v7 = this[3] + this[91];
  v8 = sub_49D770(this, 3);
  if ( v8 <= 0 )
    v8 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this) - this[91];
  v9 = v8 - v7;
  v19 = v9;
  sub_4AE230(Destination, (int)&v17, (int)&v18);
  v16 = 1;
  if ( v17 > v9 )
  {
    do
    {
      v20[0] = byte_629120;
      memset(&v20[1], 0, 0xFCu);
      v21 = 0;
      v22 = 0;
      strncpy(v20, v6, 0xFFu);
      v22 = 0;
      v10 = strlen(v20);
      sub_4AE230(v20, (int)&v17, (int)&v18);
      if ( v17 <= v19 )
      {
LABEL_20:
        if ( v10 > 0 )
        {
          sub_49F730(this, (int)v20, 0, 0, 0, 0);
          if ( a3 )
            sub_49FE20(this[37] - 1, a3);
          goto LABEL_24;
        }
      }
      else
      {
        while ( v10 > 0 )
        {
          v11 = 0;
          do
          {
            if ( v11 )
              break;
            if ( v20[v10 - 1] == 32 || !v16 )
              v11 = 1;
            v20[v10 - 1] = 0;
            v10 = strlen(v20);
          }
          while ( v10 > 0 );
          sub_4AE230(v20, (int)&v17, (int)&v18);
          if ( v17 <= v19 )
            goto LABEL_20;
        }
      }
      v16 = 0;
LABEL_24:
      v12 = strlen(v20) + 1;
      v13 = v6[v12 - 1];
      v6 += v12 - 1;
      if ( v13 == 32 )
      {
        do
          v14 = *++v6;
        while ( v14 == 32 );
      }
      sub_4AE230(v6, (int)&v17, (int)&v18);
    }
    while ( v17 > v19 );
  }
  if ( strlen(v6) )
  {
    sub_49F730(this, (int)v6, 0, 0, 0, 0);
    if ( a3 )
      sub_49FE20(this[37] - 1, a3);
  }
  sub_49FF10(this);
  return 0;
}
