int __fastcall sub_562C90(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // eax

  if ( *a1 )
    return 4;
  a1[36] = a4;
  result = sub_562D90(a1);
  if ( !result )
  {
    result = sub_562E30(a1, a3);
    if ( !result && (a4 == 6 || a4 == 7 || (result = SocketArrayCreate(a1)) == 0) )
    {
      a1[28] = 0;
      a1[29] = 0;
      a1[38] = SingleDelegationCall(a1);
      a1[343] = -1;
      if ( !a2 )
        PollingLoopWithProcessCalls(a1);
      return 0;
    }
  }
  return result;
}

