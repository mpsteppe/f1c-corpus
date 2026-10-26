char __thiscall sub_616960(_DWORD *this, _DWORD *Block)
{
  bool v4; // bl
  const char *v5; // eax
  int v6; // eax
  bool v8; // [esp+Ah] [ebp-2h]
  bool v9; // [esp+Bh] [ebp-1h]
  bool Blocka; // [esp+10h] [ebp+4h]

  if ( Block )
  {
    v9 = *Block == 0;
    v4 = Block[1] != 0;
    v8 = Block[8] != 0;
    v5 = (const char *)Block[3];
    Blocka = Block[8] == 0;
    if ( !v5 )
      v5 = WindowName;
    v6 = sub_616750(v5);
    if ( v9 )
    {
      if ( Blocka )
      {
        this[v6] = Block[1];
        if ( v4 )
        {
LABEL_7:
          *(_DWORD *)(Block[1] + 32) = 0;
          sub_6168E0((int)Block, Block);
          return 0;
        }
      }
      else if ( v8 )
      {
        *(_DWORD *)(Block[8] + 4) = Block[1];
        if ( v4 )
        {
          *(_DWORD *)(Block[1] + 32) = Block[8];
          sub_6168E0((int)Block, Block);
          return 0;
        }
      }
    }
    else if ( Blocka )
    {
      *(_DWORD *)(*Block + 8) = Block[1];
      if ( v4 )
        goto LABEL_7;
    }
    else if ( v8 )
    {
      *(_DWORD *)(Block[8] + 4) = Block[1];
      if ( v4 )
        *(_DWORD *)(Block[1] + 32) = Block[8];
    }
  }
  sub_6168E0((int)Block, Block);
  return 0;
}
