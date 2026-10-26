int __thiscall sub_4982C0(const char *this, const char *a2, int a3, int a4, int a5, int a6, char a7)
{
  const char *v7; // ebx
  int v9; // esi
  char *v10; // eax
  int v11; // edi
  int v12; // esi
  int v13; // eax
  char v14; // [esp-10h] [ebp-1Ch]
  int v15; // [esp+4h] [ebp-8h] BYREF
  const char *v16; // [esp+8h] [ebp-4h]

  v7 = a2;
  if ( !a2 )
    return -1;
  v9 = (int)(this + 5400);
  v16 = this + 5400;
  if ( strlen(this + 5400) )
  {
    if ( a7 )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) )
        strcpy(byte_5EC4CC, v7);
      v10 = byte_5EC4CC;
    }
    else
    {
      v10 = (char *)a2;
    }
    ShortComputation_4f00(v9, (int)v10, (int)&a2, (int)&v15);
    v11 = a6 - (_DWORD)a2;
    if ( a4 - a3 <= v15 )
      v12 = a3;
    else
      v12 = a3 + (a4 - a3) / 2 - v15 / 2;
    v14 = a7;
    v13 = GlobalAccessor_5150();
    UIMessageDispatch((int)v16, v7, v11, v12, v13, v14);
  }
  return 0;
}

