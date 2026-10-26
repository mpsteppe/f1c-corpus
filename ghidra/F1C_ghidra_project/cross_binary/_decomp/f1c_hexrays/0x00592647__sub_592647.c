// f1c  0x00592647  size=320
int __cdecl sub_592647(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  int v17; // ecx
  int result; // eax
  int v19; // eax
  bool v20; // sf
  int v21; // ecx
  int v22; // [esp+18h] [ebp+10h]

  if ( a2 == 1 )
  {
    v22 = a3 & 3;
    if ( (a3 & 3) != 0 )
      v12 = dword_5E9B04[a4];
    else
      v12 = dword_5E9AD0[a4];
    v13 = v12 + 1;
    v14 = (365 * a3 + ((a3 - 1) >> 2) + v12 + 1 - 25563) % 7;
    if ( v14 > a6 )
      v15 = a6 + 7 * a5 - v14 + v13;
    else
      v15 = v13 + a6 + 7 * a5 - v14 - 7;
    if ( a5 == 5 )
    {
      if ( v22 )
        v16 = dword_5E9B08[a4];
      else
        v16 = dword_5E9AD4[a4];
      if ( v15 > v16 )
        v15 -= 7;
    }
  }
  else
  {
    if ( (a3 & 3) != 0 )
      v17 = dword_5E9B04[a4];
    else
      v17 = dword_5E9AD0[a4];
    v15 = a7 + v17;
  }
  if ( a1 == 1 )
  {
    dword_5E77F4 = v15;
    dword_5E77F0 = a3;
    result = a11 + 1000 * (a10 + 60 * (a9 + 60 * a8));
    dword_5E77F8 = result;
    return result;
  }
  dword_5E7804 = v15;
  v19 = 1000 * (a10 + dword_5E7760 + 60 * (a9 + 60 * a8));
  v20 = a11 + v19 < 0;
  result = a11 + v19;
  dword_5E7808 = result;
  if ( v20 )
  {
    result += 86400000;
    v21 = v15 - 1;
    dword_5E7808 = result;
LABEL_24:
    dword_5E7804 = v21;
    goto LABEL_25;
  }
  if ( result >= 86400000 )
  {
    result -= 86400000;
    v21 = v15 + 1;
    dword_5E7808 = result;
    goto LABEL_24;
  }
LABEL_25:
  dword_5E7800 = a3;
  return result;
}
