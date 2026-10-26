int __cdecl sub_58DD70(int a1)
{
  _BYTE *v1; // eax
  char v2; // bl
  int v3; // ecx
  int v4; // esi
  unsigned int v5; // edx
  _BYTE *v6; // ecx
  int v7; // eax
  unsigned __int8 *v8; // eax
  int result; // eax
  _DWORD v10[2]; // [esp+8h] [ebp-8h] BYREF

  sub_58DE20(v10);
  if ( LOWORD(dword_800100[2 * a1]) == 0xFFFF )
    return sub_58DE40(0, a1);
  v1 = (_BYTE *)sub_58D520((unsigned __int16 *)(8 * a1 + 8388864));
  if ( !v1 )
    return sub_58DE40(0, a1);
  v2 = v1[10];
  if ( (v2 & 0x10) == 0 )
    return sub_58DE40(0, a1);
  v3 = (char)v1[7];
  v4 = 2 * (unsigned __int8)v1[6];
  v5 = (3 * ((v3 & 0xF) + 1)) & 0xFFFFFFFC;
  v6 = &v1[(3 * ((v3 >> 4) + 1)) & 0xFFFFFFFC];
  v7 = v4 + 3;
  LOBYTE(v7) = (v4 + 3) & 0xFC;
  v8 = &v6[v5 + 12 + v7];
  if ( (v2 & 8) != 0 )
    v8 += (v4 + 7) & 0xFFFFFFFC;
  v10[0] = *v8;
  v10[1] = v8 + 2;
  result = sub_58DE40(v10, a1);
  if ( result < 0 )
    return sub_58DE40(0, a1);
  return result;
}
