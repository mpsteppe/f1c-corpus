int __stdcall sub_4B3EA0(char *Buffer, int a2)
{
  int v2; // eax

  v2 = sub_4C0BA0(dword_75AAC4 + 16588);
  if ( v2 > 0 )
    sprintf(Buffer, "%d", v2);
  else
    sprintf(Buffer, word_5FBEB8);
  return 0;
}
