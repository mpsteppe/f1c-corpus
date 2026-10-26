int __thiscall sub_5508A0(_BYTE *this, const char *a2)
{
  int v2; // eax
  int v3; // edi
  int v5; // ebx
  const char *v6; // ebp
  int v7; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ebx
  char v11[256]; // [esp+10h] [ebp-300h] BYREF
  CHAR SrcStr[256]; // [esp+110h] [ebp-200h] BYREF
  char v13[256]; // [esp+210h] [ebp-100h] BYREF

  this[28] = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  if ( !SrcStr[0] || !sub_587C20(SrcStr, &off_5DC050) )
  {
    StringFormatWithBufferOverflowCheck(v11, "Illegal mesh file name %s", a2);
    sub_53C590(-1, v11);
    return -1;
  }
  v2 = sub_587DB0(SrcStr, aRb);
  v3 = v2;
  if ( !v2 )
  {
    v5 = 0;
    if ( dword_8B8E30 > 0 )
    {
      v6 = byte_8B5A3C;
      while ( 1 )
      {
        StringFormatWithBufferOverflowCheck(v13, "%s\\%s", v6, SrcStr);
        v7 = sub_587DB0(v13, aRb);
        v8 = v7;
        if ( v7 )
          break;
        ++v5;
        v6 += 132;
        if ( v5 >= dword_8B8E30 )
          goto LABEL_17;
      }
      if ( MeshVertexIndexBufferLoader(v7, 0) )
      {
        FileCloseWithLock(v8);
        StringFormatWithBufferOverflowCheck(v11, "Error loading animation file %s", v13);
        goto LABEL_15;
      }
      FileCloseWithLock(v8);
    }
LABEL_17:
    if ( v5 == dword_8B8E30 )
    {
      v9 = dword_8B8F14;
      v10 = 0;
      if ( dword_8B8F14 )
      {
        while ( sub_560230(SrcStr) )
        {
          v9 = *(_DWORD *)(v9 + 304);
          ++v10;
          if ( !v9 )
            goto LABEL_25;
        }
        if ( MeshVertexIndexBufferLoader(*(_DWORD *)(v9 + 16), v9) )
        {
          StringFormatWithBufferOverflowCheck(v11, "Error loading MAS animation file %s", a2);
          goto LABEL_15;
        }
      }
    }
    else
    {
      v10 = -1;
    }
LABEL_25:
    if ( v10 == dword_8B6AC0 )
    {
      StringFormatWithBufferOverflowCheck(v11, "Could not locate mesh file %s", a2);
      goto LABEL_15;
    }
    return 0;
  }
  if ( !MeshVertexIndexBufferLoader(v2, 0) )
  {
    FileCloseWithLock(v3);
    return 0;
  }
  FileCloseWithLock(v3);
  StringFormatWithBufferOverflowCheck(v11, "Error loading animation file %s", a2);
LABEL_15:
  sub_53C590(-1, v11);
  return -1;
}

