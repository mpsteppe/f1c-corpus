BOOL __thiscall sub_49CA00(_DWORD *this)
{
  BOOL v2; // ebx
  int v3; // eax
  int v4; // ecx
  const char *v5; // ecx
  const char *v6; // eax
  int v8; // [esp+8h] [ebp-104h] BYREF
  _BYTE v9[128]; // [esp+Ch] [ebp-100h] BYREF
  _BYTE v10[128]; // [esp+8Ch] [ebp-80h] BYREF

  v2 = 1;
  if ( !*(_BYTE *)this )
  {
    sub_49CD80((int)(this + 24), (int)(this + 19), off_5CCB70, 1.0, 1.0, 1133969408, 1118437376);
    sub_49CD80((int)(this + 43), (int)(this + 20), off_5CCB74, 0.5, 0.5, 1129447424, 1134886912);
    sub_49CD80((int)(this + 62), (int)(this + 21), off_5CCB78, 0.5, 0.5, 1129447424, 1134886912);
    sub_49CD80((int)(this + 81), (int)(this + 22), off_5CCB7C, 0.5, 0.5, 1129447424, 1134886912);
    sub_49CD80((int)(this + 100), (int)(this + 23), off_5CCB80, 0.5, 0.5, 1129447424, 1134886912);
    if ( dword_8AFE88 )
    {
      if ( ValueGetter(dword_8AFE88) )
      {
        this[4] = StringSearchInLinkedList(off_5CCB5C[0]);
        v3 = StringSearchInLinkedList(off_5CCB68[0]);
        v4 = this[4];
        this[5] = v3;
        if ( v4 )
          v2 = v3 == 0;
        this[8] = sub_548890(off_5CCB88[0]);
        this[9] = sub_548890(off_5CCB8C[0]);
        this[10] = sub_548890(off_5CCB90[0]);
        this[11] = sub_548890(off_5CCB94[0]);
        this[12] = sub_548890(off_5CCB98[0]);
        this[13] = sub_548890(off_5CCB9C[0]);
        this[14] = sub_548890(off_5CCBA0[0]);
        this[15] = sub_548890(off_5CCBA4[0]);
        this[16] = sub_548890(off_5CCBA8[0]);
        this[17] = sub_548890(off_5CCBAC[0]);
        this[18] = sub_548890(off_5CCBB0[0]);
      }
      v8 = 0;
      v5 = (const char *)dword_5EC428;
      if ( !dword_5EC428 )
        v5 = byte_5EA438;
      v6 = (const char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v6 = byte_5EA438;
      StringFormatWithBufferOverflowCheck(v10, "%s%s%s", v6, v5, aCmapsMas);
      sub_53CBC0(&v8, v10);
      if ( v8 )
      {
        StringFormatWithBufferOverflowCheck(v9, "%s.BMP", off_5CCB58[0]);
        sub_53CFE0(this + 1, v9, 67585);
        if ( !this[1] )
          v2 = 1;
        StringFormatWithBufferOverflowCheck(v9, "%s.BMP", off_5CCB60[0]);
        sub_53CFE0(this + 2, v9, 67585);
        if ( !this[2] )
          v2 = 1;
        StringFormatWithBufferOverflowCheck(v9, "%s.BMP", off_5CCB64[0]);
        sub_53CFE0(this + 3, v9, 67585);
        if ( !this[3] )
          v2 = 1;
        if ( this[5] )
        {
          MemoryAllocation_cb20(this + 6, off_5CCB68[0], 0, 1);
          if ( !this[6] )
            v2 = 1;
          MemoryAllocation_cb20(this + 7, off_5CCB6C[0], 0, 1);
          if ( !this[7] )
            v2 = 1;
        }
        PhysicsObjectLinkedListRemoval(v8);
      }
    }
    *(_BYTE *)this = 1;
  }
  return v2;
}

