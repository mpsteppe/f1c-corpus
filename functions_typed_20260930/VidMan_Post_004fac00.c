int sub_4FAC00()
{
  int result; // eax
  char *v1; // eax
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  char *i; // eax
  int v6; // ecx
  char v8[512]; // [esp+2h] [ebp-200h] BYREF

  if ( StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_26, 1426) )
    DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanP);
  FrameRateCounterInitReset(&dword_8AFCA8);
  MutexSemaphoreCleanup(dword_8AFE88);
  dword_8AFE88 = 0;
  SingleGlobalSetter(0);
  result = 396 * dword_8AC48C + dword_8AC490;
  if ( result )
  {
    v1 = (char *)(result + 4);
    v2 = (char *)(v8 - v1);
    do
    {
      v3 = *v1;
      v1[(_DWORD)v2] = *v1;
      ++v1;
    }
    while ( v3 );
    v4 = strlen(v8);
    if ( v4 > 0 )
    {
      for ( i = &v8[v4 - 1]; i >= v8; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v6 = strlen(v8);
    if ( v6 > 0 && v8[v6 - 1] == 92 )
      v8[v6 - 1] = 0;
    return StringMatchWithFlagSet(v8);
  }
  return result;
}

