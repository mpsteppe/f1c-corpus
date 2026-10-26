void __stdcall sub_616710(void **Block)
{
  int v1; // [esp+0h] [ebp-8h]

  if ( Block )
  {
    sub_616710(Block[1]);
    sub_616710(Block[2]);
    sub_616580((__int32)Block, v1);
    j__free(Block);
  }
}
