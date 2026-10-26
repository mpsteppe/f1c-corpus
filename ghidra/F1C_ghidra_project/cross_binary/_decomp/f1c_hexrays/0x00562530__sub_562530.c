// f1c  0x00562530  size=209
char *__fastcall sub_562530(int a1, const char *a2)
{
  __int16 v2; // bp
  int v4; // edx
  char *result; // eax
  char *v6; // edx
  char v7; // cl
  _BYTE *i; // esi
  _WORD v9[128]; // [esp+14h] [ebp-100h] BYREF

  v2 = word_5C2AAC;
  v9[0] = word_5C2AAC;
  memset(&v9[1], 0, 254);
  dword_8CF080 ^= 1u;
  strcat((char *)v9, a2);
  *(_WORD *)((char *)v9 + strlen((const char *)v9)) = v2;
  v4 = sub_587C20(a1, v9);
  result = 0;
  if ( v4 )
  {
    v6 = (char *)(strlen((const char *)v9) + v4);
    result = (char *)&unk_8CF088 + 256 * dword_8CF080;
    v7 = *v6;
    for ( i = result; v7; ++v6 )
    {
      if ( v7 == 92 )
        break;
      *i = v7;
      v7 = v6[1];
      ++i;
    }
    *i = 0;
  }
  return result;
}
