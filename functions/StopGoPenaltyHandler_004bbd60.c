void __thiscall sub_4BBD60(int *this, const char *a2, char a3)
{
  int v4; // eax
  char v5; // cl
  int v6; // esi
  int v7; // [esp+0h] [ebp-154h]
  char v8[64]; // [esp+14h] [ebp-140h] BYREF
  char v9[64]; // [esp+54h] [ebp-100h] BYREF
  _BYTE v10[192]; // [esp+94h] [ebp-C0h] BYREF

  if ( !this[12] )
  {
    if ( a2 && !*(_DWORD *)(*this + 13000) )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, aStopGoPenalty, byte_5EC4CC) )
      {
        v4 = 0;
        do
        {
          v5 = aStopGoPenalty[v4];
          byte_5EC4CC[v4++] = v5;
        }
        while ( v5 );
      }
      sub_587DD0(v8, byte_5EC4CC, 63);
      v8[63] = 0;
      if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) )
        strcpy(byte_5EC4CC, a2);
      sub_587DD0(v9, byte_5EC4CC, 63);
      v9[63] = 0;
      StringFormatWithBufferOverflowCheck(v10, "%s %s", v8, v9);
      TextLineWrappingAndRendering(&dword_7CD204, (int)v10, 3, 16909060);
    }
    v6 = dword_8AAE64;
    if ( dword_83EE60 < 1023 )
    {
      ++dword_83EE60;
      dword_8AAE64 += 432;
    }
    *(float *)&v7 = dbl_8AFEA0;
    ProgressBarEventEncode((_DWORD *)v6, 4, 23, 1, this[1], v7, 0);
    *(_BYTE *)(v6 + 8) = a3;
    sub_41A720(*this, a2);
  }
}
