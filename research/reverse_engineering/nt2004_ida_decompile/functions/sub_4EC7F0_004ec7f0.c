char __stdcall sub_4EC7F0(char *a1)
{
  char result; // al
  char v2[256]; // [esp+8h] [ebp-200h] BYREF
  char String1[253]; // [esp+108h] [ebp-100h] BYREF
  __int16 v4; // [esp+205h] [ebp-3h]
  char v5; // [esp+207h] [ebp-1h]

  String1[0] = byte_629120;
  memset(&String1[1], 0, 0xFCu);
  v4 = 0;
  v5 = 0;
  v2[0] = byte_629120;
  memset(&v2[1], 0, 255);
  result = sub_4EB370(a1, String1, v2);
  if ( result )
    return sub_4ECF20(String1, (int)v2, (int)a1);
  return result;
}
