int __thiscall sub_563E00(LPVOID *this)
{
  void *v3; // eax
  void *v4; // ecx

  if ( *this )
    return 4;
  BatchLoopWithMemoryCleanup(this[1]);
  v3 = (void *)Malloc0x18ByteStructWithInnerBuffer(sub_5640F0);
  v4 = this[37];
  this[1] = v3;
  DestroyAudioArrayFreeElementsThenContainer(v4);
  this[37] = (LPVOID)AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630);
  this[38] = 0;
  return 0;
}

