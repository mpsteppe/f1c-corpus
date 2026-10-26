char __thiscall sub_4E3570(_BYTE *this, _DWORD *a2)
{
  char v2; // bl
  int v4; // eax
  int v5; // eax
  unsigned int v7; // kr04_4
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // kr08_4
  char *v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // kr0C_4
  char *v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // edi
  int v19; // [esp+10h] [ebp-84h] BYREF
  char Buffer[128]; // [esp+14h] [ebp-80h] BYREF

  v2 = 0;
  if ( *a2 )
  {
    while ( sub_57A490(byte_7D68B0, 256) )
    {
      v2 = 1;
      v4 = sub_577B60(byte_7D6718);
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( !v5 || v5 == 3 )
          return v2;
      }
      else if ( sub_577E50(byte_7D6718, aName_0, (int)Buffer)
             || sub_577E50(byte_7D6718, aVehfile, (int)Buffer)
             || sub_577E50(byte_7D6718, aModfile, (int)Buffer)
             || sub_577E50(byte_7D6718, aRcdfile, (int)Buffer) )
      {
        sub_578600(Buffer);
      }
      else
      {
        v7 = strlen(aFinishresult) + 1;
        v8 = strstr(byte_7D68B0, aFinishresult);
        if ( v8 )
        {
          v9 = atol(&v8[v7 - 1]);
          v10 = v9;
          if ( v9 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", aFinishresult, v9);
            sub_578110(Buffer, (int)&this[4 * v10 + 32], 0, 0, 0);
          }
        }
        v11 = strlen(aFinishposition) + 1;
        v12 = strstr(byte_7D68B0, aFinishposition);
        if ( v12 )
        {
          v13 = atol(&v12[v11 - 1]);
          v14 = v13;
          if ( v13 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", aFinishposition, v13);
            sub_578110(Buffer, (int)&this[4 * v14 + 224], 0, 0, 0);
          }
        }
        v15 = strlen(aFinishpoints) + 1;
        v16 = strstr(byte_7D68B0, aFinishpoints);
        if ( v16 )
        {
          v17 = atol(&v16[v15 - 1]);
          v18 = v17;
          if ( v17 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", aFinishpoints, v17);
            sub_578110(Buffer, (int)&this[4 * v18 + 416], 0, 0, 0);
          }
        }
        sub_578110(aSeasonpoints, (int)(this + 608), 0, 0, 0);
        sub_578110(aPointsposition, (int)(this + 612), 0, 0, 0);
        sub_578110(aPolestaken, (int)(this + 616), 0, 0, 0);
        sub_578110(aLapslead, (int)(this + 620), 0, 0, 0);
        sub_578110(aLapscompleted, (int)(this + 624), 0, 0, 0);
        sub_578110(aOriginalgridpo, (int)(this + 628), 0, 0, 0);
        sub_578110(aCurrentgridpos, (int)(this + 632), 0, 0, 0);
        sub_578110(aControltype, (int)(this + 636), 0, 0, 0);
        if ( sub_578110(aActive, (int)&v19, 0, 0, 0) )
          this[640] = v19 != 0;
      }
    }
  }
  return v2;
}
