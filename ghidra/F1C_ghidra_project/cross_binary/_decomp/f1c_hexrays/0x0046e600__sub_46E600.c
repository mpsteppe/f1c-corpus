// f1c  0x0046e600  size=238
char *__thiscall sub_46E600(void *this, int a2)
{
  char *v3; // eax
  char *v4; // edx
  const char *v5; // edi
  unsigned int v6; // kr04_4
  char *result; // eax
  char *v8; // [esp+Ch] [ebp-88h]
  _BYTE v9[128]; // [esp+14h] [ebp-80h] BYREF

  v8 = (char *)sub_587C03(128);
  *v8 = 0;
  v3 = sub_432870((char ***)dword_7C73E0);
  sub_566650(v3);
  v4 = v8;
  v5 = v8;
  if ( !v8 )
    v5 = byte_5EA438;
  v6 = strlen(v5) + 1;
  if ( (int)(v6 - 1) > 0 )
  {
    if ( !v8 )
      v4 = byte_5EA438;
    if ( v4[v6 - 2] != 92 )
      sub_5665B0(&word_5C2AAC);
  }
  sub_587DD0(v9, this, 127);
  v9[127] = 0;
  sub_568560(v9);
  sub_5665B0(v9);
  sub_5665B0(aSvm);
  sub_568620(a2);
  result = v8;
  if ( v8 )
    return (char *)sub_587BCF(v8);
  return result;
}
