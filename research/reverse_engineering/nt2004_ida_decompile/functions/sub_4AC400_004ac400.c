int __thiscall sub_4AC400(char *this)
{
  int v1; // esi
  char *v3; // edi
  int v4; // eax
  int result; // eax
  int v6; // eax
  double v7; // st7
  int v8; // ebp
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // [esp-8h] [ebp-48h]
  int v14; // [esp+10h] [ebp-30h]
  int v15; // [esp+14h] [ebp-2Ch]
  int v16; // [esp+14h] [ebp-2Ch]
  int v17; // [esp+18h] [ebp-28h]
  int v18; // [esp+18h] [ebp-28h]
  int v19; // [esp+1Ch] [ebp-24h] BYREF
  int v20; // [esp+20h] [ebp-20h]
  int v21; // [esp+24h] [ebp-1Ch]
  int v22; // [esp+28h] [ebp-18h] BYREF
  int v23; // [esp+2Ch] [ebp-14h]
  int v24; // [esp+30h] [ebp-10h]
  int v25; // [esp+34h] [ebp-Ch]
  int v26; // [esp+38h] [ebp-8h] BYREF
  int v27; // [esp+3Ch] [ebp-4h] BYREF

  v1 = 0;
  v21 = 2;
  v17 = 2;
  v15 = 0;
  v22 = 0;
  v14 = 0;
  v23 = sub_4AB570();
  v3 = this + 508;
  v20 = 4;
  do
  {
    if ( (unsigned __int8)sub_4AFCD0(v3) )
    {
      v4 = sub_4AFCF0(v3);
      sub_4AE370(0, v4, (int)&v19, (int)&v22);
      v1 += v22 + 1;
      if ( v19 > v15 )
        v15 = v19 + 5;
      ++v14;
    }
    v3 += 12;
    --v20;
  }
  while ( v20 );
  result = v14;
  v22 = v1;
  if ( v14 > 0 )
  {
    if ( v15 + 8 > 800 )
      v21 = 794 - v15;
    if ( v1 + 8 <= 600 )
    {
      v6 = 2;
    }
    else
    {
      v6 = 594 - v1;
      v17 = 594 - v1;
    }
    v20 = v6 + 3;
    v7 = (double)dword_6152E8 * 0.00125;
    *(float *)&v19 = (double)dword_6152EC * 0.0016666667;
    v21 = (__int64)((double)v21 * v7 + 0.5);
    v8 = (__int64)((double)v17 * *(float *)&v19 + 0.5);
    v24 = v8;
    v18 = (__int64)((double)v15 * v7 + 0.5);
    v22 = (__int64)((double)v22 * *(float *)&v19 + 0.5);
    v9 = (__int64)(v7 * 6.0 + 0.5);
    v10 = 0;
    v25 = v9 / 2;
    v16 = v21 + v9 / 2;
    while ( 1 )
    {
      if ( !v10 )
      {
        sub_4AB0E0(v23, v21, v8, v9 + v18, v9 + v22, -1426111420);
        sub_4AB0E0(v23, v16, v8 + v25, v18, v22, 2236962);
      }
      v13 = (__int64)((double)v20 * *(float *)&v19 + 0.5);
      v11 = sub_4AFCF0(&this[12 * v10 + 508]);
      sub_4AE3F0(0, v11, v16, v13, 0);
      v12 = sub_4AFCF0(&this[12 * v10 + 508]);
      sub_4AE370(0, v12, (int)&v27, (int)&v26);
      result = v14;
      ++v10;
      v20 += v26;
      if ( v10 >= v14 )
        break;
      v8 = v24;
    }
  }
  return result;
}
