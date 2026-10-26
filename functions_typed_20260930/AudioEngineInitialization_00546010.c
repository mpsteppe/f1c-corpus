int __stdcall sub_546010(int *a1, int a2, int a3)
{
  int v3; // eax
  int v4; // eax
  int i; // esi

  dword_8B8EF8 = 0;
  Addend = 0;
  dword_8B8EE8 = 0;
  if ( dword_8B8F00 && !sub_55B8C0(a2, &dword_8B8EE8) )
    dword_8B8F00(16, 0);
  dword_8B8EF0 = dword_8B8EE8;
  Addend = dword_8B8EE8 / 2;
  InterlockedIncrement(&dword_8B8EF8);
  AudioVolumeLoadComputation(0);
  v3 = OperatorNewNhMallocWrapper(496);
  if ( v3 )
    v4 = AudioMixerChannelInitializer(v3);
  else
    v4 = 0;
  *a1 = v4;
  LinkedListAppend_c5d0(v4);
  *(_DWORD *)(*a1 + 236) |= a3;
  EmptyStubWithFlagCheck(2, 0);
  if ( MemoryAllocationWithFallback((_BYTE *)*a1, a2) )
  {
    DoublyLinkedListUnlink(*a1);
    return -1;
  }
  else
  {
    Addend += *(_DWORD *)(*(_DWORD *)(*a1 + 272) + 20)
            + *(_DWORD *)(*(_DWORD *)(*a1 + 272) + 24)
            + *(_DWORD *)(*(_DWORD *)(*a1 + 272) + 28)
            + *(_DWORD *)(*(_DWORD *)(*a1 + 272) + 32);
    dword_8B8EF4 = Addend;
    InterlockedIncrement(&dword_8B8EF8);
    AudioVolumeLoadComputation(0);
    if ( VertexBufferResourceAllocation((_DWORD *)*a1) )
    {
      DoublyLinkedListUnlink(*a1);
      *a1 = 0;
      return -1;
    }
    else
    {
      for ( i = *(_DWORD *)(*a1 + 256); i; i = *(_DWORD *)(i + 260) )
      {
        ArithmeticComparison_9170(i);
        LinkedListWalkWithDispatch(i);
        LinkedListUpdate(i);
        AudioNodeUpdateWalk(i);
        sub_549470(i);
      }
      InterlockedIncrement(&dword_8B8EF8);
      AudioVolumeLoadComputation(0);
      EmptyStubWithFlagCheck(1, 0);
      return 0;
    }
  }
}

