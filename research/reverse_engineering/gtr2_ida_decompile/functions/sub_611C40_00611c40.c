void __thiscall sub_611C40(void *this, char *Block)
{
  if ( Block )
  {
    sub_60BA90(Block);
    if ( (*(_DWORD *)Block & 0x40000) != 0 )
      (*(void (__thiscall **)(void *))(*(_DWORD *)this + 364))(this);
    else
      j__free(Block);
  }
}
