__time32_t __thiscall sub_44BE60(char *FileName)
{
  __time32_t result; // eax
  int v2; // esi
  __time32_t st_mtime; // edi
  struct _stat32 Stat; // [esp+4h] [ebp-24h] BYREF

  result = _open(FileName, 0);
  v2 = result;
  if ( result != -1 )
  {
    if ( _fstat(result, &Stat) )
    {
      _close(v2);
      return -1;
    }
    else
    {
      st_mtime = Stat.st_mtime;
      _close(v2);
      return st_mtime;
    }
  }
  return result;
}
