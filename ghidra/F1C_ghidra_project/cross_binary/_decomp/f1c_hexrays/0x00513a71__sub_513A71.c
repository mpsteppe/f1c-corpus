// f1c  0x00513a71  size=161
void __cdecl sub_513A71(int a1, int a2, unsigned int a3, int a4, char a5, char a6, char a7, char a8, char a9)
{
  unsigned __int8 v9; // al

  if ( a1 && a2 )
  {
    *(_BYTE *)(a2 + 26) = a8;
    *(_DWORD *)(a2 + 4) = a4;
    *(_BYTE *)(a2 + 27) = a9;
    *(_DWORD *)a2 = a3;
    *(_BYTE *)(a2 + 24) = a5;
    *(_BYTE *)(a2 + 25) = a6;
    *(_BYTE *)(a2 + 28) = a7;
    if ( a6 == 3 || (a6 & 2) == 0 )
      *(_BYTE *)(a2 + 29) = 1;
    else
      *(_BYTE *)(a2 + 29) = 3;
    if ( (a6 & 4) != 0 )
      ++*(_BYTE *)(a2 + 29);
    v9 = a5 * *(_BYTE *)(a2 + 29);
    *(_BYTE *)(a2 + 30) = v9;
    if ( a3 <= 0x7FFFFFFFu / ((v9 + 7) >> 3) )
    {
      *(_DWORD *)(a2 + 12) = (a3 * v9 + 7) >> 3;
    }
    else
    {
      sub_511887(a1, (int)"Width too large to process image data; rowbytes will overflow.");
      *(_DWORD *)(a2 + 12) = 0;
    }
  }
}
