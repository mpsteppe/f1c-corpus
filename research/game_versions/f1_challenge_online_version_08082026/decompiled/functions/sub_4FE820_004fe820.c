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
    sub_5887B1(v3, aWeather);
    sub_5887B1(v4, asc_5C4060);
    for ( i = 0; i < 8; ++i )
    {
      sub_42CE30(i, 0);
      sub_5887B1(v4, aS_3);
      sub_5887B1(v4, asc_5D70F4);
      v10 = sub_4FB910((void *)i);
      this[14] = this[15];
      v9 = 0.0;
      if ( v10 > 0.0 )
      {
        do
        {
          sub_4FDEB0(this, 10.0, v9, 0);
          v7 = v9 + 10.0;
          v9 = v7;
        }
        while ( v7 < v10 );
      }
      sub_5887B1(v4, aConditions2f);
      sub_5887B1(v4, aOnpathwetness2);
      sub_5887B1(v4, aOffpathwetness);
      sub_5887B1(v4, aAmbienttemp2f);
      sub_5887B1(v4, aTracktemp2f);
      v8 = *(float **)(this[14] + 12);
      for ( this[14] = v8; v8; this[14] = v8 )
      {
        if ( (*v8 - v10) * 0.016666668 > 150.0 )
          break;
        sub_5887B1(v4, aMinute2f);
        sub_5887B1(v4, asc_5D7070);
        sub_5887B1(v4, aConditions2f_0);
        sub_5887B1(v4, aAmbienttemp2f_0);
        sub_5887B1(v4, asc_5D703C);
        v8 = *(float **)(this[14] + 12);
      }
      sub_5887B1(v4, asc_5D7038);
    }
    sub_5887B1(v4, asc_5D7034);
    sub_587D02(v4);
    return 0;
  }
  else
  {
    if ( sub_4D7A50(dword_8AD25C, 1, (int)aDDevF119992002_9, 2102) )
      sub_4D7AA0((int)dword_8AD25C, (int)"Could not write to file %s", a2);
    return -1;
  }
}
