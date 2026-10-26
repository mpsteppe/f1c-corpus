int __thiscall sub_6A0733(_DWORD *this, _DWORD *Block, _DWORD *a3)
{
  unsigned int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // edi
  char *v11; // eax
  int v12; // edi
  int v13; // [esp-10h] [ebp-68h]
  char v14[32]; // [esp+Ch] [ebp-4Ch] BYREF
  int v15; // [esp+50h] [ebp-8h]
  void *Blocka; // [esp+60h] [ebp+8h]
  char *Blockb; // [esp+60h] [ebp+8h]
  unsigned int Blockc; // [esp+60h] [ebp+8h]

  Blocka = (void *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, Block[27]);
  v5 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 88))(this, Block[27]);
  if ( this[86] )
  {
    if ( Block[27] == -1 )
      return 0;
    if ( Blocka == (void *)0xFFFF )
    {
LABEL_17:
      if ( a3 )
        *a3 = Block[27];
      return 0;
    }
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * Block[1]) + 4) & 0x10) != 0 )
    {
      v6 = (_DWORD *)sub_6CA49D(Blocka);
      sub_632041((int)v14, 32, "v_%s%d", *v6, v5);
    }
    else
    {
      v7 = (_DWORD *)sub_6CA49D(Blocka);
      sub_632041((int)v14, 32, "o_%s%d", *v7, v5);
    }
    v13 = Block[3];
    v14[31] = 0;
    result = sub_66078B(this + 117, v14, v13, 1);
    if ( result >= 0 )
    {
      ++this[124];
      if ( (this[51] & 1) != 0 )
      {
        v9 = Block[24];
        if ( v9 )
        {
          if ( *(_DWORD *)(v9 + 4) == 6 )
          {
            v10 = *(_DWORD *)(v9 + 20);
            if ( *(_DWORD *)(v10 + 4) == 3 )
            {
              v11 = (char *)operator new(strlen(*(const char **)(v10 + 24)) + 3);
              Blockb = v11;
              if ( !v11 )
                return -2147024882;
              sprintf(v11, "n_%s", *(const char **)(v10 + 24));
              v12 = sub_66078B(this + 117, Blockb, Block[3], 1);
              j__free(Blockb);
              if ( v12 < 0 )
                return v12;
              ++this[124];
            }
          }
        }
      }
      goto LABEL_17;
    }
  }
  else
  {
    v15 = 0;
    switch ( (unsigned int)Blocka )
    {
      case 0u:
        return 1;
      case 1u:
        Blockc = 0;
        goto LABEL_21;
      case 2u:
        Blockc = 1;
        goto LABEL_21;
      case 3u:
        Blockc = 2;
        goto LABEL_21;
      case 4u:
        Blockc = 3;
        goto LABEL_21;
      case 5u:
        Blockc = 4;
        goto LABEL_21;
      case 6u:
        Blockc = 5;
        goto LABEL_21;
      case 7u:
        Blockc = 6;
        goto LABEL_21;
      case 8u:
        Blockc = 7;
        goto LABEL_21;
      case 9u:
        Blockc = 8;
        if ( v5 )
          goto LABEL_31;
        goto LABEL_22;
      case 0xAu:
        Blockc = 9;
        goto LABEL_21;
      case 0xBu:
        Blockc = 10;
        goto LABEL_21;
      case 0xCu:
        Blockc = 11;
        goto LABEL_21;
      case 0xDu:
        Blockc = 12;
        goto LABEL_21;
      case 0xEu:
        Blockc = 13;
        goto LABEL_21;
      case 0x11u:
        Blockc = 0x80000000;
        v15 = 1;
        goto LABEL_21;
      case 0x12u:
        Blockc = 0x80000000;
LABEL_21:
        if ( v5 > 0xF )
          goto LABEL_31;
LABEL_22:
        result = off_16C9580(Blockc, a3);
        break;
      default:
LABEL_31:
        result = -2147467259;
        break;
    }
  }
  return result;
}
