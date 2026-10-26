// f1c  0x004dc770  size=493
int __fastcall sub_4DC770(const char *a1, char a2, const char *a3, const char *a4, const char *a5, char a6, int a7)
{
  int v9; // eax
  int v10; // esi
  int result; // eax
  char v13[253]; // [esp+14h] [ebp-300h] BYREF
  __int16 v14; // [esp+111h] [ebp-203h]
  char v15; // [esp+113h] [ebp-201h]
  char v16[253]; // [esp+114h] [ebp-200h] BYREF
  __int16 v17; // [esp+211h] [ebp-103h]
  char v18; // [esp+213h] [ebp-101h]
  char v19[253]; // [esp+214h] [ebp-100h] BYREF
  __int16 v20; // [esp+311h] [ebp-3h]
  char v21; // [esp+313h] [ebp-1h]

  if ( !a1 )
    return -1;
  if ( !sub_4DC430(a7) )
    return -1;
  v9 = sub_548890(a1);
  v10 = v9;
  if ( !v9 )
    return -1;
  if ( !a3 || (result = sub_4DC450(v9, a2, a3, a6)) != 0 )
  {
    if ( !a4 || sub_4DC450(v10, a2, a4, a6) )
    {
      if ( !a5 || sub_4DC450(v10, a2, a5, a6) )
      {
        v19[0] = byte_5EA438[0];
        memset(&v19[1], 0, 0xFCu);
        v20 = 0;
        v21 = 0;
        v16[0] = byte_5EA438[0];
        memset(&v16[1], 0, 0xFCu);
        v17 = 0;
        v18 = 0;
        v13[0] = byte_5EA438[0];
        memset(&v13[1], 0, 0xFCu);
        v14 = 0;
        v15 = 0;
        if ( a3 )
        {
          sub_587DD0(v19, a3, 255);
          v21 = 0;
        }
        if ( a4 )
        {
          sub_587DD0(v16, a4, 255);
          v18 = 0;
        }
        if ( a5 )
        {
          sub_587DD0(v13, a5, 255);
          v15 = 0;
        }
        if ( sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_5, 265) )
          sub_4D7AA0(
            (int)dword_8AD25C,
            (int)"Unable to adjust texture for material: %s, tex0=%s, tex1=%s, tex2=%s",
            a1,
            v19,
            v16,
            v13);
        return -1;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      return 1;
    }
  }
  return result;
}
