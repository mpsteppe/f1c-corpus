int __thiscall sub_55FE70(_DWORD *this, const char *a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int v7; // edx
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // ebp
  void *v12; // ebx
  void *v13; // ebp
  int v14; // [esp-4h] [ebp-11Ch]
  int v15; // [esp+10h] [ebp-108h]
  int v16; // [esp+14h] [ebp-104h]
  char v17[256]; // [esp+18h] [ebp-100h] BYREF

  if ( sub_560230(a2) )
  {
    StringFormatWithBufferOverflowCheck(v17, "Could not locate bitmap file %s", a2);
    sub_53C590(-2, v17);
    return -2;
  }
  v7 = this[74];
  v8 = this[73] << 8;
  v9 = *(_DWORD *)(v8 + v7 + 8);
  v10 = v7 + v8;
  v15 = v9;
  v11 = *(_DWORD *)(v10 + 12);
  v16 = v11;
  v12 = (void *)OperatorNewNhMallocWrapper(v9);
  v13 = (void *)OperatorNewNhMallocWrapper(v11);
  v14 = this[4];
  if ( (*(_BYTE *)v10 & 0x10) != 0 )
  {
    if ( ThreadSafeReadWrapper_803f(v13, 1, v16, v14) != v16 || sub_59B260(v13, v16) )
      goto LABEL_10;
  }
  else if ( ThreadSafeReadWrapper_803f(v12, 1, v15, v14) != v15 )
  {
    goto LABEL_10;
  }
  if ( ResourceLoadWithOutput(dword_8B78A0, (int)v12, v15, a3, a4, a5) )
  {
LABEL_10:
    FreeWrapper_7bcf(v12);
    FreeWrapper_7bcf(v13);
    StringFormatWithBufferOverflowCheck(v17, "Error loading bit map %s", (const char *)(v10 + 20));
    sub_53C590(-1, v17);
    return -1;
  }
  FreeWrapper_7bcf(v12);
  FreeWrapper_7bcf(v13);
  return 0;
}

