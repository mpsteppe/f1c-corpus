int __thiscall sub_4A8B20(int this, int a2)
{
  int v3; // edi
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v9; // [esp+8h] [ebp-1A0h] BYREF
  int v10; // [esp+Ch] [ebp-19Ch] BYREF
  int v11; // [esp+10h] [ebp-198h] BYREF
  int v12; // [esp+14h] [ebp-194h] BYREF
  int v13; // [esp+18h] [ebp-190h] BYREF
  int v14; // [esp+1Ch] [ebp-18Ch] BYREF
  int v15; // [esp+20h] [ebp-188h] BYREF
  int v16; // [esp+24h] [ebp-184h] BYREF
  char String2[128]; // [esp+28h] [ebp-180h] BYREF
  char String[128]; // [esp+A8h] [ebp-100h] BYREF
  int v19[32]; // [esp+128h] [ebp-80h] BYREF

  String[0] = byte_629120;
  memset(&String[1], 0, 127);
  if ( operator new(0x64u) )
    v3 = sub_4AF330(0);
  else
    v3 = 0;
  sub_4AEFA0(v3);
  v4 = *(_DWORD *)(this + 492);
  v5 = *(_DWORD *)(this + 476) + 1;
  *(_DWORD *)(this + 500) = v3;
  *(_DWORD *)(this + 476) = v5;
  *(_DWORD *)(v3 + 48) = v4;
  while ( sub_4A84A0((_DWORD *)this) )
  {
    if ( strstr(Str, asc_608AB4) )
      break;
    if ( sub_577E50(byte_7656E8, aName_0, (int)String) )
    {
      if ( *(_BYTE *)(this + 482) && *(_DWORD *)(this + 484) < 4u )
        sub_4AA510(String);
      sub_4B1560(String);
      continue;
    }
    if ( sub_577E50(byte_7656E8, aEntertarget, (int)String2) || sub_577E50(byte_7656E8, aEsctarget, (int)String2) )
      goto LABEL_23;
    if ( sub_578220(aLocation, (int)&v12, (int)&v10, (int)&v9, (int)&v11, 0, 0, 0, 0) )
    {
      sub_4B13F0((__int64)*(float *)&v12, (__int64)*(float *)&v10, (__int64)*(float *)&v9, (__int64)*(float *)&v11);
    }
    else if ( sub_578220(aPosWH, (int)&v14, (int)&v13, (int)&v16, (int)&v15, 0, 0, 0, 0) )
    {
      sub_4B13F0(
        (__int64)*(float *)&v13,
        (__int64)(*(float *)&v13 + *(float *)&v15),
        (__int64)*(float *)&v14,
        (__int64)(*(float *)&v14 + *(float *)&v16));
    }
    else if ( sub_578220(aLocation2, (int)&v12, (int)&v10, (int)&v9, (int)&v11, 0, 0, 0, 0) )
    {
      sub_4B1410((__int64)*(float *)&v12, (__int64)*(float *)&v10, (__int64)*(float *)&v9, (__int64)*(float *)&v11);
    }
    else
    {
      if ( !sub_577E50(byte_7656E8, aSurface, (int)String2) )
      {
        if ( !sub_577E50(byte_7656E8, aPagePointer, (int)String2) )
        {
          if ( sub_577E50(byte_7656E8, aGizmo, (int)v19) )
          {
            v7 = sub_4A8E80(v19);
            if ( v7 )
              sub_4AD360(v7, *(_DWORD *)(this + 496), *(_DWORD *)(this + 500));
          }
          continue;
        }
LABEL_23:
        sub_578600(String2);
        continue;
      }
      sub_4AD970(String2, 1, 0, 1);
      v6 = sub_4ADBB0(String2);
      sub_4AF4C0(v6, 1);
    }
  }
  --*(_DWORD *)(this + 476);
  *(_DWORD *)(this + 500) = 0;
  return 0;
}
