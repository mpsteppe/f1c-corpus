int __fastcall sub_562E30(int a1, const char *a2)
{
  int v3; // eax
  int v4; // eax
  int v6; // esi
  int i; // eax
  int v8; // eax
  int v9; // eax
  const char *v10; // eax
  int v11; // eax
  char buf[256]; // [esp+10h] [ebp-140h] BYREF
  char v14[64]; // [esp+110h] [ebp-40h] BYREF

  v3 = recv(*(_DWORD *)(a1 + 136), buf, 255, 0);
  if ( v3 == -1 )
    return 3;
  buf[v3] = 0;
  v4 = sub_587C20(buf, aSecure);
  if ( !v4 )
    return 5;
  v6 = v4 + 8;
  sub_564C70(v4 + 8, 6);
  for ( i = 0; i < 6; ++i )
    *(_BYTE *)(v6 + i) ^= *(_BYTE *)(a1 + 44 + i);
  PadOutputWithSpacesUpToLengthLimit(v14);
  StringFormatWithBufferOverflowCheck(
    buf,
    "\\gamename\\%s\\gamever\\%s\\location\\0\\validate\\%s\\enctype\\2\\final\\\\queryid\\1.1\\",
    (const char *)(a1 + 76),
    a18,
    v14);
  v8 = send(*(_DWORD *)(a1 + 136), buf, strlen(buf), 0);
  if ( v8 == -1 || !v8 )
    return 3;
  v9 = *(_DWORD *)(a1 + 144);
  if ( v9 == 6 )
  {
    v10 = aGroups;
    *(_DWORD *)(a1 + 1460) = 0;
  }
  else if ( v9 == 7 )
  {
    v10 = aInfo2;
    *(_DWORD *)(a1 + 1460) = 0;
  }
  else
  {
    v10 = (const char *)&off_5E4FD4;
  }
  if ( a2 )
    StringFormatWithBufferOverflowCheck(
      buf,
      "\\list\\%s\\gamename\\%s\\where\\%s\\final\\",
      v10,
      (const char *)(a1 + 12),
      a2);
  else
    StringFormatWithBufferOverflowCheck(buf, "\\list\\%s\\gamename\\%s\\final\\", v10, (const char *)(a1 + 12));
  v11 = send(*(_DWORD *)(a1 + 136), buf, strlen(buf), 0);
  if ( v11 == -1 || !v11 )
    return 3;
  AudioValueSetterCall(a1, 1);
  return 0;
}

