// f1c  0x0055f060  size=26
void sub_55F060()
{
  _MEMORYSTATUS Buffer; // [esp+0h] [ebp-20h] BYREF

  Buffer.dwLength = 32;
  GlobalMemoryStatus(&Buffer);
}
