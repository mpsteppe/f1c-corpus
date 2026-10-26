int __thiscall sub_49D150(_DWORD *this)
{
  int v2; // eax
  int result; // eax

  v2 = this[6];
  if ( v2 )
  {
    sub_53CB90(v2);
    this[6] = 0;
  }
  if ( this[7] )
  {
    sub_53CB90(this[7]);
    this[7] = 0;
  }
  if ( this[1] )
  {
    StringCompareLinkedListSearch(this[1]);
    this[1] = 0;
  }
  if ( this[2] )
  {
    StringCompareLinkedListSearch(this[2]);
    this[2] = 0;
  }
  if ( this[3] )
  {
    StringCompareLinkedListSearch(this[3]);
    this[3] = 0;
  }
  ShortComputation_ec40(this + 24);
  SoundResourceCleanup(this + 24);
  SingleFieldFreeWrapper(this + 24);
  ConditionalFreeSubCall(this + 24);
  ShortComputation_ec40(this + 43);
  SoundResourceCleanup(this + 43);
  SingleFieldFreeWrapper(this + 43);
  ConditionalFreeSubCall(this + 43);
  ShortComputation_ec40(this + 62);
  SoundResourceCleanup(this + 62);
  SingleFieldFreeWrapper(this + 62);
  ConditionalFreeSubCall(this + 62);
  ShortComputation_ec40(this + 81);
  SoundResourceCleanup(this + 81);
  SingleFieldFreeWrapper(this + 81);
  ConditionalFreeSubCall(this + 81);
  ShortComputation_ec40(this + 100);
  SoundResourceCleanup(this + 100);
  SingleFieldFreeWrapper(this + 100);
  ConditionalFreeSubCall(this + 100);
  result = 0;
  *(_BYTE *)this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  return result;
}

