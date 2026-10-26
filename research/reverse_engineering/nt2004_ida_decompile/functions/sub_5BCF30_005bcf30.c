int __fastcall sub_5BCF30(int a1, int a2, int a3)
{
  int v4; // ebp
  int v5; // esi
  unsigned int i; // kr04_4
  _BYTE *v7; // eax
  char v8; // cl

  v4 = a1 + 76;
  v5 = 0;
  for ( i = strlen((const char *)(a1 + 76)) + 1; v5 < a3; *v7 = v8 )
  {
    v7 = (_BYTE *)(v5 * *(char *)(v5 % (int)(i - 1) + v4) % 8 + a1 + 108);
    v8 = *(_BYTE *)(v5 + a2) ^ *(_BYTE *)(v5 % 8 + a1 + 108) ^ *v7;
    ++v5;
  }
  return sub_5BE500(8);
}
