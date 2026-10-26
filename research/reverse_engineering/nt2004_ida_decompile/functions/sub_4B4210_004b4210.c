int __thiscall sub_4B4210(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  const char *v4; // ecx
  const char *v5; // eax
  int v6; // [esp+8h] [ebp-104h] BYREF
  char v7[125]; // [esp+Ch] [ebp-100h] BYREF
  __int16 v8; // [esp+89h] [ebp-83h]
  char v9; // [esp+8Bh] [ebp-81h]
  char Buffer[125]; // [esp+8Ch] [ebp-80h] BYREF
  __int16 v11; // [esp+109h] [ebp-3h]
  char v12; // [esp+10Bh] [ebp-1h]

  result = 1;
  if ( !*(_BYTE *)this )
  {
    sub_4B4600((int)(this + 26), (int)(this + 21), off_609070, 1.0, 1.0, 1133838336, 1117913088);
    sub_4B4600((int)(this + 45), (int)(this + 22), off_609074, 0.5, 0.5, 1129447424, 1134886912);
    sub_4B4600((int)(this + 64), (int)(this + 23), off_609078, 0.5, 0.5, 1129447424, 1134886912);
    sub_4B4600((int)(this + 83), (int)(this + 24), off_60907C, 0.5, 0.5, 1129447424, 1134886912);
    sub_4B4600((int)(this + 102), (int)(this + 25), off_609080, 0.5, 0.5, 1129447424, 1134886912);
    v3 = 0;
    if ( dword_7DA9B8 )
    {
      if ( sub_598170(dword_7DA9B8) )
      {
        this[13] = sub_59A660(off_6090B4);
        this[4] = sub_599D20(off_60905C[0]);
        this[5] = sub_599D20(off_609068[0]);
        this[6] = sub_599D20(off_60906C[0]);
        this[9] = sub_59A660(off_609088[0]);
        this[10] = sub_59A660(off_60908C[0]);
        this[11] = sub_59A660(off_609090[0]);
        this[12] = sub_59A660(off_609094[0]);
        this[14] = sub_59A660(off_609098[0]);
        this[15] = sub_59A660(off_60909C[0]);
        this[16] = sub_59A660(off_6090A0[0]);
        this[17] = sub_59A660(off_6090A4[0]);
        this[18] = sub_59A660(off_6090A8[0]);
        this[19] = sub_59A660(off_6090AC[0]);
        this[20] = sub_59A660(off_6090B0[0]);
      }
      Buffer[0] = byte_629120;
      memset(&Buffer[1], 0, 0x7Cu);
      v11 = 0;
      v12 = 0;
      v6 = 0;
      v4 = (const char *)dword_62A0B8;
      if ( !dword_62A0B8 )
        v4 = &byte_629120;
      v5 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v5 = &byte_629120;
      sprintf(Buffer, "%s%s%s", v5, v4, aCmapsMas);
      sub_5924D0(dword_7DA988, (int)&v6, (int)Buffer);
      if ( v6 )
      {
        v7[0] = byte_629120;
        memset(&v7[1], 0, 0x7Cu);
        v8 = 0;
        v9 = 0;
        sprintf(v7, "%s.BMP", off_609058[0]);
        sub_592A60(this + 1, v7, 67585);
        if ( !this[1] )
          v3 = 1;
        sprintf(v7, "%s.BMP", off_609060[0]);
        sub_592A60(this + 2, v7, 67585);
        if ( !this[2] )
          v3 = 1;
        sprintf(v7, "%s.BMP", off_609064[0]);
        sub_592A60(this + 3, v7, 67585);
        if ( !this[3] )
          v3 = 1;
        if ( this[5] )
        {
          sub_5922A0(this + 7, off_609068[0], 0, 1);
          if ( !this[7] )
            v3 = 1;
          sub_5922A0(this + 8, off_60906C[0], 0, 1);
          if ( !this[8] )
            v3 = 1;
        }
        sub_592750(v6);
      }
      *(_BYTE *)this = 1;
    }
    return v3;
  }
  return result;
}
