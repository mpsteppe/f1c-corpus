int __thiscall sub_4FE820(_DWORD *this, const char *a2)
{
  int v3; // eax
  int v4; // esi
  int i; // ebx
  double v7; // st7
  float *v8; // eax
  float v9; // [esp+18h] [ebp-8h]
  float v10; // [esp+1Ch] [ebp-4h]

  v3 = sub_587DB0(a2, &unk_5C2AB0);
  v4 = v3;
  if ( v3 )
  {
    StringFormatWithNestedIO(v3, aWeather);
    StringFormatWithNestedIO(v4, asc_5C4060);
    for ( i = 0; i < 8; ++i )
    {
      SessionTypeNameLookup(i, 0);
      StringFormatWithNestedIO(v4, aS_3);
      StringFormatWithNestedIO(v4, asc_5D70F4);
      v10 = sub_4FB910((void *)i);
      this[14] = this[15];
      v9 = 0.0;
      if ( v10 > 0.0 )
      {
        do
        {
          AudioADSREnvelope(this, 10.0, v9, 0);
          v7 = v9 + 10.0;
          v9 = v7;
        }
        while ( v7 < v10 );
      }
      StringFormatWithNestedIO(v4, aConditions2f);
      StringFormatWithNestedIO(v4, aOnpathwetness2);
      StringFormatWithNestedIO(v4, aOffpathwetness);
      StringFormatWithNestedIO(v4, aAmbienttemp2f);
      StringFormatWithNestedIO(v4, aTracktemp2f);
      v8 = *(float **)(this[14] + 12);
      for ( this[14] = v8; v8; this[14] = v8 )
      {
        if ( (*v8 - v10) * 0.016666668 > 150.0 )
          break;
        StringFormatWithNestedIO(v4, aMinute2f);
        StringFormatWithNestedIO(v4, asc_5D7070);
        StringFormatWithNestedIO(v4, aConditions2f_0);
        StringFormatWithNestedIO(v4, aAmbienttemp2f_0);
        StringFormatWithNestedIO(v4, asc_5D703C);
        v8 = *(float **)(this[14] + 12);
      }
      StringFormatWithNestedIO(v4, asc_5D7038);
    }
    StringFormatWithNestedIO(v4, asc_5D7034);
    FileCloseWithLock(v4);
    return 0;
  }
  else
  {
    if ( StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_9, 2102) )
      DebugLogWrite((int)dword_8AD25C, (int)"Could not write to file %s", a2);
    return -1;
  }
}
