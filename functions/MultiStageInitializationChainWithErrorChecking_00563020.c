int __fastcall sub_563020(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( *a1 )
    return 4;
  result = SocketArrayCreate(a1);
  if ( !result )
  {
    result = CreateUdpBroadcastSocket(a1);
    if ( !result )
    {
      result = sub_5630D0(a1, a3, a4, a5);
      if ( !result )
      {
        a1[28] = 0;
        a1[29] = 0;
        if ( !a2 )
          PollingLoopWithProcessCalls(a1);
        return 0;
      }
    }
  }
  return result;
}
