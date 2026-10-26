int __thiscall sub_5574A0(_DWORD *this)
{
  int v2; // esi
  int v3; // edx
  char v4; // cl
  int v5; // eax
  int v6; // eax
  int v7; // edx
  char v8; // cl
  int v9; // esi
  int result; // eax
  char v11; // [esp+Fh] [ebp-9h] BYREF
  float v12; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h] BYREF

  v11 = 4;
  sub_557190(this, (int)&v11, 1);
  v2 = 0;
  v3 = 0;
  v4 = 0;
  do
  {
    v5 = (unsigned __int8)byte_B660D2[v3];
    if ( v3 == 5 && !dword_B6FD6C )
      v5 = 1;
    v6 = v5 << v4;
    v4 += 2;
    v2 += v6;
    ++v3;
  }
  while ( v3 < 11 );
  v7 = dword_B6F934 << v4;
  v8 = v4 + 2;
  v9 = (dword_B6FC28 << v8) + v7 + v2;
  v13 = v9;
  if ( *(_DWORD *)(dword_91E084 + 5744) == 1 )
    v13 = (1 << (v8 + 1)) + v9;
  sub_557190(this, (int)&v13, 4);
  v12 = sub_592960(&dword_FB1EF8);
  sub_557190(this, (int)&v12, 4);
  v12 = sub_592970(&dword_FB1EF8);
  sub_557190(this, (int)&v12, 4);
  v12 = sub_592980(&dword_FB1EF8);
  sub_557190(this, (int)&v12, 4);
  v12 = flt_FB1F2C + 273.16;
  sub_557190(this, (int)&v12, 4);
  v12 = flt_FB1F30 + 273.16;
  result = sub_557190(this, (int)&v12, 4);
  ++this[72];
  return result;
}
