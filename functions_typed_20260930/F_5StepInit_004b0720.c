int __thiscall sub_4B0720(_DWORD *this)
{
  char v3[256]; // [esp+8h] [ebp-100h] BYREF

  NamePathFormatterWithLengthCheck(this, v3, 0x100u);
  DualListDestructionWithDeepCleanup(this + 4678);
  VehicleDataFieldCopy(this);
  FAILWRONGTRIAGECATEGORY(v3);
  sub_4B0C00(this);
  return 0;
}

