int __stdcall sub_4DB6F0(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  char v5; // cl
  int v6; // eax
  char v7; // cl
  int v9[2]; // [esp+8h] [ebp-Ch] BYREF
  char v10; // [esp+11h] [ebp-3h]

  v3 = 16776960;
  if ( a1 == -1 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, byte_5CCEC4, byte_5EC4CC) )
    {
      v4 = 0;
      do
      {
        v5 = byte_5CCEC4[v4];
        byte_5EC4CC[v4++] = v5;
      }
      while ( v5 );
    }
LABEL_5:
    sub_587DD0(v9, byte_5EC4CC, 9);
    v10 = 0;
    goto LABEL_12;
  }
  if ( !a1 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, aN, byte_5EC4CC) )
    {
      v6 = 0;
      do
      {
        v7 = aN[v6];
        byte_5EC4CC[v6++] = v7;
      }
      while ( v7 );
    }
    goto LABEL_5;
  }
  StringFormatWithBufferOverflowCheck(v9, "%d", a1);
LABEL_12:
  if ( (sub_49B7A0(&unk_7CE234) & 0xF) == 0xF )
    v3 = 16711680;
  return UITextRenderWithScale((int)v9, a2, a3, v3, 2, 0, 1.25, 1.5);
}
