void __thiscall sub_611470(void *this, _DWORD *Block, int a3)
{
  if ( Block )
  {
    sub_60B4D0();
    if ( (*Block & 0x40000) != 0 )
    {
      (*(void (__thiscall **)(void *))(*(_DWORD *)this + 364))(this);
    }
    else
    {
      nullsub_7(Block);
      j__free(Block);
    }
  }
}
