int __thiscall sub_53C360(void *this, int a2, int a3, int a4, char a5)
{
  char *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  dword_8B8E30 = 0;
  v6 = &byte_8B5A3C;
  do
  {
    *v6 = 0;
    v6 += 132;
  }
  while ( (int)v6 < (int)byte_8B6ABC );
  dword_8B6AC0 = 0;
  dword_8B8F14 = 0;
  dword_8B8EE0 = -1;
  dword_8B8E34 = -1;
  dword_8B6AC4 = 1;
  dword_8B8E24 = 1;
  dword_8B8E2C = 1;
  dword_8B8E28 = 1;
  dword_8B8DC4 = 0;
  dword_8B8DC8 = 0;
  dword_8B8DCC = 0;
  dword_8B8DD0 = 0;
  dword_8B8F18 = 0;
  dword_8B8F1C = 0;
  dword_8B8F20 = 0;
  if ( (a5 & 2) != 0 )
    goto LABEL_10;
  if ( (a5 & 4) != 0 )
  {
    dword_8B8CEC = 2;
    flt_8B8CF0 = 0.5;
    flt_8B8CF4 = 0.5;
LABEL_8:
    StateIntSetter4(-1, -1, 16000, 12000);
    goto LABEL_9;
  }
  if ( (a5 & 8) != 0 )
  {
    dword_8B8CEC = 3;
    flt_8B8CF0 = 0.33340001;
    flt_8B8CF4 = 0.33340001;
    goto LABEL_8;
  }
LABEL_9:
  sub_53D750(&dword_8B78A0);
  sub_55BE80(a4, a5 & 1);
LABEL_10:
  ArithmeticComparison_b0d0();
  InitializeAudioSystemChannels(this);
  v7 = OperatorNewNhMallocWrapper(160);
  if ( v7 )
    v8 = StructZeroInitConstructor_f080(v7);
  else
    v8 = 0;
  dword_8B8F04 = v8;
  sub_55F0D0(this);
  GlobalMemoryStatusWrapper(this);
  v9 = OperatorNewNhMallocWrapper(12);
  if ( v9 )
    dword_8B8F2C = StructZeroInit_93b0(v9);
  else
    dword_8B8F2C = 0;
  return 0;
}
