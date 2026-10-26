_DWORD *__thiscall sub_6444C0(_DWORD *Block, char a2)
{
  void *v4; // [esp-8h] [ebp-Ch]
  void *v5; // [esp-4h] [ebp-8h]

  v5 = (void *)Block[1];
  *Block = &off_735FDC;
  free(v5);
  v4 = (void *)Block[2];
  Block[1] = 0;
  free(v4);
  Block[2] = 0;
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}
