char __thiscall sub_4C03F0(_BYTE *this, _DWORD *a2)
{
  char v2; // bl
  int v4; // eax
  int v5; // eax
  unsigned int v7; // kr04_4
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // kr08_4
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  int v15; // [esp+10h] [ebp-84h] BYREF
  _BYTE v16[128]; // [esp+14h] [ebp-80h] BYREF

  v2 = 0;
  if ( *a2 )
  {
    while ( ConditionalDispatchBasedOnFlag(&unk_8AC1E8, 256) )
    {
      v2 = 1;
      v4 = sub_5651B0(&unk_8AC050);
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( !v5 || v5 == 3 )
          return v2;
      }
      else if ( sub_5654A0(aName_2, v16) || sub_5654A0(aVehfile, v16) || sub_5654A0(aRcdfile, v16) )
      {
        StringCopyWithBufferRealloc(v16);
      }
      else
      {
        v7 = strlen(aFinishposition) + 1;
        v8 = sub_587C20(&unk_8AC1E8, aFinishposition);
        if ( v8 )
        {
          v9 = sub_587ECE(v7 - 1 + v8);
          v10 = v9;
          if ( v9 < 0x30 )
          {
            StringFormatWithBufferOverflowCheck(v16, "%s%2.2d", aFinishposition, v9);
            sub_565760(v16, &this[4 * v10 + 24], 0, 0, 0);
          }
        }
        v11 = strlen(aFinishpoints) + 1;
        v12 = sub_587C20(&unk_8AC1E8, aFinishpoints);
        if ( v12 )
        {
          v13 = sub_587ECE(v12 + v11 - 1);
          v14 = v13;
          if ( v13 < 0x30 )
          {
            StringFormatWithBufferOverflowCheck(v16, "%s%2.2d", aFinishpoints, v13);
            sub_565760(v16, &this[4 * v14 + 216], 0, 0, 0);
          }
        }
        sub_565760(aSeasonpoints, this + 408, 0, 0, 0);
        sub_565760(aPointsposition, this + 412, 0, 0, 0);
        sub_565760(aPolestaken, this + 416, 0, 0, 0);
        sub_565760(aOriginalgridpo, this + 420, 0, 0, 0);
        sub_565760(aCurrentgridpos, this + 424, 0, 0, 0);
        sub_565760(aControltype, this + 428, 0, 0, 0);
        if ( sub_565760(aActive, &v15, 0, 0, 0) )
          this[432] = v15 != 0;
      }
    }
  }
  return v2;
}
