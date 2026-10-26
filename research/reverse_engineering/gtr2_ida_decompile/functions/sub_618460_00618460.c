DWORD __stdcall sub_618460(LPVOID lpThreadParameter)
{
  signed int v1; // esi
  int v2; // esi
  int v3; // eax
  HANDLE Handles[2]; // [esp+4h] [ebp-8h] BYREF

  Handles[0] = dword_FB4154;
  Handles[1] = (HANDLE)dword_FB415C;
  while ( !WaitForMultipleObjects(2u, Handles, 0, 0xFFFFFFFF) )
  {
    v1 = Seed;
    srand(Seed);
    dword_FB4164 = 0;
    if ( v1 % 10 > 0 )
    {
      v2 = v1 % 10;
      do
      {
        v3 = rand();
        --v2;
        dword_FB4164 = (v3 + dword_FB4164) * (v3 + dword_FB4164);
      }
      while ( v2 );
    }
    dword_FB4164 += rand();
    SetEvent(hEvent);
  }
  return 0;
}
