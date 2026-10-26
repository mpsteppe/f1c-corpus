_DWORD *__thiscall sub_5EE620(_DWORD *this, char *ArgList)
{
  _DWORD *result; // eax
  int v4; // edx
  int v5; // edi
  size_t v6; // eax
  int v7; // edi
  size_t v8; // ebp
  void *v9; // ebx
  void *v10; // edi
  int v11; // [esp-Ch] [ebp-1Ch]
  void *Block; // [esp+8h] [ebp-8h]
  size_t v13; // [esp+Ch] [ebp-4h]

  if ( sub_5EE200(this, ArgList) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFE, "Could not locate %s in MAS file %s", (char)ArgList);
    return 0;
  }
  v4 = this[73];
  v5 = this[72] << 8;
  v6 = *(_DWORD *)(v5 + v4 + 8);
  v7 = v4 + v5;
  v13 = v6;
  v8 = *(_DWORD *)(v7 + 12);
  Block = operator new(v6);
  v9 = operator new(v8);
  v11 = this[4];
  if ( (*(_BYTE *)v7 & 0x10) != 0 )
  {
    if ( sub_6318A2(v9, 1, v8, v11) != v8 )
    {
      j__free(Block);
      j__free(v9);
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error reading compressed file %s from MAS file %s", (char)ArgList);
      return 0;
    }
    v10 = Block;
    if ( sub_62B130(v9, v8) )
    {
      j__free(Block);
      j__free(v9);
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error decompressing file %s from MAS file %s", (char)ArgList);
      return 0;
    }
  }
  else
  {
    if ( sub_6318A2(Block, 1, v13, v11) != v13 )
    {
      j__free(Block);
      j__free(v9);
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error reading file %s from MAS file %s", (char)ArgList);
      return 0;
    }
    v10 = Block;
  }
  j__free(v9);
  result = operator new(0x10u);
  if ( result )
  {
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
    *result = v10;
    result[2] = v13;
  }
  else
  {
    result = 0;
    MEMORY[0] = v10;
    MEMORY[8] = v13;
  }
  return result;
}
