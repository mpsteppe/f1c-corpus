int __stdcall sub_4B3B40(char *Buffer, int a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(dword_75AAC4 + 20848) + 1;
  if ( v2 > dword_7D74B8 )
    v2 = dword_7D74B8;
  if ( dword_7D74B8 == 0x7FFFFFFF )
  {
    sprintf(Buffer, "%d/--", v2);
    return 0;
  }
  if ( v2 == 1 )
  {
    if ( dword_75CBB4 >= 5 )
    {
LABEL_7:
      sprintf(Buffer, "%d/%d", v2, dword_7D74B8);
      return 0;
    }
  }
  else if ( v2 > 0 )
  {
    goto LABEL_7;
  }
  sprintf(Buffer, "0/%d", dword_7D74B8);
  return 0;
}
