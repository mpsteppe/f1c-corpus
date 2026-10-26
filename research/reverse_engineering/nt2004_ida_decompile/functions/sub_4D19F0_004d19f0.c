int __thiscall sub_4D19F0(float *this)
{
  DWORD TickCount; // eax
  float *v3; // esi
  int v4; // ebx
  float *v5; // esi
  int v6; // ebx
  char v8[4]; // [esp+10h] [ebp-4h] BYREF

  *this = 0.0;
  TickCount = GetTickCount();
  srand(TickCount);
  v3 = this + 1;
  v4 = 256;
  do
  {
    ++v3;
    --v4;
    *(v3 - 1) = (double)rand() * 0.000030518509;
  }
  while ( v4 );
  v5 = this + 257;
  v6 = 256;
  do
  {
    ++v5;
    --v6;
    *(v5 - 1) = (double)rand() * 0.000061037019 - 1.0;
  }
  while ( v6 );
  return sub_5AE03B(v8, this + 513);
}
