int __thiscall sub_55B6B0(void *this, const char *a2)
{
  int v2; // edi
  int v4; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // ebx
  const char *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edi
  int *v12; // esi
  int v13; // ebx
  char v15[256]; // [esp+14h] [ebp-200h] BYREF
  _BYTE v16[256]; // [esp+114h] [ebp-100h] BYREF

  v2 = (int)this;
  if ( !*a2 )
  {
    StringFormatWithBufferOverflowCheck(v15, "Illegal scene file name %s", a2);
    sub_53C590(-1, v15);
    return -1;
  }
  v4 = sub_587DB0(a2, aRb);
  v5 = v4;
  if ( v4 )
  {
    sub_587F64(v4, 0, 2);
    v6 = FileSizeQueryWrapper(v5);
    sub_587F64(v5, 0, 0);
    if ( SceneFileTopLevelParser(v2, v5, v6) )
    {
      FileCloseWithLock(v5);
      return -1;
    }
    FileCloseWithLock(v5);
    return 0;
  }
  v7 = 0;
  if ( dword_8B8E30 > 0 )
  {
    v8 = byte_8B5A3C;
    while ( 1 )
    {
      StringFormatWithBufferOverflowCheck(v16, "%s\\%s", v8, a2);
      v9 = sub_587DB0(v16, aRb);
      v10 = v9;
      if ( v9 )
        break;
      ++v7;
      v8 += 132;
      if ( v7 >= dword_8B8E30 )
        goto LABEL_16;
    }
    sub_587F64(v9, 0, 2);
    v11 = FileSizeQueryWrapper(v10);
    sub_587F64(v10, 0, 0);
    if ( SceneFileTopLevelParser((int)this, v10, v11) )
    {
      FileCloseWithLock(v10);
      return -1;
    }
    FileCloseWithLock(v10);
LABEL_16:
    v2 = (int)this;
  }
  if ( v7 == dword_8B8E30 )
  {
    v12 = (int *)dword_8B8F14;
    v13 = 0;
    if ( dword_8B8F14 )
    {
      while ( sub_560230(a2) )
      {
        v12 = (int *)v12[76];
        ++v13;
        if ( !v12 )
          goto LABEL_25;
      }
      if ( SceneFileTopLevelParser(v2, v12[4], *(_DWORD *)((v12[73] << 8) + v12[74] + 8)) )
        return -1;
    }
  }
  else
  {
    v13 = -1;
  }
LABEL_25:
  if ( v13 != dword_8B6AC0 )
    return 0;
  StringFormatWithBufferOverflowCheck(v15, "Could not locate scene file %s", a2);
  sub_53C590(-1, v15);
  return -1;
}

