int __fastcall sub_41BE60(int *a1, int *a2)
{
  int result; // eax
  char String[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v6; // [esp+89h] [ebp-3h]
  char v7; // [esp+8Bh] [ebp-1h]

  String[0] = byte_629120;
  memset(&String[1], 0, 0x7Cu);
  v6 = 0;
  v7 = 0;
  if ( sub_4E8E50(String, 128, aCommtrackid, 0) )
    *a1 = 15;
  else
    *a1 = atoi(String);
  result = sub_4E8E50(String, 128, aCommracenum, 0);
  if ( result )
  {
    *a2 = 15;
  }
  else
  {
    result = atoi(String);
    *a2 = result;
  }
  return result;
}
