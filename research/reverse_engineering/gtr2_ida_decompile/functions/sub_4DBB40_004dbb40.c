int __thiscall sub_4DBB40(_DWORD *this, int a2, const char *a3)
{
  int result; // eax
  _WORD *v5; // edi
  char v6; // cl
  unsigned int v7; // eax
  char *v8; // edi
  _WORD *v10; // edi
  char v11; // al
  _WORD *v12; // edi
  char v13; // al
  int v14; // [esp-4h] [ebp-124h]
  _DWORD v15[3]; // [esp+10h] [ebp-110h]
  const char *v16; // [esp+1Ch] [ebp-104h] BYREF
  CHAR Text[253]; // [esp+20h] [ebp-100h] BYREF
  __int16 v18; // [esp+11Dh] [ebp-3h]
  char v19; // [esp+11Fh] [ebp-1h]

  result = 0;
  if ( a2 > 1 )
  {
    memset(Text, 0, sizeof(Text));
    v18 = 0;
    v19 = 0;
    v14 = this[188];
    v15[0] = "Undefined Error";
    v15[1] = "Warning";
    v15[2] = "Error";
    v16 = "Critical Error";
    sprintf(Text, "OSC %s on line %d : ", (const char *)v15[a2], v14);
    if ( a3 )
    {
      v5 = (_WORD *)((char *)&v16 + 3);
      do
      {
        v6 = *((_BYTE *)v5 + 1);
        v5 = (_WORD *)((char *)v5 + 1);
      }
      while ( v6 );
      *v5 = 34;
      v7 = strlen(a3) + 1;
      v8 = (char *)&v16 + 3;
      while ( *++v8 )
        ;
      qmemcpy(v8, a3, v7);
      v10 = (_WORD *)((char *)&v16 + 3);
      do
      {
        v11 = *((_BYTE *)v10 + 1);
        v10 = (_WORD *)((char *)v10 + 1);
      }
      while ( v11 );
      *v10 = 34;
      v12 = (_WORD *)((char *)&v16 + 3);
      do
      {
        v13 = *((_BYTE *)v12 + 1);
        v12 = (_WORD *)((char *)v12 + 1);
      }
      while ( v13 );
      *v12 = 10;
    }
    if ( this[70] )
      goto LABEL_16;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, _DWORD *, _DWORD, int, int, int))(this[69] + 8))(
           this + 69,
           this + 156,
           0,
           1,
           1,
           1) )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(this[69] + 52))(this + 69, 0);
    }
    if ( this[70] )
LABEL_16:
      (*(void (**)(_DWORD *, const char *, ...))(this[69] + 32))(this + 69, "%s\n", Text);
    if ( a2 == 3 || a2 == 2 )
    {
      if ( !this[194] )
      {
        MessageBoxA(0, Text, "OSC Read Error", 0);
        exit(1);
      }
      sub_4DE410(Text);
    }
    return 0;
  }
  return result;
}
