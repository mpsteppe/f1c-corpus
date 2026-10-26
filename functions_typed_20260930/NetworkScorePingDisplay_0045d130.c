int __thiscall sub_45D130(char *this, int a2)
{
  int result; // eax
  int v4; // esi
  int i; // [esp+Ch] [ebp-F4h]
  char v6[4]; // [esp+10h] [ebp-F0h] BYREF
  char v7[32]; // [esp+14h] [ebp-ECh] BYREF
  char v8[64]; // [esp+34h] [ebp-CCh] BYREF
  char v9[4]; // [esp+74h] [ebp-8Ch] BYREF
  char v10[124]; // [esp+78h] [ebp-88h] BYREF
  __int16 v11; // [esp+F4h] [ebp-Ch]
  __int16 v12; // [esp+FAh] [ebp-6h]

  result = StructFieldReadAt0x3e14(dword_7CD25C);
  v4 = 0;
  for ( i = result; v4 < i; ++v4 )
  {
    ThunkToFUN00461480(v9);
    if ( (unsigned __int8)DataTableRowAccessor(v4, v9, v6) )
    {
      v7[0] = 0;
      v8[0] = 0;
      StringFormatWithBufferOverflowCheck(v7, "player_%d", v4);
      ShortComputation_ce30(v7, v10, this);
      StringFormatWithBufferOverflowCheck(v7, "score_%d", v4);
      StringFormatWithBufferOverflowCheck(v8, "%d", v11);
      ShortComputation_ce30(v7, v8, this);
      StringFormatWithBufferOverflowCheck(v7, "ping_%d", v4);
      StringFormatWithBufferOverflowCheck(v8, "%d", v12);
      ShortComputation_ce30(v7, v8, this);
    }
    EmptyStub_0170(v9);
    result = i;
  }
  return result;
}

