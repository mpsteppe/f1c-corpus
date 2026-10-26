int __thiscall sub_560050(_DWORD *this, _DWORD *a2, const char *a3)
{
  int v5; // edx
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // ebp
  void *v10; // ebx
  void *v11; // ebp
  int v12; // [esp-4h] [ebp-11Ch]
  int v13; // [esp+10h] [ebp-108h]
  int v14; // [esp+14h] [ebp-104h]
  char v15[256]; // [esp+18h] [ebp-100h] BYREF

  if ( sub_560230(a3) )
  {
    StringFormatWithBufferOverflowCheck(v15, "Could not locate bitmap file %s", a3);
    sub_53C590(-2, v15);
    return -2;
  }
  if ( dword_8B8E28 )
  {
    v5 = this[74];
    v6 = this[73] << 8;
    v7 = *(_DWORD *)(v6 + v5 + 8);
    v8 = v5 + v6;
    v13 = v7;
    v9 = *(_DWORD *)(v8 + 12);
    v14 = v9;
    v10 = (void *)OperatorNewNhMallocWrapper(v7);
    v11 = (void *)OperatorNewNhMallocWrapper(v9);
    v12 = this[4];
    if ( (*(_BYTE *)v8 & 0x10) != 0 )
    {
      if ( ThreadSafeReadWrapper_803f(v11, 1, v14, v12) != v14 || sub_59B260(v11, v14) )
        goto LABEL_11;
    }
    else if ( ThreadSafeReadWrapper_803f(v10, 1, v13, v12) != v13 )
    {
      goto LABEL_11;
    }
    if ( RenderingCompositionSetup(dword_8B78A0, (int)v10, v13, a2, 1, 0) )
    {
LABEL_11:
      FreeWrapper_7bcf(v10);
      FreeWrapper_7bcf(v11);
      StringFormatWithBufferOverflowCheck(v15, "Error loading bit map %s", (const char *)(v8 + 20));
      sub_53C590(-1, v15);
      return -1;
    }
    FreeWrapper_7bcf(v10);
    FreeWrapper_7bcf(v11);
  }
  return 0;
}

