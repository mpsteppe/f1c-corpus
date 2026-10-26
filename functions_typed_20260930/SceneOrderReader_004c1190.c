int sub_4C1190()
{
  int v0; // eax

  v0 = AudioChannelStop(aSceneorder);
  if ( v0 )
    return LinkedListCount(v0);
  else
    return 0;
}

