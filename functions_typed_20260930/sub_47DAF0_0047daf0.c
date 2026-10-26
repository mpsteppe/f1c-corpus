_DWORD *__thiscall sub_47DAF0(_DWORD *this, int a2)
{
  ConstructorInitVTable(1, -1);
  *this = &off_5A6B20;
  this[59] = a2;
  if ( a2 == 480 )
  {
    LinkedListInsertWithNodeAllocation(aBegin, -1);
    LinkedListInsertWithNodeAllocation(&off_5C7364, -1);
    LinkedListInsertWithNodeAllocation(aReverseScanFas, -1);
    LinkedListInsertWithNodeAllocation(aReverseScan, -1);
    LinkedListInsertWithNodeAllocation(aPlaybackwards, -1);
    LinkedListInsertWithNodeAllocation(aStop, -1);
    LinkedListInsertWithNodeAllocation(aPlay, -1);
    LinkedListInsertWithNodeAllocation(aForwardScan, -1);
    LinkedListInsertWithNodeAllocation(aForwardScanFas, -1);
    LinkedListInsertWithNodeAllocation(aDropBookmark, -1);
    LinkedListInsertWithNodeAllocation(aRemoveBookmark, -1);
  }
  return this;
}

