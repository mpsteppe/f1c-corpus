bool __thiscall sub_57AF60(char *FileName)
{
  _chmod(FileName, 384);
  return remove(FileName) == 0;
}
