char __thiscall sub_45D240(_BYTE *this)
{
  if ( *this )
  {
    SingleFunctionCallWrapper_1f60(0);
    SocketCloseAndCleanup(0);
    *this = 0;
  }
  return 1;
}
