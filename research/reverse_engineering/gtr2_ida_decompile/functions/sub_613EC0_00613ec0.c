char __thiscall sub_613EC0(int this, char *Buffer)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 20);
  if ( !v2 )
    return fputs(Buffer, *(FILE **)(this + 4)) != -1;
  if ( v2 != 5 )
    return sub_62A8F0(*(_DWORD *)(this + 4), Buffer) != -1;
  sub_613900(*(_DWORD *)(this + 4), (int)Buffer, strlen(Buffer));
  return 1;
}
