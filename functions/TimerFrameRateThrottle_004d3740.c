int __thiscall sub_4D3740(_DWORD *this)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  FlagPropertyGetter(&v3, 2048);
  LapSplitTimeEvent((float *)&unk_5F070C + 4656 * v3, (int)this);
  FlagPropertyGetter(&v4, 2048);
  AICommandMessageQueueDispatcher((int *)&unk_5EC6D8 + 4656 * v3, v4 + 1, 0);
  BufferEntryClear(this[5]);
  return 0;
}
