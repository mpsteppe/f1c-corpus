char __thiscall sub_4B9FD0(_BYTE *this)
{
  char result; // al
  int v3; // eax
  char v4; // cl
  int v5; // eax
  char v6; // cl
  int v7; // eax
  char v8; // cl
  char *v9; // eax
  const char *v10; // esi
  char v11[77]; // [esp+4h] [ebp-50h] BYREF
  __int16 v12; // [esp+51h] [ebp-3h]
  char v13; // [esp+53h] [ebp-1h]

  result = this[4];
  if ( !result && *(_DWORD *)this == 1 )
  {
    if ( sub_423A00(byte_5EC4C0, aReplayRecordin, byte_5EC4CC) )
    {
      v3 = 0;
      do
      {
        v4 = aReplayRecordin[v3];
        byte_5EC4CC[v3++] = v4;
      }
      while ( v4 );
    }
    sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 2, 16909060);
    result = sub_461DB0(dword_7CD25C);
    if ( !result )
    {
      v11[0] = byte_5EA438[0];
      memset(&v11[1], 0, 0x4Cu);
      v12 = 0;
      v13 = 0;
      if ( sub_423A00(byte_5EC4C0, aReplayActivati, byte_5EC4CC) )
      {
        v5 = 0;
        do
        {
          v6 = aReplayActivati[v5];
          byte_5EC4CC[v5++] = v6;
        }
        while ( v6 );
      }
      v7 = 0;
      do
      {
        v8 = byte_5EC4CC[v7];
        v11[v7++] = v8;
      }
      while ( v8 );
      *(_WORD *)&v11[strlen(v11)] = word_5C32D8;
      v9 = sub_455260(dword_7D1D8C);
      v10 = v9;
      if ( v9 )
      {
        if ( sub_423A00(byte_5EC4C0, v9, byte_5EC4CC) )
          strcpy(byte_5EC4CC, v10);
        strcat(v11, byte_5EC4CC);
      }
      result = sub_45BD10(&dword_7CD204, (int)v11, 3, 16909060);
    }
    this[4] = 1;
  }
  return result;
}
