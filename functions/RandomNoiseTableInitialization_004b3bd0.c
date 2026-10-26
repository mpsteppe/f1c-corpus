int __thiscall sub_4B3BD0(float *this)
{
  DWORD TickCount; // eax
  int v3; // ecx
  float *v4; // esi
  int v5; // ebx
  float *v6; // esi
  int v7; // ebx
  char v9[4]; // [esp+10h] [ebp-4h] BYREF

  *this = 0.0;
  TickCount = GetTickCount();
  TLSFieldSetter(TickCount);
  v4 = this + 1;
  v5 = 256;
  do
  {
    ++v4;
    --v5;
    *(v4 - 1) = (double)RandLCGRandomNumberGenerator(v3) * 0.000030518509;
  }
  while ( v5 );
  v6 = this + 257;
  v7 = 256;
  do
  {
    ++v6;
    --v7;
    *(v6 - 1) = (double)RandLCGRandomNumberGenerator(v3) * 0.000061037019 - 1.0;
  }
  while ( v7 );
  return RDTSCTimestampRead(v9, this + 513);
}
