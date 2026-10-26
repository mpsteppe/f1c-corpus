int __thiscall sub_4983B0(const char *this, const char *a2, _DWORD *a3, _DWORD *a4, char a5)
{
  char *v5; // esi
  int v7; // ebx

  v5 = (char *)a2;
  *a3 = 0;
  *a4 = 0;
  if ( !a2 )
    return -1;
  v7 = (int)(this + 5400);
  if ( strlen(this + 5400) )
  {
    if ( a5 )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) )
        strcpy(byte_5EC4CC, a2);
      v5 = byte_5EC4CC;
    }
    ShortComputation_4f00(v7, (int)v5, (int)a3, (int)a4);
  }
  return 0;
}
