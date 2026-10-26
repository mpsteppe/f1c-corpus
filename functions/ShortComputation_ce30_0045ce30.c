unsigned int __fastcall sub_45CE30(char *a1, const char *a2, char *a3)
{
  char *v3; // eax
  char *v4; // esi
  char v5; // cl
  unsigned int v6; // kr04_4
  char v8[64]; // [esp+10h] [ebp-C0h] BYREF
  char v9[128]; // [esp+50h] [ebp-80h] BYREF

  v3 = a1;
  v8[0] = 0;
  v9[0] = 0;
  v4 = (char *)(v8 - a1);
  do
  {
    v5 = *v3;
    v3[(_DWORD)v4] = *v3;
    ++v3;
  }
  while ( v5 );
  strcpy(v9, a2);
  ShortComputation_cf30(v8);
  ShortComputation_cf30(v9);
  v6 = strlen(a3) + 1;
  *(_WORD *)&a3[strlen(a3)] = word_5C2AAC;
  strcat(a3, v8);
  *(_WORD *)&a3[strlen(a3)] = word_5C2AAC;
  strcat(a3, v9);
  return strlen(&a3[v6 - 1]);
}
