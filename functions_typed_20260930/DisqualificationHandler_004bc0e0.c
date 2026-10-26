// DisqualificationHandler: Guarded by this[12] != 3 (anti-double-DQ). Does NOT write this[12] — only reads it. Shows "Disqualified:" text + logs event.
void __thiscall sub_4BC0E0(int *this, const char *a2)
{
  int v3; // eax
  char v4; // cl
  _DWORD *v5; // ecx
  int v6; // [esp+0h] [ebp-150h]
  char v7[64]; // [esp+10h] [ebp-140h] BYREF
  char v8[64]; // [esp+50h] [ebp-100h] BYREF
  _BYTE v9[192]; // [esp+90h] [ebp-C0h] BYREF

  if ( this[12] != 3 )
  {
    if ( a2 && !*(_DWORD *)(*this + 13000) )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, aDisqualified, byte_5EC4CC) )
      {
        v3 = 0;
        do
        {
          v4 = aDisqualified[v3];
          byte_5EC4CC[v3++] = v4;
        }
        while ( v4 );
      }
      sub_587DD0(v7, byte_5EC4CC, 63);
      v7[63] = 0;
      if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) )
        strcpy(byte_5EC4CC, a2);
      sub_587DD0(v8, byte_5EC4CC, 63);
      v8[63] = 0;
      StringFormatWithBufferOverflowCheck(v9, "%s %s", v7, v8);
      TextLineWrappingAndRendering(&dword_7CD204, (int)v9, 3, 16909060);
    }
    if ( dword_83EE60 >= 1023 )
    {
      v5 = (_DWORD *)dword_8AAE64;
    }
    else
    {
      ++dword_83EE60;
      v5 = (_DWORD *)dword_8AAE64;
      dword_8AAE64 += 432;
    }
    *(float *)&v6 = dbl_8AFEA0;
    ProgressBarEventEncode(v5, 4, 28, 0, this[1], v6, 0);
    sub_41A940(*this, a2);
  }
}

