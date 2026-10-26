int __thiscall sub_409890(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int v7; // [esp-4h] [ebp-Ch]

  if ( ValueGetter(dword_8AFE88) )
  {
    v3 = StringSearchInLinkedList(aMirrorBmp);
    v4 = v3;
    if ( v3 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(v3 + 84) + 24) & 0x40000) != 0 )
        this[2] = TwoLevelWideStringSearch(aRearview);
      else
        this[2] = 0;
      if ( this[2] )
      {
        v7 = *(_DWORD *)(v4 + 84);
        this[3] = v7;
        SuspensionPhysicsParameterSet(v7);
        if ( TwoLevelWideStringSearch(aMainview) )
          PointerStorePair2(sub_409950, 0);
        ConditionalRenderPipelineDispatch(this);
        v5 = this[3];
      }
      else
      {
        v5 = *(_DWORD *)(v4 + 84);
      }
      RenderDrawOperationWithClipping(0, 0, *(_DWORD *)(v5 + 28), *(_DWORD *)(v5 + 32), &unk_686B75);
    }
  }
  return 0;
}
