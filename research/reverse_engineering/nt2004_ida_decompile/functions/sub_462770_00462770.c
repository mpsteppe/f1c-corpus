int __thiscall sub_462770(int this)
{
  int v2; // edi
  LPVOID *v3; // eax
  LPVOID *v4; // edi
  char *v5; // eax
  int result; // eax
  LPVOID **v7; // eax
  float v8; // [esp+0h] [ebp-E0h]
  char v9; // [esp+8h] [ebp-D8h]
  int v10[52]; // [esp+10h] [ebp-D0h] BYREF

  v8 = dbl_7DA9D0;
  sub_4D0D00(4, 46, 0, 63, LODWORD(v8), 3);
  v2 = sub_56A3B0(*(_DWORD *)(this + 6708));
  *(_BYTE *)(v2 + 4) = 1;
  sub_56A3D0(v10, (LOWORD(v10[0]) >> 6) + 8, v2, 1, 1, -1, 0);
  sub_56A3C0(*(_DWORD *)(this + 6708), v2);
  *(_BYTE *)(this + 33) = 0;
  v3 = (LPVOID *)operator new(8u);
  if ( v3 )
  {
    *v3 = 0;
    v3[1] = (LPVOID)-1;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  sub_578600(aClosingTrack);
  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5513) )
  {
    v5 = (char *)*v4;
    if ( !*v4 )
      v5 = &byte_629120;
    sub_500FE0((int)&unk_7D7920, v5, v9);
  }
  result = dword_768948;
  if ( dword_768948 )
  {
    if ( v4 )
    {
      v7 = (LPVOID **)operator new(0xCu);
      if ( v7 )
      {
        *v7 = v4;
        v7[1] = 0;
        *((_BYTE *)v7 + 8) = 0;
      }
      else
      {
        v7 = 0;
      }
      if ( *(_DWORD *)(this + 30120) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 30124) + 4) = v7;
      }
      else
      {
        *(_DWORD *)(this + 30120) = v7;
        *(_DWORD *)(this + 30128) = v7;
      }
      *(_DWORD *)(this + 30124) = v7;
      result = *(_DWORD *)(this + 30132) + 1;
      *(_DWORD *)(this + 30132) = result;
    }
  }
  else if ( v4 )
  {
    if ( *v4 )
      sub_5BE8AE(*v4);
    return sub_5BE8AE(v4);
  }
  return result;
}
