int __thiscall sub_4A51C0(void *this, int a2, int a3)
{
  int v5; // edx
  float v6; // [esp+8h] [ebp-378h]
  _DWORD v7[7]; // [esp+Ch] [ebp-374h] BYREF
  CHAR v8[64]; // [esp+28h] [ebp-358h] BYREF
  _BYTE v9[384]; // [esp+68h] [ebp-318h] BYREF
  int v10; // [esp+1E8h] [ebp-198h]
  char v11; // [esp+1ECh] [ebp-194h]
  int v12; // [esp+1F4h] [ebp-18Ch]
  int v13; // [esp+1F8h] [ebp-188h]
  int v14; // [esp+1FCh] [ebp-184h]
  _BYTE v15[384]; // [esp+200h] [ebp-180h] BYREF

  sub_5668B0(v7);
  sub_566B20(a2, 1);
  if ( !v7[0] )
    return sub_5668D0(v7);
  v6 = 0.0;
  switch ( dword_7CF884 )
  {
    case 0:
      v6 = 3.0;
      break;
    case 1:
      v6 = 2.0;
      break;
    case 2:
      v6 = 1.0;
      break;
    case 3:
      v6 = 0.0;
      break;
    default:
      break;
  }
  memset(v15, 0, sizeof(v15));
  v10 = 0;
  v14 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 1;
  while ( sub_566CC0(v15, 384) )
  {
    if ( !sub_5651B0(v9) )
    {
      if ( sub_565520(aInstance, v8, 0) )
        sub_4A4ED0((int)this, v5, (int)v7, (int)v8, a3, v6);
    }
  }
  sub_566B90(v7);
  return sub_5668D0(v7);
}
