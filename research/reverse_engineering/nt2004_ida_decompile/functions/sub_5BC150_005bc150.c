int __fastcall sub_5BC150(int a1, const char *a2, const char *a3, const char *a4, int a5, int a6, int a7)
{
  DWORD TickCount; // eax

  *(_DWORD *)a1 = 1;
  sub_5BDAA0();
  sub_5B9FF0();
  strcpy((char *)(a1 + 12), a2);
  strcpy((char *)(a1 + 44), a3);
  strcpy((char *)(a1 + 76), a4);
  *(_DWORD *)(a1 + 1152) = a6;
  *(_DWORD *)(a1 + 1156) = a7;
  *(_DWORD *)(a1 + 1160) = &byte_629120;
  *(_DWORD *)(a1 + 1168) = 0;
  *(_DWORD *)(a1 + 1184) = -1;
  *(_DWORD *)(a1 + 116) = 0;
  *(_DWORD *)(a1 + 120) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 1148) = -1;
  *(_DWORD *)(a1 + 1144) = 0;
  *(_DWORD *)(a1 + 1180) = &byte_629120;
  *(_DWORD *)(a1 + 1172) = 0;
  *(_DWORD *)(a1 + 1192) = a5;
  TickCount = GetTickCount();
  srand(TickCount);
  return sub_5BDB90();
}
