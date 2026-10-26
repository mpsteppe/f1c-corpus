int __thiscall sub_4A1E3A(char *this)
{
  MEMORY[0xFFFFFF8B](this - 1);
  __asm { icebp }
  return sub_4A1E46(MEMORY[0x30]);
}
