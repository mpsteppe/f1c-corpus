char sub_437780()
{
  unsigned int v0; // eax
  char *v1; // edi
  _WORD *v3; // edi
  char v4; // al
  int v6; // [esp-Ch] [ebp-214h] BYREF
  char v7; // [esp-1h] [ebp-209h] BYREF
  _BYTE v8[8]; // [esp+0h] [ebp-208h] BYREF
  _BYTE v9[512]; // [esp+8h] [ebp-200h] BYREF

  v9[0] = 0;
  sub_501410(&byte_B6F530, v9, 512);
  v0 = strlen(off_757C64[0]) + 1;
  v1 = &v7;
  while ( *++v1 )
    ;
  qmemcpy(v1, off_757C64[0], v0);
  v3 = (_WORD *)((char *)&v6 + 11);
  do
  {
    v4 = *((_BYTE *)v3 + 1);
    v3 = (_WORD *)((char *)v3 + 1);
  }
  while ( v4 );
  *v3 = 92;
  sub_615860(v8);
  sub_615860(WindowName);
  v6 = 0;
  sub_437470();
  return 1;
}
