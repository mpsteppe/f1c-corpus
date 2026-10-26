int __thiscall sub_4D8720(void *this)
{
  sub_4D8FB0();
  AudioResourceReleaseByType(1);
  AudioResourceReleaseByType(2);
  AudioResourceReleaseByType(3);
  AudioResourceReleaseByType(4);
  AudioResourceReleaseByType(5);
  return BatchVTableDispatchAndCleanup(this);
}

