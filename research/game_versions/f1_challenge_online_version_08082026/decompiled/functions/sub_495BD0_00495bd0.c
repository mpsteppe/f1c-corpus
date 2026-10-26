char __thiscall sub_495BD0(char *this)
{
  int v2; // ebx
  int v3; // ebp
  char *v4; // ecx
  int v5; // eax
  bool v6; // zf
  char result; // al
  int v8; // ecx
  int v9; // eax
  int i; // esi
  const char *v11; // eax
  int v12; // eax
  int **v13; // eax
  int v14; // [esp-4h] [ebp-3Ch]
  int v15; // [esp+10h] [ebp-28h]
  int v16; // [esp+14h] [ebp-24h]
  int v17; // [esp+18h] [ebp-20h]
  int v18; // [esp+1Ch] [ebp-1Ch]
  int v19; // [esp+20h] [ebp-18h]
  char *v20; // [esp+24h] [ebp-14h]
  int v21; // [esp+24h] [ebp-14h]
  int v22; // [esp+28h] [ebp-10h]
  int v23; // [esp+2Ch] [ebp-Ch] BYREF
  int v24; // [esp+30h] [ebp-8h] BYREF
  char v25[4]; // [esp+34h] [ebp-4h] BYREF

  v2 = 2;
  v16 = 2;
  v19 = 2;
  v18 = 0;
  v17 = 0;
  v15 = 0;
  v3 = sub_495150();
  sub_498550(this);
  v4 = this + 5628;
  v20 = this + 5628;
  v22 = 4;
  do
  {
    if ( (unsigned __int8)sub_499A50(v4) )
    {
      v5 = sub_49A2B0(v20);
      sub_4983B0(v5, &v24, &v23, 1);
      v17 += v23;
      if ( v24 > v18 )
        v18 = v24;
      ++v15;
    }
    v4 = v20 + 12;
    v6 = v22 == 1;
    v20 += 12;
    --v22;
  }
  while ( !v6 );
  result = v15;
  if ( v15 > 0 )
  {
    v8 = v18 + 6;
    if ( v18 + 8 > 800 )
      v16 = 794 - v18;
    v9 = v17 + 6;
    v23 = v17 + 6;
    if ( v17 + 8 > 600 )
    {
      v19 = 594 - v17;
      v2 = 594 - v17;
    }
    v21 = v2 + 3;
    for ( i = 0; i < v15; ++i )
    {
      if ( !i )
      {
        sub_494BF0(v3, v16, v2, v8, v9, -1426111420);
        sub_494BF0(v3, v16 + 3, v2 + 3, v18, v17, 2236962);
      }
      v11 = (const char *)sub_49A2B0(&this[12 * i + 5628]);
      sub_494F10((int)(this + 5400), v11, v16 + 3, v21, v3, 1);
      v12 = sub_49A2B0(&this[12 * i + 5628]);
      sub_4983B0(v12, v25, &v24, 1);
      v2 = v19;
      v8 = v18 + 6;
      v9 = v23;
      v21 += v24;
    }
    v14 = v23;
    v13 = (int **)sub_490920();
    return sub_4918D0(v13, v16, v19, v18 + 6, v14);
  }
  return result;
}
