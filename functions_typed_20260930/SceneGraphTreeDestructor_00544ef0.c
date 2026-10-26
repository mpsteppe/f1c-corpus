int __stdcall sub_544EF0(_DWORD *a1)
{
  if ( a1[108] )
    SceneGraphTreeDestructor(a1[108]);
  if ( a1[107] && a1[110] )
    SceneGraphTreeDestructor(a1[110]);
  EmptyStub_0170();
  DoublyLinkedListNodeRemoval_5090(a1);
  EmptyStub_7470(a1);
  FreeWrapper_7bcf(a1);
  return 0;
}

