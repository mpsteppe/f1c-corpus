int __thiscall sub_476570(void *this)
{
  int result; // eax
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // esi
  char *v6; // esi
  int v7; // esi
  const char *v8; // ebx
  const char *v9; // edi
  const char *v10; // ebp
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // [esp+Ch] [ebp-98h]
  char *String1; // [esp+10h] [ebp-94h]
  CHAR v17; // [esp+14h] [ebp-90h] BYREF
  int v18; // [esp+15h] [ebp-8Fh]
  __int16 v19; // [esp+19h] [ebp-8Bh]
  char v20; // [esp+1Bh] [ebp-89h]
  void *v21; // [esp+1Ch] [ebp-88h]
  int v22; // [esp+20h] [ebp-84h]
  char Buffer[125]; // [esp+24h] [ebp-80h] BYREF
  __int16 v24; // [esp+A1h] [ebp-3h]
  char v25; // [esp+A3h] [ebp-1h]

  v21 = this;
  sub_49FEC0(this);
  result = sub_4E5DA0(&unk_76BB28);
  v2 = result;
  v22 = result;
  if ( result )
  {
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v17 = byte_629120;
    String1 = 0;
    if ( sub_57AE50(aRaceorder) )
    {
      v3 = sub_4E4980(v2);
      if ( v3 >= 0 )
      {
        v4 = sub_57A700(v3);
        if ( v4 )
          String1 = (char *)sub_57A6C0(v4);
      }
    }
    sub_49F640(&v17);
    v5 = 0;
    v15 = 0;
    result = sub_4B15C0(v2);
    if ( result > 0 )
    {
      do
      {
        v6 = (char *)sub_4E4800(v5);
        if ( v6 )
        {
          if ( sub_57AE50(aSeasonraces) )
          {
            v7 = sub_57A720(v6);
            if ( v7 )
            {
              Buffer[0] = byte_629120;
              memset(&Buffer[1], 0, 0x7Cu);
              v24 = 0;
              v25 = 0;
              v8 = 0;
              v9 = 0;
              v10 = 0;
              v11 = sub_57A720(aDate);
              if ( v11 )
                v10 = (const char *)sub_57A6D0(v11);
              v12 = sub_57A720(aEventname);
              if ( v12 )
                v8 = (const char *)sub_57A6D0(v12);
              v13 = sub_57A720(aVenuename);
              if ( v13 )
                v9 = (const char *)sub_57A6D0(v13);
              sprintf(Buffer, "%s%s%s%s%s", v10, &v17, v8, &v17, v9);
              sub_49F730(Buffer, 0, 0, 0, 0);
              if ( String1 )
              {
                v14 = (const char *)sub_57A6C0(v7);
                if ( !_strcmpi(String1, v14) )
                  sub_49FCC0(v15 + 1, 0);
              }
              v2 = v22;
            }
          }
        }
        v5 = ++v15;
        result = sub_4B15C0(v2);
      }
      while ( v15 < result );
    }
  }
  return result;
}
