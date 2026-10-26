unsigned int *__stdcall sub_41F8C0(int a1, char *Buffer)
{
  int v2; // ecx
  int v3; // ebx
  char *p_Buffer; // ecx
  int v5; // esi
  unsigned int *v7; // [esp+0h] [ebp-18h]
  char Locale[8]; // [esp+8h] [ebp-10h] BYREF
  _BYTE v9[8]; // [esp+10h] [ebp-8h] BYREF
  int savedregs; // [esp+18h] [ebp+0h]
  _UNKNOWN *retaddr; // [esp+1Ch] [ebp+4h]

  sub_631BD0(savedregs);
  v3 = v2;
  p_Buffer = Buffer;
  retaddr = 0;
  if ( Buffer )
  {
    if ( !a1 )
      goto LABEL_6;
    sprintf((char *const)&Buffer, "%s%s", a1, Buffer);
  }
  else
  {
    sprintf((char *const)&Buffer, "%s%s", a1, "GAME.DIC");
  }
  p_Buffer = (char *)&Buffer;
LABEL_6:
  v5 = sub_62AD30(p_Buffer);
  if ( !v5 )
    return (unsigned int *)-1;
  LOBYTE(STACK[0x2A4]) = 0;
  memset(&STACK[0x2A5], 0, 0xFFCu);
  LOWORD(STACK[0x12A1]) = 0;
  *(_DWORD *)Locale = 256;
  LOBYTE(STACK[0x12A3]) = 0;
  if ( sub_62AF80(*(_DWORD *)Locale) )
  {
    do
    {
      *(_DWORD *)Locale = &STACK[0x1A4];
      v7 = &STACK[0x2A4];
      if ( sub_41F460() != -1 && !sub_41F5B0() )
        ++*(_DWORD *)Locale;
    }
    while ( sub_62AF80(256) );
  }
  sub_62AAB0(v5);
  sub_632C60(*(_DWORD *)(v3 + 8), *(_DWORD *)(v3 + 4));
  v9[0] = 0;
  if ( !sub_41F7F0((int)"__OSC_LOCALE_STRING", (int)v9) )
  {
    if ( strlen(Locale) )
      setlocale(2, Locale);
  }
  return v7;
}
