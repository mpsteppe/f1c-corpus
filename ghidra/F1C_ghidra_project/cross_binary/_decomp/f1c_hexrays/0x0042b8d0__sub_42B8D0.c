// f1c  0x0042b8d0  size=615
int __fastcall sub_42B8D0(int a1, int *a2, int a3, const char *a4)
{
  int v6; // eax
  char v7; // cl
  int v8; // eax
  char v9; // cl
  int v11; // eax
  int v12; // esi
  int v13; // esi
  const char *v14; // ebp
  int v15; // eax
  char v16; // cl
  char v17[128]; // [esp+Ch] [ebp-80h] BYREF

  if ( !(unsigned __int8)sub_4B15D0(a1) )
  {
    if ( sub_423A00(byte_5EC4C0, a4, byte_5EC4CC) )
    {
      if ( a4 )
        strcpy(byte_5EC4CC, a4);
      else
        byte_5EC4CC[0] = 0;
    }
    v6 = 0;
    do
    {
      v7 = byte_5EC4CC[v6];
      v17[v6++] = v7;
    }
    while ( v7 );
    *(_WORD *)&v17[strlen(v17)] = word_5C32D8;
    if ( sub_423A00(byte_5EC4C0, aDisallowed, byte_5EC4CC) )
    {
      v8 = 0;
      do
      {
        v9 = aDisallowed[v8];
        byte_5EC4CC[v8++] = v9;
      }
      while ( v9 );
    }
    strcat(v17, byte_5EC4CC);
    return sub_45BD10(v17, 3, 16909060);
  }
  v11 = *a2 + 1;
  *a2 = v11;
  if ( v11 > a3 )
    *a2 = 0;
  v12 = *a2;
  if ( a1 == 3 )
  {
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        if ( v13 == 1 )
          v14 = aDownshifts;
        else
          v14 = aOn;
      }
      else
      {
        v14 = aUpshifts;
      }
      goto LABEL_28;
    }
  }
  else if ( v12 )
  {
    if ( v12 == 1 )
    {
      if ( a3 == 1 )
        v14 = aOn;
      else
        v14 = (const char *)&off_5C32A4;
    }
    else
    {
      v14 = aHigh;
    }
    goto LABEL_28;
  }
  v14 = (const char *)&off_5BE704;
LABEL_28:
  if ( sub_423A00(byte_5EC4C0, a4, byte_5EC4CC) )
  {
    if ( a4 )
      strcpy(byte_5EC4CC, a4);
    else
      byte_5EC4CC[0] = 0;
  }
  v15 = 0;
  do
  {
    v16 = byte_5EC4CC[v15];
    v17[v15++] = v16;
  }
  while ( v16 );
  *(_WORD *)&v17[strlen(v17)] = word_5C32D8;
  if ( sub_423A00(byte_5EC4C0, v14, byte_5EC4CC) )
  {
    if ( v14 )
      strcpy(byte_5EC4CC, v14);
    else
      byte_5EC4CC[0] = 0;
  }
  strcat(v17, byte_5EC4CC);
  sub_45BDF0(&unk_7CD204);
  sub_45BD10(v17, 3, 16909060);
  return sub_438CC0(&dbl_7C7428);
}
