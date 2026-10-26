int __fastcall sub_564110(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // ebp
  int v7; // edx
  char *v8; // ebx
  int v9; // edx
  char *v10; // eax
  int v13; // [esp+Ch] [ebp-14h]
  _DWORD v16[2]; // [esp+18h] [ebp-8h] BYREF

  v13 = 0;
  v6 = StructAllocInitWithSwitchBasedType(a4, a5);
  v7 = a3;
  LOBYTE(v7) = 92;
  v8 = (char *)StringTokenizer(a3 + 1, v7);
  if ( a2 > 0 )
  {
    while ( 1 )
    {
      if ( !v8 )
        v8 = byte_5EA438;
      if ( !strcmp(*(const char **)(a1 + 4 * v13), aIp_0) )
      {
        NetworkAddressParser(v6, v8);
      }
      else if ( a4 == 6 && !strcmp(*(const char **)(a1 + 4 * v13), aOther) )
      {
        v10 = v8;
        if ( *v8 )
        {
          do
          {
            if ( *v10 == 1 )
              *v10 = 92;
          }
          while ( *++v10 );
        }
        AudioMixerPollingUpdateLoop(v6, v8);
      }
      else
      {
        v16[0] = SingletonGlobalAccessorWithFallbackAlloc(v6);
        v16[1] = SingletonGlobalAccessorWithFallbackAlloc(v6);
        FunctionPointerCallWithErrorHandling(*(_DWORD *)(v6 + 12), v16);
      }
      if ( ++v13 >= a2 )
        break;
      LOBYTE(v9) = 92;
      v8 = (char *)StringTokenizer(0, v9);
    }
  }
  return v6;
}

