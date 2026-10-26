int __thiscall sub_4E5990(void *this, float Buffer, int a3)
{
  char *v3; // edi
  int v4; // eax
  int v5; // ebx
  const char *v6; // eax
  char *v7; // eax
  double v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+24h] [ebp-4h] BYREF

  v3 = (char *)LODWORD(Buffer);
  *(_DWORD *)LODWORD(Buffer) = 758787360;
  *((_DWORD *)v3 + 1) = 2960941;
  if ( *((_DWORD *)dword_91E07C + 4845) )
    return 0;
  v4 = *((_DWORD *)dword_91E07C + 4875);
  if ( !v4
    || *(_DWORD *)(v4 + 19380)
    || ((int (__thiscall *)(void *, char *, int, float *, int *))loc_4E4BE0)(this, dword_91E07C, v4, &Buffer, &v10) )
  {
    return 0;
  }
  v5 = v10;
  if ( v10 <= 0 )
  {
    Buffer = fabs(Buffer);
    sub_4E42B0(Buffer, &v10, &Buffer);
    v9 = Buffer;
    if ( v10 > 0 )
    {
      sprintf(v3, "+%.1d:%04.1f", v10, v9);
      return 0;
    }
    sprintf(v3, "+%03.1f", v9);
    return 0;
  }
  v6 = (const char *)&off_713304;
  if ( v10 != 1 )
    v6 = "LAPS";
  v7 = sub_41D840(&byte_91CC38, v6);
  sprintf(v3, " +%d %s", v5, v7);
  return 0;
}
