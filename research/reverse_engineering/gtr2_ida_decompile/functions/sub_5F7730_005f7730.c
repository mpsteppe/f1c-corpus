int __thiscall sub_5F7730(_DWORD *this, const char *a2, const char *a3, void *Block, int a5)
{
  if ( a2 )
    sub_5D8EF0((int)(this + 67), a2, 63);
  if ( a3 )
    sub_5D8EF0((int)(this + 51), a3, 63);
  this[94] = Block;
  if ( Block )
  {
    if ( dword_FB40C8
      && (*(int (__stdcall **)(int, void *, _DWORD *))(*(_DWORD *)dword_FB40C8 + 424))(dword_FB40C8, Block, this + 95) )
    {
      j__free(Block);
      return -1;
    }
    j__free(Block);
  }
  return 0;
}
