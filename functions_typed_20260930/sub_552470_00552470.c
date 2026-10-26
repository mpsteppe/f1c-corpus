int __thiscall sub_552470(_DWORD *this, const char *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // edi
  int v6; // edi
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  void *v17; // esi
  int v19; // [esp-8h] [ebp-218h]
  CHAR SrcStr[256]; // [esp+10h] [ebp-200h] BYREF
  char v21[256]; // [esp+110h] [ebp-100h] BYREF

  v3 = a3;
  v5 = 0x8000;
  if ( (a3 & 0x800) != 0 )
    v5 = 34816;
  if ( (a3 & 2) != 0 )
    v6 = v5 | 2;
  else
    v6 = 1;
  v7 = SimpleFieldGetter_bfc0(dword_8B78A0);
  v8 = IndexedArrayAccess_d890(dword_8B78A0, v7);
  if ( v8 && (*(int *)(v8 + 284) <= 256 || *(int *)(v8 + 288) <= 256) )
    v3 = a3 & 0xFFFCFFFF | 0x10000;
  this[9] = v3;
  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  if ( !sub_587C20(SrcStr, &dword_5CC79C) )
  {
    StringFormatWithBufferOverflowCheck(v21, "Illegal font file type %s", SrcStr);
    sub_53C590(-1, v21);
    return -1;
  }
  v19 = (v3 & 0x20000) != 0 ? 5 : 0;
  v9 = this + 25;
  if ( !MemoryAllocation_cb20(this + 25, (int)SrcStr, v19, v6) && !TexturePathParsingAndDimensionCalculation(SrcStr) )
  {
    v10 = this[9];
    if ( (v10 & 0x20000) == 0 )
    {
      if ( (v10 & 0x10000) != 0 && (a3 & 0x800) == 0 )
        this[11] = -1;
      return 0;
    }
    if ( !VertexBufferSurfaceInit(this) )
    {
      v11 = *(_DWORD *)(*v9 + 28);
      if ( v11 > 32 )
      {
        if ( v11 > 64 )
        {
          if ( v11 > 128 )
          {
            if ( v11 > 256 )
            {
              if ( v11 > 512 )
              {
                if ( v11 > 1024 )
                {
                  if ( v11 > 2048 )
                    return -1;
                  v12 = 2048;
                }
                else
                {
                  v12 = 1024;
                }
              }
              else
              {
                v12 = 512;
              }
            }
            else
            {
              v12 = 256;
            }
          }
          else
          {
            v12 = 128;
          }
        }
        else
        {
          v12 = 64;
        }
      }
      else
      {
        v12 = 32;
      }
      v13 = *(_DWORD *)(*v9 + 32);
      if ( v13 > 32 )
      {
        if ( v13 > 64 )
        {
          if ( v13 > 128 )
          {
            if ( v13 > 256 )
            {
              if ( v13 > 512 )
              {
                if ( v13 > 1024 )
                {
                  if ( v13 > 2048 )
                    return -1;
                  v14 = 2048;
                }
                else
                {
                  v14 = 1024;
                }
              }
              else
              {
                v14 = 512;
              }
            }
            else
            {
              v14 = 256;
            }
          }
          else
          {
            v14 = 128;
          }
        }
        else
        {
          v14 = 64;
        }
      }
      else
      {
        v14 = 32;
      }
      v15 = (_DWORD *)OperatorNewNhMallocWrapper(96);
      if ( v15 )
        v16 = StructInitWithZeroFill(v15);
      else
        v16 = 0;
      this[538] = v16;
      if ( !sub_54FEC0((int)v16, aFonttex, v12, v14, 5, 4) )
      {
        ClippedRenderRegion(
          (_DWORD *)*v9,
          0,
          0,
          *(_DWORD **)(this[538] + 84),
          0,
          0,
          *(_DWORD *)(*v9 + 28),
          *(_DWORD *)(*v9 + 32),
          this[11],
          0);
        sub_542E50((_DWORD *)*v9);
        v17 = (void *)*v9;
        if ( *v9 )
        {
          EmptyStub_7470(*v9);
          FreeWrapper_7bcf(v17);
        }
        *v9 = *(_DWORD *)(this[538] + 84);
        if ( (a3 & 0x800) == 0 )
        {
          this[20] &= ~0x80u;
          return 0;
        }
        return 0;
      }
    }
  }
  return -1;
}

