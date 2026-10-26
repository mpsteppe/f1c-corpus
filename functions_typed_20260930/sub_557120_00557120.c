int __thiscall sub_557120(int this)
{
  int v2; // ebx
  int v3; // edi
  _DWORD *v4; // ecx
  int i; // eax
  int j; // edi
  float v8; // [esp+Ch] [ebp-4h]

  EmptyStub_0170();
  v2 = 0;
  if ( *(int *)(this + 332) > 0 )
  {
    v3 = 0;
    do
    {
      v4 = *(_DWORD **)(v3 + *(_DWORD *)(this + 336) + 16);
      if ( v4 )
        sub_5503A0(v4);
      ++v2;
      v3 += 24;
    }
    while ( v2 < *(_DWORD *)(this + 332) );
  }
  for ( i = *(_DWORD *)(this + 348); i; i = *(_DWORD *)(i + 52) )
    *(_DWORD *)(i + 36) &= ~8u;
  if ( (*(_DWORD *)(this + 236) & 0x800) != 0 )
  {
    ClearBuffersLoop((_DWORD *)this);
    if ( ((unsigned int)&unk_600000 & *(_DWORD *)(this + 236)) != 0 )
      NestedLinkedListTraversalWithDirtyMark((_DWORD *)this, *(_DWORD *)(this + 248));
    *(_DWORD *)(this + 236) &= 0xFFBFF7FF;
  }
  dword_8CEF70 = 0;
  if ( !dword_8B8DF0 )
    VTableGetterWrapper(dword_8B78A0);
  if ( *(int *)(this + 364) > 0 )
    AudioNodeIterator((_DWORD *)this);
  for ( j = *(_DWORD *)(this + 248); j; j = *(_DWORD *)(j + 440) )
    sub_556E70(j, (_DWORD *)this);
  if ( !dword_8B8DF0 )
    VTableDispatchGetter(dword_8B78A0);
  v8 = sub_556730(-1);
  *(float *)(this + 240) = v8;
  D3DAnimationTimeUpdate((_DWORD *)this, v8);
  return AddFloatToAnimationChannels((_DWORD *)this, *(float *)(this + 240));
}

