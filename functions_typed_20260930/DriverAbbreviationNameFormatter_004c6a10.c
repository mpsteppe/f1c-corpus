void __thiscall sub_4C6A10(const char *this)
{
  const char *v2; // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  CHAR SrcStr[16]; // [esp+Ch] [ebp-50h] BYREF
  char v7[64]; // [esp+1Ch] [ebp-40h] BYREF

  v2 = this + 17952;
  if ( this != (const char *)-17952 )
  {
    if ( AudioChannelStop(this + 17952) && (v3 = StringKeyedLinkedListSearch(aAbbreviation)) != 0 )
    {
      v4 = (const char *)DataEntryAccessor(v3);
      if ( BinarySearchInStringTable(byte_5EC4C0, v4, byte_5EC4CC) )
      {
        if ( v4 )
          strcpy(byte_5EC4CC, v4);
        else
          byte_5EC4CC[0] = 0;
      }
      StringFormatWithBufferOverflowCheck(SrcStr, "%-.13s", byte_5EC4CC);
    }
    else
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, v2, byte_5EC4CC) )
      {
        if ( v2 )
          strcpy(byte_5EC4CC, v2);
        else
          byte_5EC4CC[0] = 0;
      }
      sub_587DD0(v7, byte_5EC4CC, 63);
      v7[63] = 0;
      v5 = sub_587C20(v7, &word_5C32D8);
      if ( v5 )
        StringFormatWithBufferOverflowCheck(SrcStr, "%c. %-.11s", v7[0], (const char *)(v5 + 1));
      else
        StringFormatWithBufferOverflowCheck(SrcStr, "%-.13s", v7);
    }
    sub_589901(SrcStr);
    sub_587DD0(this + 18168, SrcStr, 15);
    *((_BYTE *)this + 18183) = 0;
  }
}

