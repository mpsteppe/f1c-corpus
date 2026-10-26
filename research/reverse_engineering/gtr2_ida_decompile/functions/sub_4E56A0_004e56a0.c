int __thiscall sub_4E56A0(void *this, float Buffer, int a3)
{
  char *v3; // ebx
  float v4; // eax
  int v5; // eax
  int v6; // edi
  const char *v7; // eax
  char *v8; // eax
  int v10; // [esp+24h] [ebp-4h] BYREF

  v3 = (char *)LODWORD(Buffer);
  v4 = Buffer;
  *(_DWORD *)LODWORD(Buffer) = 758787360;
  strcpy((char *)(LODWORD(v4) + 4), "-.---");
  if ( *((_DWORD *)dword_91E07C + 4845) )
    return 0;
  v5 = *((_DWORD *)dword_91E07C + 4874);
  if ( !v5
    || *(_DWORD *)(v5 + 19380)
    || ((int (__thiscall *)(void *, int, char *, float *, int *))loc_4E4BE0)(this, v5, dword_91E07C, &Buffer, &v10) )
  {
    return 0;
  }
  v6 = v10;
  if ( v10 <= 0 )
  {
    Buffer = fabs(Buffer);
    sub_4E42B0(Buffer, &v10, &Buffer);
    sprintf(v3, "-%.1d:%06.3f", v10, Buffer);
    return 0;
  }
  v7 = (const char *)&off_713304;
  if ( v10 != 1 )
    v7 = "LAPS";
  v8 = sub_41D840(&byte_91CC38, v7);
  sprintf(v3, " -%d %s", v6, v8);
  return 0;
}
