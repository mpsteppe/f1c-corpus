int __stdcall sub_4B3C90(char *Buffer, int a2)
{
  int v2; // eax

  if ( dword_75CBB0 != 7 || dword_768948 )
    v2 = *(_DWORD *)(dword_75AAC4 + 20884);
  else
    v2 = *(_DWORD *)(dword_75AAC4 + 20888);
  if ( v2 <= 0 )
    sprintf(Buffer, "-/%d", NumOfElements);
  else
    sprintf(Buffer, "%d/%d", v2, NumOfElements);
  return 0;
}
