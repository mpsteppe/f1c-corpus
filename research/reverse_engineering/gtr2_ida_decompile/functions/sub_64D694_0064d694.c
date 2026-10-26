void **__thiscall sub_64D694(void **Block, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    sub_644F0B((int)Block, 12, (int)*(Block - 1), (int (__thiscall *)(int))std::_Timevec::~_Timevec);
    if ( (a2 & 1) != 0 )
      j__free(Block - 1);
    return Block - 1;
  }
  else
  {
    j__free(*Block);
    if ( (a2 & 1) != 0 )
      j__free(Block);
    return Block;
  }
}
