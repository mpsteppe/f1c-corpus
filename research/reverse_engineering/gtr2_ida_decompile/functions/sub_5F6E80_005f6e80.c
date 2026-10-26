int __thiscall sub_5F6E80(_DWORD *this, const char *ArgList, const char *a3, int a4, _DWORD *Block, int a6, int a7)
{
  int v8; // eax

  if ( ArgList )
    sub_5D8EF0((int)(this + 67), ArgList, 63);
  if ( a3 )
    sub_5D8EF0((int)(this + 51), a3, 63);
  this[86] = a4;
  this[87] = Block;
  this[90] = a6;
  if ( !a4 || !dword_FB40C8 )
  {
    this[87] = 0;
    if ( Block )
    {
      this[90] = *Block;
      return 0;
    }
    this[90] = 0;
    return 0;
  }
  v8 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 652))(dword_FB27A4, a4);
  this[88] = v8;
  if ( !v8 )
  {
    if ( Block )
      j__free(Block);
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating vertex declaration for shader %s", (char)ArgList);
    return -1;
  }
  if ( !(*(int (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)dword_FB40C8 + 364))(dword_FB40C8, this[87], this + 89) )
  {
    if ( Block )
    {
      j__free(Block);
      return 0;
    }
    return 0;
  }
  if ( Block )
    j__free(Block);
  sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating vertex shader %s", (char)ArgList);
  return -1;
}
