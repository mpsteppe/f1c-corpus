int *__cdecl _fltin2(int *a1, int a2)
{
  int v2; // edi
  char v3; // bl
  int v4; // eax
  int *result; // eax
  int v6; // ecx
  int v7; // [esp+Ch] [ebp-1Ch] BYREF
  int v8; // [esp+10h] [ebp-18h] BYREF
  int v9; // [esp+14h] [ebp-14h]
  _BYTE v10[12]; // [esp+18h] [ebp-10h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  v11 = dword_912B08;
  v2 = 0;
  v3 = sub_641CE6(v10, &v7, a2, 0, 0, 0, 0);
  if ( (v3 & 4) != 0 )
  {
    v2 = 512;
    v8 = 0;
    v9 = 0;
  }
  else
  {
    v4 = sub_64094B(v10, &v8);
    if ( (v3 & 2) != 0 || v4 == 1 )
      v2 = 128;
    if ( (v3 & 1) != 0 || v4 == 2 )
      v2 |= 0x100u;
  }
  result = a1;
  v6 = v7 - a2;
  *a1 = v2;
  a1[1] = v6;
  a1[4] = v8;
  a1[5] = v9;
  return result;
}
