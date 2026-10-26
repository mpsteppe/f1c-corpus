// f1c  0x00567bb0  size=257
char __stdcall sub_567BB0(int *a1, int a2)
{
  int v2; // esi
  _BYTE *v3; // eax
  char *v4; // ecx
  _BYTE *v5; // eax
  char *v6; // eax
  char v8; // [esp+Fh] [ebp-401h]
  char v9[512]; // [esp+10h] [ebp-400h] BYREF
  char v10[512]; // [esp+210h] [ebp-200h] BYREF

  v2 = 0;
  memset(v10, 0, sizeof(v10));
  memset(v9, 0, sizeof(v9));
  v8 = 0;
  while ( sub_566CC0(a1, v10, 512) )
  {
    v8 = 1;
    if ( sub_567B10((unsigned __int8 *)v10, v9) )
    {
      if ( v9[0] == 123 )
      {
        sub_567BB0(a1, v2);
      }
      else
      {
        if ( v9[0] == 125 )
          return v8;
        v3 = (_BYTE *)sub_587C20(v9, asc_5C30AC);
        if ( v3 )
        {
          *v3 = 0;
          v4 = (char *)a1[1];
          v5 = v3 + 1;
          if ( !v4 )
            v4 = byte_5EA438;
          v2 = sub_567FB0(v9, v5, v4, a2);
        }
        else
        {
          v6 = (char *)a1[1];
          if ( !v6 )
            v6 = byte_5EA438;
          v2 = sub_567FB0(v9, 0, v6, a2);
        }
      }
    }
  }
  return v8;
}
