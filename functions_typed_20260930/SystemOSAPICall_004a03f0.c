int __thiscall sub_4A03F0(void *this)
{
  while ( ShowCursor(1) <= 0 )
    ;
  GlobalStateSetter(0);
  ShortComputation_0ad0(this);
  AudioMixerDeviceInit(&byte_8AC494);
  return 0;
}

