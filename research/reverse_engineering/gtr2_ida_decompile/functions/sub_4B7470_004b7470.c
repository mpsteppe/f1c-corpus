int sub_4B7470()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // eax
  int v8; // edx

  byte_B71D08 = 0;
  if ( byte_B71D0A )
    byte_B71D08 = byte_B71D0A;
  v0 = dword_B7231C;
  *(_DWORD *)dword_B72314 = 3;
  if ( dword_B7231C > 3 || (v0 = dword_B72320, dword_B72320 < 3) )
    *(_DWORD *)dword_B72314 = v0;
  byte_B6FEEC = 0;
  if ( byte_B6FEEE )
    byte_B6FEEC = byte_B6FEEE;
  byte_B6FF04 = 0;
  if ( byte_B6FF06 )
    byte_B6FF04 = byte_B6FF06;
  byte_B6FEBC = 0;
  if ( byte_B6FEBE )
    byte_B6FEBC = byte_B6FEBE;
  byte_B6FED4 = 0;
  if ( byte_B6FED6 )
    byte_B6FED4 = byte_B6FED6;
  byte_B6FF1C = 0;
  if ( byte_B6FF1E )
    byte_B6FF1C = byte_B6FF1E;
  v1 = dword_B7068C;
  dword_B70684 = 1;
  if ( dword_B7068C > 1 || (v1 = dword_B70690, dword_B70690 < 1) )
    dword_B70684 = v1;
  dword_B72910 = 1036831949;
  if ( flt_B72918 <= 0.1 )
  {
    if ( flt_B7291C < 0.1 )
      dword_B72910 = LODWORD(flt_B7291C);
  }
  else
  {
    dword_B72910 = LODWORD(flt_B72918);
  }
  v2 = rand();
  v3 = dword_B72BDC;
  v4 = v2 % 6 + 8;
  dword_B72BD4 = v4;
  if ( v4 < dword_B72BDC || (v3 = dword_B72BE0, v4 > dword_B72BE0) )
    dword_B72BD4 = v3;
  v5 = v4 / 2;
  v6 = rand() % (v4 / 2);
  v7 = dword_B71F50;
  v8 = v5 + v6;
  dword_B71F48 = v8;
  if ( v8 < dword_B71F50 || (v7 = dword_B71F54, v8 > dword_B71F54) )
    dword_B71F48 = v7;
  dword_75B17C = 1;
  return -1;
}
