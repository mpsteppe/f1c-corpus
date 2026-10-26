// f1c  0x0049c140  size=316
int __stdcall sub_49C140(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // esi
  const char *v5; // esi
  int v6; // esi
  const char *v7; // esi
  const char *v8; // esi

  v2 = *(_DWORD *)(dword_7C54E0 + 16448) + 1;
  if ( *(_DWORD *)(dword_7C54E0 + 16448) == 2 )
    v2 = 0;
  if ( !v2 )
  {
    v8 = off_5CCBF0[0];
    if ( !sub_423A00(byte_5EC4C0, off_5CCBF0[0], byte_5EC4CC) )
      goto LABEL_23;
    if ( v8 )
    {
      strcpy(byte_5EC4CC, v8);
      goto LABEL_23;
    }
    goto LABEL_22;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    v7 = off_5CCBE8[0];
    if ( sub_423A00(byte_5EC4C0, off_5CCBE8[0], byte_5EC4CC) )
    {
      if ( v7 )
      {
        strcpy(byte_5EC4CC, v7);
        v6 = a2 - 1;
        goto LABEL_24;
      }
      byte_5EC4CC[0] = 0;
    }
    v6 = a2 - 1;
    goto LABEL_24;
  }
  if ( v3 != 1 )
  {
    v4 = off_5CCBF0[0];
    if ( !sub_423A00(byte_5EC4C0, off_5CCBF0[0], byte_5EC4CC) )
    {
LABEL_23:
      v6 = a2 - 1;
      goto LABEL_24;
    }
    if ( v4 )
    {
      strcpy(byte_5EC4CC, v4);
      goto LABEL_23;
    }
LABEL_22:
    byte_5EC4CC[0] = 0;
    goto LABEL_23;
  }
  v5 = off_5CCBEC[0];
  if ( !sub_423A00(byte_5EC4C0, off_5CCBEC[0], byte_5EC4CC) )
    goto LABEL_13;
  if ( !v5 )
  {
    byte_5EC4CC[0] = 0;
LABEL_13:
    v6 = a2 - 1;
    goto LABEL_24;
  }
  strcpy(byte_5EC4CC, v5);
  v6 = a2 - 1;
LABEL_24:
  sub_587DD0(a1, byte_5EC4CC, v6);
  *(_BYTE *)(v6 + a1) = 0;
  return 0;
}
