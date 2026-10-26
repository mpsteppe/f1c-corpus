int __thiscall sub_6B1A9C(_DWORD *this, _DWORD *Block, _DWORD *a3)
{
  unsigned int v5; // edi
  const char **v6; // eax
  int result; // eax
  int v8; // eax
  int v9; // edi
  char *v10; // eax
  int v11; // edi
  int v12; // [esp-10h] [ebp-4Ch]
  char v13[32]; // [esp+Ch] [ebp-30h] BYREF
  void *Blocka; // [esp+44h] [ebp+8h]
  char *Blockb; // [esp+44h] [ebp+8h]
  int Blockc; // [esp+44h] [ebp+8h]

  Blocka = (void *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, Block[27]);
  v5 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 88))(this, Block[27]);
  if ( this[86] )
  {
    if ( Block[27] == -1 )
      return 0;
    if ( Blocka == (void *)0xFFFF )
    {
LABEL_14:
      if ( a3 )
        *a3 = Block[27];
      return 0;
    }
    v6 = (const char **)sub_6CA49D(Blocka);
    sub_632041((int)v13, 32, "v_%s%d", *v6, v5);
    v12 = Block[3];
    v13[31] = 0;
    result = sub_66078B(this + 117, v13, v12, 1);
    if ( result >= 0 )
    {
      ++this[124];
      if ( (this[51] & 1) != 0 )
      {
        v8 = Block[24];
        if ( v8 )
        {
          if ( *(_DWORD *)(v8 + 4) == 6 )
          {
            v9 = *(_DWORD *)(v8 + 20);
            if ( *(_DWORD *)(v9 + 4) == 3 )
            {
              v10 = (char *)operator new(strlen(*(const char **)(v9 + 24)) + 3);
              Blockb = v10;
              if ( !v10 )
                return -2147024882;
              sprintf(v10, "n_%s", *(const char **)(v9 + 24));
              v11 = sub_66078B(this + 117, Blockb, Block[3], 1);
              j__free(Blockb);
              if ( v11 < 0 )
                return v11;
              ++this[124];
            }
          }
        }
      }
      goto LABEL_14;
    }
  }
  else
  {
    switch ( (unsigned int)Blocka )
    {
      case 0u:
        return 1;
      case 1u:
        Blockc = 0;
        goto LABEL_18;
      case 2u:
        Blockc = 1;
        goto LABEL_18;
      case 3u:
        Blockc = 2;
        goto LABEL_18;
      case 4u:
        Blockc = 3;
        goto LABEL_18;
      case 5u:
        Blockc = 4;
        goto LABEL_18;
      case 6u:
        Blockc = 5;
        goto LABEL_18;
      case 7u:
        Blockc = 6;
        goto LABEL_18;
      case 8u:
        Blockc = 7;
        goto LABEL_18;
      case 9u:
        Blockc = 8;
        if ( v5 )
          goto LABEL_29;
        goto LABEL_19;
      case 0xAu:
        Blockc = 9;
        goto LABEL_18;
      case 0xBu:
        Blockc = 10;
        goto LABEL_18;
      case 0xCu:
        Blockc = 11;
        goto LABEL_18;
      case 0xDu:
        Blockc = 12;
        goto LABEL_18;
      case 0xEu:
        Blockc = 13;
LABEL_18:
        if ( v5 > 0xF )
          goto LABEL_29;
LABEL_19:
        result = off_16C96EC(Blockc, a3);
        break;
      default:
LABEL_29:
        result = -2147467259;
        break;
    }
  }
  return result;
}
