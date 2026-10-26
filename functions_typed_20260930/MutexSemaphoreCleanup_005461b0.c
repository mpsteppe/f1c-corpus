int __stdcall sub_5461B0(void **a1)
{
  if ( ResourceCleanupDestructionForDirectXObjects(a1) )
    return -1;
  DoublyLinkedListUnlink((int)a1);
  if ( a1 )
  {
    ReleaseSceneNode(a1);
    FreeWrapper_7bcf(a1);
  }
  dword_8B8F28 = 0;
  return 0;
}

