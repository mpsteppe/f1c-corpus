int __userpurge sub_6040D0@<eax>(_DWORD *a1@<ecx>, char a2@<dil>, int a3, unsigned int a4, unsigned int a5)
{
  bool v5; // zf
  int v6; // eax
  int v7; // eax

  if ( a4 < 0xFFFE0200 )
  {
    if ( a4 < 0xFFFE0101 )
      a1[27] = 1;
    else
      a1[27] = 2;
  }
  else
  {
    a1[27] = 8;
  }
  a1[29] = a5;
  if ( a5 < 0xFFFF0200 )
  {
    if ( a5 < 0xFFFF0101 )
      a1[28] = 256;
    else
      a1[28] = 512;
  }
  else
  {
    v5 = a1[27] == 1;
    a1[28] = 1024;
    if ( v5 )
    {
      a1[27] = 4;
      a1[1] |= 0x80u;
    }
  }
  v6 = a1[1];
  if ( (v6 & 4) != 0 )
  {
    a1[27] = 1;
    a1[28] = 256;
  }
  else if ( (v6 & 8) != 0 )
  {
    if ( (int)a1[27] >= 2 )
      a1[27] = 2;
    if ( (int)a1[28] >= 512 )
      a1[28] = 512;
  }
  else if ( (v6 & 0x10) != 0 )
  {
    if ( (int)a1[27] >= 8 )
      a1[27] = 8;
    if ( (int)a1[28] >= 1024 )
      a1[28] = 1024;
  }
  v7 = a1[27];
  if ( v7 == 1 && a1[28] == 256 )
    goto LABEL_38;
  if ( v7 != 2 || a1[28] != 512 )
  {
    if ( v7 == 8 && a1[28] == 1024 )
    {
      a1[30] = 1032;
      goto LABEL_39;
    }
    if ( v7 == 4 && a1[28] == 1024 )
    {
      a1[30] = 1028;
      goto LABEL_39;
    }
    if ( v7 != 8 || a1[28] != 256 )
    {
      sub_5D8C80(
        (int)(a1 + 1),
        (char *)0xFFFFFFFF,
        "Programmable shader support at some whack level I can't handle.",
        a2);
      return -1;
    }
    a1[27] = 1;
    a1[28] = 256;
LABEL_38:
    a1[30] = 257;
    goto LABEL_39;
  }
  a1[30] = 514;
LABEL_39:
  if ( a1[30] == 257 && a4 < 0xFFFE0101 )
    a1[1] |= 0x80u;
  return 0;
}
