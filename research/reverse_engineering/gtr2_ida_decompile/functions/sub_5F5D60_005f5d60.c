int sub_5F5D60()
{
  _DWORD *v0; // eax
  int v1; // ebp
  _DWORD *v2; // esi
  void *v3; // ecx
  int v4; // esi
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  void *v8; // ecx
  int result; // eax
  char *v10; // esi
  int v11; // eax
  double v12; // st7
  int v13; // eax
  int v14; // [esp+10h] [ebp-20h]
  LARGE_INTEGER Frequency; // [esp+18h] [ebp-18h] BYREF
  int v16; // [esp+2Ch] [ebp-4h]

  dword_910EF4 = 3;
  v0 = operator new(0x124u);
  v1 = 0;
  v16 = 0;
  if ( v0 )
  {
    v2 = v0 + 1;
    *v0 = 3;
    sub_630A11(v0 + 1, 96, 3, sub_5F56F0, nullsub_7);
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v16 = -1;
  dword_FB2778 = v3;
  sub_5F5AD0((int)v3, 1);
  v4 = 0;
  if ( dword_910EF4 > 0 )
  {
    v5 = 0;
    do
    {
      sub_5F5AD0((int)dword_FB2778 + v5, 1);
      ++v4;
      v5 += 96;
    }
    while ( v4 < dword_910EF4 );
  }
  dword_910EF8 = 3;
  v6 = operator new(0x124u);
  v16 = 1;
  if ( v6 )
  {
    v7 = v6 + 1;
    *v6 = 3;
    sub_630A11(v6 + 1, 96, 3, sub_5F56F0, nullsub_7);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  dword_FB277C = v8;
  result = sub_5F5AD0((int)v8, 1);
  if ( dword_910EF8 > 0 )
  {
    v14 = 0;
    do
    {
      v10 = (char *)dword_FB277C + v14;
      *(_DWORD *)((char *)dword_FB277C + v14) = 1;
      if ( QueryPerformanceFrequency(&Frequency) )
        *((double *)v10 + 1) = 1.0 / ((double)Frequency.HighPart * 4294967296.0 + (double)Frequency.LowPart);
      sub_5F5760((double *)v10, (LONG *)v10 + 11, (DWORD *)v10 + 10, 0);
      v11 = *((_DWORD *)v10 + 10);
      v12 = *((double *)v10 + 1) * 4294967296.0;
      *((_DWORD *)v10 + 12) = v11;
      *((_DWORD *)v10 + 16) = v11;
      *((double *)v10 + 2) = v12;
      *((_DWORD *)v10 + 22) = v11;
      v13 = *((_DWORD *)v10 + 11);
      *((double *)v10 + 3) = 0.0;
      *((_DWORD *)v10 + 13) = v13;
      *((_DWORD *)v10 + 17) = v13;
      *((_DWORD *)v10 + 23) = v13;
      *((_DWORD *)v10 + 14) = 0;
      *((_DWORD *)v10 + 15) = 0;
      result = dword_910EF8;
      ++v1;
      v14 += 96;
    }
    while ( v1 < dword_910EF8 );
  }
  return result;
}
