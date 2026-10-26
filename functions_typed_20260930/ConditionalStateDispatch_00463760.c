char __thiscall sub_463760(int *this, char a2)
{
  bool v3; // al
  int v4; // ecx

  v3 = StateCheckWrapper(this);
  v4 = *this;
  if ( !v3 )
    return ServerOpenedClosedNotification(v4, a2);
  if ( a2 )
    return ServerOpenTrackSignal(v4);
  return ServerCloseTrackSignal(v4);
}

