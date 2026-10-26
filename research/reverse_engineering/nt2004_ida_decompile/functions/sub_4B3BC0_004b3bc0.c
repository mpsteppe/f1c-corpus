int __stdcall sub_4B3BC0(char *Buffer, int a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(dword_75AAC4 + 20848);
  if ( v2 < 0 )
    goto LABEL_5;
  if ( v2 > dword_7D74B8 - 1 )
    v2 = dword_7D74B8 - 1;
  if ( v2 )
  {
    sprintf(Buffer, "%d/%d", v2, dword_7D74B8 - 1);
    return 0;
  }
  else
  {
LABEL_5:
    sprintf(Buffer, "-/%d", dword_7D74B8 - 1);
    return 0;
  }
}
