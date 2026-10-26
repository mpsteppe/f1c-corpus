int __fastcall sub_41D0F0(char *Str, const char *a2)
{
  int i; // eax
  const char *v4; // ebx
  FILE *v5; // esi
  FILE *v6; // edi
  signed int j; // eax
  _BYTE v9[4]; // [esp+8h] [ebp-A08h] BYREF
  const char *v10; // [esp+Ch] [ebp-A04h]
  char v11[512]; // [esp+10h] [ebp-A00h] BYREF
  char Buffer[1021]; // [esp+210h] [ebp-800h] BYREF
  __int16 v13; // [esp+60Dh] [ebp-403h]
  char v14; // [esp+60Fh] [ebp-401h]
  char FileName[1021]; // [esp+610h] [ebp-400h] BYREF
  __int16 v16; // [esp+A0Dh] [ebp-3h]
  char v17; // [esp+A0Fh] [ebp-1h]

  v10 = a2;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3FCu);
  v13 = 0;
  v14 = 0;
  FileName[0] = byte_629120;
  memset(&FileName[1], 0, 0x3FCu);
  v16 = 0;
  v17 = 0;
  sub_578870(v9);
  sub_578A30(asc_5FCA68, 0, Str, 1);
  sub_578A00(v9);
  for ( i = sub_578980(v9); i; i = sub_578980(v9) )
  {
    if ( (*(_BYTE *)i & 0x10) == 0 )
    {
      v4 = (const char *)(i + 44);
      if ( strcmp((const char *)(i + 44), word_5FC804) )
      {
        if ( strcmp((const char *)(i + 44), asc_5FCA64) )
        {
          if ( strlen(Str) )
          {
            if ( strlen(v10) )
            {
              sprintf(Buffer, "%s%s", Str, v4);
              sprintf(FileName, "%s%s", v10, v4);
              v5 = fopen(Buffer, aRb);
              if ( v5 )
              {
                v6 = fopen(FileName, aWb);
                if ( v6 )
                {
                  for ( j = sub_5BED6F(v11, 1u, 0x200u, v5); j > 0; j = sub_5BED6F(v11, 1u, 0x200u, v5) )
                    sub_5BF5A6(v11, 1u, j, v6);
                  fclose(v5);
                  fclose(v6);
                }
              }
            }
          }
        }
      }
    }
    sub_5789D0(v9);
  }
  return sub_5788D0(v9);
}
