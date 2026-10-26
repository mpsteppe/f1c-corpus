int __thiscall sub_54A870(_BYTE *this, const char *a2)
{
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // ebp
  int v7; // ebp
  const char *v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // edi
  _DWORD *v12; // esi
  int v13; // edi
  int v14; // eax
  int v16; // [esp+10h] [ebp-408h] BYREF
  int v17; // [esp+14h] [ebp-404h]
  char v18[256]; // [esp+18h] [ebp-400h] BYREF
  CHAR SrcStr[256]; // [esp+118h] [ebp-300h] BYREF
  char v20[256]; // [esp+218h] [ebp-200h] BYREF
  _BYTE v21[256]; // [esp+318h] [ebp-100h] BYREF

  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  if ( !SrcStr[0] || !sub_587C20(SrcStr, aMts_0) )
  {
    StringFormatWithBufferOverflowCheck(v18, "Illegal mesh file name %s", SrcStr);
    sub_53C590(-1, v18);
    return -1;
  }
  v3 = sub_587DB0(SrcStr, aRb);
  v4 = v3;
  if ( !v3 )
  {
    v7 = 0;
    if ( dword_8B8E30 > 0 )
    {
      v8 = byte_8B5A3C;
      while ( 1 )
      {
        StringFormatWithBufferOverflowCheck(v21, "%s\\%s", v8, SrcStr);
        v9 = sub_587DB0(v21, aRb);
        v10 = v9;
        if ( v9 )
          break;
        ++v7;
        v8 += 132;
        if ( v7 >= dword_8B8E30 )
          goto LABEL_19;
      }
      v11 = FileSizeQueryWrapper(v9);
      sub_587F64(v10, 0, 2);
      v17 = FileSizeQueryWrapper(v10);
      sub_587F64(v10, v11, 0);
      if ( sub_54AC70(v10, v17, &v16, 0) )
      {
        FileCloseWithLock(v10);
LABEL_16:
        StringRelocationCopy(0, v18);
        StringFormatWithBufferOverflowCheck(v20, " for file %s", SrcStr);
        goto LABEL_17;
      }
      FileCloseWithLock(v10);
    }
LABEL_19:
    if ( v7 == dword_8B8E30 )
    {
      v12 = (_DWORD *)dword_8B8F14;
      v13 = 0;
      if ( dword_8B8F14 )
      {
        do
        {
          if ( !sub_560230(SrcStr) )
          {
            v14 = sub_54AC70(v12[4], *(_DWORD *)((v12[73] << 8) + v12[74] + 8), &v16, v12);
            if ( !v14 )
              break;
            if ( v14 == -1 )
              goto LABEL_16;
          }
          v12 = (_DWORD *)v12[76];
          ++v13;
        }
        while ( v12 );
      }
    }
    else
    {
      v13 = -1;
    }
    if ( v13 == dword_8B6AC0 )
    {
      StringFormatWithBufferOverflowCheck(v18, "Could not locate mesh file %s", SrcStr);
      sub_53C590(-1, v18);
      return -1;
    }
    goto LABEL_7;
  }
  v5 = FileSizeQueryWrapper(v3);
  sub_587F64(v4, 0, 2);
  v6 = FileSizeQueryWrapper(v4);
  sub_587F64(v4, v5, 0);
  if ( sub_54AC70(v4, v6, &v16, 0) )
  {
    FileCloseWithLock(v4);
    StringRelocationCopy(0, v18);
    StringFormatWithBufferOverflowCheck(v20, " for file %s", SrcStr);
LABEL_17:
    strcat(v18, v20);
    sub_53C590(-1, v18);
    return -1;
  }
  FileCloseWithLock(v4);
LABEL_7:
  *(_DWORD *)(v16 + 312) = this;
  if ( (this[60] & 0x10) != 0 )
    sub_54B4D0(
      *(_DWORD *)(v16 + 256),
      *(_DWORD *)(v16 + 260),
      *(_DWORD *)(v16 + 264),
      *(float *)(v16 + 268),
      *(float *)(v16 + 272),
      *(float *)(v16 + 276));
  else
    sub_54B4D0(0, 0, 0, 0.0, 0.0, 0.0);
  sub_54B570(0, v16);
  LinkedListAppend_abe0(v16);
  *((_DWORD *)this + 15) &= ~0x8000u;
  return 0;
}

