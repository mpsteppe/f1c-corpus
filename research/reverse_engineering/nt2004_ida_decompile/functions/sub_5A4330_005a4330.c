_DWORD *__thiscall sub_5A4330(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // ebp
  void *v4; // eax
  int v5; // eax

  byte_7E5D60 = 0;
  dword_7E5D4C = 0;
  v2 = this + 1142;
  v3 = 8;
  do
  {
    sub_5A9F70(v2);
    v2 += 17;
    --v3;
  }
  while ( v3 );
  this[26] = 0;
  this[25] = 0;
  this[1111] = 0;
  this[1112] = 0;
  memset(this + 1113, 0, 0x34u);
  this[1132] = 0x2000;
  this[1134] = 0x2000;
  this[1128] = 0;
  this[1127] = 0;
  this[1129] = 0;
  this[1130] = 0;
  this[1131] = 0;
  this[1136] = 0x8000;
  this[1138] = 0x8000;
  this[1133] = 0;
  this[1135] = 0;
  this[1137] = 0;
  this[1139] = 0;
  this[1141] = 0;
  this[1278] = 0;
  this[1279] = 0;
  this[1280] = 1;
  this[1281] = 2;
  this[1282] = 0;
  this[2159] = 0;
  this[1287] = 0;
  this[1288] = 0;
  this[1289] = 0;
  this[1290] = 0;
  this[2160] = 512;
  this[2161] = 6;
  this[1284] = 1;
  this[1285] = 0;
  this[1286] = 1;
  this[1298] = 0;
  this[1291] = 11513775;
  this[1300] = 0;
  v4 = operator new(0x4Cu);
  if ( v4 )
    v5 = sub_5AC560(v4);
  else
    v5 = 0;
  this[1299] = v5;
  sub_5AC5A0(1);
  this[1293] = 0;
  this[1294] = 0;
  this[1295] = 0;
  this[1296] = 1;
  this[1297] = 1;
  this[2148] = 0;
  this[2149] = 0;
  this[2150] = 0;
  this[2151] = 0;
  this[2145] = 0;
  this[2171] = 0;
  this[2146] = 0;
  this[2147] = 0;
  this[2092] = 0;
  this[2091] = 0;
  this[2090] = 0;
  this[2089] = 0;
  this[2087] = 0;
  this[2086] = 0;
  this[2085] = 0;
  this[2084] = 0;
  this[2082] = 0;
  this[2081] = 0;
  this[2080] = 0;
  this[2079] = 0;
  this[2093] = 1065353216;
  this[2088] = 1065353216;
  this[2083] = 1065353216;
  this[2078] = 1065353216;
  this[2094] = 1;
  this[2096] = 1065353216;
  this[2135] = 0;
  this[2136] = 0;
  this[2137] = 0;
  this[2138] = 0;
  this[2139] = 0;
  this[2140] = 0;
  this[2095] = 0;
  this[2141] = 640;
  this[2142] = 480;
  this[2143] = 1600;
  this[2144] = 1200;
  return this;
}
