// f1c  0x00421b10  size=441
int __fastcall sub_421B10(const char *a1, const char *a2)
{
  int i; // eax
  const char *v4; // ebx
  int v5; // esi
  int v6; // edi
  int j; // eax
  _BYTE v9[4]; // [esp+8h] [ebp-A08h] BYREF
  const char *v10; // [esp+Ch] [ebp-A04h]
  _BYTE v11[512]; // [esp+10h] [ebp-A00h] BYREF
  _BYTE v12[1021]; // [esp+210h] [ebp-800h] BYREF
  __int16 v13; // [esp+60Dh] [ebp-403h]
  char v14; // [esp+60Fh] [ebp-401h]
  _BYTE v15[1021]; // [esp+610h] [ebp-400h] BYREF
  __int16 v16; // [esp+A0Dh] [ebp-3h]
  char v17; // [esp+A0Fh] [ebp-1h]

  v10 = a2;
  v12[0] = byte_5EA438;
  memset(&v12[1], 0, 0x3FCu);
  v13 = 0;
  v14 = 0;
  v15[0] = byte_5EA438;
  memset(&v15[1], 0, 0x3FCu);
  v16 = 0;
  v17 = 0;
  sub_565DC0(v9);
  sub_565F80(dword_5C2AB8, 0, (int)a1, 1);
  sub_565F50(v9);
  for ( i = sub_565ED0(v9); i; i = sub_565ED0(v9) )
  {
    if ( (*(_BYTE *)i & 0x10) == 0 )
    {
      v4 = (const char *)(i + 44);
      if ( strcmp((const char *)(i + 44), (const char *)&word_5BEB48) )
      {
        if ( strcmp((const char *)(i + 44), "..") )
        {
          if ( strlen(a1) )
          {
            if ( strlen(v10) )
            {
              sub_58815F(v12, "%s%s", a1, v4);
              sub_58815F(v15, "%s%s", v10, v4);
              v5 = sub_587DB0(v12, aRb);
              if ( v5 )
              {
                v6 = sub_587DB0(v15, &unk_5C2AB0);
                if ( v6 )
                {
                  for ( j = sub_58803F(v11, 1, 512, v5); j > 0; j = sub_58803F(v11, 1, 512, v5) )
                    sub_588678(v11, 1, j, v6);
                  sub_587D02(v5);
                  sub_587D02(v6);
                }
              }
            }
          }
        }
      }
    }
    sub_565F20(v9);
  }
  return sub_565E20(v9);
}
