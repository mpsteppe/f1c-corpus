_DWORD *__thiscall sub_65B2FE(_DWORD *Block, char a2)
{
  std::tr1::_Ref_count<__ExceptionPtr>::_Destroy(Block);
  if ( (a2 & 1) != 0 )
    j__free(Block);
  return Block;
}
