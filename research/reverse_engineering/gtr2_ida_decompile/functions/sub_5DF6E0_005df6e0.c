void __stdcall sub_5DF6E0(void **Block)
{
  if ( Block )
  {
    if ( *Block )
    {
      j__free(*Block);
      *Block = 0;
    }
    if ( Block[1] )
    {
      j__free(Block[1]);
      Block[1] = 0;
    }
    Block[3] = 0;
    Block[2] = 0;
    if ( *Block )
      j__free(*Block);
    if ( Block[1] )
      j__free(Block[1]);
    j__free(Block);
  }
}
